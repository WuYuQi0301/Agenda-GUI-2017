#include "Storage.hpp"
#include "Path.hpp"
#include <fstream> 
#include <vector>
#include <algorithm>
#include <QDebug>
#include <QDir>
using namespace std;

shared_ptr<Storage> Storage::m_instance = nullptr;

Storage::Storage()
{
  m_dirty = false;
  readFromFile();
}

bool Storage::readFromFile(void)
{
    ifstream fin;
    fin.open(Path::userPath, ios::in);

    if (!fin.is_open())
    {
qDebug() << "storage : open fail";
qDebug() << QDir::currentPath();
      return false;  
    }
    string _data = "";
    while (getline(fin, _data))
    {
        int counter = 0;
        for (unsigned i = 0; i < _data.size(); i++)
            if(_data[i] == '\"')
                counter++;
        if (counter != 8)
        {
            _data.clear();
            continue;
        }

        string _name = "", _password = "", _email = "", _phone = "";

        int i = 1;
        while (_data[i] != '\"')
            _name.append(1, _data[i++]);

        i += 3;
        while (_data[i] != '\"')
            _password.append(1, _data[i++]);

        i += 3;
        while (_data[i] != '\"')
            _email.append(1, _data[i++]);

        i +=3;
        while (_data[i] != '\"')
            _phone.append(1, _data[i++]);

        if (_name == "" || _password == "" || _email == "" || _phone == "")
            continue;
//        qDebug() << QString::fromStdString(_name) << "\n";
        User newUser(_name, _password, _email, _phone); 
        m_userList.push_back(newUser);
        _data.clear();
    }

    fin.close();

    fin.open(Path::meetingPath);

    if (!fin.is_open())
        return false;

    while (getline(fin, _data))
    {
        int counter = 0;
        for (unsigned i = 0; i < _data.size(); i++)
            if(_data[i] == '\"')
                counter++;
        if (counter != 10)
        {
            _data.clear();
            continue;
        }

        string _title = "", _sponsor = "", _startDate = "", _endDate = "", _paticipator = "";
        std::vector<string> _paticipators;
        int i = 1;
        while (_data[i] != '\"')
            _sponsor.append(1, _data[i++]);

        i += 3;
        while (_data[i] != '\"')
            _paticipator.append(1, _data[i++]);
        
        i += 3;
        while (_data[i] != '\"')
            _startDate.append(1, _data[i++]);
        
        i += 3;
        while (_data[i] != '\"')
            _endDate.append(1, _data[i++]);

        i += 3;
        while (_data[i] != '\"')
            _title.append(1, _data[i++]);

        if (_title == "" || _sponsor == "" || _startDate == "" || _endDate == "" || _paticipator == "")
            continue;

        unsigned int j = 0;
        while (j < _paticipator.size())
        {
            string _pa;
            while (_paticipator[j] != '&' && j < _paticipator.size())
               _pa.append(1, _paticipator[j++]);
            _paticipators.push_back(_pa);
            if( j < _paticipator.size() )j++;
        }
        Date startDate(_startDate);
        Date endDate(_endDate);

        m_meetingList.push_back(Meeting(_sponsor, _paticipators, startDate, endDate, _title));
    }
    fin.close();
    return true;
}

bool Storage::writeToFile(void)
{
    ofstream fout;
    fout.open(Path::userPath, ios::out);
    if (!fout)
        return false;

    for (auto it_user = m_userList.begin(); it_user != m_userList.end(); )
    {
        if (it_user->getName() == "" || it_user->getPassword() == ""
             || it_user->getEmail() == "" || it_user->getPhone() == "" )
        {
            it_user++;
            continue;
        }
        else {
            fout << "\"" << it_user->getName() << "\",\"" << it_user->getPassword()
                <<"\",\"" << it_user->getEmail() << "\",\"" << it_user->getPhone() << "\""; 
            if (++it_user != m_userList.end()) fout << endl;
        }
    }

    fout.close();

    fout.open(Path::meetingPath, ios::out);
    if (!fout)
        return false;
    
    for (auto it_meetings = m_meetingList.begin(); it_meetings != m_meetingList.end();)
    {
        Date cmp = Date();
        if(it_meetings->getSponsor() == "" || it_meetings->getParticipator().size() == 0 
            || it_meetings->getTitle() == "" || it_meetings->getStartDate() == cmp ||it_meetings->getEndDate() == cmp)
        {
            it_meetings++;
            continue;
        }
        else {
            fout << "\"" << it_meetings->getSponsor() << "\",\"";

            auto paticipator = it_meetings->getParticipator();
            for (unsigned i = 0; i < paticipator.size(); ++i)
            {
                fout << paticipator[i];
                if(i != paticipator.size() - 1)
                    fout << "&";
            }

            fout <<"\",\"" << Date::dateToString(it_meetings->getStartDate())
                <<"\",\"" << Date::dateToString(it_meetings->getEndDate())
                 <<"\",\"" << it_meetings->getTitle()
                 <<"\"";
            if (++it_meetings != m_meetingList.end()) fout << endl;
        }
    }
    fout.close();
    m_dirty = 0;
    return true;
}

std::shared_ptr<Storage> Storage::getInstance(void)
{
    if (m_instance == nullptr)
        m_instance = shared_ptr<Storage> (new Storage());
    return m_instance;
}

Storage::~Storage() { m_instance = nullptr; }

void Storage::createUser(const User &t_user)
{
    m_userList.push_back(t_user);
    m_dirty = true;
}

std::list<User> Storage::queryUser(std::function<bool(const User & in)> filter) const
{
    std::list<User> toReturn;

    auto it_user = m_userList.begin();
    
    while (it_user != m_userList.end())
    {
        if(filter(*it_user))
            toReturn.push_back(*it_user);
        it_user++;
    }
    return toReturn;
}

int Storage::updateUser(std::function<bool(const User &)> filter,
                 std::function<void(User &)> switcher)
{
    int counter = 0;
    list<User>::iterator it_user = m_userList.begin();

    while (it_user != m_userList.end())
    {
        if(filter(*it_user))
        {
            counter++;
            switcher(*it_user);
            m_dirty = true;
        }
        it_user++;
    }
    return counter;
}

int Storage::deleteUser(std::function<bool(const User &)> filter)
{
    int counter = 0;
    auto it_user = m_userList.begin();

    while ( it_user != m_userList.end())
    {
        if(filter(*it_user))
        {
            counter++;
            it_user = m_userList.erase(it_user);
            m_dirty = true;
        }
        else it_user++;
    }
    return counter;
}

void Storage::createMeeting(const Meeting &t_meeting)
{
    m_meetingList.push_back(t_meeting);
    m_dirty = true;
}

std::list<Meeting> Storage::queryMeeting( std::function<bool(const Meeting &)> filter ) const
{
    list<Meeting> toReturn;

    for (auto it_meetings = m_meetingList.begin(); it_meetings != m_meetingList.end();)
    {
        if(filter(*it_meetings))
            toReturn.push_back(*it_meetings);
        it_meetings++;
    }

    return toReturn;
}

int Storage::updateMeeting(std::function<bool(const Meeting &)> filter,
                    std::function<void(Meeting &)> switcher)
{
    int counter = 0;
    list<Meeting>::iterator it_meetings = m_meetingList.begin();
    
    while (it_meetings != m_meetingList.end())
    {
        if(filter(*it_meetings))
        {
            counter++;
            switcher(*it_meetings);
            m_dirty = true;
        }
        it_meetings++;
    }
    return counter;
}

int Storage::deleteMeeting(std::function<bool(const Meeting &)> filter)
{
    int counter = 0;
    auto it_meetings = m_meetingList.begin();

    // int counter = count_if(m_meetingList.begin(), m_meetingList.end(), filter);
    // auto it_ = remove_if(m_meetingList.begin(), m_meetingList.end(), filter);
    // m_meetingList.erase(it_, m_meetingList.end());
    // m_dirty = true;
    while (it_meetings != m_meetingList.end())
    {
        if(filter(*it_meetings))
        {
            counter++;
            it_meetings = m_meetingList.erase(it_meetings);
            m_dirty = true;
        }
        else it_meetings++;
    }
    return counter;
}

bool Storage::sync(void)
{
    if (m_dirty)
        return writeToFile();
    else return true;
}

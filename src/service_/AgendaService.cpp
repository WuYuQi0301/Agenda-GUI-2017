#include "AgendaService.hpp"
#include <list>
#include <string>
#include <set>
#include <QDebug>
#include <iostream>
using namespace std;
AgendaService::AgendaService()
{
	m_storage = nullptr;
	// m_storage = nullptr;
}

AgendaService::~AgendaService()
{
	m_storage = nullptr;
}



bool AgendaService::userLogIn(const std::string &userName, const std::string &password)
{
	std::function<bool(const User &)> filter = [&](const User &other){
		return (userName == other.getName() && password == other.getPassword());
	};
	if (m_storage->queryUser(filter).size() != 0) return true;
	return false;
}

bool AgendaService::userRegister(const std::string &userName, const std::string &password,
                    const std::string &email, const std::string &phone)
{
    if (userName == "" || password == "" || email == "" || phone == "")
        return false;
	std::function<bool(const User &)> filter = [userName](const User &other)
	{
		return (userName == other.getName());
	};
	if (m_storage->queryUser(filter).size() > 0) return false;

	m_storage->createUser(User(userName, password, email, phone));
	m_storage->sync();
	return true;
}

bool AgendaService::deleteUser(const std::string &userName, const std::string &password)
{
 	// filter : search for same username and same passwprd
	auto filter = [&](const User &other)
 	{
		return (userName == other.getName() && password == other.getPassword());
	};

	if (m_storage->deleteUser(filter) > 0)
	{	//filter1 : search for meeting having same sponsor
		auto filter1 = [userName](const Meeting &meeting) {
			return (userName == meeting.getSponsor());
		};
		//filter2 : search for meeting having this participator 
		auto filter2 = [userName](const Meeting &meeting) {
			return meeting.isParticipator(userName);
		};
		//switcher : remove this participator
		auto switcher = [userName](Meeting &meeting) {
			meeting.removeParticipator(userName);
		};
		//filter3 : search for meeting having no participator
		auto filter3 = [](const Meeting &meeting) {
			return meeting.getParticipator().size() == 0;
		};

		m_storage->deleteMeeting(filter1);
		m_storage->updateMeeting(filter2, switcher);
		m_storage->deleteMeeting(filter3);
		m_storage->sync();
		return true;
	}
	return false;
}

std::list<User> AgendaService::listAllUsers(void) const
{
    return m_storage->queryUser([](const User &){return true;});
}

bool AgendaService::createMeeting(const std::string &userName, const std::string &title,
                     const std::string &_startDate, const std::string &_endDate,
                     const std::vector<std::string> &participator)
{
    if(userName == ""  || title == "" || _startDate == "" || _endDate == "" || participator.size() == 0)
    {
        qDebug() << "void" << participator.size();
        return false;
    }
    //if start == end, create fail
	//if date is not vaild, return false
	Date startDate = Date::stringToDate(_startDate);
	Date endDate = Date::stringToDate(_endDate);
	// Date cmp = Date();

	if (_startDate >= _endDate || !Date::isValid(startDate) || !Date::isValid(endDate))
    {
        qDebug() << "Date invaild\n "
                 << QString::fromStdString( _startDate)
                 << " "
                 <<QString::fromStdString( _endDate);
		return false;
    }
	//if title has exist, create fail
	if (m_storage->queryMeeting([title](const Meeting& meeting){
		return (title == meeting.getTitle());
	}).size() > 0)
    {
        qDebug() << "title invaild";
		return false;
    }
		//if sponser is not a user create fail
	if ((m_storage->queryUser([userName](const User &user){
		return userName == user.getName();
	})).size() != 1)
    {
        qDebug() << "sponser not available";
		return false;
}
	//list is void return false
	if (participator.size() == 0)
    {
        qDebug() << "none pa";
		return false;
    }
        //paticipator not include sponsor
	//paticipator not overloaded
	set<string> over_pa;
	for (auto it_ = participator.begin(); it_ != participator.end(); it_++)
	{
		if (userName == *it_)
			return false;
		over_pa.insert(*it_);

	}
	if (over_pa.size() != participator.size())
		return false;

	//if participator is not user,create fail
	for (auto it_ = participator.begin(); it_ != participator.end() ; ++it_)
	{
		string pa = *it_;
		if ((m_storage->queryUser([pa](const User &user){
			return pa == user.getName();
		})).size() == 0)
        {
            qDebug() << "pa not available";
			return false;
        }
	}


	//if sponsor time overlarred, create fail
	auto filter = [userName](const Meeting& meeting) {
		return ((userName == meeting.getSponsor()) 
			|| meeting.isParticipator(userName));
	};
	list<Meeting> sponsorMeeting = m_storage->queryMeeting(filter);
	for (auto it_begin = sponsorMeeting.begin(); it_begin != sponsorMeeting.end();it_begin++)
	{
		if ( !((endDate <= it_begin->getStartDate()) 
			|| (startDate >= it_begin->getEndDate()) ) )
			return false;
	}

	//if paticipator time overlarred, create fail
	for (unsigned int i = 0; i < participator.size(); ++i)
	{
		string _pa = participator[i];
		auto filter2 = [startDate, endDate, _pa](const Meeting& meeting) {
			return (((_pa == meeting.getSponsor()) || meeting.isParticipator(_pa))
					&& !((endDate <= meeting.getStartDate()) || (startDate >= meeting.getEndDate()) ));
		};
		// list<Meeting> participatorMeeting = 
		if (m_storage->queryMeeting(filter2).size() > 0)
			return false;
	}

	m_storage->createMeeting(Meeting(userName, participator, startDate, endDate, title));
	m_storage->sync();
	return true;
}

  /**
   * add a participator to a meeting
   * @param userName the sponsor's userName
   * @param title the meeting's title
   * @param participator the meeting's participator
   * @return if success, true will be returned
   */
bool AgendaService::addMeetingParticipator(const std::string &userName,
                              const std::string &title,
                              const std::string &participator)
{
	
	//if participator is not user,create fai;
		if ((m_storage->queryUser([participator](const User &user){
			return participator == user.getName();
		})).size() == 0) 
			return false;
	//if sponsor is not user,create fai;
		if ((m_storage->queryUser([userName](const User &user){
			return userName == user.getName();
		})).size() == 0) 
			return false;

	//query meeting having same sponsor and title
	auto filter = [userName, title, participator](const Meeting& meeting){
		return (userName == meeting.getSponsor() 
				&& title == meeting.getTitle()
				&& !meeting.isParticipator(participator));
	//already is the paticipator?
	};
	list<Meeting> sponsorMeeting = m_storage->queryMeeting(filter);
	if (sponsorMeeting.size() == 0) return false;
	

	//query meeting for that participator has taken part in
	auto filter2 = [participator](const Meeting& meeting) {
	return (( participator == meeting.getSponsor()) 
			|| meeting.isParticipator(participator));
	};
	list<Meeting> participatorMeeting = m_storage->queryMeeting(filter2);

	//verify if participator time overlarred
	for (auto it_meeting = participatorMeeting.begin(); 
			it_meeting != participatorMeeting.end() ; it_meeting++)
	{
		if ( !(( sponsorMeeting.begin()->getEndDate() <= it_meeting->getStartDate()) 
			|| (sponsorMeeting.begin()->getStartDate() >= it_meeting->getEndDate()) ) )
		return false;
	}

	//if not, update meeting with new participator
	auto filter3 = [title](const Meeting& meeting){
		return title == meeting.getTitle();
	};
	auto switcher = [participator](Meeting& meeting){
		meeting.addParticipator(participator);
	};
	m_storage->updateMeeting(filter3, switcher);
	m_storage->sync();
	return true;
}	

  /**
   * remove a participator from a meeting
   * @param userName the sponsor's userName
   * @param title the meeting's title
   * @param participator the meeting's participator
   * @return if success, true will be returned
   */
bool AgendaService::removeMeetingParticipator(const std::string &userName,
                                 const std::string &title,
                                 const std::string &participator)
{
		//if sponsor is not user,create fai;
		if ((m_storage->queryUser([userName](const User &user){
			return userName == user.getName();
		})).size() == 0) 
			return false;
	//query meeting having same sponsor and title, and with the participator
	auto filter = [userName, title, participator](const Meeting& meeting)
	{
		return (userName == meeting.getSponsor() 
				&& title == meeting.getTitle() 
				&& meeting.isParticipator(participator));
	};
	//if yes remove it
	auto switcher = [participator](Meeting& meeting) {
		meeting.removeParticipator(participator);
	};
	//if meeting's paticipator none , remove it
	if (m_storage->updateMeeting(filter, switcher) != 0 )
	{
		auto filter1 = [](const Meeting &meeting) 
		{ 
			return meeting.getParticipator().size() == 0; 
		};
		m_storage->deleteMeeting(filter1);
		m_storage->sync();
		return true;
	}
	return false;
}

  /**
   * quit from a meeting
   * @param userName the current userName. no need to be the sponsor
   * @param title the meeting's title
   * @return if success, true will be returned
   */
bool AgendaService::quitMeeting(const std::string &userName, const std::string &title)
{
	auto filter = [userName, title](const Meeting & meeting){
		return (title == meeting.getTitle() 
				&& meeting.isParticipator(userName) 
				&& userName != meeting.getSponsor());
	};
	auto switcher = [userName](Meeting &meeting){
		meeting.removeParticipator(userName);
	};

	if (m_storage->updateMeeting(filter ,switcher) > 0)
	{
		m_storage->deleteMeeting([](const Meeting &meeting){
			return meeting.getParticipator().size() == 0;
		});
		m_storage->sync();
		return true;
	}
	return false;
}

  /**
   * search a meeting by username and title
   * @param uesrName the sponsor's userName
   * @param title the meeting's title
   * @return a meeting list result
   */
std::list<Meeting> AgendaService::meetingQuery(const std::string &userName,
                                  const std::string &title) const
{
	return m_storage->queryMeeting([&](const Meeting &meeting){
		return ((userName == meeting.getSponsor() || meeting.isParticipator(userName)) 
					&& title == meeting.getTitle());
	});
}

std::list<Meeting> AgendaService::meetingQuery(const std::string &userName,
                                  const std::string &_startDate,
                                  const std::string &_endDate) const
{
	Date startDate = Date::stringToDate(_startDate);
	Date endDate = Date::stringToDate(_endDate);
	
	//if date is not vaild, return void list
	if (!Date::isValid(startDate) || !Date::isValid(endDate) || startDate > endDate)
	{
		list<Meeting> none;
		return none;
	}
	//query meeting even if time point is overlarred
	return m_storage->queryMeeting([userName, startDate, endDate](const Meeting &meeting){
		return ((userName == meeting.getSponsor() || meeting.isParticipator(userName) )
				&& !( endDate < meeting.getStartDate() || meeting.getEndDate() < startDate));
	});
}


std::list<Meeting> AgendaService::listAllMeetings(const std::string &userName) const
{
	return (m_storage->queryMeeting([userName](const Meeting &meeting){
		return ((userName == meeting.getSponsor()) || (meeting.isParticipator(userName)));
	}));
}

  /**
   * list all meetings the user sponsor
   * @param userName user's username
   * @return a meeting list result
   */
std::list<Meeting> AgendaService::listAllSponsorMeetings(const std::string &userName) const
{
	return m_storage->queryMeeting([userName](const Meeting &meeting){
		return (userName == meeting.getSponsor() && !meeting.isParticipator(userName));
	});
}

  /**
   * list all meetings the user take part in and sponsor by other
   * @param userName user's username
   * @return a meeting list result
   */
std::list<Meeting> AgendaService::listAllParticipateMeetings(const std::string &userName) const
{
	return m_storage->queryMeeting([userName](const Meeting &meeting){
		return (meeting.isParticipator(userName) && userName != meeting.getSponsor());
	});
}

  /**
   * delete a meeting by title and its sponsor
   * @param userName sponsor's username
   * @param title meeting's title
   * @return if success, true will be returned
   */
bool AgendaService::deleteMeeting(const std::string &userName, const std::string &title)
{
	int i = m_storage->deleteMeeting([userName, title](const Meeting &meeting){
		return (userName == meeting.getSponsor() && title == meeting.getTitle());
	}) != 0;
	m_storage->sync();
	return i > 0;
}

  /**
   * delete all meetings by sponsor
   * @param userName sponsor's username
   * @return if success, true will be returned
   */
bool AgendaService::deleteAllMeetings(const std::string &userName)
{
	int i = m_storage->deleteMeeting([userName](const Meeting &meeting){
		return userName == meeting.getSponsor();
	}) != 0;
	m_storage->sync();
	return i > 0;
}

  /**
   * start Agenda service and connect to storage
   */
void AgendaService::startAgenda(void)
{
 	m_storage = Storage::getInstance();
}

  /**
   * quit Agenda service
   */
void AgendaService::quitAgenda(void)
{

	if (m_storage != nullptr) m_storage->sync();
	m_storage = nullptr;
}

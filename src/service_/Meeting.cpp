#include "Meeting.hpp"

#include <algorithm>
using namespace std;

Meeting::Meeting(const std::string &t_sponsor,
          const std::vector<std::string> &t_participator,
          const Date &t_startTime, const Date &t_endTime,
          const std::string &t_title)
{
    m_sponsor = t_sponsor;
    m_startDate = t_startTime;
    m_endDate = t_endTime;
    m_title = t_title;
    m_participators = t_participator;
}

Meeting::Meeting(const Meeting &t_meeting)
{
    m_sponsor = t_meeting.m_sponsor;
    m_startDate = t_meeting.m_startDate;
    m_endDate = t_meeting.m_endDate;
    m_title = t_meeting.m_title;

    m_participators = t_meeting.m_participators;
}


std::string Meeting::getSponsor(void) const { return m_sponsor; }

void Meeting::setSponsor(const std::string &t_sponsor) { m_sponsor = t_sponsor; }

  /**
  * @brief  get the participators of a meeting
  */
std::vector<std::string> Meeting::getParticipator(void) const { return m_participators; }

  /**
  *   @brief set the new participators of a meeting
  */
void Meeting::setParticipator(const std::vector<std::string> &t_participators) { m_participators = t_participators; }

  /**
  * @brief add a new participator to the meeting
  */
void Meeting::addParticipator(const std::string &t_participator)
{
    m_participators.push_back(t_participator);
}

  /**
  * @brief remove a participator of the meeting
  */
void Meeting::removeParticipator(const std::string &t_participator)
{
    std::vector<std::string>::iterator it = find(m_participators.begin(), m_participators.end(), t_participator);
    if (it != m_participators.end())
      m_participators.erase(it);    
}

  /**
  * @brief get the startDate of a meeting
  */  
Date Meeting::getStartDate(void) const { return m_startDate; }

  /**
  * @brief  set the startDate of a meeting
  */
void Meeting::setStartDate(const Date &t_startTime) { m_startDate = t_startTime; }

  /**
  * @brief get the endDate of a meeting
  */
Date Meeting::getEndDate(void) const { return m_endDate; }

  /**
  * @brief  set the endDate of a meeting
  */
void Meeting::setEndDate(const Date &t_endTime) { m_endDate = t_endTime; }

  /**
  * @brief get the title of a meeting
  */
std::string Meeting::getTitle(void) const { return m_title; }

  /**
  * @brief  set the title of a meeting
  */
void Meeting::setTitle(const std::string &t_title) { m_title = t_title; }

  /**
  * @brief check if the user take part in this meeting
  * @param t_username the source username
  * @return if the user take part in this meeting
  */
bool Meeting::isParticipator(const std::string &t_username) const
{
    return (find(m_participators.begin(), m_participators.end(), t_username) != m_participators.end());
}

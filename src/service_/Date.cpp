#include "Date.hpp"
#include <sstream>
#include <iomanip>
using namespace std;

Date::Date() : m_year(0), m_month(0), m_day(0), m_hour(0), m_minute(0) { }

Date::Date(int t_year, int t_month, int t_day, int t_hour, int t_minute)
{
  	m_year = t_year;
  	m_month = t_month;
  	m_day = t_day;
  	m_hour = t_hour;
  	m_minute = t_minute;
}

Date::Date(const std::string &dateString)
{
	if  ( (dateString.size() != 16) || (dateString[4] != '-') || (dateString[7] != '-') 
		|| (dateString[10] != '/') || (dateString[13] != ':')
		|| !isdigit(dateString[0]) || !isdigit(dateString[1]) 
		|| !isdigit(dateString[2]) || !isdigit(dateString[3]) 
		|| !isdigit(dateString[5]) || !isdigit(dateString[6]) 
		|| !isdigit(dateString[8]) || !isdigit(dateString[9]) 
		|| !isdigit(dateString[11]) || !isdigit(dateString[12])
		|| !isdigit(dateString[14]) || !isdigit(dateString[15])  )
	{
		m_year = 0;
		m_minute = 0;
		m_hour = 0;
		m_day = 0;
		m_month = 0;
	}
	else {
  		std::stringstream toDate;
  		char ch;

  		toDate << dateString;
  		toDate >> m_year >> ch 
  			>> m_month >> ch 
  			>> m_day >> ch 
  			>> m_hour >> ch 
  			>> m_minute; 
  	}
}

int Date::getYear(void) const { return m_year; }

void Date::setYear(const int t_year) { m_year = t_year; }

int Date::getMonth(void) const { return m_month; }

void Date::setMonth(const int t_month) { m_month = t_month; }

int Date::getDay(void) const { return m_day; }

void Date::setDay(const int t_day) { m_day = t_day; }

int Date::getHour(void) const { return m_hour; }

void Date::setHour(const int t_hour) { m_hour = t_hour; }

int Date::getMinute(void) const { return m_minute; }

void Date::setMinute(const int t_minute) { m_minute = t_minute; }

//static
bool Date::isValid(const Date &t_date)
{
	if (t_date.getYear() < 1000 || t_date.getYear() > 9999)
		return false;
	if (t_date.getMonth() < 1 || t_date.getMonth() > 12)
		return false;
	switch(t_date.getMonth())
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (t_date.getDay() < 1 || t_date.getDay() > 31)
				return false;
			break;

		case 4: case 6: case 9: case 11:
			if (t_date.getDay() < 1 || t_date.getDay() > 30)
				return false;
			break;

		default: 
			if ( (t_date.getYear() % 400 == 0) || ( (t_date.getYear() % 4 == 0) && (t_date.getYear() % 100 != 0)) )
			{
				if (t_date.getDay() < 1 || t_date.getDay() > 29)
					return false;
			}
			else
			{
				if (t_date.getDay() < 1 || t_date.getDay() > 28)
					return false;
			}
	}

	if (t_date.getHour() < 0 || t_date.getHour() > 23)
		return false;

	if (t_date.getMinute() < 0 || t_date.getMinute() > 59)
		return false;

	return true;
}

//static 
Date Date::stringToDate(const std::string &t_dateString)
{
	if((t_dateString.size() != 16) || (t_dateString[4] != '-') || (t_dateString[7] != '-') 
		|| (t_dateString[10] != '/') || (t_dateString[13] != ':')
		|| !isdigit(t_dateString[0]) || !isdigit(t_dateString[1]) 
		|| !isdigit(t_dateString[2]) || !isdigit(t_dateString[3]) 
		|| !isdigit(t_dateString[5]) || !isdigit(t_dateString[6]) 
		|| !isdigit(t_dateString[8]) || !isdigit(t_dateString[9]) 
		|| !isdigit(t_dateString[11]) || !isdigit(t_dateString[12])
		|| !isdigit(t_dateString[14]) || !isdigit(t_dateString[15])  )
		return Date();
	
	return Date(t_dateString);
}

//static 
std::string Date::dateToString(const Date &t_date)
{
	if (!isValid(t_date))
		return "0000-00-00/00:00";

	std::stringstream toString;
	toString.fill('0');
	toString << setw(4) << t_date.getYear() << "-"
			<< setw(2) << t_date.getMonth() << "-"
			<< setw(2) << t_date.getDay() << "/"
			<< setw(2) << t_date.getHour() << ":"
			<< setw(2) << t_date.getMinute();
	return toString.str();
}

Date &Date::operator=(const Date &t_date)
{
	m_year = t_date.m_year;
	m_month = t_date.m_month;
	m_day = t_date.m_day;
	m_hour = t_date.m_hour;
	m_minute = t_date.m_minute;
	return *this;
}

bool Date::operator==(const Date &t_date) const
{
	return (m_year == t_date.m_year && m_month == t_date.m_month 
			&& m_day == t_date.m_day && m_hour == t_date.m_hour
			&& m_minute == t_date.m_minute);
}

bool Date::operator>(const Date &t_date) const
{
	if (m_year < t_date.m_year)
		return false;
	else if (m_year == t_date.m_year)
	{
		if (m_month < t_date.m_month)
			return false;
		else if (m_month == t_date.m_month)
		{
			if (m_day < t_date.m_day)
				return false;
			else if (m_day == t_date.m_day)
			{
				if (m_hour < t_date.m_hour)
					return false;
				else if(m_hour == t_date.m_hour)
				{
					if(m_minute <= t_date.m_minute)
						return false;
				}
			}
		}
	}
	return true;
}

bool Date::operator<(const Date &t_date) const
{
	return !( ( *this > t_date) || ( *this == t_date) );
}

bool Date::operator>=(const Date &t_date) const
{
	return ((*this) == t_date || (*this) > t_date);
}

bool Date::operator<=(const Date &t_date) const
{
	return !( (*this) > t_date );
}

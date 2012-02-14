/* Maciej Poleski (C) 2012 */

#ifndef CALENDAR_HXX
#define CALENDAR_HXX

#include <vector>
#include <memory>
#include <utility>

#include <boost/date_time/gregorian/gregorian_types.hpp>

#include "Schedule.hxx"

class Calendar
{
public:
    Calendar();

private:
    std::vector<std::pair<Schedule,boost::gregorian::date_period>> schedules_;
};

#endif // CALENDAR_HXX

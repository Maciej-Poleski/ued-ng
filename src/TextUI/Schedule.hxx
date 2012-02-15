/* Maciej Poleski (C) 2012 */

#ifndef TEXTUI_SCHEDULE_HXX
#define TEXTUI_SCHEDULE_HXX

#include <boost/shared_ptr.hpp>

namespace Core
{
class Schedule;
}

namespace TextUI {

class Schedule
{
public:
    explicit Schedule();
    explicit Schedule(boost::shared_ptr<Core::Schedule> schedule);

    void userTime();
    void createNew();

    boost::shared_ptr<Core::Schedule> schedule() const;

private:
    boost::shared_ptr<Core::Schedule> _schedule;
};

inline boost::shared_ptr< Core::Schedule > Schedule::schedule() const
{
    return _schedule;
}

}

#endif // TEXTUI_SCHEDULE_HXX

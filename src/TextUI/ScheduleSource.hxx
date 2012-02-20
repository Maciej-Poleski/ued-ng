/* Maciej Poleski (C) 2012 */

#ifndef TEXTUI_SCHEDULESOURCE_HXX
#define TEXTUI_SCHEDULESOURCE_HXX

#include <boost/shared_ptr.hpp>

namespace Core
{
class ScheduleSource;
}

namespace TextUI {

class ScheduleSource
{
public:
    explicit ScheduleSource();
    explicit ScheduleSource(boost::shared_ptr<Core::ScheduleSource> scheduleSource);

    const boost::shared_ptr<Core::ScheduleSource> scheduleSource() const;

    void createNew();
    void userTime();

    void printSubjectsSources();
    void printSchedules();
    void addNewSchedule();
    void addNewSubjectSource();
    void removeSubjectSource();
    void removeSchedule();

private:
    boost::shared_ptr<Core::ScheduleSource> _scheduleSource;
};

inline const boost::shared_ptr< Core::ScheduleSource > ScheduleSource::scheduleSource() const
{
    return _scheduleSource;
}

}

#endif // TEXTUI_SCHEDULESOURCE_HXX

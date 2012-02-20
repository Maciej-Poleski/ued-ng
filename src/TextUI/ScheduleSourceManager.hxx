/* Maciej Poleski (C) 2012 */

#ifndef TEXTUI_SCHEDULESOURCEMANAGER_HXX
#define TEXTUI_SCHEDULESOURCEMANAGER_HXX

#include <boost/shared_ptr.hpp>

namespace Core
{
class ScheduleSourceManager;
}

namespace TextUI {

class ScheduleSourceManager
{
public:
    explicit ScheduleSourceManager();
    explicit ScheduleSourceManager(
        boost::shared_ptr<Core::ScheduleSourceManager> scheduleSourceManager
    );

    void printSchedulesSources();
    void addNewScheduleSource();
    void removeScheduleSource();

    void userTime();
private:
    boost::shared_ptr<Core::ScheduleSourceManager> _scheduleSourceManager;
};

}

#endif // TEXTUI_SCHEDULESOURCEMANAGER_HXX

/* Maciej Poleski (C) 2012 */

#include "ScheduleSourceManager.hxx"

using namespace Core;

ScheduleSourceManager::ScheduleSourceManager()
{

}

void ScheduleSourceManager::addScheduleSource(
    boost::shared_ptr< ScheduleSource > scheduleSource
)
{
    if(std::find(_schedulesSources.begin(),
                 _schedulesSources.end(),
                 scheduleSource)!=_schedulesSources.end())
        return;
    _schedulesSources.push_back(scheduleSource);
}

void ScheduleSourceManager::removeScheduleSource(
    boost::shared_ptr< ScheduleSource > scheduleSource
)
{
    auto i=std::find(_schedulesSources.begin(),
                     _schedulesSources.end(),
                     scheduleSource);
    if(i==_schedulesSources.end())
        return;
    _schedulesSources.erase(i);
}

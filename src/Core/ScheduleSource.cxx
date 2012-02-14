/* Maciej Poleski (C) 2012 */

#include "ScheduleSource.hxx"

#include "SubjectSource.hxx"
#include "Schedule.hxx"
namespace Core
{

ScheduleSource::ScheduleSource()
{

}

void ScheduleSource::addSubjectSource(boost::shared_ptr< SubjectSource > subjectSource)
{
    if(std::find(_subjectsSources.begin(),
                 _subjectsSources.end(),
                 subjectSource)!=_subjectsSources.end())
        return;
    _subjectsSources.push_back(subjectSource);
    subjectSource->setScheduleSource(shared_from_this());
}

void ScheduleSource::addSchedule(boost::shared_ptr< Schedule > schedule)
{
    if(std::find(_schedules.begin(),_schedules.end(),schedule)!=_schedules.end())
        return;
    _schedules.push_back(schedule);
    schedule->setScheduleSource(shared_from_this());
}

void ScheduleSource::removeSubjectSource(boost::shared_ptr< SubjectSource > subjectSource)
{
    auto i=std::find(_subjectsSources.begin(),
                     _subjectsSources.end(),
                     subjectSource);
    if(i==_subjectsSources.end())
        return;
    _subjectsSources.erase(i);
    subjectSource->setScheduleSource(boost::shared_ptr<ScheduleSource>());
}

void ScheduleSource::removeSchedule(boost::shared_ptr< Schedule > schedule)
{
    auto i=std::find(_schedules.begin(),_schedules.end(),schedule);
    if(i==_schedules.end())
        return;
    _schedules.erase(i);
    schedule->setScheduleSource(boost::shared_ptr<ScheduleSource>());
}

}

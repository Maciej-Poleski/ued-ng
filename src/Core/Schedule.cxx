/* Maciej Poleski (C) 2012 */

#include "Schedule.hxx"

#include "ScheduleSource.hxx"
#include "Subject.hxx"
namespace Core
{

Schedule::Schedule()
{

}

void Schedule::setScheduleSource(boost::shared_ptr< ScheduleSource > scheduleSource)
{
    if(_scheduleSource.lock()==scheduleSource)
        return;
    if(boost::shared_ptr<ScheduleSource> ss=_scheduleSource.lock())
    {
        _scheduleSource.reset();
        ss->removeSchedule(shared_from_this());
    }
    _scheduleSource=scheduleSource;
    if(scheduleSource)
        scheduleSource->addSchedule(shared_from_this());
}

void Schedule::addSubject(boost::shared_ptr< Subject > subject)
{
    if(std::find(_subjects.begin(),_subjects.end(),subject)!=_subjects.end())
        return;
    _subjects.push_back(subject);
    subject->addSchedule(shared_from_this());
}

void Schedule::removeSubject(boost::shared_ptr< Subject > subject)
{
    auto i=std::find(_subjects.begin(),_subjects.end(),subject);
    if(i==_subjects.end())
        return;
    _subjects.erase(i);
    subject->removeSchedule(shared_from_this());
}

}

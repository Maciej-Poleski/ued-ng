/* Maciej Poleski (C) 2012 */

#include "Subject.hxx"

#include "SubjectSource.hxx"
#include "Group.hxx"
#include "Category.hxx"
#include "Schedule.hxx"

Subject::Subject() : _name("unknown")
{

}

Subject::Subject(const std::string& name) : _name(name)
{

}

const std::vector< boost::shared_ptr< Schedule > > Subject::schedules() const
{
    return std::vector<boost::shared_ptr<Schedule>>(
               _schedules.begin(),
               _schedules.end()
           );
}

void Subject::setSource(boost::shared_ptr< SubjectSource > source)
{
    if(_source.lock()==source)
        return;
    if(boost::shared_ptr<SubjectSource> ss=_source.lock())
    {
        _source.reset();
        ss->removeSubject(shared_from_this());
    }
    _source=source;
    if(source)
        source->addSubject(shared_from_this());
}

void Subject::addGroup(boost::shared_ptr< Group > group)
{
    if(std::find(_groups.begin(),_groups.end(),group)!=_groups.end())
        return;
    _groups.push_back(group);
}

void Subject::addCategory(boost::shared_ptr< Category > category)
{
    if(std::find(_categories.begin(),_categories.end(),category)!=_categories.end())
        return;
    _categories.push_back(category);
    category->addSubject(shared_from_this());
}

void Subject::addSchedule(boost::shared_ptr< Schedule > schedule)
{
    if(std::find_if(_schedules.begin(),
                    _schedules.end(),
    [&schedule](const boost::weak_ptr<Schedule> &ptr) {
    return ptr.lock()==schedule;
    })!=_schedules.end())
    return;
    _schedules.push_back(schedule);
    schedule->addSubject(shared_from_this());
}

void Subject::removeGroup(boost::shared_ptr< Group > group)
{
    auto i=std::find(_groups.begin(),_groups.end(),group);
    if(i==_groups.end())
        return;
    _groups.erase(i);
}

void Subject::removeCategory(boost::shared_ptr< Category > category)
{
    auto i=std::find(_categories.begin(),_categories.end(),category);
    if(i==_categories.end())
        return;
    _categories.erase(i);
    category->removeSubject(shared_from_this());
}

void Subject::removeSchedule(boost::shared_ptr< Schedule > schedule)
{
    auto i=std::find_if(_schedules.begin(),
                        _schedules.end(),
    [&schedule](const boost::weak_ptr<Schedule> &ptr) {
        return ptr.lock()==schedule;
    });
    if(i==_schedules.end())
        return;
    _schedules.erase(i);
    schedule->removeSubject(shared_from_this());
}

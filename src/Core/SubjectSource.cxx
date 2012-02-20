/* Maciej Poleski (C) 2012 */

#include "SubjectSource.hxx"

#include "ScheduleSource.hxx"

#include "Category.hxx"
#include "Subject.hxx"
#include "Group.hxx"
namespace Core
{

SubjectSource::SubjectSource() : _name("unknown")
{

}

SubjectSource::SubjectSource(const std::string& name) : _name(name)
{

}

void SubjectSource::setScheduleSource(boost::shared_ptr< ScheduleSource > scheduleSource)
{
    if(_scheduleSource.lock()==scheduleSource)
        return;
    if(boost::shared_ptr<ScheduleSource> ss=_scheduleSource.lock())
    {
        _scheduleSource.reset();
        ss->removeSubjectSource(shared_from_this());
    }
    _scheduleSource=scheduleSource;
    if(scheduleSource)
        scheduleSource->addSubjectSource(shared_from_this());
}

void SubjectSource::addGroup(boost::shared_ptr< Group > group)
{
    if(std::find(_groups.begin(),_groups.end(),group)!=_groups.end())
        return;
    _groups.push_back(group);
}

void SubjectSource::addCategory(boost::shared_ptr< Category > category)
{
    if(std::find(_categories.begin(),_categories.end(),category)!=_categories.end())
        return;
    _categories.push_back(category);
    category->setSubjectSource(shared_from_this());
}

void SubjectSource::addSubject(boost::shared_ptr< Subject > subject)
{
    if(std::find(_subjects.begin(),_subjects.end(),subject)!=_subjects.end())
        return;
    _subjects.push_back(subject);
    subject->setSource(shared_from_this());
}

void SubjectSource::removeGroup(boost::shared_ptr< Group > group)
{
    auto i=std::find(_groups.begin(),_groups.end(),group);
    if(i==_groups.end())
        return;
    _groups.erase(i);
}

void SubjectSource::removeCategory(boost::shared_ptr< Category > category)
{
    auto i=std::find(_categories.begin(),_categories.end(),category);
    if(i==_categories.end())
        return;
    _categories.erase(i);
    category->setSubjectSource(boost::shared_ptr<SubjectSource>());
}

void SubjectSource::removeSubject(boost::shared_ptr< Subject > subject)
{
    auto i=std::find(_subjects.begin(),_subjects.end(),subject);
    if(i==_subjects.end())
        return;
    _subjects.erase(i);
    subject->setSource(boost::shared_ptr<SubjectSource>());
}

}

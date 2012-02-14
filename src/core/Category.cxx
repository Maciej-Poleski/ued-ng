/* Maciej Poleski (C) 2012 */

#include "Category.hxx"

#include <algorithm>

#include <cassert>

#include "Group.hxx"
#include "Subject.hxx"
#include "SubjectSource.hxx"

Category::Category() : _name("unknown")
{

}

Category::Category(const std::string& categoryName) :
    _name(categoryName)
{

}

const std::vector< boost::shared_ptr< Subject > > Category::subjects() const
{
    return std::vector<boost::shared_ptr<Subject>>(_subjects.begin(),_subjects.end());
}

void Category::setName(const std::string& name)
{
    _name=name;
}

void Category::setSubjectSource(boost::shared_ptr< SubjectSource > subjectSource)
{
    if(_subjectSource.lock()==subjectSource)
        return;
    if(boost::shared_ptr<SubjectSource> ss=_subjectSource.lock())
    {
        _subjectSource.reset();
        ss->removeCategory(shared_from_this());
    }
    _subjectSource=subjectSource;
    if(subjectSource)
        subjectSource->addCategory(shared_from_this());
}

void Category::addSubject(boost::shared_ptr< Subject > subject)
{
    using namespace std;
    if(find_if(_subjects.begin(),
               _subjects.end(),
    [&subject](const boost::weak_ptr<Subject> &ptr) {
    return ptr.lock()==subject;
    })!=_subjects.end())
    return;
    _subjects.push_back(subject);
    subject->addCategory(shared_from_this());
}

void Category::addGroup(boost::shared_ptr< Group > group)
{
    using namespace std;
    if(find(_groups.begin(),_groups.end(),group)!=_groups.end())
        return;
    _groups.push_back(group);
    group->setCategory(shared_from_this());
}

void Category::removeGroup(boost::shared_ptr< Group > group)
{
    using namespace std;
    auto i=find(_groups.begin(),_groups.end(),group);
    if(i==_groups.end())
        return;
    _groups.erase(i);
    group->setCategory(boost::shared_ptr<Category>());
}

void Category::removeSubject(boost::shared_ptr< Subject > subject)
{
    using namespace std;
    auto i=find_if(_subjects.begin(),
                   _subjects.end(),
    [&subject](const boost::weak_ptr<Subject> &ptr) {
        return ptr.lock()==subject;
    });
    if(i==_subjects.end())
        return;
    _subjects.erase(i);
    subject->removeCategory(shared_from_this());
}

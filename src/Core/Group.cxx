/* Maciej Poleski (C) 2012 */

#include "Group.hxx"
#include "Teacher.hxx"
#include "MarkCategory.hxx"
#include "Category.hxx"
namespace Core
{

Group::Group() :
    _period(
        boost::gregorian::date(boost::date_time::not_a_date_time),
        boost::gregorian::date(boost::date_time::not_a_date_time)
    )
{

}

Group::Group(const std::string& name) :
    _period(
        boost::gregorian::date(boost::date_time::not_a_date_time),
        boost::gregorian::date(boost::date_time::not_a_date_time)
    ),
    _name(name)
{

}

void Group::addMarkCategory(boost::shared_ptr< MarkCategory > markCategory)
{
    if(find(_markCategories.begin(),_markCategories.end(),markCategory)!=_markCategories.end())
        return;
    _markCategories.push_back(markCategory);
    markCategory->setGroup(shared_from_this());
}

void Group::setCategory(boost::shared_ptr< Category > category)
{
    if(_category.lock()==category)
        return;
    if(boost::shared_ptr<Category> c=_category.lock())
    {
        _category.reset();
        c->removeGroup(shared_from_this());
    }
    _category=category;
    if(category)
        category->addGroup(shared_from_this());
}

void Group::setTeacher(boost::shared_ptr< Teacher > newTeacher)
{
    if(_teacher==newTeacher)
        return;
    if(_teacher)
    {
        boost::shared_ptr<Teacher> t(_teacher);
        _teacher.reset();
        t->removeGroup(shared_from_this());
    }
    _teacher=newTeacher;
    if(_teacher)
        _teacher->addGroup(shared_from_this());
}

void Group::removeMarkCategory(boost::shared_ptr< MarkCategory > markCategory)
{
    using namespace std;
    auto i=find(_markCategories.begin(),_markCategories.end(),markCategory);
    if(i==_markCategories.end())
        return;
    _markCategories.erase(i);
    markCategory->setGroup(boost::shared_ptr<Group>());
}

void Group::removeTerm(DayOfTheWeek dayOfTheWeek, HoursOfTheDay hoursOfTheDay)
{
    using namespace std;
    auto i=find(_terms.begin(),_terms.end(),make_pair(dayOfTheWeek,hoursOfTheDay));
    if(i!=_terms.end())
        _terms.erase(i);
}
}

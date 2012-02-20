/* Maciej Poleski (C) 2012 */

#include "Teacher.hxx"
#include "Group.hxx"
namespace Core
{

Teacher::Teacher() : _name("unknown")
{

}

Teacher::Teacher(const std::string& name) : _name(name)
{

}

const std::vector<boost::shared_ptr<Group>> Teacher::groups() const
{
    return std::vector<boost::shared_ptr<Group>>(_groups.begin(),_groups.end());
}

void Teacher::addGroup(boost::shared_ptr< Group > group)
{
    if(std::find_if(_groups.begin(),
                    _groups.end(),
    [&group](const boost::weak_ptr<Group> &ptr) {
    return ptr.lock()==group;
    })!=_groups.end())
    return;
    _groups.push_back(group);
    group->setTeacher(shared_from_this());
}

void Teacher::removeGroup(boost::shared_ptr< Group > group)
{
    auto i=std::find_if(_groups.begin(),
                        _groups.end(),
    [&group](const boost::weak_ptr<Group> &ptr) {
        return ptr.lock()==group;
    });
    if(i==_groups.end())
        return;
    _groups.erase(i);
    group->setTeacher(boost::shared_ptr<Teacher>());
}

}

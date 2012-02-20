/* Maciej Poleski (C) 2012 */

#include "MarkCategory.hxx"
#include "Group.hxx"
namespace Core
{

MarkCategory::MarkCategory() : _name("unknown")
{

}

MarkCategory::MarkCategory(const std::string& categoryName) :
    _name(categoryName)
{

}

boost::shared_ptr< Group > MarkCategory::group() const
{
    return _group.lock();
}

const std::string MarkCategory::name() const
{
    return _name;
}

void MarkCategory::setGroup(boost::shared_ptr< Group > group)
{
    if(_group.lock()==group)
        return;
    if(boost::shared_ptr<Group> g=_group.lock())
    {
        _group.reset();
        g->removeMarkCategory(shared_from_this());
    }
    _group=group;
    if(group)
        group->addMarkCategory(shared_from_this());
}

void MarkCategory::setName(const std::string& name)
{
    _name=name;
}

}

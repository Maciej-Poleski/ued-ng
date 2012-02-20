/* Maciej Poleski (C) 2012 */

#include "GroupManager.hxx"

Core::GroupManager::GroupManager()
{

}

void Core::GroupManager::addGroup(boost::shared_ptr< Core::Group > group)
{
    if(std::find(_groups.begin(),_groups.end(),group)!=_groups.end())
        return;
    _groups.push_back(group);
}

void Core::GroupManager::removeGroup(boost::shared_ptr< Core::Group > group)
{
    auto i=std::find(_groups.begin(),_groups.end(),group);
    if(i==_groups.end())
        return;
    _groups.erase(i);
}

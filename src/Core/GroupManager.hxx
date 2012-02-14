/* Maciej Poleski (C) 2012 */

#ifndef GROUPMANAGER_HXX
#define GROUPMANAGER_HXX

#include <vector>

#include <boost/shared_ptr.hpp>

namespace Core
{

class Group;

class GroupManager
{
public:
    explicit GroupManager();

    const std::vector<boost::shared_ptr<Group>> groups() const;

    void addGroup(boost::shared_ptr<Group> group);

    void removeGroup(boost::shared_ptr<Group> group);

private:
    std::vector<boost::shared_ptr<Group>> _groups;
};

inline const std::vector< boost::shared_ptr< Group > > GroupManager::groups() const
{
    return _groups;
}

}

#endif // GROUPMANAGER_HXX

/* Maciej Poleski (C) 2012 */

#ifndef CORE_TEACHERMANAGER_HXX
#define CORE_TEACHERMANAGER_HXX

#include <vector>

#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>

#include "Teacher.hxx"

namespace Core
{

class TeacherManager
{
public:
    explicit TeacherManager();

    const std::vector<boost::shared_ptr<Teacher>> teachers() const;

    void addTeacher(boost::shared_ptr<Teacher> teacher);

    void removeTeacher(boost::shared_ptr<Teacher> teacher);

    template<class Archive>
    void serialize(Archive & ar, const unsigned int /* version */);

private:
    std::vector<boost::shared_ptr<Teacher>> _teachers;
};

inline const std::vector< boost::shared_ptr< Teacher > > TeacherManager::teachers() const
{
    return _teachers;
}

template<class Archive>
void TeacherManager::serialize(Archive& ar, const unsigned int /* version */)
{
    ar & _teachers;
}
}

#endif // CORE_TEACHERMANAGER_HXX

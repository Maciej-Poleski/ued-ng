/* Maciej Poleski (C) 2012 */

#ifndef CATEGORY_HXX
#define CATEGORY_HXX

#include <string>
#include <vector>

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/weak_ptr.hpp>

namespace Core
{

class Group;
class Subject;
class SubjectSource;

/**
 * @brief Przechowywane w puli każdego przedmiotu.
 *
 * Gotowa do testów
 **/
class Category : public boost::enable_shared_from_this<Category>
{
    friend class boost::serialization::access;
public:
    explicit Category();
    explicit Category(const std::string & categoryName);

    const std::string name() const;
    boost::shared_ptr<SubjectSource> subjectSource() const;
    const std::vector<boost::shared_ptr<Subject>> subjects() const;
    const std::vector<boost::shared_ptr<Group>> groups() const;

    void setName(const std::string &name);
    void setSubjectSource(boost::shared_ptr<SubjectSource> subjectSource);

    void addSubject(boost::shared_ptr< Subject > subject);
    void addGroup(boost::shared_ptr<Group> group);

    void removeSubject(boost::shared_ptr<Subject> subject);
    void removeGroup(boost::shared_ptr<Group> group);

private:
    template<class Archive>
    void serialize(Archive &ar, unsigned int version);

    std::string _name;
    boost::weak_ptr<SubjectSource> _subjectSource;
    std::vector<boost::weak_ptr<Subject>> _subjects;
    std::vector<boost::shared_ptr<Group>> _groups;
};

inline const std::string Category::name() const
{
    return _name;
}

inline boost::shared_ptr<SubjectSource> Category::subjectSource() const
{
    return _subjectSource.lock();
}

inline const std::vector<boost::shared_ptr<Group>> Category::groups() const
{
    return _groups;
}

template<class Archive>
void Category::serialize(Archive& ar, const unsigned int /*version*/)
{
    ar & _name & _subjectSource & _subjects & _groups;
}

}
#endif // CATEGORY_HXX



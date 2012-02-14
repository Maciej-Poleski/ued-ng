/* Maciej Poleski (C) 2012 */

#ifndef TEACHER_HXX
#define TEACHER_HXX

#include <string>
#include <vector>

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

class Group;

/**
 * @brief Nauczyciel
 *
 * Gotowa do testów
 *
 **/
class Teacher : public boost::enable_shared_from_this<Teacher>
{
public:
    explicit Teacher();
    explicit Teacher(const std::string & name);

    void setName(const std::string &name);
    void addGroup(boost::shared_ptr< Group > group);
    void removeGroup(boost::shared_ptr<Group> group);

    const std::string name() const;
    const std::vector<boost::shared_ptr<Group>> groups() const;

private:
    /**
     * @brief Imię i nazwisko
     **/
    std::string _name;
    std::vector<boost::weak_ptr<Group>> _groups;
};

inline const std::string Teacher::name() const
{
    return _name;
}

inline void Teacher::setName(const std::string& name)
{
    _name=name;
}

#endif // TEACHER_HXX

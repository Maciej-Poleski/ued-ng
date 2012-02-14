/* Maciej Poleski (C) 2012 */

#ifndef SUBJECT_HXX
#define SUBJECT_HXX

#include <string>
#include <vector>

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
namespace Core
{

class Schedule;
class SubjectSource;
class Category;
class Group;

/**
 * @brief Poprawne przyporządkowanie grup - kompletny przedmiot
 *
 * Gotowy do testów
 **/
class Subject : public boost::enable_shared_from_this<Subject>
{
public:
    explicit Subject();
    explicit Subject(const std::string & name);

    const std::string name() const;
    const std::vector<boost::shared_ptr<Group>> groups() const;
    const std::vector<boost::shared_ptr<Category>> categories() const;
    const boost::shared_ptr<SubjectSource> source() const;
    const std::vector<boost::shared_ptr<Schedule>> schedules() const;

    void setName(const std::string &name);
    void setSource(boost::shared_ptr<SubjectSource> source);

    void addGroup(boost::shared_ptr<Group> group);
    void addCategory(boost::shared_ptr< Category > category);
    void addSchedule(boost::shared_ptr<Schedule> schedule);

    void removeGroup(boost::shared_ptr<Group> group);
    void removeCategory(boost::shared_ptr< Category > category);
    void removeSchedule(boost::shared_ptr<Schedule> schedule);

private:
    std::string _name;
    std::vector<boost::shared_ptr<Group>> _groups;
    std::vector<boost::shared_ptr<Category>> _categories;
    boost::weak_ptr<SubjectSource> _source;
    std::vector<boost::weak_ptr<Schedule>> _schedules;
};

inline const std::string Subject::name() const
{
    return _name;
}

inline const std::vector< boost::shared_ptr< Group > > Subject::groups() const
{
    return _groups;
}

inline const std::vector< boost::shared_ptr< Category > > Subject::categories() const
{
    return _categories;
}

inline const boost::shared_ptr< SubjectSource > Subject::source() const
{
    return _source.lock();
}

inline void Subject::setName(const std::string& name)
{
    _name=name;
}

}

#endif // SUBJECT_HXX

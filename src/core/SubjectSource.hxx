/* Maciej Poleski (C) 2012 */

#ifndef SUBJECTSOURCE_HXX
#define SUBJECTSOURCE_HXX

#include <vector>
#include <string>

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

class ScheduleSource;
class Subject;
class Group;
class Category;

/**
 * @brief Potrzebny jest manager który trzymałby korzenie drzew shared_ptr
 **/
class SubjectSource : public boost::enable_shared_from_this<SubjectSource>
{
public:
    explicit SubjectSource();
    explicit SubjectSource(const std::string &name);

    const std::string name() const;
    const boost::shared_ptr<ScheduleSource> scheduleSource() const;
    const std::vector<boost::shared_ptr<Group>> groups() const;
    const std::vector<boost::shared_ptr<Category>> categories() const;
    const std::vector<boost::shared_ptr<Subject>> childSubjects() const;

    void setName(const std::string &name);
    void setScheduleSource(boost::shared_ptr<ScheduleSource> scheduleSource);

    void addGroup(boost::shared_ptr<Group> group);
    void addCategory(boost::shared_ptr< Category > category);
    void addSubject(boost::shared_ptr< Subject > subject);

    void removeGroup(boost::shared_ptr<Group> group);
    void removeCategory(boost::shared_ptr< Category > category);
    void removeSubject(boost::shared_ptr< Subject > subject);

private:
    std::string _name;
    std::vector<boost::shared_ptr<Group>> _groups;
    std::vector<boost::shared_ptr<Category>> _categories;
    std::vector<boost::shared_ptr<Subject>> _subjects;
    boost::weak_ptr<ScheduleSource> _scheduleSource;
};

inline const std::string SubjectSource::name() const
{
    return _name;
}

inline const boost::shared_ptr< ScheduleSource > SubjectSource::scheduleSource() const
{
    return _scheduleSource.lock();
}

inline const std::vector< boost::shared_ptr< Group > > SubjectSource::groups() const
{
    return _groups;
}

inline const std::vector< boost::shared_ptr< Category > > SubjectSource::categories() const
{
    return _categories;
}

inline const std::vector< boost::shared_ptr< Subject > > SubjectSource::childSubjects() const
{
    return _subjects;
}

inline void SubjectSource::setName(const std::string& name)
{
    _name=name;
}


#endif // SUBJECTSOURCE_HXX

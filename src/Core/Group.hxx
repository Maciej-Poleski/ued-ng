/* Maciej Poleski (C) 2012 */

#ifndef GROUP_HXX
#define GROUP_HXX

#include <utility>
#include <vector>
#include <string>

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/gregorian/greg_serialize.hpp>

#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/weak_ptr.hpp>
#include <boost/serialization/utility.hpp>

#include "DayOfTheWeek.hxx"
#include "HoursOfTheDay.hxx"
namespace Core
{

class Subject;
class SubjectSource;
class MarkCategory;
class Teacher;
class Category;

/**
 * @brief Pojedyńcza grupa zajęciowa. Np. WdM Ćwiczenia gr.1
 *
 * Gotowa do testów
 **/
class Group : public boost::enable_shared_from_this<Group>
{
    friend class boost::serialization::access;
public:
    explicit Group();
    explicit Group(const std::string &name);

    const std::string name() const;
    boost::shared_ptr<Teacher> teacher() const;
    boost::shared_ptr<Category> category() const;
    const std::vector<std::pair<DayOfTheWeek,HoursOfTheDay>> terms() const;
    const std::vector<boost::shared_ptr<MarkCategory>> markCategories() const;
    const boost::gregorian::date_period period() const;

    void setTeacher(boost::shared_ptr< Teacher > newTeacher);
    void setName(const std::string & name);
    void setCategory(boost::shared_ptr< Category > category);
    void setPeriod(const boost::gregorian::date_period & period);

    void addMarkCategory(boost::shared_ptr< MarkCategory > markCategory);
    void addTerm(DayOfTheWeek DayOfTheWeek, HoursOfTheDay HoursOfTheDay);
    void removeMarkCategory(boost::shared_ptr< MarkCategory > markCategory);
    void removeTerm(DayOfTheWeek DayOfTheWeek, HoursOfTheDay HoursOfTheDay);

private:
    template<class Archive>
    void load(Archive &ar, unsigned int version);
    template<class Archive>
    void save(Archive &ar, unsigned int version) const;

    BOOST_SERIALIZATION_SPLIT_MEMBER()

    std::string _name;
    boost::shared_ptr<Teacher> _teacher;
    boost::weak_ptr<Category> _category;
    std::vector<std::pair<DayOfTheWeek,HoursOfTheDay>> _terms;
    std::vector<boost::shared_ptr<MarkCategory>> _markCategories;
    boost::gregorian::date_period _period;
};

inline const std::vector< std::pair< DayOfTheWeek, HoursOfTheDay > > Group::terms() const
{
    return _terms;
}

inline boost::shared_ptr< Category > Group::category() const
{
    return _category.lock();
}

inline const std::vector< boost::shared_ptr< MarkCategory > > Group::markCategories() const
{
    return _markCategories;
}

inline const std::string Group::name() const
{
    return _name;
}

inline const boost::gregorian::date_period Group::period() const
{
    return _period;
}

inline boost::shared_ptr< Teacher > Group::teacher() const
{
    return _teacher;
}

inline void Group::addTerm(DayOfTheWeek DayOfTheWeek, HoursOfTheDay HoursOfTheDay)
{
    _terms.push_back(std::make_pair(DayOfTheWeek,HoursOfTheDay));
}

inline void Group::setName(const std::string& name)
{
    _name=name;
}

inline void Group::setPeriod(const boost::gregorian::date_period& period)
{
    _period=period;
}

namespace detail
{
    template<class archive_type, class temporal_type>
    void save_to(archive_type& ar, const temporal_type& tt)
    {
        ar << tt;
    }
}

template<class Archive>
void Group::load(Archive& ar, const unsigned int /*version*/)
{
    ar & _name & _teacher & _category & _terms & _markCategories & _period;
}

template<class Archive>
void Group::save(Archive& ar, const unsigned int /*version*/) const
{
    ar & _name & _teacher & _category & _terms & _markCategories;
    detail::save_to(ar,_period);
}

}
#endif // GROUP_HXX


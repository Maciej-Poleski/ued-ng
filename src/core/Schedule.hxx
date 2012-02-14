/* Maciej Poleski (C) 2012 */

#ifndef SCHEDULE_HXX
#define SCHEDULE_HXX

#include <vector>

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

class ScheduleSource;
class Subject;

/**
 * @brief Plan lekcji - zbiór przedmiotów. Gotowy do użycia
 *
 * Gotowy do testów
 **/
class Schedule : public boost::enable_shared_from_this<Schedule>
{
public:
    explicit Schedule();

    const std::vector<boost::shared_ptr<Subject>> subjects() const;
    boost::shared_ptr<ScheduleSource> scheduleSource() const;

    void setScheduleSource(boost::shared_ptr<ScheduleSource> scheduleSource);

    void addSubject(boost::shared_ptr< Subject > subject);

    void removeSubject(boost::shared_ptr< Subject > subject);

private:
    std::vector<boost::shared_ptr<Subject>> _subjects;
    boost::weak_ptr<ScheduleSource> _scheduleSource;
};

inline const std::vector< boost::shared_ptr< Subject > > Schedule::subjects() const
{
    return _subjects;
}

inline boost::shared_ptr< ScheduleSource > Schedule::scheduleSource() const
{
    return _scheduleSource.lock();
}

#endif // SCHEDULE_HXX

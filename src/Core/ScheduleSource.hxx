/* Maciej Poleski (C) 2012 */

#ifndef SCHEDULESOURCE_HXX
#define SCHEDULESOURCE_HXX

#include <vector>

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/access.hpp>

namespace Core
{

    class SubjectSource;
    class Schedule;

/**
 * @brief Żródło planu lekcji - zbiór źródeł przedmiotów
 *
 * Gotowe do testów
 **/
class ScheduleSource : public boost::enable_shared_from_this<ScheduleSource>
{
    friend class boost::serialization::access;
public:
    explicit ScheduleSource();

    const std::vector<boost::shared_ptr<SubjectSource>> subjectsSources() const;
    const std::vector<boost::shared_ptr<Schedule>> schedules() const;

    void addSubjectSource(boost::shared_ptr< SubjectSource > subjectSource);
    void addSchedule(boost::shared_ptr< Schedule > schedule);

    void removeSubjectSource(boost::shared_ptr< SubjectSource > subjectSource);
    void removeSchedule(boost::shared_ptr< Schedule > schedule);

private:
    template<class Archive>
    void serialize(Archive &ar, unsigned int version);

    std::vector<boost::shared_ptr<SubjectSource>> _subjectsSources;
    std::vector<boost::shared_ptr<Schedule>> _schedules;
};

inline const std::vector< boost::shared_ptr< SubjectSource > > ScheduleSource::subjectsSources() const
{
    return _subjectsSources;
}

inline const std::vector< boost::shared_ptr< Schedule > > ScheduleSource::schedules() const
{
    return _schedules;
}

template<class Archive>
void ScheduleSource::serialize(Archive& ar, unsigned int version)
{
    ar & _subjectsSources & _schedules;
}


}

#endif // SCHEDULESOURCE_HXX

/* Maciej Poleski (C) 2012 */

#ifndef CORE_SCHEDULESOURCEMANAGER_HXX
#define CORE_SCHEDULESOURCEMANAGER_HXX

#include <boost/serialization/access.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>

namespace Core {

class ScheduleSource;

class ScheduleSourceManager
{
    friend class boost::serialization::access;
public:
    explicit ScheduleSourceManager();

    const std::vector<boost::shared_ptr<ScheduleSource>> schedulesSources() const;

    void addScheduleSource(boost::shared_ptr<ScheduleSource> scheduleSource);

    void removeScheduleSource(boost::shared_ptr<ScheduleSource> scheduleSource);
private:
    template<class Archive>
    void serialize(Archive &ar, unsigned int version);

    std::vector<boost::shared_ptr<ScheduleSource>> _schedulesSources;
};

inline const std::vector< boost::shared_ptr< ScheduleSource > >
ScheduleSourceManager::schedulesSources() const
{
    return _schedulesSources;
}

template<class Archive>
void ScheduleSourceManager::serialize(Archive& ar, unsigned int version)
{
    ar & _schedulesSources;
}

}

#endif // CORE_SCHEDULESOURCEMANAGER_HXX

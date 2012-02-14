/* Maciej Poleski (C) 2012 */

#ifndef REPORT_HXX
#define REPORT_HXX

#include <vector>
#include <string>
#include <memory>

#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/date_time/gregorian/gregorian_types.hpp>

#include "HoursOfTheDay.hxx"
#include "Present.hxx"
#include "Revoke.hxx"
#include "Additional.hxx"
#include "Teacher.hxx"
namespace Core
{

class MarkPart;
class Group;

class Report
{
public:
    Report();

private:
    boost::posix_time::ptime reportCreationTime_;
    std::weak_ptr<Report> previousVersion_;
    boost::gregorian::date date_;
    HoursOfTheDay hours_;
    Present present_;
    Present teacherPresent_;
    std::string comment_;
    Revoke revoked_;
    Additional additional_;

    // Tylko gdy dodatkowa:
    Teacher teacher_;
    std::string additionalComment_;
    std::weak_ptr<Group> group_;

    std::vector<std::shared_ptr<MarkPart>> marks_;
};

}

#endif // REPORT_HXX

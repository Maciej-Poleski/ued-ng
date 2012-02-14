/* Maciej Poleski (C) 2012 */

#ifndef REPORTMANAGER_HXX
#define REPORTMANAGER_HXX

#include <vector>
#include <memory>

class Report;

class ReportManager
{
public:
    ReportManager();

private:
    std::vector<std::shared_ptr<Report>> reports_;
};

#endif // REPORTMANAGER_HXX

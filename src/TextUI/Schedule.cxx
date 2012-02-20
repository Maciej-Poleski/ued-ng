/* Maciej Poleski (C) 2012 */

#include "Schedule.hxx"

using namespace TextUI;

Schedule::Schedule()
{

}

Schedule::Schedule(boost::shared_ptr< Core::Schedule > schedule)
    : _schedule(schedule)
{

}

void Schedule::createNew()
{
    std::cout<<"Niezaimplementowane\n";
}

void Schedule::userTime()
{
    std::cout<<"Niezaimplementowane\n";
}

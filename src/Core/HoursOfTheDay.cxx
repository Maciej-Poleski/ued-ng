/* Maciej Poleski (C) 2012 */

#include "HoursOfTheDay.hxx"

#include <cassert>
namespace Core
{

HoursOfTheDay::HoursOfTheDay() : _from(0), _to(0)
{

}

HoursOfTheDay::HoursOfTheDay(uint8_t from, uint8_t to) : _from(from), _to(to)
{
    assert(from<=to);
    assert(to<=23);
}

}

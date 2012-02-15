/* Maciej Poleski (C) 2012 */

#include "DayOfTheWeek.hxx"

#include <cassert>
#include <stdexcept>
namespace Core
{

DayOfTheWeek::DayOfTheWeek() : _day(0) {}

DayOfTheWeek::DayOfTheWeek(uint8_t day) : _day(day) {
    assert(day<=7);
    assert(day>0);
}

}

/* Maciej Poleski (C) 2012 */

#include "DayOfTheWeek.hxx"

#include <cassert>
#include <stdexcept>
namespace Core
{

DayOfTheWeek::DayOfTheWeek() : day_(0) {}

DayOfTheWeek::DayOfTheWeek(uint8_t day) : day_(day) {
    assert(day<=7);
    assert(day>0);
}

}

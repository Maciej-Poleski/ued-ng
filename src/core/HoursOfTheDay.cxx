/* Maciej Poleski (C) 2012 */

#include "HoursOfTheDay.hxx"

#include <cassert>

HoursOfTheDay::HoursOfTheDay() : from_(0), to_(0)
{

}

HoursOfTheDay::HoursOfTheDay(uint8_t from, uint8_t to) : from_(from), to_(to)
{
    assert(from<=to);
    assert(to<=23);
}

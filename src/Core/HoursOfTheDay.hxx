/* Maciej Poleski (C) 2012 */

#ifndef HOURSOFTHEDAY_HXX
#define HOURSOFTHEDAY_HXX

#include <cstdint>
namespace Core
{

class HoursOfTheDay
{
public:
    explicit HoursOfTheDay();
    explicit HoursOfTheDay(uint8_t from, uint8_t to);

    inline const bool operator==(const HoursOfTheDay &o) const
    {
        return from_==o.from_ && to_==o.to_;
    }

private:
    std::uint8_t from_;
    std::uint8_t to_;
};
}

#endif // HOURSOFTHEDAY_HXX

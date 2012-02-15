/* Maciej Poleski (C) 2012 */

#ifndef HOURSOFTHEDAY_HXX
#define HOURSOFTHEDAY_HXX

#include <cstdint>

#include <boost/serialization/access.hpp>

namespace Core
{

class HoursOfTheDay
{
    friend class boost::serialization::access;
public:
    explicit HoursOfTheDay();
    explicit HoursOfTheDay(uint8_t from, uint8_t to);

    const bool operator==(const HoursOfTheDay &o) const;

private:
    template<class Archive>
    void serialize(Archive &ar, unsigned int version);

    std::uint8_t _from;
    std::uint8_t _to;
};

inline const bool HoursOfTheDay::operator==(const HoursOfTheDay &o) const
{
    return _from==o._from && _to==o._to;
}

template<class Archive>
void HoursOfTheDay::serialize(Archive& ar, const unsigned int /*version*/)
{
    std::uint16_t __from=this->_from;
    std::uint16_t __to=this->_to;
    ar & __from & __to;
    this->_from=__from;
    this->_to=__to;
}

}

#endif // HOURSOFTHEDAY_HXX

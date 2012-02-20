/* Maciej Poleski (C) 2012 */

#ifndef DAYOFTHEWEEK_HXX
#define DAYOFTHEWEEK_HXX

#include <cstdint>

#include <boost/serialization/access.hpp>

namespace Core
{

class DayOfTheWeek
{
    friend class boost::serialization::access;
public:
    explicit DayOfTheWeek();
    explicit DayOfTheWeek(uint8_t day);

    const bool operator==(const DayOfTheWeek & o) const;
private:
    template<class Archive>
    void serialize(Archive &ar, unsigned int version);

    /**
     * @brief 0 - niezainicjalizowane, 1 - poniedziałek
     **/
    std::uint8_t _day;
};

inline const bool DayOfTheWeek::operator==(const DayOfTheWeek & o) const
{
    return _day==o._day;
}

template<class Archive>
void DayOfTheWeek::serialize(Archive& ar, unsigned int version)
{
    std::uint16_t __day=this->_day;
    ar & __day;
    this->_day=__day;
}

}
#endif // DAYOFTHEWEEK_HXX

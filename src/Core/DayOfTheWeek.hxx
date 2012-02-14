/* Maciej Poleski (C) 2012 */

#ifndef DAYOFTHEWEEK_HXX
#define DAYOFTHEWEEK_HXX

#include <cstdint>
namespace Core
{

class DayOfTheWeek
{
public:
    explicit DayOfTheWeek();
    explicit DayOfTheWeek(uint8_t day);

    inline const bool operator==(const DayOfTheWeek & o) const
    {
        return day_==o.day_;
    }
private:
    /**
     * @brief 0 - niezainicjalizowane, 1 - poniedziałek
     **/
    std::uint8_t day_;
};
}
#endif // DAYOFTHEWEEK_HXX

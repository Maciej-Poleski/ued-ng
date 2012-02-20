/* Maciej Poleski (C) 2012 */

#ifndef POINTS_HXX
#define POINTS_HXX

#include <cstdint>
namespace Core
{

class Points
{
public:
    explicit Points();
    explicit Points(int64_t numerator, uint64_t denominator=1);

private:
    std::int64_t numerator_;
    std::uint64_t denominator_;
};
}

#endif // POINTS_HXX

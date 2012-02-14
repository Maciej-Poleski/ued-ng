/* Maciej Poleski (C) 2012 */

#include "Points.hxx"

Points::Points() : numerator_(0), denominator_(0)
{

}

Points::Points(int64_t numerator, uint64_t denominator) :
    numerator_(numerator),
    denominator_(denominator)
{

}

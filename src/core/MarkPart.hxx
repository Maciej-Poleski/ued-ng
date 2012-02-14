/* Maciej Poleski (C) 2012 */

#ifndef MARKPART_HXX
#define MARKPART_HXX

#include <string>
#include <utility>

#include <boost/shared_ptr.hpp>

#include "Points.hxx"

class MarkCategory;

/**
 * @brief Zbiór punktów zdobytych podczas pewnej lekcji
 *
 * Gotowa do testów
 **/
class MarkPart
{
public:
    explicit MarkPart();
    explicit MarkPart(Points points, Points pool);

    void setComment(const std::string &comment);
    void setPoints(Points points, Points pool);
    void setMarkCategory(boost::shared_ptr<MarkCategory> markCategory);

    const std::string comment() const;
    const std::pair<Points,Points> points() const;
    boost::shared_ptr<MarkCategory> markCategory() const;

private:
    std::string _comment;
    Points _points;
    Points _pool;
    boost::shared_ptr<MarkCategory> _markCategory;
};

#endif // MARKPART_HXX

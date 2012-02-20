/* Maciej Poleski (C) 2012 */

#include "MarkPart.hxx"

#include "MarkCategory.hxx"
namespace Core
{

MarkPart::MarkPart()
{

}

MarkPart::MarkPart(Points points, Points pool) : _points(points), _pool(pool)
{

}

const std::string MarkPart::comment() const
{
    return _comment;
}

boost::shared_ptr< MarkCategory > MarkPart::markCategory() const
{
    return _markCategory;
}

const std::pair< Points,Points > MarkPart::points() const
{
    return std::make_pair(_points,_pool);
}

void MarkPart::setComment(const std::string& comment)
{
    _comment=comment;
}

void MarkPart::setPoints(Points points, Points pool)
{
    _points=points;
    _pool=pool;
}

void MarkPart::setMarkCategory(boost::shared_ptr< MarkCategory > markCategory)
{
    _markCategory=markCategory;
}

}

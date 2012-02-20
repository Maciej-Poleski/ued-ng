#ifndef MARKCATEGORY_HXX
#define MARKCATEGORY_HXX

#include <string>

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <boost/serialization/access.hpp>
#include <boost/serialization/weak_ptr.hpp>
#include <boost/serialization/string.hpp>

namespace Core
{

class Group;

/**
 * @brief Obiekty tej klasy powinny być składowane w puli każdej grupy.
 *
 * Gotowa do testów
 **/
class MarkCategory : public boost::enable_shared_from_this<MarkCategory>
{
    friend class boost::serialization::access;
public:
    explicit MarkCategory();
    explicit MarkCategory(const std::string & categoryName);

    boost::shared_ptr<Group> group() const;
    const std::string name() const;

    void setGroup(boost::shared_ptr< Group > group);
    void setName(const std::string &name);

private:
    template<class Archive>
    void serialize(Archive &ar, unsigned int version);

    std::string _name;
    boost::weak_ptr<Group> _group;
};

template<class Archive>
void MarkCategory::serialize(Archive& ar, const unsigned int /*version*/)
{
    ar & _name & _group;
}

}

#endif // MARKCATEGORY_HXX

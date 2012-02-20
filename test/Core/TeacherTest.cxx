#include <boost/test/unit_test.hpp>

#include <string>
#include <algorithm>

#include <Teacher.hxx>
#include <Group.hxx>

BOOST_AUTO_TEST_CASE(constructors)
{
    Core::Teacher t0;
    Core::Teacher t1("imię nazwisko");
}

BOOST_AUTO_TEST_CASE(accessors) {
    Core::Teacher t0;
    BOOST_CHECK(t0.name()=="unknown");
    t0.setName(std::string("imię nazwisko"));
    BOOST_CHECK(t0.name()=="imię nazwisko");
    Core::Teacher t1("imię2");
    BOOST_CHECK(t1.name()=="imię2");
}

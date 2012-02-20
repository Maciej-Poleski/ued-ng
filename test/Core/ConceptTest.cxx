#include <boost/test/unit_test.hpp>

#include <string>
#include <algorithm>

#include <boost/shared_ptr.hpp>

#include <Teacher.hxx>
#include <Group.hxx>
#include <Category.hxx>
#include <MarkCategory.hxx>
#include <DayOfTheWeek.hxx>
#include <HoursOfTheDay.hxx>
#include <Subject.hxx>

BOOST_AUTO_TEST_CASE(group_construction_0) {
    boost::weak_ptr<Core::Teacher> wt0;
    boost::weak_ptr<Core::Group> wg0;
    boost::weak_ptr<Core::Group> wg1;
    {
        boost::shared_ptr<Core::Teacher> t0(new Core::Teacher("t0"));
        wt0=t0;
        boost::shared_ptr<Core::Group> g0(new Core::Group(std::string("g0")));
        wg0=g0;
        g0->setTeacher(t0);
        boost::shared_ptr<Core::Group> g1(new Core::Group("g1"));
        wg1=g1;
        g1->setTeacher(t0);
        auto t0_g=t0->groups();
        BOOST_CHECK_EQUAL(count(t0_g.begin(),t0_g.end(),g0),1);
        t0_g=t0->groups();
        BOOST_CHECK_EQUAL(count(t0_g.begin(),t0_g.end(),g1),1);
        BOOST_CHECK_EQUAL(t0->groups().size(),2);
    }
    BOOST_CHECK(wt0.expired());
    BOOST_CHECK(wg0.expired());
    BOOST_CHECK(wg1.expired());
}

BOOST_AUTO_TEST_CASE(group_construction_1) {
    boost::weak_ptr<Core::Group> wg0;
    boost::weak_ptr<Core::Teacher> wt0;
    boost::weak_ptr<Core::Category> wc0;
    boost::weak_ptr<Core::MarkCategory> wmc0;
    boost::weak_ptr<Core::MarkCategory> wmc1;
    {
        boost::shared_ptr<Core::Group> g0(new Core::Group);
        wg0=g0;
        boost::shared_ptr<Core::Teacher> t0(new Core::Teacher("t0"));
        wt0=t0;
        g0->setTeacher(t0);
        g0->setName(std::string("g0"));
        boost::shared_ptr<Core::Category> c0(new Core::Category("c0"));
        wc0=c0;
        g0->setCategory(c0);
        boost::shared_ptr<Core::MarkCategory> mc0(new Core::MarkCategory(std::string("mc0")));
        wmc0=mc0;
        boost::shared_ptr<Core::MarkCategory> mc1(new Core::MarkCategory(std::string("mc1")));
        wmc1=mc1;
        g0->addMarkCategory(mc0);
        g0->addMarkCategory(mc1);
        g0->addTerm(Core::DayOfTheWeek(2),Core::HoursOfTheDay(8,9));
        BOOST_CHECK(mc0->group()==g0);
        BOOST_CHECK(mc1->group()==g0);
        auto c0_g=c0->groups();
        BOOST_CHECK_EQUAL(count(c0_g.begin(),c0_g.end(),g0),1);
        auto t0_g=t0->groups();
        BOOST_CHECK_EQUAL(count(t0_g.begin(),t0_g.end(),g0), 1);
        auto g0_t=g0->terms();
        BOOST_CHECK_EQUAL(
            count(g0_t.begin(),
                  g0_t.end(),
                  std::make_pair(Core::DayOfTheWeek(2),Core::HoursOfTheDay(8,9))
                 ),
            1);
    }
    BOOST_CHECK(wg0.expired());
    BOOST_CHECK(wt0.expired());
    BOOST_CHECK(wc0.expired());
    BOOST_CHECK(wmc0.expired());
    BOOST_CHECK(wmc1.expired());
}

BOOST_AUTO_TEST_CASE(category_construction_1) {
    boost::shared_ptr<Core::Category> c0(new Core::Category(std::string("c0")));
    boost::shared_ptr<Core::Category> c1(new Core::Category(std::string("c1")));
    boost::shared_ptr<Core::Subject> s0(new Core::Subject(std::string("s0")));
    s0->addCategory(c0);
    c1->addSubject(s0);
}

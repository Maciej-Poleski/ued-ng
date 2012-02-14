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
    boost::weak_ptr<Teacher> wt0;
    boost::weak_ptr<Group> wg0;
    boost::weak_ptr<Group> wg1;
    {
        boost::shared_ptr<Teacher> t0(new Teacher("t0"));
        wt0=t0;
        boost::shared_ptr<Group> g0(new Group(std::string("g0")));
        wg0=g0;
        g0->setTeacher(t0);
        boost::shared_ptr<Group> g1(new Group("g1"));
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
    boost::weak_ptr<Group> wg0;
    boost::weak_ptr<Teacher> wt0;
    boost::weak_ptr<Category> wc0;
    boost::weak_ptr<MarkCategory> wmc0;
    boost::weak_ptr<MarkCategory> wmc1;
    {
        boost::shared_ptr<Group> g0(new Group);
        wg0=g0;
        boost::shared_ptr<Teacher> t0(new Teacher("t0"));
        wt0=t0;
        g0->setTeacher(t0);
        g0->setName(std::string("g0"));
        boost::shared_ptr<Category> c0(new Category("c0"));
        wc0=c0;
        g0->setCategory(c0);
        boost::shared_ptr<MarkCategory> mc0(new MarkCategory(std::string("mc0")));
        wmc0=mc0;
        boost::shared_ptr<MarkCategory> mc1(new MarkCategory(std::string("mc1")));
        wmc1=mc1;
        g0->addMarkCategory(mc0);
        g0->addMarkCategory(mc1);
        g0->addTerm(DayOfTheWeek(2),HoursOfTheDay(8,9));
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
                  std::make_pair(DayOfTheWeek(2),HoursOfTheDay(8,9))
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
    boost::shared_ptr<Category> c0(new Category(std::string("c0")));
    boost::shared_ptr<Category> c1(new Category(std::string("c1")));
    boost::shared_ptr<Subject> s0(new Subject(std::string("s0")));
    s0->addCategory(c0);
    c1->addSubject(s0);
}

#include <iostream>
#include <memory>
#include <fstream>
#include <string>

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/weak_ptr.hpp>

class B;

class A : public boost::enable_shared_from_this<A>
{
    friend class boost::serialization::access;
public:
    A()
    {
        std::cout<<"Konstruktor A\n";
    }
    ~A()
    {
        std::cout<<"Destruktor A\n";
    }

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version);

    boost::shared_ptr<B> _b;
    std::string _comment;
};

class B : public boost::enable_shared_from_this<B>
{
    friend class boost::serialization::access;
public:
    B()
    {
        std::cout<<"Konstruktor B\n";
    }
    ~B()
    {
        std::cout<<"Destruktor B\n";
    }

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version);

    boost::weak_ptr<A> _a;
    std::string _comment;
};

template<class Archive>
inline void A::serialize(Archive& ar, const unsigned int version)
{
    ar & _b & _comment;
}

template<class Archive>
inline void B::serialize(Archive& ar, const unsigned int version)
{
    ar & _a & _comment;
}


int main(int argc,char**argv)
{
    boost::shared_ptr<A> a;
    boost::shared_ptr<B> b;
    std::ifstream in("/tmp/t");
    {
        boost::archive::text_iarchive ia(in);
        ia>>a>>b;
    }
    std::cout<<a->_comment<<' '<<b->_comment<<'\n';
    std::cout<<a->_b->_comment<<' '<<b->_a.lock()->_comment<<'\n';
    a.reset(new A);
    b.reset(new B);
    a->_b=b;
    b->_a=a;
    a->_comment="Komentarz a";
    b->_comment="Komentarz b";
    std::ofstream out("/tmp/t");
    {
        boost::archive::text_oarchive oa(out);
        oa<<a<<b;
    }
    std::cout<<u8"Witaj Świecie!\n";
    return 0;
}

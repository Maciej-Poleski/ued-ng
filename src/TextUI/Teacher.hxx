/* Maciej Poleski (C) 2012 */

#ifndef TEXTUI_TEACHER_HXX
#define TEXTUI_TEACHER_HXX

#include <boost/shared_ptr.hpp>

namespace Core
{
class Teacher;
}

namespace TextUI
{

class Teacher
{
public:
    explicit Teacher();
    explicit Teacher(boost::shared_ptr<Core::Teacher> teacher);

    const boost::shared_ptr<Core::Teacher> teacher() const;

    void setTeacher(boost::shared_ptr<Core::Teacher> teacher);

    void printName() const;
    void printGroups() const;

    void getName();
    void addGroup();
    void removeGroup();

    void constructNew();

private:
    boost::shared_ptr<Core::Teacher> _teacher;
};

inline const boost::shared_ptr< Core::Teacher > Teacher::teacher() const
{
    return _teacher;
}

inline void Teacher::setTeacher(boost::shared_ptr< Core::Teacher > teacher)
{
    _teacher=teacher;
}

}

#endif // TEXTUI_TEACHER_HXX

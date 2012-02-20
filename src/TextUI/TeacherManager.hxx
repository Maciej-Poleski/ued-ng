/* Maciej Poleski (C) 2012 */

#ifndef TEXTUI_TEACHERMANAGER_HXX
#define TEXTUI_TEACHERMANAGER_HXX

#include <boost/shared_ptr.hpp>

namespace Core
{
    class TeacherManager;
}

namespace TextUI
{

class TeacherManager
{
public:
    explicit TeacherManager();
    explicit TeacherManager(boost::shared_ptr<Core::TeacherManager> teacherManager);

    void printTeacherList() const;

    void addTeacher();
    void removeTeacher();

    void userTime();

private:
    boost::shared_ptr<Core::TeacherManager> _teacherManager;
};

}

#endif // TEXTUI_TEACHERMANAGER_HXX

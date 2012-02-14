/* Maciej Poleski (C) 2012 */

#ifndef TEACHERMANAGER_HXX
#define TEACHERMANAGER_HXX

#include <vector>
#include <memory>

class Teacher;

class TeacherManager
{
public:
    TeacherManager();

private:
    std::vector<std::shared_ptr<Teacher>> teachers_;
};

#endif // TEACHERMANAGER_HXX

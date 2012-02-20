/* Maciej Poleski (C) 2012 */

#include "TeacherManager.hxx"
namespace Core
{

TeacherManager::TeacherManager()
{

}

void TeacherManager::addTeacher(boost::shared_ptr< Teacher > teacher)
{
    if(std::find(_teachers.begin(),_teachers.end(),teacher)!=_teachers.end())
        return;
    _teachers.push_back(teacher);
}

void TeacherManager::removeTeacher(boost::shared_ptr< Teacher > teacher)
{
    auto i=std::find(_teachers.begin(),_teachers.end(),teacher);
    if(i==_teachers.end())
        return;
    _teachers.erase(i);
}
}

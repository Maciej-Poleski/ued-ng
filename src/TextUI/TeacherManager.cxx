/* Maciej Poleski (C) 2012 */

#include "TeacherManager.hxx"

#include <iostream>
#include <exception>

#include <Core/TeacherManager.hxx>
#include <Core/Teacher.hxx>

#include "Teacher.hxx"

TextUI::TeacherManager::TeacherManager()
{

}

TextUI::TeacherManager::TeacherManager(boost::shared_ptr< Core::TeacherManager > teacherManager) :
    _teacherManager(teacherManager)
{

}

void TextUI::TeacherManager::printTeacherList() const
{
    using namespace std;
    cout<<"Lista wszystkich nauczycieli:\n";
    int c=0;
for(auto i: _teacherManager->teachers())
    {
        cout<<'['<<++c<<"] ";
        TextUI::Teacher(i).printName();
    }
}

void TextUI::TeacherManager::addTeacher()
{
    TextUI::Teacher ui;
    ui.constructNew();
    _teacherManager->addTeacher(ui.teacher());
}

void TextUI::TeacherManager::removeTeacher()
{
    using namespace std;
    cout<<"Podaj id nauczyciela do usunięcia (0 - anuluj)\n";
    int c;
    cin>>c;
    if(c==0)
    {
        cout<<"Anulowano\n";
        return;
    }
    _teacherManager->removeTeacher(_teacherManager->teachers().at(c-1));
}

void TextUI::TeacherManager::userTime()
{
    using namespace std;
    for(;;)
    {
        cout<<"Menadżer nauczycieli\n";
        cout<<" 1 - Dodaj nauczyciela\n"
            <<" 2 - Usuń nauczyciela\n"
            <<" 3 - Wyświetl listę nauczycieli\n"
            <<" 4 - Modyfikuj nauczyciela\n"
            <<" 0 - Powrót do menu głównego\n";
        int c;
        cin>>c;
        try
        {
            if(c==0)
                break;
            else if(c==1)
                addTeacher();
            else if(c==2)
                removeTeacher();
            else if(c==3)
            {
                printTeacherList();
            }
            else if(c==4)
            {
                cout<<"Podaj id nauczyciela (0 - Anuluj)\n";
                int c;
                cin>>c;
                if(c==0)
                {
                    cout<<" Anulowano\n";
                }
                else
                {
                    TextUI::Teacher(
                        _teacherManager->teachers().at(c-1)
                    ).userTime();
                }
            }
            else
            {
                cout<<"Niepoprawne polecenie >>"<<c<<"<<\n";
                continue;
            }
        }
        catch(const exception &e)
        {
            cout<<"Wystąpił wyjątek: "<<e.what()<<'\n';
        }
    }
}


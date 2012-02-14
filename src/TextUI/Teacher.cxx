/* Maciej Poleski (C) 2012 */

#include "Teacher.hxx"

#include <iostream>

#include <Core/Teacher.hxx>

TextUI::Teacher::Teacher()
{

}

TextUI::Teacher::Teacher(boost::shared_ptr< Core::Teacher > teacher) : _teacher(teacher)
{

}

void TextUI::Teacher::printName() const
{
    std::cout<<teacher()->name()<<'\n';
}

void TextUI::Teacher::printGroups() const
{
    std::cout<<"Grupy nauczyciela:\n";
    int c=0;
for(auto i: teacher()->groups())
    {
        std::cout<<'['<<++c<<']'<<" niezaimplementowane\n";
    }
}

void TextUI::Teacher::getName()
{
    std::cout<<"Podaj nową nazwę nauczyciela\n";
    std::string name;
    std::cin>>name;
    teacher()->setName(name);
}

void TextUI::Teacher::addGroup()
{

}

void TextUI::Teacher::removeGroup()
{
    std::cout<<"Podaj numer grupy do usunięcia (0 - anuluj)\n";
    int c;
    std::cin>>c;
    if(c==0)
    {
        std::cout<<" Anulowano\n";
        return;
    }
    teacher()->removeGroup(teacher()->groups().at(c-1));
}

void TextUI::Teacher::constructNew()
{
    using namespace std;
    cout<<"Tworzony jest nowy nauczyciel\n"
    <<"Podaj nazwę\n";
    string name;
    cin>>name;
    cout<<"Grupy są niezaimplementowane\n";
    _teacher.reset(new Core::Teacher(name));
    cout<<"Nauczyciel "<<name<<" stworzony\n";
}

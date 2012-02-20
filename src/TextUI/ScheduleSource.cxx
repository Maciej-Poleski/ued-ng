/* Maciej Poleski (C) 2012 */

#include "ScheduleSource.hxx"

#include <iostream>
#include <boost/algorithm/string/case_conv.hpp>

#include <Core/ScheduleSource.hxx>
#include <Core/SubjectSource.hxx>
#include <Core/Schedule.hxx>

#include "SubjectSource.hxx"
#include "Schedule.hxx"

namespace TextUI
{

ScheduleSource::ScheduleSource()
{

}

ScheduleSource::ScheduleSource(
    boost::shared_ptr< Core::ScheduleSource > scheduleSource
) : _scheduleSource(scheduleSource)

{

}

void ScheduleSource::userTime()
{
    using namespace std;
    for(;;)
    {
        cout<<"Harmonogram źródłowy\n"
            <<" 1 - Lista przedmiotów źródłowych\n"
            <<" 2 - Lista planów lekcji\n"
            <<" 3 - Dodaj przedmiot źródłowy\n"
            <<" 4 - Dodaj plan lekcji\n"
            <<" 5 - Usuń przedmiot źródłowy\n"
            <<" 6 - Usuń plan lekcji\n"
            <<" 7 - Wybierz przedmiot źródłowy\n"
            <<" 8 - Wybierz plan lekcji\n"
            <<" 0 - powrót\n";
        int c;
        cin>>c;
        try
        {
            if(c==0)
                break;
            else if(c==1)
                printSubjectsSources();
            else if(c==2)
                printSchedules();
            else if(c==3)
                addNewSubjectSource();
            else if(c==4)
                addNewSchedule();
            else if(c==5)
                removeSubjectSource();
            else if(c==6)
                removeSchedule();
            else if(c==7)
            {
                cout<<"Podaj id przedmiotu źródłowego (0 - Anuluj)\n";
                int c;
                cin>>c;
                if(c==0)
                {
                    cout<<" Anulowano\n";
                }
                else
                {
                    TextUI::SubjectSource(
                        _scheduleSource->subjectsSources().at(c-1)
                    ).userTime();
                }
            }
            else if(c==8)
            {
                cout<<"Podaj id planu lekcji (0 - Anuluj)\n";
                int c;
                cin>>c;
                if(c==0)
                {
                    cout<<" Anulowano\n";
                }
                else
                {
                    TextUI::Schedule(
                        _scheduleSource->schedules().at(c-1)
                    ).userTime();
                }
            }
            else
                cout<<"Niepoprawne polecenie >>"<<c<<"<<\n";
        }
        catch(const exception &e)
        {
            cout<<"Wystąpił wyjątek: "<<e.what()<<'\n';
        }
    }
}

void ScheduleSource::printSubjectsSources()
{
    using namespace std;
    cout<<"Lista przedmiotów źródłowych:\n";
    int c=0;
for(auto i:_scheduleSource->subjectsSources())
    {
        cout<<" ["<<++c<<"] "<<i->name()<<'\n';
    }
}

void ScheduleSource::printSchedules()
{
    using namespace std;
    cout<<"Lista planów lekcji:\n";
    int c=0;
for(auto i :_scheduleSource->schedules())
    {
        cout<<" ["<<++c<<"] "<<"niezaimplementowano"<<'\n';
    }
}

void ScheduleSource::addNewSubjectSource()
{
    using namespace std;
    TextUI::SubjectSource ss;
    ss.createNew();
    boost::shared_ptr<Core::SubjectSource> subjectSource(ss.subjectSource());
    _scheduleSource->addSubjectSource(subjectSource);
    cout<<" Gotowe\n";
}

void ScheduleSource::addNewSchedule()
{
    using namespace std;
    TextUI::Schedule s;
    s.createNew();
    boost::shared_ptr<Core::Schedule> schedule(s.schedule());
    _scheduleSource->addSchedule(schedule);
    cout<<" Gotowe\n";
}

void ScheduleSource::removeSubjectSource()
{
    using namespace std;
    cout<<"Podaj id przedmiotu źródłowego do usunięcia (0 - Anuluj)\n";
    int c;
    cin>>c;
    if(c==0)
    {
        cout<<" Anulowano\n";
        return;
    }
    _scheduleSource->removeSubjectSource(
        _scheduleSource->subjectsSources().at(c-1)
    );
}

void ScheduleSource::removeSchedule()
{
    using namespace std;
    cout<<"Podaj id planu lekcji do usunięcia (0 - Anuluj)\n";
    int c;
    cin>>c;
    if(c==0)
    {
        cout<<" Anulowano\n";
        return;
    }
    _scheduleSource->removeSchedule(_scheduleSource->schedules().at(c-1));
}

void ScheduleSource::createNew()
{
    using namespace std;
    cout<<"Tworzony jest nowy Harmonogram źródłowy\n";
    _scheduleSource.reset(new Core::ScheduleSource);
    for(;;)
    {
        cin.ignore();
        cout<<"Czy chcesz dodać nowy przedmiot źródłowy? [T/n]\n";
        string c;
        getline(cin,c);
        boost::algorithm::to_upper(c);
        if(c.empty() || c=="T" || c=="TA" || c=="TAK")
        {
            addNewSubjectSource();
        }
        else
        {
            break;
        }
    }
    for(;;)
    {
        cin.ignore();
        cout<<"Czy chcesz dodać nowy plan lekcji? [T/n]\n";
        string c;
        getline(cin,c);
        boost::algorithm::to_upper(c);
        if(c.empty() || c=="T" || c=="TA" || c=="TAK")
        {
            addNewSchedule();
        }
        else
        {
            break;
        }
    }
}

}

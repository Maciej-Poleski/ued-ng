/* Maciej Poleski (C) 2012 */

#include "ScheduleSourceManager.hxx"

#include <Core/ScheduleSourceManager.hxx>

#include "ScheduleSource.hxx"

namespace TextUI
{

ScheduleSourceManager::ScheduleSourceManager()
{

}

ScheduleSourceManager::ScheduleSourceManager(
    boost::shared_ptr< Core::ScheduleSourceManager > scheduleSourceManager
) : _scheduleSourceManager(scheduleSourceManager)
{

}

void ScheduleSourceManager::userTime()
{
    using namespace std;
    for(;;)
    {
        cout<<"Menadżer Harmonogramów źródłowych\n"
            <<" 1 - Wyświetl listę Harmonogramów źródłowych\n"
            <<" 2 - Dodaj nowy Harmonogram źródłowy\n"
            <<" 3 - Usuń Harmonogram źródłowy\n"
            <<" 4 - Modyfikuj Harmonogram źródłowy\n"
            <<" 0 - Powrót\n";
        int c;
        cin>>c;
        try
        {
            if(c==0)
                break;
            else if(c==1)
                printSchedulesSources();
            else if(c==2)
                addNewScheduleSource();
            else if(c==3)
                removeScheduleSource();
            else if(c==4)
            {
                cout<<"Podaj id Harmonogramu źródłowego (0 - Anuluj)\n";
                int c;
                cin>>c;
                if(c==0)
                {
                    cout<<" Anulowano\n";
                }
                else
                {
                    TextUI::ScheduleSource(
                        _scheduleSourceManager->schedulesSources().at(c-1)
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

void ScheduleSourceManager::printSchedulesSources()
{
    using namespace std;
    cout<<"Lista Harmonogramów źródłowych:\n";
    int c=0;
for(auto i:_scheduleSourceManager->schedulesSources())
    {
        cout<<" ["<<++c<<"] "<<"niezaimplementowano"<<'\n';
    }
}

void ScheduleSourceManager::addNewScheduleSource()
{
    using namespace std;
    TextUI::ScheduleSource ss;
    ss.createNew();
    boost::shared_ptr<Core::ScheduleSource> scheduleSource(ss.scheduleSource());
    _scheduleSourceManager->addScheduleSource(scheduleSource);
    cout<<" Gotowe\n";
}

void ScheduleSourceManager::removeScheduleSource()
{
    using namespace std;
    cout<<"Podaj id Harmonogramu źródłowego do usunięcia (0 - Anuluj)\n";
    int c;
    cin>>c;
    if(c==0)
    {
        cout<<" Anulowano\n";
        return;
    }
    _scheduleSourceManager->removeScheduleSource(
        _scheduleSourceManager->schedulesSources().at(c-1)
    );
}

}

#include <iostream>
#include <fstream>
#include <string>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/archive/archive_exception.hpp>

#include <Core/TeacherManager.hxx>
#include <Core/ScheduleSource.hxx>
#include <Core/SubjectSource.hxx>
#include <Core/Schedule.hxx>
#include <Core/Subject.hxx>
#include <Core/Group.hxx>
#include <Core/Category.hxx>
#include <Core/MarkCategory.hxx>
#include <Core/ScheduleSourceManager.hxx>

#include <TextUI/TeacherManager.hxx>
#include <TextUI/ScheduleSource.hxx>
#include <TextUI/ScheduleSourceManager.hxx>

using namespace std;

int main(int argc,char**argv)
{
    cout<<"Wersja rozwojowa\n"
        <<"Nie wszystkie menadżery posiadają API/UI\n";
    boost::shared_ptr<Core::TeacherManager> teacherManager;
    boost::shared_ptr<Core::ScheduleSourceManager> scheduleSourceManager;
    {
        ifstream in("/home/evil/ued2.txt");
        try
        {
            boost::archive::text_iarchive ia(in);
            ia>>teacherManager>>scheduleSourceManager;
        }
        catch(const boost::archive::archive_exception & e)
        {
            cout<<"Archiwum jest uszkodzone: "<<e.what()<<'\n';
            if(!scheduleSourceManager)
            {
                scheduleSourceManager.reset(new Core::ScheduleSourceManager);
                if(!teacherManager)
                {
                    teacherManager.reset(new Core::TeacherManager);
                }
            }
        }

    }
    for(;;)
    {
        cout<<"Wybierz menadżer do oddelegowania kontroli\n"
            <<" 1 - Menadżer nauczycieli\n"
            <<" 2 - Menadżer Harmonogramów źródłowych\n"
            <<" 0 - Koniec\n";
        int c;
        cin>>c;
        if(c==0)
        {
            break;
        }
        else if(c==1)
        {
            TextUI::TeacherManager(teacherManager).userTime();
        }
        else if(c==2)
        {
            TextUI::ScheduleSourceManager(scheduleSourceManager).userTime();
        }
        else
        {
            cout<<"Niepoprawny wybór >>"<<c<<"<<\n";
            continue;
        }
    }
    {
        ofstream out("/home/evil/ued2.txt");
        boost::archive::text_oarchive oa(out);
        oa<<teacherManager<<scheduleSourceManager;
    }
    return 0;
}

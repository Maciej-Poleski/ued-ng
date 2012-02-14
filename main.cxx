#include <iostream>
#include <fstream>
#include <string>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include <Core/TeacherManager.hxx>

#include <TextUI/TeacherManager.hxx>

using namespace std;

int main(int argc,char**argv)
{
    cout<<"Wersja rozwojowa\n"
        <<"Nie wszystkie menadżery posiadają API/UI\n";
    boost::shared_ptr<Core::TeacherManager> teacherManager;
    {
        ifstream in("/home/evil/ued2.txt");
        if(in.fail())
            teacherManager.reset(new Core::TeacherManager);
        else
        {
            boost::archive::text_iarchive ia(in);
            ia>>teacherManager;
        }
    }
    for(;;)
    {
        cout<<"Wybierz menadżer do oddelegowania kontroli\n"
            <<" 1 - Menadżer nauczycieli\n"
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
        else
        {
            cout<<"Niepoprawny wybór >>"<<c<<"<<\n";
            continue;
        }
    }
    {
        ofstream out("/home/evil/ued2.txt");
        boost::archive::text_oarchive oa(out);
        oa<<teacherManager;
    }
    return 0;
}

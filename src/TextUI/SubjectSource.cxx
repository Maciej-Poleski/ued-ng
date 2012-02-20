/* Maciej Poleski (C) 2012 */

#include "SubjectSource.hxx"

using namespace TextUI;

SubjectSource::SubjectSource()
{

}

SubjectSource::SubjectSource(boost::shared_ptr< Core::SubjectSource > subjectSource)
    : _subjectSource(subjectSource)
{

}

void SubjectSource::userTime()
{
    using namespace std;
    for(;;)
    {
        cout<<"Przedmiot źródłowy\n"
        <<" 0 - powrót\n";
        int c;
        cin>>c;
        try
        {
            if(c==0)
                break;
            else
                cout<<"Niepoprawne polecenie >>"<<c<<"<<\n";
        }
        catch(const exception &e)
        {
            cout<<"Wystąpił wyjątek: "<<e.what()<<'\n';
        }
    }
}

void SubjectSource::createNew()
{

}

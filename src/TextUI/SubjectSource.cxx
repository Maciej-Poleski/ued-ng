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

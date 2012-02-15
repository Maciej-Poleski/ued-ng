/* Maciej Poleski (C) 2012 */

#ifndef TEXTUI_SUBJECTSOURCE_HXX
#define TEXTUI_SUBJECTSOURCE_HXX

#include <boost/shared_ptr.hpp>

namespace Core
{
class SubjectSource;
}

namespace TextUI {

class SubjectSource
{
public:
    explicit SubjectSource();
    explicit SubjectSource(boost::shared_ptr<Core::SubjectSource> subjectSource);

    void userTime();
    void createNew();

    boost::shared_ptr<Core::SubjectSource> subjectSource() const;

private:
    boost::shared_ptr<Core::SubjectSource> _subjectSource;
};

inline boost::shared_ptr< Core::SubjectSource > SubjectSource::subjectSource() const
{
    return _subjectSource;
}


}

#endif // TEXTUI_SUBJECTSOURCE_HXX

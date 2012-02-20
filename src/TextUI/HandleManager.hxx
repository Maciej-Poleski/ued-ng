/* Maciej Poleski (C) 2012 */

#ifndef TEXTUI_HANDLEMANAGER_HXX
#define TEXTUI_HANDLEMANAGER_HXX

#include <vector>

#include <boost/shared_ptr.hpp>
#include <boost/any.hpp>

namespace TextUI {

class HandleManager
{
public:
    explicit HandleManager();

private:
    std::vector<boost::any> _handles;
};

}

#endif // TEXTUI_HANDLEMANAGER_HXX

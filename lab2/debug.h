#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

#define __FILENAME__ (strrchr(__FILE__,'\\')+1)

#define __DEBUG_INFO__(info) do {\
	std::clog << ">>>> file " << __FILENAME__ \
        << ", fun "\
        << __FUNCTION__ \
        << ", line " \
        << __LINE__ \
        << ", " << info << std::endl; \
			        } while(0)

#endif

#ifndef _VELOCITYFIELD_H_
#define _VELOCITYFIELD_H_

#include <memory>
#include "../lattice.h"

namespace LBM {

	namespace containers {

		template <typename T,int X,int Y,int Z, template <typename...> class  latticeModel>
		class velocity {};

	} //end of namespace containers

} //end of namespace LBM

#endif
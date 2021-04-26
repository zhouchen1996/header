#ifndef _GEOMETRY_HH_
#define _GEOMETRY_HH_

#include "geometry.h"

namespace LBM {

	namespace geometry {

		template <typename T>
		constructBaseOnPrimitive<T, D2Q9>::constructBaseOnPrimitive()
			:circle_p(std::make_shared<geometryPrimitive<D2Q9>::circle<T>>()) {}

		template <typename T>
		void constructBaseOnPrimitive<T, D2Q9>::construct(){

		}

	} // end of namespace geometry

} //end of namespace LBM

#endif
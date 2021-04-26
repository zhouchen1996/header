#ifndef _GEOMETRYPRIMITIVE_HH_
#define _GEOMETRYPRIMITIVE_HH_

#include "geometryPrimitive.h"

namespace LBM {

	namespace geometry {

		template <typename T>struct geometryPrimitive<D2Q9>::triangle {
			T point1[2];
			T point2[2];
			T point3[2];
		};

		template <typename T>struct geometryPrimitive<D2Q9>::square {};

		template <typename T>struct geometryPrimitive<D2Q9>::rectangle {};

		template <typename T>struct geometryPrimitive<D2Q9>::parallelogram {};

		template <typename T>struct geometryPrimitive<D2Q9>::trapezoid {};

		template <typename T>struct geometryPrimitive<D2Q9>::quadrangle {};

		template <typename T>struct geometryPrimitive<D2Q9>::pentagram {};

		template <typename T>struct geometryPrimitive<D2Q9>::polygon {};

		template <typename T>struct geometryPrimitive<D2Q9>::circle {
			T centre_x, centre_y;
			T radius;
		};

		template <typename T>struct geometryPrimitive<D2Q9>::moon {};

		template <typename T>struct geometryPrimitive<D2Q9>::ellipse {};

	} // end of namespace geometry

} //end of namespace LBM

#endif // !_GEOMETRYPRIMITIVE_HH_
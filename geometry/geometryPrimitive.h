#ifndef _GEOMETRYPRIMITIVE_H_
#define _GEOMETRYPRIMITIVE_H_

#include "../lattice.h"

namespace LBM {

	namespace geometry {

		template <template <typename...> class latticeType>
		class geometryPrimitive;

		//-----------------------------------------------------------------------------------------
		//geometryPrimitive<D2Q9>
		template <>
		class geometryPrimitive<D2Q9> {
		public:

			template <typename> struct triangle;
			template <typename> struct square;
			template <typename> struct rectangle;
			template <typename> struct parallelogram;
			template <typename> struct trapezoid;
			template <typename> struct quadrangle;

			template <typename> struct pentagram;
			template <typename> struct polygon;

			template <typename> struct circle;
			template <typename> struct moon;
			template <typename> struct ellipse;

			geometryPrimitive() {}
			~geometryPrimitive() {}
		};

		//-----------------------------------------------------------------------------------------
		//geometryPrimitive<D3Q19>

		//......

	} // end of namespace geometry

} //end of namespace LBM

#endif // !_GEOMETRYPRIMITIVE_H_
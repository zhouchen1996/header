#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include <memory>

#include "geometryPrimitive.hh"
#include "../lattice.h"

namespace LBM {

	namespace geometry {

		enum class domainType;

		template <typename T,template <typename...> class latticeType>
		class constructBaseOnPrimitive;

		template <template <typename...> class latticeType>
		class constructBaseOnIO;

		//-----------------------------------------------------------------------------------------
		//constructBaseOnPrimitive<D2Q9>
		
		template <typename T>
		class constructBaseOnPrimitive<T, D2Q9> {
		public:
			std::shared_ptr<geometryPrimitive<D2Q9>::circle<T>> circle_p;

			template <int M, int N>
			using geometry2D = domainType[M][N]; // option : S F inlet outlet

			constructBaseOnPrimitive();
			~constructBaseOnPrimitive() {}
			void construct();
		};

		//-----------------------------------------------------------------------------------------
		//constructBaseOnIO<D2Q9>
		//......
		template <>
		class constructBaseOnIO<D2Q9> {
			constructBaseOnIO() {}
			~constructBaseOnIO() {}
		};
	
	} // end of namespace geometry

} //end of namespace LBM

#endif
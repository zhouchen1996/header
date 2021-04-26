#ifndef _DOMAIN_H_
#define _DOMAIN_H_

#include <memory>

#include "../../lattice.h"
#include "../../geometry/geometry.h"

namespace LBM {

	enum class domainType { F, FB, FL, S, SB, SL, inlet, outlet, FB_inlet, FB_outlet };

	template <int M,int N,template <typename...> class latticeType>
	class domain {};

	//---------------------------------------------------------------------------------------------
	//domain<D2Q9>
	template <int M, int N>
	class domain<M,N,D2Q9> {
	public:

		std::shared_ptr<domainType[M][N]> dm;
		
		domain();
		~domain();
		//void generate(auto primitives);
		//void generate(auto file);
	};

	//---------------------------------------------------------------------------------------------
	//domain<D3Q19>
	
}

#endif // !_DOMAIN_H_
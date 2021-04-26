#ifndef _DOMAIN_HH_
#define _DOMAIN_HH_

#include "domain.h"

namespace LBM {

	//---------------------------------------------------------------------------------------------
	//domain<D2Q9>
	template <int M, int N>
	domain<M, N, D2Q9>::domain() :dm(std::make_shared<domainType[M][N]>()) {}

	template <int M, int N>
	domain<M, N, D2Q9>::~domain() {}

}

#endif // !_DOMAIN_HH_
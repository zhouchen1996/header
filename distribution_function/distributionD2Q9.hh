#ifndef _DISTRIBUTIOND2Q9_HH_
#define _DISTRIBUTIOND2Q9_HH_

#include "distributionD2Q9.h"

namespace LBM {

	namespace distribution {

		template <typename T, int M, int N>
		domain<M, N, D2Q9> distributionD2Q9<T, M, N>::dmclass{};//......

		template <typename T, int M, int N>
		distributionD2Q9<T, M, N>::distributionD2Q9(const std::string& str) :
			f(std::make_shared<dataType>()), feq(std::make_shared<dataType>()),
			u(std::make_shared<T[M][N]>()), v(std::make_shared<T[M][N]>()), rho(std::make_shared<T[M][N]>())
		{
			tag = str;
			if (tag.find("!velocity") != tag.npos) {
				u.reset();
				v.reset();
			}
			if (tag.find("!density") != tag.npos) {
				rho.reset();
			}
			if (tag.find("!equilibrium") != tag.npos) {
				feq.reset();
			}
		}

		template <typename T, int M, int N>
		distributionD2Q9<T, M, N>::~distributionD2Q9() {}

		template <typename T, int M, int N>
		template<typename operation>
		distributionD2Q9<T, M, N>& distributionD2Q9<T, M, N>::manipulation(operation _operate) {
			return _operate(*this);
		}

	} //end of namespace distribution 

} //end of namespace LBM 


#endif
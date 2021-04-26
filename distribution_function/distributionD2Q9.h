#ifndef _DISTRIBUTIOND2Q9_H_
#define _DISTRIBUTIOND2Q9_H_

#include <memory>
#include <string>

#include "domain/domain.hh"

namespace LBM {

	namespace distribution {

		template <typename T,int M,int N>
		class distributionD2Q9 {
		public:
			using dataType = T[M][N][9];

			std::shared_ptr<dataType> f, feq;
			std::shared_ptr<T[M][N]> u, v;
			std::shared_ptr<T[M][N]> rho;
			std::string tag;
			static domain<M, N, D2Q9> dmclass;

			distributionD2Q9(const std::string& str = "default"); 
			// option:
			// "!velocity"
			// "!density"
			// "!equilibrium"
			//e.g. distributionD2Q9<double,100,200> func("!velocity!density")
			~distributionD2Q9();
			template<typename operation> distributionD2Q9<T, M, N>& manipulation(operation);
		};

	} //end of namespace distribution 

} //end of namespace LBM

#endif
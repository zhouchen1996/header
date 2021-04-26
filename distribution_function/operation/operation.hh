#ifndef _OPERATION_HH_
#define _OPERATION_HH_

#include "operation.h"
#include "../../constantD2Q9.h"

namespace LBM {

	namespace operation {

		//SRT<D2Q9> operator()()
		template <typename T, int M, int N> 
		distribution::distributionD2Q9<T, M, N>& SRT<D2Q9>::operator()(distribution::distributionD2Q9<T, M, N>& f) {
			#include "_SRTD2Q9.h"
			return f;
		}

		//Streaming<D2Q9> operator()()
		template <typename T, int nx, int ny>
		distribution::distributionD2Q9<T, nx, ny>& Streaming<D2Q9>::operator()(distribution::distributionD2Q9<T, nx, ny>& fclass) {
			#include "_STREAMINGD2Q9.h"
			return fclass;
		}

		

	} //end of namespace operation

} //end of namespace LBM 

#endif
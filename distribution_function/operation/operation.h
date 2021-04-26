#ifndef _OPERATION_H_
#define _OPERATION_H_

#include <memory>
#include "../distributionD2Q9.hh"
#include "../../lattice.h"

namespace LBM {

	namespace operation {

		template <template <typename...> class  latticeModel>
		class SRT {};

		template <template <typename...> class  latticeModel>
		class MRT {};

		template <template <typename...> class  latticeModel>
		class Streaming {};
		
		//-----------------------------------------------------------------------------------------
		//SRT<D2Q9>
		template <>
		class SRT<D2Q9> {
		public:
			double tau;
			SRT() = delete;
			SRT(double relaxTime) :tau(relaxTime) {}
			~SRT() {}
			template <typename T, int M, int N> distribution::distributionD2Q9<T, M, N>& operator()(distribution::distributionD2Q9<T, M, N>&);
		};

		//-----------------------------------------------------------------------------------------
		//MRT<D2Q9>
		template <>
		class MRT<D2Q9> {
		public:
			MRT() {}
			~MRT() {}
		};

		//-----------------------------------------------------------------------------------------
		//Streaming<D2Q9>
		template<>
		class Streaming<D2Q9> {
		public:
			Streaming() {}
			~Streaming() {}
			template <typename T, int M, int N> distribution::distributionD2Q9<T, M, N>& operator()(distribution::distributionD2Q9<T, M, N>&);
		};

	} // end of namespace operation

} // end of namespace LBM 

#endif
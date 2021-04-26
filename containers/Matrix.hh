#ifndef _MATRIX_HH_
#define _MATRIX_HH_

#include <iomanip>

#include "Matrix.h"

namespace LBM {

	namespace containers {

		template <typename T, int M, int N>
		Matrix<T, M, N>::Matrix() : p_matrix(std::make_shared<_matrix>()) {
			for (int i = 0; i < M; i++)
				for (int j = 0; j < N; j++)
					(*p_matrix)[i][j] = 0;
		}

		template <typename T, int M, int N>
		Matrix<T, M, N>::Matrix(Matrix<T, M, N> const& m) : p_matrix(std::make_shared<_matrix>()) {
			for (int i = 0; i < M; i++)
				for (int j = 0; j < N; j++)
					(*p_matrix)[i][j] = (*(m.p_matrix))[i][j];
		}

		template <typename T, int M, int N>
		Matrix<T, M, N>::Matrix(T const(&raw_m)[M][N]) : p_matrix(std::make_shared<_matrix>()) {
			for (int i = 0; i < M; i++)
				for (int j = 0; j < N; j++)
					(*p_matrix)[i][j] = raw_m[i][j];
		}

		template <typename T, int M, int N>
		Matrix<T, M, N>& Matrix<T, M, N>::operator=(Matrix<T, M, N> const& m) {
			for (int i = 0; i < M; i++)
				for (int j = 0; j < N; j++)
					(*p_matrix)[i][j] = (*(m.p_matrix))[i][j];
			return *this;
		}

		template <typename T, int M, int N>
		Matrix<T, M, N>& Matrix<T, M, N>::operator=(T const(&raw_m)[M][N]) {
			for (int i = 0; i < M; i++)
				for (int j = 0; j < N; j++)
					(*p_matrix)[i][j] = raw_m[i][j];
			return *this;
		}

		template <typename T1, int M1, int K, int N1>
		Matrix<T1, M1, N1> operator*(Matrix<T1, M1, K> const& m1, Matrix<T1, K, N1> const& m2) {
			Matrix<T1, M1, N1> m_temp;
			for (int i = 0; i < M1; i++)
				for (int j = 0; j < N1; j++)
					for (int k = 0; k < K; k++)
						(*(m_temp.p_matrix))[i][j] += (*(m1.p_matrix))[i][k] * (*(m2.p_matrix))[k][j];
			return m_temp;
		}
		//, bool isScientific = false, int width = 8
		template <typename T2, int M2, int N2>
		std::ostream& operator<<(std::ostream& os, Matrix<T2, M2, N2> const& m) {
			if(!m.isScientific)
				os << std::fixed << std::setprecision(m.precision);
			for (int i = 0; i < M2; i++) {
				for (int j = 0; j < N2; j++)
					os << std::setw(m.width) << (*(m.p_matrix))[i][j];
				os << std::endl;
			}
			os << std::defaultfloat;
			return os;
		}

	} //end of namespace containers

} //end of namespace LBM

#endif // !_MATRIX_HH_
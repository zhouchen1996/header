#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <array>
#include <memory>

namespace LBM {

	namespace containers {

		template <typename T, int M, int N>
		class Matrix {
		public:
			using _matrix = std::array<std::array<T, N>, M>;
			Matrix();
			Matrix(Matrix<T, M, N> const&);
			Matrix(T const(&)[M][N]);
			Matrix<T, M, N>& operator=(Matrix<T, M, N> const&);
			Matrix<T, M, N>& operator=(T const(&)[M][N]);
			template <typename T1, int M1, int K, int N1> friend Matrix<T1, M1, N1> operator*(Matrix<T1, M1, K> const&, Matrix<T1, K, N1> const&);
			template <typename T2, int M2, int N2> friend std::ostream& operator<<(std::ostream&, Matrix<T2, M2, N2> const&);
			~Matrix() {}
			std::shared_ptr<_matrix> p_matrix;
			///operator<<() ///Matrix output format
			bool isScientific = false;
			int precision = 3;
			int width = 8;
		};

	} //end of namespace containers

} //end of namespace LBM

#endif // !_MATRIX_H_
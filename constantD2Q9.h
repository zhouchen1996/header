#ifndef _CONSTANTD2Q9_H_
#define _CONSTANTD2Q9_H_

namespace LBM {

	namespace constantD2Q9 {

		const double M[9][9] = {
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{-4,-1,-1,-1,-1, 2, 2, 2, 2},
			{ 4,-2,-2,-2,-2, 1, 1, 1, 1},
			{ 0, 1, 0,-1, 0, 1,-1,-1, 1},
			{ 0,-2, 0, 2, 0, 1,-1,-1, 1},
			{ 0, 0, 1, 0,-1, 1, 1,-1,-1},
			{ 0, 0,-2, 0, 2, 1, 1,-1,-1},
			{ 0, 1,-1, 1,-1, 0, 0, 0, 0},
			{ 0, 0, 0, 0, 0, 1,-1, 1,-1} };

		const double InvM[9][9] = {
			{1.0 / 9.0, -1.0 / 9.0, 1.0 / 9.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
			{1.0 / 9.0, -1.0 / 36.0,-1.0 / 18.0,1.0 / 6.0,-1.0 / 6.0,0.0,0.0,1.0 / 4.0,0.0},
			{1.0 / 9.0, -1.0 / 36.0,-1.0 / 18.0,0.0,0.0,1.0 / 6.0,-1.0 / 6.0,-1.0 / 4.0,0.0},
			{1.0 / 9.0, -1.0 / 36.0,-1.0 / 18.0,-1.0 / 6.0,1.0 / 6.0,0.0,0.0,1.0 / 4.0,0.0},
			{1.0 / 9.0, -1.0 / 36.0,-1.0 / 18.0,0.0,0.0,-1.0 / 6.0,1.0 / 6.0,-1.0 / 4.0,0.0},
			{1.0 / 9.0, 1.0 / 18.0, 1.0 / 36.0,1.0 / 6.0,1.0 / 12.0,1.0 / 6.0,1.0 / 12.0,0.0,1.0 / 4.0},
			{1.0 / 9.0, 1.0 / 18.0, 1.0 / 36.0,-1.0 / 6.0,-1.0 / 12.0,1.0 / 6.0,1.0 / 12.0,0.0,-1.0 / 4.0},
			{1.0 / 9.0, 1.0 / 18.0, 1.0 / 36.0,-1.0 / 6.0,-1.0 / 12.0,-1.0 / 6.0,-1.0 / 12.0,0.0,1.0 / 4.0},
			{1.0 / 9.0, 1.0 / 18.0, 1.0 / 36.0,1.0 / 6.0,1.0 / 12.0,-1.0 / 6.0,-1.0 / 12.0,0.0,-1.0 / 4.0} };

		const double cx[9]{ 0,1,0,-1,0,1,-1,-1,1 };
		const double cy[9]{ 0,0,1,0,-1,1,1,-1,-1 };

		const double w[9] = { 4.0 / 9.0,1.0 / 9.0,1.0 / 9.0,1.0 / 9.0,1.0 / 9.0,1.0 / 36.0,1.0 / 36.0,1.0 / 36.0,1.0 / 36.0 };
	}
}
#endif
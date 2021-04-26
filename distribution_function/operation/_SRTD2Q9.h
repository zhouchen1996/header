T uu{}, cu{};
using constantD2Q9::cx, constantD2Q9::cy, constantD2Q9::w; 
if(f.tag.find("!equilibrium")==f.tag.npos){ // have feq
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++) {
			uu = f.u[i][j] * f.u[i][j] + f.v[i][j] * f.v[i][j];
			for (int k = 0; k < 9; k++) {
				cu = f.u[i][j] * cx[k] + f.v[i][j] * cy[k];
				f.feq[i][j][k] = f.rho[i][j] * w[k] * (1.0 + 3.0 * cu + 4.5 * cu * cu - 1.5 * uu);
				f.f[i][j][k] = (1.0 - 1.0 / tau) * f.f[i][j][k] + tau * f.feq[i][j][k];
			}
		}
	}
}
else{ // have no feq
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++) {
			uu = f.u[i][j] * f.u[i][j] + f.v[i][j] * f.v[i][j];
			for (int k = 0; k < 9; k++) {
				cu = f.u[i][j] * cx[k] + f.v[i][j] * cy[k];
				f.f[i][j][k] = (1.0 - 1.0 / tau) * f.f[i][j][k] + tau * f.rho[i][j] * w[k] * (1.0 + 3.0 * cu + 4.5 * cu * cu - 1.5 * uu);
			}
		}
	}
}	
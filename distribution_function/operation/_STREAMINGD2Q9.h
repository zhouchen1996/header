for (int j = 0; j < ny; j++) {
	for (int i = nx - 1; i > 0; i--) {
		fclass.f[i][j][1] = fclass.f[i - 1][j][1];
	}
}
for (int i = 0; i < nx; i++) {
	for (int j = ny - 1; j > 0; j--) {
		fclass.f[i][j][2] = fclass.f[i][j - 1][2];
	}
}
for (int j = 0; j < ny; j++) {
	for (int i = 0; i < nx - 1; i++) {
		fclass.f[i][j][3] = fclass.f[i + 1][j][3];
	}
}
for (int i = 0; i < nx; i++) {
	for (int j = 0; j < ny - 1; j++) {
		fclass.f[i][j][4] = fclass.f[i][j + 1][4];
	}
}
for (int j = ny - 1; j > 0; j--) {
	for (int i = nx - 1; i > 0; i--) {
		fclass.f[i][j][5] = fclass.f[i - 1][j - 1][5];
	}
}
for (int j = ny - 1; j > 0; j--) {
	for (int i = 0; i < nx - 1; i++) {
		fclass.f[i][j][6] = fclass.f[i + 1][j - 1][6];
	}
}
for (int j = 0; j < ny - 1; j++) {
	for (int i = 0; i < nx - 1; i++) {
		fclass.f[i][j][7] = fclass.f[i + 1][j + 1][7];
	}
}
for (int j = 0; j < ny - 1; j++) {
	for (int i = nx - 1; i > 0; i--) {
		fclass.f[i][j][8] = fclass.f[i - 1][j + 1][8];
	}
}
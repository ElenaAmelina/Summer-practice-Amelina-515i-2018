#include "stdafx.h"
#include <stdio.h>
#include <math.h>
float coordinates(float xa, int ya, float xb, int yb);
float coefficients(int A, float B, float C);
int main(void) {
	int a, ya, yb, A, xa, xb, f, C;
	float  B, k, l, k1, k2, n, m1, m2, x, y;
	for (int i = 0; i < 2; i++)
	{
		printf("What you will enter data:\n1-coordinates of  lines\n2-coefficients of  lines?\n");
		scanf_s("%i", &a);
		if (a < 1 || a>2) {
			printf("Error\n");
			return 0;
		}
		if (a == 1) {
			printf("Input xa,ya,xb,yb : ");
			scanf_s("%i%i%i%i", &xa, &ya, &xb, &yb);
			k1 = coordinates(xa, ya, xb, yb);
			m1 = k1 * (-((ya - yb) * xa + (xb - xa) * ya)) / (ya - yb);

		}
		if (a == 2) {
			printf("Input A,B,C :\n");
			scanf_s("%i%f%i", &A, &B, &C);
			k2 = coefficients(A, B, C);
			m2 = k2 * C / A;

		}

	}
	n = (k1 - k2) / (1 + k1 * k2);
	l = -atan(n);
	l = l * 180 / 3.14;
	printf("Angle between straight lines = %f\n", l);
	x = (m2 - m1) / (k1 - k2);
	printf("x = %.3f\n", x);
	y = x * k1 + m1;
	printf("y = %.3f\n", y);
	return 0;
}
float coordinates(float xa, int ya, float xb, int yb) {
	int A;
	float B, C, k2;
	A = ya - yb;
	B = xb - xa;
	C = -(A * xa + B * ya);
	k2 = coefficients(A, B, C);
	return k2;
}
float coefficients(int A, float B, float C) {
	float m, k;
	m = -C / B;
	k = -A / B;
	printf("k = %.5f\n", k);
	if (m > 0 && k != 1) {
		printf("y = %.5fx+%.2f\n", k, m);
	}
	if (m == 0) {
		printf("y = %.5f\n", k);
	}
	if (k == 0) {
		printf("y = %.2f\n", m);
	}
	if (m < 0 && k != 1) {
		printf("y = %.5fx%.2f\n", k, m);
	}
	if (k == 1 && m>0) {
		printf("y = x+%.2f\n", m);
	}
	if (k == 1 && m<0) {
		printf("y = x%.2f\n", m);
	}
	return k;
}

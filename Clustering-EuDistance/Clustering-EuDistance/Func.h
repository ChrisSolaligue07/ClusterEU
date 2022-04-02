#pragma once

#include <cmath>

float Dimension_1(int xi, int xj);
float Dimension_n(int xi[], int yj, int n);

float Dimension_1(int xi, int xj)
{
	// (pi - qi)^2
	return pow(xi - xj, 2);
}
float Dimension_n(int xi[], int xj[], int n)
{	// n = dimension.
	// xi = un punto con n dimensiones.
	// xk = un punto con n dimensiones.
	float res = {};
	for (int i = 0; i < n; i++)
	{
		res = res + (Dimension_1(xi[i], xj[i]));
	}
	return sqrt(res);
}
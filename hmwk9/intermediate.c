#include <stdio.h>
#include <math.h>

double ivt (double (*continuous) (double x), double a, double b, double v, double error) {
	double m;
	m = (a + b) / 2;
	if (fabs(continuous(m) - v) < error) {
		return m;
	}
	else if (continuous(m) > v) {
		return ivt(continuous, a, m, v, error);
	}
	else if (continuous(m) < v) {
		return ivt(continuous, m, b, v, error);
	}
}

double quadratic(double x) {
	return x * x - 2;
}
	

int main () {
	double a = 1;
	double b = 2;
	double v = 0;
	printf("Given the continuous function f defined on the closed interval (%lf, %lf)\n"
			"and a value v = %lf, the value c such that for value v f(c) = v is %lf\n",
		  a, b, v, ivt(quadratic, a, b, v, 0.01));
	return 0;
}

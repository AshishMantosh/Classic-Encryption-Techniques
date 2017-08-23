#include"bits/stdc++.h"

using namespace std;

int gcdExtended(int a, int b, int *x, int *y)
{
	if(a == 0)
	{
		*x = 0;
		*y = 1;

		return b;
	}

	int gcd, x1, y1;

	gcd = gcdExtended(b%a, a, &x1, &y1);

	*x = y1 - (b/a)*x1;
	*y = x1;

	return gcd;
}

int multiplicativeInverse(int a)
{
	int g, x, y, res;

	g = gcdExtended(a, 26, &x, &y);

	if(g!=1)
	{
		return -1;
	}
	else
	{
		res = (x%26 + 26) % 26;
	}

	return res;
}

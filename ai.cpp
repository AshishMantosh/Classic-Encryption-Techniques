#include"bits/stdc++.h"

using namespace std;

int additiveInverse(int a)
{
	int ans;

	ans = 26 - a;

	return ans;
}

int main(int argc, char** argv)
{
	int a;

	cin>>a;

	int ans = additiveInverse(a);

	cout<<ans<<endl;
	
	return 0;
}

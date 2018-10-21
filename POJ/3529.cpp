#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX (long long)1e5
bool check(int mid, int a[], int n, int c_n_2)
{
	int i, s = 0;
	for (i = 0; i < n; i++)
		s += (a + n) - lower_bound(a, a + n, a[i] + mid);
	return s > c_n_2 / 2;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	while (cin>>n&&n!=EOF)
	{
		int r,mid,a[MAX],c_n_2,ans,i,l=0;
		c_n_2 = n * (n - 1) / 2;
		for (i = 0; i < n; i++)
			std::cin>>a[i];//cin = TLE
		sort(a, a + n);
		r = a[n - 1] - a[0];
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (check(mid, a, n, c_n_2))
			{
				ans = mid;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
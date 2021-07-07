#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
using namespace std;

// ll powFunc(ll p, ll n)
// {
//     ll result = 1;
//     for (ll i = 0; i < n; i++)
//     {
//         result *= p;
//     }
//     return result;
// }

// ll fact(ll n)
// {
//     ll ans = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         ans *= i;
//     }
//     return ans;
// }

// int gcd(int a, int b){
//     if(b==0){
//         return a;
//     }
//     return gcd(b, a%b);
// }

// int lcm(int a, int b){
//     int res = (a*b)/gcd(a,b);
//     return res;
// }

void func()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		mx = max(mx, v[i]);
	}
	ll lo = mx;
	ll hi = 1e18;
	ll ans = 1e18;
	while (lo <= hi)
	{
		ll mid = lo + (hi - lo) / 2;
		int b = 1;
		ll sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (sum + v[i] > mid)
			{
				sum = 0;
				b++;
			}
			sum += v[i];
		}
		if (b > k)
		{
			lo = mid + 1;
		}
		else
		{
			ans = min(ans, mid);
			hi = mid - 1;
		}
	}
	cout << ans << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	clock_t start, end;
	start = clock();
	ios::sync_with_stdio(false);

	cin.tie(nullptr);
	cout.tie(nullptr);

	int num = 1;
	//cin >> num;
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (num--)
	{
		func();
	}
	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cerr << "Time taken by program is : " << fixed
		 << time_taken << setprecision(5);
	cerr << " sec " << endl;
	return 0;
}
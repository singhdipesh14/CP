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

int mod = 1e9 + 7;

int func2(int n, unordered_map<int, int> &dp)
{
	if (n < 0)
	{
		return 0;
	}
	if (n == 0)
	{
		return 1;
	}
	int cnt = 0;
	for (int i = 1; i <= 6; i++)
	{
		if (dp.count(n - i))
		{
			cnt = cnt + dp[n - i];
		}
		else
		{
			dp[n - i] = func2(n - i, dp) % mod;
			cnt += dp[n - i];
		}
		cnt = cnt % mod;
	}
	return cnt;
}

void func()
{
	int n;
	cin >> n;
	// cout << "n is : " << n << '\n';
	unordered_map<int, int> dp;
	dp.reserve(1e6 + 1);
	int ans = func2(n, dp);
	cout << ans % mod << '\n';
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
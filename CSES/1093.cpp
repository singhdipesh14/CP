#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
using namespace std;
const int mod = 1e9 + 7;

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
	int n;
	cin >> n;
	if ((n * (n + 1)) % 4 != 0)
	{
		cout << 0 << '\n';
		return;
	}
	ll dp[n + 1][n * n];
	// memset(dp, 0, sizeof(dp));
	for (int i = 1; i < n * n; i++)
	{
		dp[0][i] = 0;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int x = 0; x <= ((n * (n + 1)) / 4); x++)
		{
			if (x >= i)
				dp[i][x] = (dp[i - 1][x] + dp[i - 1][x - i]) % mod;
			else
				dp[i][x] = dp[i - 1][x] % mod;
		}
	}
	cout << (dp[n][(n * (n + 1)) / 4] * 500000004) % mod << '\n';
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
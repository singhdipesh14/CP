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
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	ll dp[n][m + 1];
	memset(dp, 0, sizeof(dp));
	if (v[0] == 0)
	{
		for (int i = 1; i <= m; i++)
		{
			dp[0][i] = 1;
		}
	}
	else
	{
		dp[0][v[0]] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		if (v[i] == 0)
		{
			for (int j = 1; j <= m; j++)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
				if (j > 1)
					dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
				if (j < m)
					dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
			}
		}
		else
		{
			dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][v[i]]) % mod;
			if (v[i] > 1)
				dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][v[i] - 1]) % mod;
			if (v[i] < m)
				dp[i][v[i]] = (dp[i][v[i]] + dp[i - 1][v[i] + 1]) % mod;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= m; i++)
	{
		ans = (ans + dp[n - 1][i]) % mod;
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
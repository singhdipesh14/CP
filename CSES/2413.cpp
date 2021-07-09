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
	const int mx = 1e6 + 1;
	ll dp[mx][8] = {0};
	for (int i = 0; i < 8; i++)
	{
		dp[0][i] = 1;
	}
	for (int i = 1; i < mx; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j == 0 || j == 2 || j == 3 || j == 4 || j == 5)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5]) % mod;
			}
			else
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][2] + dp[i - 1][6] + dp[i - 1][7]) % mod;
			}
		}
	}
	int num;
	cin >> num;
	while (num--)
	{
		int n;
		cin >> n;
		ll ans = (dp[n - 1][2] + dp[n - 1][6]) % mod;
		cout << ans << '\n';
	}
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
	// cin >> num;
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
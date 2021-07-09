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
	string n, m;
	cin >> n >> m;
	int dp[100][100];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= m.length(); i++)
	{
		dp[0][i] = i;
	}
	for (int i = 0; i <= n.length(); i++)
	{
		dp[i][0] = i;
	}
	for (int i = 1; i <= n.length(); i++)
	{
		for (int j = 1; j <= m.length(); j++)
		{
			dp[i][j] = __INT_MAX__;
			dp[i][j] = min({(dp[i - 1][j - 1] + (n[i - 1] != m[j - 1])), dp[i - 1][j] + 1, dp[i][j - 1] + 1});
		}
	}
	for (int i = 1; i <= n.length(); i++)
	{
		for (int j = 1; j <= m.length(); j++)
		{
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << dp[n.length()][m.length()] << '\n';
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
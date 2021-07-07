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
	int n, k;
	cin >> n >> k;
	vector<int> costs(n);
	vector<int> pages(n);
	for (int &i : costs)
		cin >> i;
	for (int &i : pages)
		cin >> i;
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			dp[i + 1][j] = dp[i][j];
			if (j >= costs[i])
			{
				dp[i + 1][j] = max(dp[i + 1][j], pages[i] + dp[i][j - costs[i]]);
			}
		}
	}
	cout << dp[n][k] << '\n';
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
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
	int height, width;
	int dp[501][501];
	cin >> height >> width;
	for (int i = 0; i < 501; i++)
	{
		for (int j = 0; j < 501; j++)
		{
			dp[i][j] = __INT_MAX__;
		}
	}
	for (int i = 0; i < 501; i++)
	{
		dp[i][i] = 0;
	}
	for (int h = 1; h <= height; h++)
	{
		for (int w = 1; w <= width; w++)
		{
			for (int cut = 1; cut < w; cut++)
			{
				dp[h][w] = min(dp[h][w], dp[h][cut] + dp[h][w - cut] + 1);
			}
			for (int cut = 1; cut < h; cut++)
			{
				dp[h][w] = min(dp[h][w], dp[cut][w] + dp[h - cut][w] + 1);
			}
		}
	}
	cout << dp[height][width] << '\n';
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
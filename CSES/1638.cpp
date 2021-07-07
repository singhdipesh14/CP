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
	// vector<vector<bool>> can(n, vector<bool>(n, false));
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		char c;
	// 		cin >> c;
	// 		if (c == '.')
	// 		{
	// 			can[i][j] = true;
	// 		}
	// 		else
	// 		{
	// 			can[i][j] = false;
	// 		}
	// 	}
	// }
	vector<vector<int>> paths(n, vector<int>(m, 0));
	paths[0][0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; j++)
		{
			if (j + 1 < m)
			{
				paths[i][j + 1] = paths[i][j + 1] % mod + paths[i][j] % mod;
			}
			if (i + 1 < n)
			{
				paths[i + 1][j] = paths[i + 1][j] % mod + paths[i][j] % mod;
			}
		}
	}
	cout << paths[n - 1][m - 1] << '\n';
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
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

const int mod = 1e9 + 7;

int funcs(int n, vector<int> nums, unordered_map<int, int> dp)
{
	if (n == 0)
	{
		return 1;
	}
	if (n < 0)
	{
		return 0;
	}
	int cnt = 0;
	for (int i : nums)
	{
		int b;
		if (n - i >= 0)
		{
			if (dp.count(n - i))
			{
				b = dp[n - i];
			}
			else
			{
				b = funcs(n - i, nums, dp);
				dp[n - i] = b;
			}
			cnt += b % mod;
		}
	}
	return cnt;
}

void func()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	unordered_map<int, int> dp;
	// dp.reserve(1e6 + 1);
	int ans = funcs(k, v, dp);
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
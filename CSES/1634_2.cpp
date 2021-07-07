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

int funcs(int n, vector<int> nums, int &val, unordered_map<int, pair<int, int>> &dp)
{
	if (n < 0)
	{
		return 0;
	}
	if (n == 0)
	{
		return 1;
	}
	int flag = 0;
	for (int i : nums)
	{
		int ret = 0;
		int d = 0;
		if (dp.count(n - 1))
		{
			ret = dp[n - i].second;
			d = dp[n - i].first;
		}
		else
		{
			d = funcs(n - i, nums, ret, dp);
			dp[n - i].second = ret;
			dp[n - i].first = d;
		}
		if (d)
		{
			flag = 1;
			val = min(ret + 1, val);
		}
	}
	return flag;
}

void func()
{
	int n, target;
	cin >> n >> target;
	vector<int> nums(n);
	for (int &i : nums)
	{
		cin >> i;
	}
	int ans = INT_MAX;
	unordered_map<int, pair<int, int>> dp;
	// dp.reserve((1e9 + 1));
	int ret = funcs(target, nums, ans, dp);
	if (ret)
	{
		cout << ans << '\n';
	}
	else
	{
		cout << -1 << '\n';
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
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

void func()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	int target;
	cin >> target;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	int mn = INT_MAX;
	int s = 0;
	int cnt = 0;
	bool flag = true;
	for (int i = 0; i < nums.size(); i++)
	{
		s += nums[i];
		cnt++;
		if (s >= target)
		{
			flag = false;
			i -= cnt - 1;
			mn = min(mn, cnt);
			cnt = 0;
			s = 0;
		}
	}
	if (flag)
	{
		cout << 0 << '\n';
		return;
	}
	cout << mn << '\n';
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
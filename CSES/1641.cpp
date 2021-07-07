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
	int n, t;
	cin >> n >> t;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first, v[i].second = i;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		ll x = t - v[i].first;
		for (int j = i + 1, k = n - 1; j < k; j++)
		{
			while (j < k && v[j].first + v[k].first > x)
			{
				k--;
			}
			if (j < k && v[j].first + v[k].first == x)
			{
				cout << v[i].second + 1 << ' ' << v[j].second + 1 << ' ' << v[k].second + 1 << '\n';
				return;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
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
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
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin(), v.end());
	set<pair<int, int>> last;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (last.empty())
		{
			last.insert({-1 * v[i].first, i});
		}
		else
		{
			auto t = last.lower_bound({v[i].second * -1, -1});
			if (t != last.end())
			{
				last.erase(t);
				last.insert({v[i].first * -1, i});
			}
			else if (last.size() < k)
			{
				last.insert({v[i].first * -1, i});
			}
			else
			{
				cnt++;
			}
		}
	}
	cout << n - cnt << '\n';
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
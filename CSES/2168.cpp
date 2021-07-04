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

bool functor(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	if (a.first.first == b.first.first && a.first.second != b.first.second)
	{
		if (a.first.second == 1)
			return true;
		return false;
	}
	else if (a.first.first < b.first.first)
	{
		return true;
	}
	return false;
}

bool functor2(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	if (a.second < b.second)
		return true;

	return false;
}

void func()
{
	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> c;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		c.pb({{a, 1}, i});
		c.pb({{b, -1}, i});
	}
	sort(c.begin(), c.end(), functor);
	int cnt = 0;
	int mx = 0;
	for (int i = 0; i < c.size(); i++)
	{
		cnt += c[i].first.second;
		mx = max(mx, cnt);
	}
	cout << mx << '\n';
	// sort(c.begin(), c.end(), functor2);
	// for (int i = 0; i < c.size(); i++)
	// {
	// 	cout << c[i].first.first << ' ' << c[i].first.second << ' ' << c[i].second << '\n';
	// }
	set<int> a;
	map<int, int> b;
	vector<pair<int, int>> v;
	for (int i = 1; i <= mx; i++)
	{
		a.insert(i);
	}
	for (int i = 0; i < c.size(); i++)
	{
		if (c[i].first.second == 1)
		{
			auto it = a.begin();
			v.push_back({c[i].second, *it});
			b.insert({c[i].second, *it});
			a.erase(it);
		}
		else
		{
			auto in = b[c[i].second];
			a.insert(in);
			b.erase(c[i].second);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].second << ' ';
	}
	cout << '\n';
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
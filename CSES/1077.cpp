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
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	if (k == 1)
	{
		for (int i = 0; i < n; i++)
		{
			cout << 0 << ' ';
		}
		return;
	}
	else if (k == 2)
	{
		for (int i = 0; i < n - 1; i++)
		{
			cout << abs(v[i] - v[i + 1]) << ' ';
		}
		return;
	}
	set<pair<int, int>> le;
	set<pair<int, int>> ri;
	vector<pair<int, int>> temp;
	for (int i = 0; i < k; i++)
	{
		temp.pb({v[i], i});
	}
	sort(temp.begin(), temp.end());
	ll leS = 0;
	ll riS = 0;
	for (int i = 0; i < k / 2 + (k % 2); i++)
	{
		leS += temp[i].first;
		le.insert(temp[i]);
	}
	for (int i = k / 2 + (k % 2); i < k; i++)
	{
		riS += temp[i].first;
		ri.insert(temp[i]);
	}
	cout << (ll)le.size() * le.rbegin()->first - leS + riS - (ll)ri.size() * le.rbegin()->first << ' ';
	for (int j = 1; j < n - k + 1; j++)
	{
		if (le.count({v[j - 1], j - 1}))
		{
			leS -= v[j - 1];
			le.erase({v[j - 1], j - 1});
		}
		else
		{
			riS -= v[j - 1];
			ri.erase({v[j - 1], j - 1});
		}
		if (*le.rbegin() < make_pair(v[j + k - 1], j + k - 1))
		{
			riS += v[j + k - 1];
			ri.insert({v[j + k - 1], j + k - 1});
		}
		else
		{
			leS += v[j + k - 1];
			le.insert({v[j + k - 1], j + k - 1});
		}
		while (le.size() < k / 2 + (k % 2))
		{
			auto t = ri.begin();
			le.insert(*t);
			leS += t->first;
			riS -= t->first;
			ri.erase(t);
		}
		while (le.size() > k / 2 + (k % 2))
		{
			auto t = le.rbegin();
			ri.insert(*t);
			leS -= t->first;
			riS += t->first;
			le.erase(*t);
		}
		cout << (ll)le.size() * le.rbegin()->first - leS + riS - (ll)ri.size() * le.rbegin()->first << ' ';
		;
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
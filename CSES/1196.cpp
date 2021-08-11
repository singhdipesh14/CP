#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define ff first
#define ss second
#define ar array
#define mp make_pair
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

const int mxN = 1e5;
int m, n, k;
vector<ar<ll, 2>> adj[mxN];
vector<ll> d[mxN];

void func()
{
	cin >> n >> m >> k;
	for (int i = 0, a, b, c; i < m; i++)
	{
		cin >> a >> b >> c, a--, b--;
		adj[a].pb({c, b});
	}
	priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> q;
	q.push({0, 0});
	while (q.size())
	{
		auto cur = q.top();
		q.pop();
		if (d[cur[1]].size() >= k)
		{
			continue;
		}
		d[cur[1]].push_back(cur[0]);
		for (auto v : adj[cur[1]])
		{
			q.push({cur[0] + v[0], v[1]});
		}
	}
	for (int i = 0; i < k; i++)
	{
		cout << d[n - 1][i] << ' ';
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
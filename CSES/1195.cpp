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
vector<ar<ll, 2>> adj0[mxN];
vector<ar<ll, 2>> adj1[mxN];
ll d1[mxN], d2[mxN];
int n, m;

void func(int u, ll d[], vector<ar<ll, 2>> adj[])
{
	priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> q;
	q.push({0, u});
	memset(d, 0x3f, sizeof(d1));
	d[u] = 0;
	while (q.size())
	{
		auto cur = q.top();
		q.pop();
		if (cur[0] > d[cur[1]])
			continue;
		for (auto v : adj[cur[1]])
		{
			if (d[v[1]] > cur[0] + v[0])
			{
				d[v[1]] = cur[0] + v[0];
				q.push({d[v[1]], v[1]});
			}
		}
	}
}

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c, a--, b--;
		adj0[a].pb({c, b});
		adj1[b].pb({c, a});
	}
	func(0, d1, adj0);
	func(n - 1, d2, adj1);
	ll ans = LLONG_MAX;
	for (int i = 0; i < n; i++)
	{
		for (auto j : adj0[i])
		{
			ans = min(ans, d1[i] + j[0] / 2 + d2[j[1]]);
		}
	}
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
		solve();
	}
	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cerr << "Time taken by program is : " << fixed
		 << time_taken << setprecision(5);
	cerr << " sec " << endl;
	return 0;
}
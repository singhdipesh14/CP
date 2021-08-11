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

const int mxN = 5e2;
vector<ar<ll, 2>> adj[mxN];
vector<bool> vis(mxN, false);
int n, m;

void func()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
		adj[b].push_back({c, a});
	}
	priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> q;
	for (auto u : adj[0])
	{
		q.push(u);
	}
	vis[0] = true;
	int edges = 0;
	ll cost = 0;
	while (!q.empty() && edges != n - 1)
	{
		auto cur = q.top();
		q.pop();
		if (vis[cur[1]])
		{
			continue;
		}
		vis[cur[1]] = true;
		cost += cur[0];
		edges++;
		for (auto u : adj[cur[1]])
		{
			if (!vis[u[1]])
			{
				q.push(u);
			}
		}
	}
	if (edges != n - 1)
	{
		cout << "NOT POSSIBLE";
	}
	else
	{
		cout << cost;
	}
	cout << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("../../input.txt", "r", stdin);
	freopen("../../output.txt", "w", stdout);
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
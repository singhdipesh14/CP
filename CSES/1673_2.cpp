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

const int mxN = 2.5e3;
vector<ar<ll, 2>> adj[mxN];
ll d[mxN];
int m, n;
vector<int> adj2[mxN];
vector<bool> vis1(mxN, false), vis2(mxN, false);

void dfs1(int u)
{
	vis1[u] = true;
	for (auto i : adj[u])
	{
		if (!vis1[i[1]])
		{
			dfs1(i[1]);
		}
	}
}

void dfs2(int u)
{
	vis2[u] = true;
	for (auto i : adj2[u])
	{
		if (!vis2[i])
		{
			dfs2(i);
		}
	}
}

void func()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		adj[a].pb({-c, b});
		adj2[b].pb(a);
	}
	memset(d, 0x3f, sizeof(d));
	d[0] = 0;
	dfs1(0);
	dfs2(n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (auto k : adj[j])
			{
				if (d[j] + k[0] < d[k[1]])
				{
					d[k[1]] = d[j] + k[0];
				}
			}
		}
	}
	bool flag = false;
	for (int i = 0; i < n - 1; i++)
	{
		flag = false;
		for (int j = 0; j < n; j++)
		{
			for (auto k : adj[j])
			{
				if (d[j] + k[0] < d[k[1]] && vis1[j] && vis2[k[1]])
				{
					flag = true;
					d[k[1]] = 0xc0c0c0c0c0c0c0c0;
				}
			}
		}
	}

	if (flag)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << -d[n - 1] << '\n';
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
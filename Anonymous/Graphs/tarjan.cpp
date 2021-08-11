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
vector<int> adj[mxN];
vector<int> ids(mxN, -1), low(mxN);
vector<bool> act(mxN, false);
vector<bool> vis(mxN, false);
stack<int> st;
vector<vector<int>> ans;
int m, n, id = 0;

void dfs(int v)
{
	st.push(v);
	ids[v] = low[v] = ++id;
	vis[v] = true;
	act[v] = true;
	for (int u : adj[v])
	{
		if (vis[u] && act[u])
		{
			low[v] = min(low[v], ids[u]);
		}
		else if (!vis[u])
		{
			dfs(u);
			if (act[u])
			{
				low[v] = min(low[v], low[u]);
			}
		}
	}
	if (ids[v] == low[v])
	{
		vector<int> res;
		while (true)
		{
			int u = st.top();
			st.pop();
			act[u] = false;
			res.push_back(u);
			if (u == v)
			{
				break;
			}
		}
		ans.push_back(res);
	}
}

void func()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b, a--, b--;
		adj[a].push_back(b);
	}
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			dfs(i);
		}
	}
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] + 1 << ' ';
		}
		cout << '\n';
	}
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
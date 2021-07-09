#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
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
const int mxM = 2 * 1e5;

vector<int> adj[mxN], ans;
vector<bool> vis(mxN, false);

void dfs(int v)
{
	vis[v] = true;
	for (int i : adj[v])
	{
		if (!vis[i])
		{
			dfs(i);
		}
	}
}

void func()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		adj[--a].push_back(--b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			ans.push_back(i);
			dfs(i);
		}
	}
	cout << ans.size() - 1 << '\n';
	for (int i = 1; i < ans.size(); i++)
	{
		cout << ans[0] + 1 << ' ' << ans[i] + 1 << '\n';
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
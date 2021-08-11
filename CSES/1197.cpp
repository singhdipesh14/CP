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
int n, m, p[mxN];
ll d[mxN];
vector<bool> vis(mxN, false);

void func()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c, a--, b--;
		adj[a].pb({b, c});
	}
	memset(d, 0x3f, sizeof(d));
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (auto t : adj[j])
			{
				if (d[t[0]] > d[j] + t[1])
				{
					d[t[0]] = d[j] + t[1];
					p[t[0]] = j;
				}
			}
		}
	}
	for (int j = 0; j < n; j++)
	{
		for (auto t : adj[j])
		{
			if (d[t[0]] > d[j] + t[1])
			{
				while (!vis[j])
				{
					vis[j] = true;
					j = p[j];
				}
				int start = j;
				vector<int> ans;
				ans.pb(start);
				start = p[start];
				while (start != j)
				{
					ans.pb(start);
					start = p[start];
				}
				ans.pb(start);
				reverse(ans.begin(), ans.end());
				cout << "YES\n";
				for (int i : ans)
				{
					cout << i + 1 << ' ';
				}
				cout << '\n';
				return;
			}
		}
	}
	cout << "NO\n";
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
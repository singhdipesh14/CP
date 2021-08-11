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
int n, m;
vector<int> adj[mxN];
int in[mxN] = {0}, out[mxN] = {0};
vector<bool> vis(mxN, false);
vector<int> ans;

bool check()
{
	int start = 0, end = 0;
	for (int i = 0; i < n; i++)
	{
		if (in[i] - out[i] > 1 || out[i] - in[i] > 1)
		{
			return false;
		}
		else if (in[i] - out[i] == 1)
		{
			end++;
		}
		else if (out[i] - in[i] == 1)
		{
			start++;
		}
	}

	return (start == 0 && end == 0) || (start == 1 && end == 1);
}

int getStart()
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (out[i] - in[i] == 1)
			return i;
		else if (out[i] > 0)
			res = i;
	}
	return res;
}

void dfs(int v)
{
	while (out[v])
	{
		dfs(adj[v][--out[v]]);
	}
	ans.push_back(v);
}

void func()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		out[a]++;
		in[b]++;
	}
	if (check())
	{
		int st = getStart();
		dfs(st);
		if (ans.size() == m + 1)
		{
			reverse(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++)
			{
				cout << ans[i] << ' ';
			}
		}
		else
		{
			cout << "DOESN'T EXIST";
		}
	}
	else
	{
		cout << "DOESN'T EXIST";
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
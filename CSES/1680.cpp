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
vector<ar<int, 2>> adj[mxN];
int m, n, p[mxN];
int d[mxN];

void func()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb({-1, b});
	}
	priority_queue<ar<int, 2>, vector<ar<int, 2>>, greater<ar<int, 2>>> q;
	q.push({0, 0});
	memset(d, 0x3f, sizeof(d));
	d[0] = 0;
	p[0] = -1;
	while (q.size())
	{
		auto cur = q.top();
		q.pop();
		if (cur[0] > d[cur[1]])
			continue;
		for (auto i : adj[cur[1]])
		{
			if (d[i[1]] > cur[0] + i[0])
			{
				d[i[1]] = cur[0] + i[0];
				q.push({d[i[1]], i[1]});
				p[i[1]] = cur[1];
			}
		}
	}
	if (d[n - 1] >= 1e9)
	{
		cout << "IMPOSSIBLE\n";
		return;
	}
	cout << -d[n - 1] + 1 << '\n';
	vector<int> ans;
	int start = n - 1;
	while (start != -1)
	{
		ans.pb(start);
		start = p[start];
	}
	reverse(ans.begin(), ans.end());
	for (int a : ans)
	{
		cout << a + 1 << ' ';
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
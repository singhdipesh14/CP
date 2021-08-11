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

class UnionFind
{
private:
public:
	vector<int> ids;
	vector<int> size;
	int num;
	UnionFind(int v)
	{
		num = v;
		ids.resize(v);
		size.resize(v);
		for (int i = 0; i < v; i++)
		{
			ids[i] = i;
			size[i] = 1;
		}
	}
	int find(int p)
	{
		int root = p;
		while (root != ids[root])
		{
			root = ids[root];
		}
		while (p != root)
		{
			int next = ids[p];
			ids[p] = root;
			p = next;
		}
		return root;
	}
	void unify(int p, int q)
	{
		int roota = find(p);
		int rootb = find(q);
		if (roota == rootb)
			return;
		else if (roota < rootb)
		{
			ids[rootb] = roota;
			size[roota] += size[rootb];
		}
		else
		{
			ids[roota] = rootb;
			size[rootb] += size[roota];
		}

		num--;
	}
};

const int mxN = 5e2;
int m, n;

void func()
{
	priority_queue<ar<ll, 3>, vector<ar<ll, 3>>, greater<ar<ll, 3>>> q;
	cin >> n >> m;
	UnionFind u(n);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		q.push({c, a, b});
	}
	ll cost = 0;
	while (u.num != 1)
	{
		auto cur = q.top();
		q.pop();
		if (u.find(cur[1]) == u.find(cur[2]))
		{
			continue;
		}
		u.unify(cur[1], cur[2]);
		cost += cur[0];
		if (u.size[0] == n)
			break;
	}
	if (u.size[0] != n)
	{
		cout << "IMPOSSIBLE" << '\n';
		return;
	}
	cout << cost << '\n';
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
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
ll d[mxN][mxN];

void func()
{
	int n, m;
	cin >> n >> m;
	memset(d, 0x3f, sizeof(d));
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = c;
	}
	for (int i = 0; i < n; i++)
	{
		d[i][i] = 0;
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (d[i][j] > d[i][k] + d[k][j])
				{
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (d[i][k] < 1e18 && d[k][j] < 1e18 && d[k][k] < 0)
				{
					d[i][j] = 0xc0c0c0c0c0c0c0c0;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (d[i][j] < -1e18)
			{
				cout << "-INFINITY" << ' ';
			}
			else if (d[i][j] > 1e18)
			{
				cout << "INFINITY" << ' ';
			}
			else
			{
				cout << d[i][j] << ' ';
			}
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
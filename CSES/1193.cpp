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

inline bool isValid(int i, int j, int n, int m)
{
	return (i < n && j < m && i >= 0 && j >= 0);
}

void func()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> x(n, vector<char>(m));
	vector<vector<bool>> v(n, vector<bool>(m, false));
	int sx, sy, ex, ey;
	map<pair<int, int>, pair<pair<int, int>, char>> p;
	int row[] = {1, -1, 0, 0};
	int col[] = {0, 0, 1, -1};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> x[i][j];
			if (x[i][j] == 'A')
			{
				sx = i;
				sy = j;
			}
			if (x[i][j] == 'B')
			{
				ex = i;
				ey = j;
			}
		}
	}
	list<pair<int, int>> q;
	q.push_back({sx, sy});
	v[sx][sy] = true;
	while (!q.empty())
	{
		auto cur = q.front();
		int a = cur.first;
		int b = cur.second;
		q.pop_front();
		for (int r : row)
		{
			for (int c : col)
			{
				if (isValid(a + r, b + c, n, m) && (abs(r) != abs(c)) && !v[a + r][b + c] && (x[a + r][b + c] == '.' || x[a + r][b + c] == 'B'))
				{
					char move;
					if (r == 1 && c == 0)
					{
						move = 'D';
					}
					else if (r == -1 && c == 0)
					{
						move = 'U';
					}
					else if (r == 0 && c == 1)
					{
						move = 'R';
					}
					else
					{
						move = 'L';
					}

					p[make_pair(a + r, b + c)] = make_pair(cur, move);

					if (x[a + r][b + c] == 'B')
					{
						auto it = make_pair(a + r, b + c);
						string res = "";
						while (true)
						{
							res += p[it].second;
							it = p[it].first;
							if (it.first == sx && it.second == sy)
							{
								break;
							}
						}
						reverse(res.begin(), res.end());
						cout << "YES\n"
							 << res.length() << "\n"
							 << res << '\n';
						return;
					}
					v[a + r][b + c] = true;
					q.push_back(make_pair(a + r, b + c));
				}
			}
		}
	}
	cout << "NO" << '\n';
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
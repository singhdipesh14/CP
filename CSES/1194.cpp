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

int n, m;
vector<vector<int>> g;
vector<vector<int>> monster;
vector<vector<int>> moves{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
map<pair<int, int>, pair<pair<int, int>, int>> p;
vector<char> charac{'D', 'U', 'R', 'L'};

bool isValid(int i, int j, int timer)
{
	if (i < 0 or j < 0 or i >= n or j >= m)
		return false;
	if (g[i][j] <= timer)
		return false;
	return true;
}

void preprocess()
{
	queue<pair<pair<int, int>, int>> q;
	for (auto m : monster)
	{
		q.push({{m[0], m[1]}, 0});
	}
	while (q.size())
	{
		auto cur = q.front();
		q.pop();
		int timer = cur.second + 1, i = cur.first.first, j = cur.first.second;

		for (auto move : moves)
		{
			int a = i + move[0];
			int b = j + move[1];
			if (isValid(a, b, timer))
			{
				g[a][b] = timer;
				q.push({{a, b}, timer});
			}
		}
	}
}

bool isExit(int i, int j, int timer)
{
	if (!isValid(i, j, timer))
		return false;
	if ((i == 0 or i == n - 1) or (j == 0 or j == m - 1))
		return true;
	return false;
}

bool bfs(pair<int, int> start, pair<int, int> &end)
{
	queue<pair<pair<int, int>, int>> q;
	q.push({start, 0});
	while (q.size())
	{
		auto cur = q.front();
		q.pop();
		int timer = cur.second + 1, i = cur.first.first, j = cur.first.second;
		for (int k = 0; k < moves.size(); k++)
		{
			int a = i + moves[k][0];
			int b = j + moves[k][1];
			if (isExit(a, b, timer))
			{
				end.first = a;
				end.second = b;
				p[{a, b}] = {{i, j}, k};
				return true;
			}
			if (isValid(a, b, timer))
			{
				p[{a, b}] = {{i, j}, k};
				g[a][b] = timer;
				q.push({{a, b}, timer});
			}
		}
	}
	return false;
}

void func()
{
	cin >> n >> m;
	g.resize(n, vector<int>(m, 1e9));
	pair<int, int> start;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == 'A')
			{
				start.first = i;
				start.second = j;
				g[i][j] = 0;
			}
			if (c == 'M')
			{
				monster.push_back({i, j});
				g[i][j] = 0;
			}
			if (c == '#')
			{
				g[i][j] = 0;
			}
		}
	}
	if (start.first == 0 or start.second == 0 or start.first == n - 1 or start.second == m - 1)
	{
		cout << "YES\n0\n";
		return;
	}
	preprocess();
	pair<int, int> end;
	p[start] = {{-1, -1}, -1};
	if (bfs(start, end))
	{
		vector<char> ans;
		pair<pair<int, int>, int> it = p[end];
		while (mp(it.first.first, it.first.second) != start)
		{
			ans.push_back(charac[it.second]);
			it = p[mp(it.first.first, it.first.second)];
		}
		ans.push_back(charac[it.second]);
		cout << "YES\n"
			 << ans.size() << '\n';
		reverse(ans.begin(), ans.end());
		for (auto c : ans)
		{
			cout << c;
		}
		cout << '\n';
		return;
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
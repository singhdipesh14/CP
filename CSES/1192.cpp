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

void dfs(int i, int j, vector<vector<bool>> &visited)
{
	visited[i][j] = true;
	if (i > 0 && !visited[i - 1][j])
		dfs(i - 1, j, visited);
	if (i < visited.size() - 1 && !visited[i + 1][j])
		dfs(i + 1, j, visited);
	if (j < visited[i].size() - 1 && !visited[i][j + 1])
		dfs(i, j + 1, visited);
	if (j > 0 && !visited[i][j - 1])
		dfs(i, j - 1, visited);
}

void func()
{
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == '#')
			{
				visited[i][j] = true;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j])
			{
				cnt++;
				dfs(i, j, visited);
			}
		}
	}
	cout << cnt << '\n';
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
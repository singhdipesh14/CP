#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
using namespace std;

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

void dfs(vector<vector<int>> updated, vector<vector<bool>> &visited, int i, int j, int &curArea)
{
	visited[i][j] = true;
	curArea++;
	int a = 0, b = 0;
	if (i + 1 < updated.size() && !visited[i + 1][j] && updated[i + 1][j] == 1)
	{
		dfs(updated, visited, i + 1, j, curArea);
	}
	if (j + 1 < updated[0].size() && !visited[i][j + 1] && updated[i][j + 1] == 1)
	{
		dfs(updated, visited, i, j + 1, curArea);
	}
	return;
}

void func()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
		}
	}
	vector<pair<int, int>> sums(matrix[0].size(), {0, 0});
	for (int i = 0; i < matrix[0].size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			sums[i].first += matrix[j][i];
		}
		sums[i].second = i;
	}
	sort(sums.begin(), sums.end());
	vector<vector<int>> updated(matrix.size(), vector<int>(matrix[0].size()));
	for (int i = 0; i < sums.size(); i++)
	{
		int j = sums[i].second;
		for (int k = 0; k < matrix.size(); k++)
		{
			updated[k][i] = matrix[k][j];
		}
	}
	int area = 0;
	vector<vector<bool>> visited(updated.size(), vector<bool>(updated[0].size(), false));
	for (int i = 0; i < updated.size(); i++)
	{
		for (int j = 0; j < updated[i].size(); j++)
		{
			if (!visited[i][j] && updated[i][j] == 1)
			{
				int a = 0;
				dfs(updated, visited, i, j, a);
				area = max(a, area);
			}
		}
	}
	cout << area << '\n';
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
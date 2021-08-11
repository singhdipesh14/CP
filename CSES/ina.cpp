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

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

// int lcm(int a, int b){
//     int res = (a*b)/gcd(a,b);
//     return res;
// }

string func2(string s, string t)
{
	int n = s.length();
	int m = t.length();
	if (n < 2 * m - 1)
	{
		return "no secret";
	}
	for (int i = 0; i < n; i++)
	{
		int j = 0, temp = 0;
		while ((j < m) && (i + temp < n) && (t[j] == s[i + temp]))
		{
			j++;
			temp += 2;
		}
		if (j == m)
		{
			stringstream a;
			a << i + 1;
			string res = "";
			res.append(a.str());
			res.append(",");
			stringstream b;
			b << i - 1 + 2 * (m);
			res.append(b.str());
			return res;
		}
	}
	return "no secret";
}

void func()
{
	string a = "ina";
	string b = "imnsa";
	string ans = func2(b, a);
	cout << ans;
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

string func(string s, string t)
{
	int n = s.length();
	int m = t.length();
	if (n < 2 * m)
	{
		return "no secret";
	}
	for (int i = 0; i <= n; i++)
	{
		int j = 0, temp = 0;
		while ((j < m) && (i + temp < n) && (t[j] == s[i + temp]))
		{
			j++;
			temp += 2;
		}
		if (j == m)
		{
			stringstream a;
			a << i + 1;
			string res = "";
			res.append(a.str());
			res.append(",");
			stringstream b;
			b << i - 1 + 2 * (m - 1);
			res.append(b.str());
			return res;
		}
	}
	return "no secret";
}
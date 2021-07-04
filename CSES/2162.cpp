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

void func()
{
	int n;
	cin >> n;
	vector<int> v(n);
	iota(v.begin(), v.end(), 1);
	while (v.size() > 1)
	{
		vector<int> s;
		for (int i = 0; i < v.size(); i++)
		{
			if (i % 2 == 1)
			{
				cout << v[i] << ' ';
			}
			else
			{
				s.pb(v[i]);
			}
		}
		if (v.size() & 1)
		{
			int start = s.back();
			s.pop_back();
			v.clear();
			v.pb(start);
			for (int a : s)
			{
				v.pb(a);
			}
		}
		else
		{
			v = s;
		}
	}
	cout << v[0] << '\n';
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
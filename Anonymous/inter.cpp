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

int partition(vector<int> &v, int first, int last)
{
	int pivot = v[last];
	int i = first;
	for (int j = first; j < last; j++)
	{
		if (v[j] < pivot)
		{
			swap(v[i], v[j]);
			i++;
		}
	}
	swap(v[i], v[last]);
	return i;
}

void sort(vector<int> &v, int first, int last)
{
	if (first >= last)
		return;
	int p = partition(v, first, last);
	sort(v, first, p - 1);
	sort(v, p + 1, last);
}

void func()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int &i : v)
	{
		cin >> i;
	}
	sort(v, 0, n - 1);
	for (int i : v)
	{
		cout << i << ' ';
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
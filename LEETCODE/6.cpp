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

// int isSubstring(string s1, string s2)
// {
//     int M = s1.length();
//     int N = s2.length();

//     /* A loop to slide pat[] one by one */
//     for (int i = 0; i <= N - M; i++) {
//         int j;

//         /* For current index i, check for
//  pattern match */
//         for (j = 0; j < M; j++)
//             if (s2[i + j] != s1[j])
//                 break;

//         if (j == M)
//             return i;
//     }

//     return -1;
// }

// int gcd(int a, int b){
//     if(b==0){
//         return a;
//     }
//     return gcd(b, a%b);
// }

// // int lcm(int a, int b){
// //     int res = (a*b)/gcd(a,b);
// //     return res;
// // }

// void makeQuery(ll n){
//     cout << "? " << n << endl;
// }

// ll solve(ll n, ll query, ll min, ll max, ll cur, ll prev, ll flag){
//     if(min > max){
//         return min;
//     }
//     if(max < min){
//         return max;
//     }
//     makeQuery(query);
//     cin >> flag;
//     if(flag == 0){
//         min = abs(cur - prev) + 1;
//         prev = cur;
//         if(cur + min > n){
//             makeQuery(1);
//             ll unused;
//             cin >> unused;
//             cur = 1;
//             prev = 1;
//         }
//         return solve(n, cur+min, min, max, cur + min, prev, flag);
//     }
//     else if(flag == 1){
//         max = abs(cur - prev) - 1;
//         prev = cur;
//         if(cur - max < 1){
//             makeQuery(n);
//             ll unused;
//             cin >> unused;
//             cur = n;
//             prev = n;
//         }
//         return solve(n, cur-max, min, max, cur -max, prev, flag);
//     }
// }

//const ll max_num = 100001;

void func()
{
	int numRows;
	string s;
	cin >> s >> numRows;
	if (s.length() <= numRows || numRows == 1 || s.length() == 1)
	{
		cout << s;
		return;
	}
	else if (numRows < 3)
	{
		for (int i = 0; i < s.length(); i += 2)
		{
			cout << s[i];
		}
		for (int i = 1; i < s.length(); i += 2)
		{
			cout << s[i];
		}
		return;
	}
	vector<string> v(numRows, "");
	int j = 0;
	bool col = true;
	for (int i = 0; i < s.length(); i++)
	{
		v[j].push_back(s[i]);
		if (col && j + 1 < numRows)
		{
			j++;
		}
		else if (col && j + 1 == numRows)
		{
			col = false;
			j = numRows - 2;
		}
		else if (!col && j - 1 > 0)
		{
			j--;
		}
		else if (!col && j - 1 == 0)
		{
			col = true;
			j = 0;
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
	string res;
	for (int i = 0; i < v.size(); i++)
	{
		res.append(v[i]);
	}
	cout << res << '\n';
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
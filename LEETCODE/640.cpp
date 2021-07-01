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
	string equation;
	getline(cin, equation);
	string lhs, rhs;
	int i = 0;
	while (equation[i] != '=')
	{
		lhs.push_back(equation[i]);
		i++;
	}
	rhs.insert(0, equation, i + 1, string::npos);
	int rhsx = 0, lhsx = 0, rhsc = 0, lhsc = 0;
	for (int i = 0; i < lhs.length(); i++)
	{
		if (lhs[i] == 'x')
		{
			continue;
		}
		else if (lhs[i] == '+')
		{
			i++;
			if (lhs[i] <= 57 && lhs[i] >= 48 && i + 1 < lhs.length() && lhs[i + 1] == 'x')
			{
				lhsx += (int)(lhs[i] - '0');
				continue;
			}
			else if (lhs[i] <= 57 && lhs[i] >= 48)
			{
				lhsc += (int)(lhs[i] - '0');
			}
		}
		else if (lhs[i] == '-')
		{
			i++;
			if (lhs[i] <= 57 && lhs[i] >= 48 && i + 1 < lhs.length() && lhs[i + 1] == 'x')
			{
				lhsx += -1 * (int)(lhs[i] - '0');
				continue;
			}
			else if (lhs[i] <= 57 && lhs[i] >= 48)
			{
				lhsc += -1 * (int)(lhs[i] - '0');
			}
		}
		else
		{
			if (lhs[i] <= 57 && lhs[i] >= 48 && i + 1 < lhs.length() && lhs[i + 1] == 'x')
			{
				lhsx += (int)(lhs[i] - '0');
				continue;
			}
			else if (lhs[i] <= 57 && lhs[i] >= 48)
			{
				lhsc += (int)(lhs[i] - '0');
			}
		}
	}
	cout << lhsc << ' ' << lhsx << '\n';
	cout << lhs << " = " << rhs;
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
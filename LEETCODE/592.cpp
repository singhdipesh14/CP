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

int gcd(int m, int n)
{
	if (n == 0)
	{
		return m;
	}
	return gcd(n, m % n);
}

void func()
{
	string expression;
	getline(cin, expression);
	vector<pair<int, int>> fraction;
	for (int i = 0; i < expression.length();)
	{
		if (expression[i] <= 57 && expression[i] >= 48)
		{
			int num = (int)(expression[i] - '0');
			i++;
			if (expression[i] <= 57 && expression[i] >= 48)
			{
				num = num * 10 + (int)(expression[i] - '0');
			}
			else
			{
				i--;
			}
			i += 2;
			int den = (int)(expression[i] - '0');
			i++;
			if (expression[i] <= 57 && expression[i] >= 48)
			{
				den = den * 10 + (int)(expression[i] - '0');
			}
			else
			{
				i--;
			}
			fraction.push_back(make_pair(num, den));
		}
		else if (expression[i] == '+' || expression[i] == '-')
		{
			int num, den;
			if (expression[i] == '-')
			{
				i++;
				num = -1 * (int)(expression[i] - '0');
				i++;
				if (expression[i] <= 57 && expression[i] >= 48)
				{
					num = num * 10 + (int)(expression[i] - '0');
				}
				else
				{
					i--;
				}
				i += 2;
				den = (int)(expression[i] - '0');
				i++;
				if (expression[i] <= 57 && expression[i] >= 48)
				{
					den = den * 10 + (int)(expression[i] - '0');
				}
				else
				{
					i--;
				}
			}
			else
			{
				i++;
				num = (int)(expression[i] - '0');
				i++;
				if (expression[i] <= 57 && expression[i] >= 48)
				{
					num = num * 10 + (int)(expression[i] - '0');
				}
				else
				{
					i--;
				}
				i += 2;
				den = (int)(expression[i] - '0');
				i++;
				if (expression[i] <= 57 && expression[i] >= 48)
				{
					den = den * 10 + (int)(expression[i] - '0');
				}
				else
				{
					i--;
				}
			}
			fraction.push_back(make_pair(num, den));
		}
		i++;
	}
	int num = 0, den = 1;
	while (!fraction.empty())
	{
		pair<int, int> temp = fraction.back();
		fraction.pop_back();
		int a = temp.first * den;
		int b = temp.second * num;
		int c = temp.second * den;
		num = a + b;
		den = c;
	}
	if (num == 0)
	{
		den = 1;
	}
	int gc;
	if (num < 0)
	{
		gc = gcd(-1 * num, den);
	}
	else
	{
		gc = gcd(num, den);
	}
	num = num / gc;
	den = den / gc;
	ostringstream str1;
	string s;
	str1 << num << "/" << den;
	s.append(str1.str());
	cout << "Answer is : " << s << endl;
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
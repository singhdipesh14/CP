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

ll fact(ll n)
{
	ll ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans *= i;
	}
	return ans;
}

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
void swap(string arr, int i, int j)
{
	char temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void reverse(string cur, int start, int end)
{
	while (start < end)
	{
		swap(cur, start, end);
		start++;
		end--;
	}
}
int findCeil(string cur, int first, int l, int h)
{
	int ceilIndex = l;
	for (int i = l + 1; i <= h; i++)
		if (cur[i] > first && cur[i] < cur[ceilIndex])
			ceilIndex = i;

	return ceilIndex;
}

string next(string cur, int num)
{
	int i;
	for (i = num - 2; i >= 0; --i)
		if (cur[i] < cur[i + 1])
			break;
	int ceilIndex = findCeil(cur, cur[i], i + 1, num - 1);
	swap(cur, i, ceilIndex);
	reverse(cur, i + 1, num - 1);
	return cur;
}

void func()
{
	string s;
	getline(cin, s);
	sort(s.begin(), s.end());
	vector<string> v;
	do
	{
		v.pb(s);
	} while (next_permutation(s.begin(), s.end()));
	cout << v.size() << '\n';
	for (string c : v)
	{
		cout << c << '\n';
	}
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
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

class Trie
{
public:
	char data;
	Trie *child[26];
	int words;
	Trie(char c)
	{
		for (int i = 0; i < 26; i++)
		{
			child[i] = nullptr;
		}
		words = 0;
		data = c;
	}
};

class WordDictionary
{
private:
	Trie *trie = new Trie('/');
	void insert(string word)
	{
		Trie *node = trie;
		for (char c : word)
		{
			if (!node->child[c - 'a'])
			{
				node->child[c - 'a'] = new Trie(c);
			}
			node = node->child[c - 'a'];
		}
		(node->words)++;
	}
	bool search(string word, int pos, Trie *cur)
	{
		if (word[pos] == '.')
		{
			bool res = false;
			for (int i = 0; i < 26; i++)
			{
				if (pos == word.size() - 1 && cur->child[i])
				{
					res |= cur->child[i]->words > 0 ? true : false;
				}
				else if (cur->child[i] && search(word, pos + 1, cur->child[i]))
				{
					return true;
				}
			}
			return res;
		}
		else if (cur->child[word[pos] - 'a'])
		{
			if (pos == word.size() - 1)
			{
				return cur->child[word[pos] - 'a']->words > 0 ? true : false;
			}
			return search(word, pos + 1, cur->child[word[pos] - 'a']);
		}
		return false;
	}

public:
	/** Initialize your data structure here. */
	WordDictionary()
	{
	}

	void addWord(string word)
	{
		insert(word);
	}

	bool search(string word)
	{
		return search(word, 0, trie);
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

void func()
{
	WordDictionary *obj = new WordDictionary();
	string s = "hello";
	string d = "hell.";
	obj->addWord(s);
	bool res = obj->search(d);
	if (res)
	{
		cout << "Found" << '\n';
		return;
	}
	cout << "Not Found" << '\n';
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
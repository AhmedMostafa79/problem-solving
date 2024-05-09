#include<iostream>
#include<algorithm>
using namespace std;
int n, i, j, k, t[500];
string s, q;
int main() {
	cin >> n >> k >> s;
	q = s;
	sort(q.begin(), q.end());
	for (int i = 0; i < k; i++)
		t[q[i]]++;
	for (int i = 0; i < n; i++)
		if (t[s[i]])
			t[s[i]]--; 
		else cout << s[i];
}
#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, k, p;
	cin >> n >> k >> p;
	int a[n];
	for (int i = 0; i < n; i++) { cin >> a[i]; }

	queue<int> q1, q2;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) { q2.push(a[i]); }
		else { q1.push(a[i]); }
	}

	vector<int> v[k];

	if (q1.size() < k - p) { cout << "NO" << endl; return 0; }

	for (int i = 0; i < k - p; i++) {
		v[i].push_back(q1.front()); q1.pop();
	}

	if (q1.size() % 2 == 1) { cout << "NO" << endl; return 0; }
	int cnt = k - p;

	while (!q1.empty()) {
		if (cnt == k) { cnt = 0; }
		v[cnt].push_back(q1.front()); q1.pop();
		v[cnt].push_back(q1.front()); q1.pop();
		cnt++;
	}

	while (!q2.empty()) {
		if (cnt == k) { cnt = 0; }
		v[cnt].push_back(q2.front()); q2.pop();
		cnt++;
	}

	for (int i = 0; i < k; i++) {
		if (v[i].size() == 0) { cout << "NO" << endl; return 0; }
	}


	cout << "YES" << endl;
	for (int i = 0; i < k; i++) {
		cout << v[i].size() << " ";
		for (int j = 0; j < v[i].size(); j++) { cout << v[i][j]; if (j != v[i].size()) { cout << " "; } }
		cout << endl;
	}

	return 0;

}

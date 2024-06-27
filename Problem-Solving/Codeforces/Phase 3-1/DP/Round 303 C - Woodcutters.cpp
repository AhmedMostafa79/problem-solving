#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;
#define  ll long long
#define  range(v) ((v).begin()),((v).end())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)


int main() {
	int size;
	cin >> size;
	vector<pair<int, int>>v(size);
	for (int i = 0; i < size; i++)cin >> v[i].first >> v[i].second;
	//v[size+1].first = INT_MAX,v[size].first=INT_MAX;
	int  r, l = v[0].first;//(v[i].first-v[i].second,v[i].first)
	int res = 1;
	if (size >= 2)res++;
	for (int i = 1; i < size - 1; i++) {
		r = v[i + 1].first;
		int x = v[i].first - v[i].second;
		int y = v[i].first + v[i].second;
		if (x > l && x < r)l = v[i].first, res++;
		else if (y > l && y < r)l = y, res++;
		else
			l = v[i].first;
	}
	cout << res;

}
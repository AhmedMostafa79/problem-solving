#include<bits/stdc++.h>
int a[100005], b[100005], n, s, i, k;
auto c(int k) {
	for (i = 0; i < n; ++i)b[i] = a[i] + i * k + k;
	std::sort(b, b + n);
	auto r = 0ll;
	for (i = 0; i < k; ++i)r += b[i];
	return r;
}
int main() {
	scanf("%d%d", &n, &s);
	for (i = 0; i < n; ++i)scanf("%d", a + i);
	for (k = 1; k <= n; ++k)if (c(k) > s)break;
	printf("%d %lld ", k - 1, c(k - 1));
}
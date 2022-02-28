#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t; cin.tie(nullptr)->sync_with_stdio(false), cin >> t;
	while (t--) {
		string S; 
		cin >> S;
		int N = S.size();
		__int128 X = 0;
		for (int i = 0; i < N; ++i)
			if (X <<= 1, S[i] == '1')
				X |= 1;
		string ans;
		if (X == 0)
			ans = "0";
		else {
			while (X > 0)
				ans += char('0'+X%6), X /= 6;
			reverse(ans.begin(),ans.end()); }
		cout << ans << '\n'; }
	return 0; }
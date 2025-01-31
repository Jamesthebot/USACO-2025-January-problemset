/*

2 3 4 1 5 6 7 1

This will be 3 distinct moos, but anything in between (accumulated set nums minus itself) 
needs to be added on to cum[ar[i]]

2 3 4 1 5 6 7 1 1 

This would be 6, plus the 5 6 7 in between. So no reset cum, keep on accumulating

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxN = 1e6 + 1;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;

	set<ll> uni;
	vector<ll> ar(N);
    vector<ll> ans_v(maxN, 0), seen(maxN, 0), cum(maxN, 0);

	for(int i = 0; i < N; i++) {
		cin >> ar[i];
	}

	ll ans = 0;

	for(int i = 0; i < N; i++) {
        cum[ar[i]]++;
		uni.insert(ar[i]);

		if(cum[ar[i]] >= 2) {
			ans_v[ar[i]] = seen[ar[i]];
		}

        seen[ar[i]] = uni.size() - 1;
	}

    for(ll num : ans_v) {
        ans += num;
    }

	cout << ans << '\n';
}

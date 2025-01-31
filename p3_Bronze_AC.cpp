#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> a(N), b(N);

    int same = 0;

    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++) {
        cin >> b[i];
        if(a[i] == b[i]) {
            same++;
        }
    }
    
    vector<int> ans(N + 1, 0);

    for(int i = 0; i < N; i++) {
        int cur = same;
        int l = i, r = i;

        while(l >= 0 && r < N) {
            cur -= (a[l] == b[l]) + (a[r] == b[r]);
            cur += (a[r] == b[l]) + (a[l] == b[r]);
            ans[cur]++;
            l--;
            r++;
        }

        l = i, r = i + 1;
        cur = same;
        while(l >= 0 && r < N) {
            cur -= (a[l] == b[l]) + (a[r] == b[r]);
            cur += (a[r] == b[l]) + (a[l] == b[r]);
            ans[cur]++;
            l--;
            r++;
        }
    }

    for(int i = 0; i <= N; i++) {
        cout << ans[i] << '\n';
    }
}

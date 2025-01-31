#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 1;

void solve() {
	int N, A, B;
	cin >> N >> A >> B;

	bool visit[maxN][maxN] = {0};
	vector<vector<char>> ar(N, vector<char>(N));

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> ar[i][j];
		}
	}

	int ans = 0;

    // special for 0 0
    if(A == 0 && B == 0) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(ar[i][j] == 'B' || ar[i][j] == 'G') ans++;
			}
		}
		cout << ans << '\n';
		return;
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
            // -1 if black isn't visited before
			int ci = i + B, cj = j + A;

            if(ar[i][j] == 'B' && !visit[i][j]) {
                cout << "-1" << '\n';
                return;
            }

			if(ci < 0 || ci >= N || cj < 0 || cj >= N) {
                if(ar[i][j] == 'B' || (ar[i][j] == 'G' && !visit[i][j])) ans++;
            }
            else if(ar[i][j] == 'G' && !visit[i][j]) {
				visit[ci][cj] = 1;
				ans++;
			}
            else if(ar[i][j] == 'G' && visit[i][j]) {	
				if(ar[ci][cj] == 'B') {
					visit[ci][cj] = 1;
					ans++;
				}
            }
            else if(ar[i][j] == 'B') {
                ans++;
                if(ar[ci][cj] == 'B' || ar[ci][cj] == 'G') {
                    visit[ci][cj] = 1;
                }
			}
		}
	}

    cout << ans << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;

	while(t--) solve();
}

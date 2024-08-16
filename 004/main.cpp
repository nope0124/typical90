#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)
#define ALL(V)  (V).begin(), (V).end()
ll dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
ll dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ll H, W; cin >> H >> W;
    vector<vector<ll>> V(H, vector<ll>(W));
    rep (i, H) {
        rep (j, W) {
            cin >> V[i][j];
        }
    }
    vector<ll> rowSum(H), columnSum(W);
    rep (i, H) {
        rep (j, W) {
            rowSum[i] += V[i][j];
        }
    }
    rep (j, W) {
        rep (i, H) {
            columnSum[j] += V[i][j];
        }
    }
    vector<vector<ll>> ans(H, vector<ll>(W));
    rep (i, H) {
        rep (j, W) {
            ans[i][j] = rowSum[i] + columnSum[j] - V[i][j];
        }
    }
    rep (i, H) {
        rep (j, W) {
            if (j == 0) cout << ans[i][j];
            else cout << ' ' << ans[i][j];
        }
        cout << "\n";
    }
    return 0;
}
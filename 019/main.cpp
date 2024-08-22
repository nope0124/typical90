#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)
#define ALL(V)  (V).begin(), (V).end()
ll dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
ll dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ll N; cin >> N;
    N *= 2;
    vector<ll> V(N);
    rep (i, N) cin >> V[i];
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 1e16));

    auto rec = [&](auto f, ll l, ll r) -> ll { // [l, r)
        assert(r >= l);
        assert((r - l) % 2 == 0);
        if (r - l == 0) {
            dp[l][r] = 0;
            return dp[l][r];
        }
        if (r - l == 2) {
            dp[l][r] = abs(V[l] - V[r - 1]);
            return dp[l][r];
        }
        if (dp[l][r] != 1e16) return dp[l][r];
        
        for (ll i = l + 2; i < r; i += 2) {
            dp[l][r] = min(dp[l][r], f(f, l, i) + f(f, i, r));
        }
        if (r - 1 >= 0 && l + 1 <= r - 1) dp[l][r] = min(dp[l][r], abs(V[l] - V[r - 1]) + f(f, l + 1, r - 1));
        return dp[l][r];
    };

    rec(rec, 0, N);
    // rep (i, N + 1) {
    //     rep (j, N + 1) {
    //         if (dp[i][j] == 1e16) cout << "#" << ' ';
    //         else cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[0][N] << endl;
    return 0;
}
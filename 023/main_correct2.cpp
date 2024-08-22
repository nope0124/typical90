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
    ll H, W; cin >> H >> W;
    if (H >= 10 || W >= 10) return 0;
    vector<string> board(H);
    rep (i, H) cin >> board[i];
    vector<vector<ll>> dp(H, vector<ll>(1LL<<W));
    rep (bit, 1LL<<W) {
        bool flag = true;
        rep (i, W) {
            if (bit & (1LL<<i)) {
                if (board[0][i] == '#') flag = false;
            }
        }
        rep (i, W - 1) {
            if ((bit & (1LL<<i)) && (bit & (1LL<<(i+1)))) flag = false;
        }
        if (flag) dp[0][bit] = 1;
        else dp[0][bit] = 0;
    }
    rep (_, H - 1) {
        rep (bit1, 1LL<<W) {
            rep (bit2, 1LL<<W) {
                bool flag = true;
                rep (i, W) {
                    if (bit1 & (1LL<<i)) {
                        if (board[_][i] == '#') flag = false;
                    }
                }
                rep (i, W) {
                    if (bit2 & (1LL<<i)) {
                        if (board[_ + 1][i] == '#') flag = false;
                    }
                }
                rep (i, W - 1) {
                    if ((bit1 & (1LL<<i)) && (bit1 & (1LL<<(i+1)))) flag = false;
                }
                rep (i, W - 1) {
                    if ((bit2 & (1LL<<i)) && (bit2 & (1LL<<(i+1)))) flag = false;
                }
                vector<vector<ll>> tmp(2, vector<ll>(W));
                rep (i, W) if (bit1 & (1LL<<i)) tmp[0][i] = 1;
                rep (i, W) if (bit2 & (1LL<<i)) tmp[1][i] = 1;
                rep (i, W) {
                    rep (k, 8) {
                        ll nx = i + dx[k];
                        ll ny = 0 + dy[k];
                        if (nx < 0 || nx >= W || ny < 0 || ny >= 2) continue;
                        if (tmp[0][i] == 1 && tmp[ny][nx] == 1) flag = false;
                    }
                }
                if (flag) {
                    dp[_ + 1][bit2] += dp[_][bit1];
                    dp[_ + 1][bit2] %= MOD;
                } else {

                }
            }
        }
    }
    ll ans = 0;
    rep (i, 1LL<<W) {
        ans += dp[H - 1][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
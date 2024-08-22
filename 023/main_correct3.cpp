#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)
#define ALL(V)  (V).begin(), (V).end()
ll dx[5] = {-1, 0, 1, -1, 1};
ll dy[5] = {-1, -1, -1, 0, 0};

int main() {
    ll H, W; cin >> H >> W;
    if (H >= 18 || W >= 18) return 0;
    vector<string> board(H);
    rep (i, H) cin >> board[i];
    vector<vector<ll>> dp(H*W + 1, vector<ll>(1LL<<(W + 1), 0));
    // vector<vector<bool>> V(H, vector<bool>(W));
    dp[0][0] = 1;
    int x = -1;
    int y = -1;
    int nx = -1;
    int ny = -1;
    int nnx = -1;
    int nny = -1;
    bool flag = true;
    rep (i, H*W) {
        x = i % W;
        y = i / W;
        rep (bit, 1LL<<(W + 1)) {
            if (board[y][x] == '#') {
                dp[i + 1][(bit >> 1)] += dp[i][bit];
                dp[i + 1][(bit >> 1)] %= MOD;
                continue;
            }
            flag = true;

            rep (j, W + 1) {
                nx = ((i - j - 1) + W) % W;
                ny = (i - j - 1) / W;
                if (i - j - 1 < 0) ny = -1;
                if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
                if (bit & (1LL<<(W - j))) {
                    rep (k, 5) {
                        nnx = x + dx[k];
                        nny = y + dy[k];
                        if (nnx == nx && nny == ny) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }
            }
            // rep (k, 5) {
            //     nx = x + dx[k];
            //     ny = y + dy[k];
            //     if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            //     if (V[ny][nx]) flag = false;
            // }
            // if (i == 1) {
            //     cout << bit << endl;
            //     rep (k, H) {
            //         rep (j, W) {
            //             cout << V[k][j] << ' ';
            //         }
            //         cout << endl;
            //     }
            //     cout << endl;
            // }
            if (flag && board[y][x] == '.') {
                dp[i + 1][(bit >> 1) + (1LL<<(W))] += dp[i][bit];
                dp[i + 1][(bit >> 1) + (1LL<<(W))] %= MOD;
            }
            dp[i + 1][(bit >> 1)] += dp[i][bit];
            dp[i + 1][(bit >> 1)] %= MOD;
        }
        // 配る
        // →01 or →0
    }
    ll ans = 0;
    rep (i, (1LL<<(W+1))) {
        // cout << i << ' ' << dp[H*W][i] << endl;
        ans += dp[H*W][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
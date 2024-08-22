#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)
#define ALL(V)  (V).begin(), (V).end()
ll dx[4] = {-1, 0, 1, -1};
ll dy[4] = {-1, -1, -1, 0};


ll H, W;
vector<ll> V1, V2;

void dfs(ll num, ll depth, ll id) {
    if (depth == 0) {
        if (id == 0) V1.push_back(num);
        if (id == 1) V2.push_back(num);
        return;
    }
    if (num % 2 == 0) {
        dfs(num*2, depth - 1, id);
        dfs(num*2+1, depth - 1, id);
    } else {
        dfs(num*2, depth - 1, id);
    }
}

pll fib(ll x, ll y) {
    ll up, down;
    if (x == 0) {
        up = 1;
        down = W;
    } else {
        up = (W - x + 1);
        down = W + 1 - up;
    }
    dfs(0, up, 0);
    dfs(0, down, 1);
    return pll(up, down);
    // rep (i, V1.size()) {
    //     rep (j, V2.size()) {
    //         V3.push_back((V2[j] << up) + V1[i]);
    //     }
    // }
}

int main() {
    cin >> H >> W;
    ll di[4] = {0, 1, 2, W};
    vector<string> board(H);
    rep (i, H) cin >> board[i];
    vector<vector<ll>> dp(2, vector<ll>(1LL<<(W + 1), 0));
    dp[0][0] = 1;
    int x = -1;
    int y = -1;
    int nx = -1;
    int ny = -1;
    int nnx = -1;
    int nny = -1;
    int prv = 0;
    int nxt = 1;
    ll bit = -1;
    int up = -1;
    int down = -1;
    bool flag = true;
    rep (i, H*W) {
        prv = i % 2;
        nxt = (i + 1) % 2;
        // rep (j, 1LL<<(W + 1)) dp[nxt][j] = 0;
        V1.clear();
        V2.clear();
        x = i % W;
        y = i / W;
        pll p = fib(x, y);
        up = p.first;
        down = p.second;

        rep (ii, V1.size()) {
            rep (jj, V2.size()) {
                bit = (V2[jj] << up) + V1[ii];
                if (board[y][x] == '#') {
                    dp[nxt][(bit >> 1)] += dp[prv][bit];
                    dp[nxt][(bit >> 1)] %= MOD;
                    dp[prv][bit] = 0;
                    continue;
                }
                flag = true;
                rep (k, 4) {
                    // step1きになる座標をピックアップ
                    nnx = x + dx[k];
                    nny = y + dy[k];
                    if (nnx < 0 || nnx >= W || nny < 0 || nny >= H) continue;
                    
                    // step2その座標をiにする
                    
                    // step3iがbitに含まれているかどうか
                    if (bit & (1LL<<di[k])) {
                        dp[nxt][(bit >> 1)] += dp[prv][bit];
                        dp[nxt][(bit >> 1)] %= MOD;
                        dp[prv][bit] = 0;
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    continue;
                }

                if (flag && board[y][x] == '.') {
                    dp[nxt][(bit >> 1) + (1LL<<(W))] += dp[prv][bit];
                    dp[nxt][(bit >> 1) + (1LL<<(W))] %= MOD;
                }
                dp[nxt][(bit >> 1)] += dp[prv][bit];
                dp[nxt][(bit >> 1)] %= MOD;
                dp[prv][bit] = 0;
            }
            // 配る
            // →01 or →0
        }
    }
    ll ans = 0;
    rep (i, (1LL<<(W+1))) {
        // cout << i << ' ' << dp[H*W][i] << endl;
        ans += dp[nxt][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
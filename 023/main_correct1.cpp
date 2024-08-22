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
    ll ans = 0;
    vector<string> board(H);
    if (H >= 5 || W >= 5) return 0;
    rep (i, H) cin >> board[i];
    rep (bit, (1LL<<(H*W))) {
        vector<vector<ll> > tmpBoard(H, vector<ll>(W, 0));
        rep (i, H*W) {
            if (bit & (1LL<<i)) {
                ll ny = i / W;
                ll nx = i % W;
                tmpBoard[ny][nx] = 1;
            }
        }
        bool flag = true;
        rep (i, H) {
            rep (j, W) {
                if (tmpBoard[i][j] == 1 && board[i][j] == '#') flag = false;
            }
        }
        rep (i, H) {
            rep (j, W) {
                if (tmpBoard[i][j] == 1) {
                    rep (k, 8) {
                        ll ny = i + dy[k];
                        ll nx = j + dx[k];
                        if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
                        if (tmpBoard[ny][nx] == 1) flag = false;
                    }
                }
            }
        }
        if (flag) ans++;
    }
    cout << ans % MOD << endl;
    return 0;
}
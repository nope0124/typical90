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
    vector<vector<ll>> board(1010, vector<ll>(1010, 0));
    rep (i, N) {
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        board[y1][x1]++;
        board[y1][x2]--;
        board[y2][x1]--;
        board[y2][x2]++;
    }
    rep (i, 1009) {
        rep (j, 1010) {
            board[i + 1][j] += board[i][j];
        }
    }
    rep (j, 1009) {
        rep (i, 1010) {
            board[i][j + 1] += board[i][j];
        }
    }
    vector<ll> cnt(N + 1, 0);
    rep (i, 1010) {
        rep (j, 1010) {
            cnt[board[i][j]]++;
        }
    }
    rep (i, N) {
        cout << cnt[i + 1] << endl;
    }
    return 0;
}
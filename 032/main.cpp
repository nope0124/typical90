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
    vector<vector<ll>> A(N, vector<ll>(N));
    rep (i, N) {
        rep (j, N) cin >> A[i][j];
    }
    ll M; cin >> M;
    vector<pll> P(M);
    rep (i, M) cin >> P[i].first >> P[i].second, P[i].first--, P[i].second--;
    vector<ll> per(N);
    iota(ALL(per), 0);
    ll ans = 1e16;
    do {
        ll tmp = 0;
        bool flag = true;
        rep (i, N - 1) {
            if (!flag) break;
            rep (j, M) {
                if (min(per[i], per[i + 1]) == P[j].first && max(per[i], per[i + 1]) == P[j].second) {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag) continue;
        rep (i, N) {
            tmp += A[per[i]][i];
        }
        ans = min(ans, tmp);
    } while (next_permutation(ALL(per)));
    if (ans == 1e16) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
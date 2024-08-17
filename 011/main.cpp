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
    vector<pair<ll, pll>> V(N);
    ll D = 0;
    rep (i, N) {
        ll d, c, s; cin >> d >> c >> s;
        V[i].first = d;
        V[i].second.first = c;
        V[i].second.second = s;
        D = max(D, d);
    }
    sort(ALL(V));
    vector<vector<ll>> dp(N + 1, vector<ll>(D + 1, -1e16));

    dp[0][0] = 0;
    rep (i, N) {
        ll d = V[i].first;
        ll c = V[i].second.first;
        ll s = V[i].second.second;
        rep (j, d + 1) {
            if (j - c >= 0) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - c] + s);
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    ll ans = 0;
    rep (i, D + 1) ans = max(ans, dp[N][i]);
    cout << ans << endl;
    return 0;
}
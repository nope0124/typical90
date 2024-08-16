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
    string S; cin >> S;
    string base = "atcoder";
    vector<vector<ll>> dp(N + 1, vector<ll>(8));
    dp[0][0] = 1;
    rep (i, N) {
        rep (j, 8) dp[i + 1][j] = dp[i][j];
        rep (j, 7) {
            if (S[i] == base[j]) {
                dp[i + 1][j + 1] += dp[i][j];
                dp[i + 1][j + 1] %= MOD;
            }
        }
    }
    cout << dp[N][7] << endl;
    return 0;
}
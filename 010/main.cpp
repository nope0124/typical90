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
    vector<vector<ll>> V(2, vector<ll>(N + 1));
    rep (i, N) {
        ll a; cin >> a; a--;
        ll b; cin >> b;
        V[a][i + 1] = b;
    }
    rep (i, 2) {
        rep (j, N + 1) {
            if (j == 0) continue;
            V[i][j] += V[i][j - 1];
        }
    }
    ll Q; cin >> Q;
    rep (i, Q) {
        ll l, r; cin >> l >> r;
        cout << V[0][r] - V[0][l - 1] << ' ' << V[1][r] - V[1][l - 1] << endl;
    }
    return 0;
}
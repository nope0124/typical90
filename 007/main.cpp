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
    vector<ll> V(N);
    rep (i, N) cin >> V[i];
    sort(ALL(V));
    ll Q; cin >> Q;
    rep (i, Q) {
        ll a; cin >> a;
        ll right = lower_bound(ALL(V), a) - V.begin();
        ll left = right - 1;
        ll ans = INT_MAX;
        if (left >= 0) ans = min(ans, abs(V[left] - a));
        if (right < N) ans = min(ans, abs(V[right] - a));
        cout << ans << endl;
    }
    return 0;
}
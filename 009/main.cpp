#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)
#define ALL(V)  (V).begin(), (V).end()
#define PI 3.14159265358979
ll dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
ll dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};


ld dosuu(ld ans) {
    return (ld)ans / PI * 180;
}

int main() {
    ll N; cin >> N;
    vector<pll> V(N);
    rep (i, N) {
        cin >> V[i].first >> V[i].second;
    }
    ld ans = 0;
    rep (i, N) {
        vector<pll> newV(N);
        rep (j, N) {
            newV[j].first = V[j].first - V[i].first;
            newV[j].second = V[j].second - V[i].second;
        }
        vector<ld> P;
        rep (j, N) {
            if (i == j) continue;
            ld a = atan2(newV[j].first, newV[j].second) + PI;
            P.push_back(a);
            // cout << j << ' ' << P[j] << endl;
            // cout << j << ' ' << dosuu(P[j]) << endl;
        }
        sort(ALL(P));
        rep (j, N - 1) {
            ld target = P[j] + PI;
            if (target >= 2 * PI) target -= 2 * PI;
            ll left = lower_bound(ALL(P), target) - P.begin() - 1;
            ll right = left + 1;
            if (left >= 0) {
                ans = max(ans, min(abs(P[left] - P[j]), 2 * PI - abs(P[left] - P[j])));
                // cout << "MIN1 " << min(abs(P[left] - P[j]), 2 * PI - abs(P[left] - P[j])) << endl;
            }
            if (right < N - 1) {
                ans = max(ans, min(abs(P[right] - P[j]), 2 * PI - abs(P[right] - P[j])));
                // cout << "MIN2 " << min(abs(P[right] - P[j]), 2 * PI - abs(P[right] - P[j])) << endl;
            }
            // cout << ans << endl;
            // cout << fixed << setprecision(10) << dosuu(ans) << endl;
        }
    }
    cout << fixed << setprecision(10) << dosuu(ans) << endl;
    return 0;
}
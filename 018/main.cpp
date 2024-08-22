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

int main() {
    ll T, tL, X, Y; cin >> T >> tL >> X >> Y;
    ll Q; cin >> Q;
    ld L = tL;
    rep (i, Q) {
        ll e; cin >> e;
        ld ee = e;
        ld ny1 = - sin((ld)ee / T * 2 * PI) * L / 2;
        ld nz1 =   cos((ld)ee / T * 2 * PI) * L / 2 - L / 2;
        ld ny2 = ny1;
        ld nz2 = 0;
        ld a = nz1;
        ld b = sqrt((nz1 * nz1) + (X * X) + (ny1 - Y) * (ny1 - Y));
        ld c = sqrt((nz2 * nz2) + (X * X) + (ny1 - Y) * (ny1 - Y));
        ld cosA = (b * b + c * c - a * a) / (2 * b * c);
        ld ans = acos(cosA) * 180 / PI;
        cout << fixed << setprecision(12) << ans << endl;
    }
    return 0;
}
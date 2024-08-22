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
    ll a, b, c; cin >> a >> b >> c;
    ll ans = 1;
    rep (i, b) ans *= c;
    if (a < ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
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


ll digitMul(ll num) {
    ll ans = 1;
    while (num) {
        ans *= num % 10;
        num /= 10;
    }
    return ans;
}

int main() {
    ll N, B; cin >> N >> B;
    ll ans = 0;
    rep (i, N) {
        ll tmp = i + 1;
        if (tmp - digitMul(tmp) == B) ans++;
    }
    cout << ans << endl;
    return 0;
}
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


ll GCD(ll a, ll b) {
  return b ? GCD(b, a % b) : a;
}

int main() {
    ll a, b, c; cin >> a >> b >> c;
    ll N = GCD(c, GCD(a, b));
    cout << a / N + b / N + c / N -3 << endl;
    return 0;
}
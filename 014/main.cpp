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
    vector<ll> A(N), B(N);
    rep (i, N) cin >> A[i];
    rep (i, N) cin >> B[i];
    sort(ALL(A));
    sort(ALL(B));
    ll ans = 0;
    rep (i, N) {
        ans += abs(A[i] - B[i]);
    }
    cout << ans << endl;
    return 0;
}
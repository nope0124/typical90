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
    vector<ll> A(N), B(N), C(N);
    vector<ll> cntA(46), cntB(46), cntC(46);
    rep (i, N) cin >> A[i], A[i] %= 46, cntA[A[i]]++;
    rep (i, N) cin >> B[i], B[i] %= 46, cntB[B[i]]++;
    rep (i, N) cin >> C[i], C[i] %= 46, cntC[C[i]]++;
    ll ans = 0;
    rep (i, 46) {
        rep (j, 46) {
            rep (k, 46) {
                if ((i + j + k) % 46 == 0) {
                    ans += cntA[i] * cntB[j] * cntC[k];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
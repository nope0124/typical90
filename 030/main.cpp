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
    ll N, K;
    cin >> N >> K;
    vector<ll> isPrime(N + 1, 0);
    isPrime[1] = 0;
    for (ll i = 2; i <= N; i++) {
        if (isPrime[i] == 0) {
            for (ll j = i; j <= N; j += i) {
                isPrime[j]++;
            }
        }
    }
    ll ans = 0;
    rep (i, N + 1) {
        if (isPrime[i] >= K) ans++;
    }
    cout << ans << endl;
    return 0;
}
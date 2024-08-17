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

/* コンビネーション */

const ll MAX = 110000;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (ll i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

ll COM(ll n, ll k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main() {
    COMinit();
    ll N; cin >> N;
    

    vector<ll> V(N);
    vector<ll> ans(N);
    vector<ll> com(N);
    for (ll i = N - 1; i >= 1; i--) {
        ll cnt = (N + i - 1) / i;
        for (ll j = 1; j < cnt; j++) {
            if (com[j] == 0) com[j] = j + 1 + (N - (j * i + 1));
            else com[j] += j;
        }
        // cout << i << endl;
        for (ll j = 1; j < cnt; j++) {
            // cout << COM(com[j], j + 1) << endl;
            ans[i - 1] += COM(com[j], j + 1);
            ans[i - 1] %= MOD;
        }
        // cout << endl;
    }
    rep (i, N) {
        cout << (ans[i] + N) % MOD << "\n";
    }
    
    return 0;
}
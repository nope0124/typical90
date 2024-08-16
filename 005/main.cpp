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

template<class T> struct Matrix {
  vector<vector<T>> mtr;
  Matrix(ll H, ll W, T val=0) : mtr(H, vector<T>(W, val)) {}
  void init(ll H, ll W, T val=0) { mtr.assign(H, vector<T>(W, val)); }
  ll size() const { return mtr.size(); }
  inline vector<T>& operator [] (ll i) { return mtr[i]; }
};


template<class T> Matrix<T> MATMUL(Matrix<T> &A, Matrix<T> &B) {
  Matrix<T> ret(A.size(), B[0].size(), 0);
  rep (i, A.size()) {
    rep (j, B[0].size()) {
      rep (k, B.size()) {
        ll a = A[i][k] * B[k][j] % MOD;
        ret[i][j] += a;
        ret[i][j] %= MOD;
      }
    }
  }
  return ret;
}

template<class T> Matrix<T> MATPOW(Matrix<T> A, ll K) {
  ll N = A.size();
  Matrix<T> ret(N, N);
  rep(i, N) ret[i][i] = 1;
  while(K) {
    if(K & 1) ret = MATMUL(ret, A);
    A = MATMUL(A, A);
    K >>= 1;
  }
  return ret;
}


ll POW(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
    ll N, B, K; cin >> N >> B >> K;
    vector<ll> V(K);
    rep (i, K) cin >> V[i];
    vector<vector<ll>> dp(61, vector<ll>(B)); // 2**i桁まで
    dp[0][0] = 0;
    vector<ll> power(61); // 10**(2**i)
    rep (i, 61) {
        ll a = 1;
        rep (j, i) a *= 2;
        power[i] = POW((ll)10, a, B);
    }
    rep (i, K) {
        dp[0][V[i]%B]++;
    }

    rep (i, 60) {
        rep (j, B) {
            rep (k, B) {
                dp[i + 1][(power[i] * j + k) % B] += dp[i][j] * dp[i][k];
                dp[i + 1][(power[i] * j + k) % B] %= MOD;
            }
        }
    }


    vector<vector<ll>> ans(61, vector<ll>(B));
    ll idx = -1;
    rep (i, 61) {
        if (N >> i & 1) {
            idx++;
            rep (j, B) {
                if (idx == 0) {
                    ans[idx][j] = dp[i][j];
                } else {
                    rep (k, B) {
                        ans[idx][(power[i] * j + k) % B] += ans[idx - 1][j] * dp[i][k];
                        ans[idx][(power[i] * j + k) % B] %= MOD;
                    }
                }
            }
        }
    }
    // cout << dp[2][0] << endl;
    // cout << dp[2][1] << endl;
    
    cout << ans[idx][0] << endl;
    return 0;
}
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
    set<ll> st;
    // TODO: 0も考える
    rep (i, 50) {
        rep (j, 50 - i) {
            rep (k, 50 - i - j) {
                rep (l, 50 - i - j - k) {
                    rep (m, 50 - i - j - k - l) {
                        ll value = 1;
                        bool flag = true;
                        rep (ii, i) {
                            if (value > N) {
                                flag = false;
                                break;
                            }
                            value *= 2;
                        }
                        rep (jj, j) {
                            if (value > N) {
                                flag = false;
                                break;
                            }
                            value *= 3;
                        }
                        rep (kk, k) {
                            if (value > N) {
                                flag = false;
                                break;
                            }
                            value *= 5;
                        }
                        rep (lll, l) {
                            if (value > N) {
                                flag = false;
                                break;
                            }
                            value *= 7;
                        }
                        if (flag) st.insert(value);
                    }
                }
            }
        }
    }
    if (digitMul(B) == 0 && N >= B) ans++;
    for (auto c: st) {
        // cout << c << endl;
        ll value = c + B;
        if (value <= N && digitMul(value) == c) ans++;
        // if (c + B <= N) ans++;
    }
    cout << ans << endl;
    return 0;
}
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

vector<vector<ll>> grundy(60, vector<ll>(4000, -1));

ll rec(ll white, ll blue) {
    if (white == 0 && blue == 1) {
        grundy[white][blue] = 0;
        return grundy[white][blue];
    }
    assert (!(white == 0 && blue == 0));
    if (grundy[white][blue] != -1) return grundy[white][blue];
    set<ll> st;
    if (white >= 1) {
        st.insert(rec(white - 1, blue + white));
    }
    if (blue >= 2) {
        for (ll i = 1; i <= blue / 2; i++) {
            st.insert(rec(white, blue - i));
        }
    }
    rep (i, 3000) {
        if (st.find(i) == st.end()) {
            grundy[white][blue] = i;
            return grundy[white][blue];
        }
    }
    while(1) {

    }
}


int main() {
    ll N; cin >> N;
    vector<ll> W(N), B(N);
    rep (i, N) cin >> W[i];
    rep (i, N) cin >> B[i];
    vector<ll> V;
    rep (i, N) V.push_back(rec(W[i], B[i]));
    ll ans = 0;
    rep (i, N) ans ^= V[i];
    if (ans == 0) cout << "Second" << endl;
    else cout << "First" << endl;
    
    return 0;
}
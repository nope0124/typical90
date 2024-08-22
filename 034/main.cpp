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
    ll N, K; cin >> N >> K;
    vector<ll> V(N);
    rep (i, N) cin >> V[i];
    set<ll> st;
    multiset<ll> ms;
    queue<ll> que;
    ll right = 0;
    ll ans = 0;
    rep (left, N) {
        while (st.size() <= K && right < N) {
            ans = max(ans, (ll)ms.size());
            ms.insert(V[right]);
            st.insert(V[right]);
            right++;
        }
        if (st.size() <= K) ans = max(ans, (ll)ms.size());
        ms.erase(ms.find(V[left]));
        if (ms.count(V[left]) == 0) st.erase(V[left]);
    }
    cout << ans << endl;
    return 0;
}
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
    ll N, M; cin >> N >> M;
    vector<pll> V(M);
    ll ans = 0;
    rep (i, M) cin >> V[i].first >> V[i].second;
    rep (i, M) {
        rep (j, i) {
            if (V[i].first == V[j].first || V[i].first == V[j].second || V[i].second == V[j].first || V[i].second == V[j].second) continue;
            if (V[i].first < V[j].first && V[j].first < V[i].second) {
                if (V[i].first < V[j].second && V[j].second < V[i].second) continue;
                ans++;
            } else if (V[i].first < V[j].second && V[j].second < V[i].second) {
                if (V[i].first < V[j].first && V[j].first < V[i].second) continue;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
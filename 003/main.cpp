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
    vector<ll> graph[100010];
    vector<ll> dist(100010, 0);
    rep (i, N - 1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    auto dfs = [&](auto f, ll v, ll p) -> void {
        for (auto c: graph[v]) {
            if (c == p) continue;
            dist[c] = dist[v] + 1;
            f(f, c, v);
        }
    };

    dfs(dfs, 0, -1);
    ll idx = max_element(ALL(dist)) - dist.begin();
    rep (i, N) dist[i] = 0;
    dfs(dfs, idx, -1);

    ll ans = *max_element(ALL(dist));
    cout << ans + 1 << endl;
    
    return 0;
}
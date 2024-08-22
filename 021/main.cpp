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

ll N, M;
vector<ll> graph[100010];
vector<ll> graph_rev[100010];
vector<ll> reached(100010, -1);
vector<ll> reached1(100010, false);

ll cnt = 0;


int main() {
    cin >> N >> M;
    rep (i, M) {
        ll a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph_rev[b].push_back(a);
    }
    auto dfs = [&](auto f, ll v, ll p) -> void {
        if (reached1[v]) return;
        reached1[v] = true;
        for (auto c: graph[v]) {
            if (c == p) continue;
            f(f, c, v);
        }
        reached[v] = cnt;
        cnt++;
        return;
    };
    rep (i, N) dfs(dfs, i, -1);
    vector<pll> P(N);
    rep (i, N) P[i] = pll(reached[i], i);
    sort(ALL(P), greater<pll>());
    vector<bool> labeled(N, false);
    ll ans = 0;
    ll tmp = 0;
    auto labeling = [&](auto f, ll v, ll p) -> void {
        // cout << " v " << v << ' ' << p << endl;
        if (labeled[v]) return;
        // cout << "2v " << v << ' ' << p << endl;
        labeled[v] = true;
        tmp++;
        for (auto c: graph_rev[v]) {
            if (c == p) continue;
            f(f, c, v);
        }
        return;
    };
    rep (i, N) {
        tmp = 0;
        labeling(labeling, P[i].second, -1);
        // cout << tmp << endl;
        ans += tmp * (tmp - 1) / 2;
    }
    rep (i, N) {
        // cout << P[i].first << ' ' << P[i].second + 1 << endl;
    }
    cout << ans << endl;
    


    return 0;
}


// 4 5
// 1 3
// 2 3
// 3 2
// 3 4
// 4 2



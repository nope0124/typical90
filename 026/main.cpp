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

vector<ll> graph[100010];
int main() {
    ll N; cin >> N;
    vector<ll> color(N, -1);
    rep (i, N) {
        ll a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    auto dfs = [&](auto f, ll v, ll p, ll col) -> void {
        if (color[v] != -1) return;
        color[v] = col;
        for (auto c: graph[v]) {
            if (c == p) continue;
            f(f, c, v, 1 - col);
        }
    };
    dfs(dfs, 0, -1, 0);
    vector<ll> W, B;
    rep (i, N) {
        if (color[i] == 0) {
            W.push_back(i + 1);
        } else if (color[i] == 1) {
            B.push_back(i + 1);
        } else {
            while (1) {

            }
        }
    }
    if (W.size() > B.size()) {
        rep (i, N / 2) {
            if (i == 0) cout << W[i];
            else cout << ' ' << W[i];
        }
    } else {
        rep (i, N / 2) {
            if (i == 0) cout << B[i];
            else cout << ' ' << B[i];
        }
    }
    cout << endl;
    return 0;
}
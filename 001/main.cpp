#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)
#define ALL(V)  (V).begin(), (V).end()
ll dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
ll dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ll N, L, K; cin >> N >> L >> K;
    vector<ll> V;
    V.push_back(0);
    rep (i, N) {
        ll a; cin >> a;
        V.push_back(a);
    }
    V.push_back(L);
    ll ok = 1;
    ll ng = 1e16;
    auto solve = [&](ll mid) {
        ll cnt = 0;
        ll curLength = 0;
        rep (i, N + 1) {
            curLength += V[i + 1] - V[i];
            if (curLength >= mid) {
                cnt++;
                curLength = 0;
            }
        }
        return cnt;
    };

    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (solve(mid) >= K + 1) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    return 0;
}
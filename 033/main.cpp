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
    ll H, W; cin >> H >> W;
    if (H == 1 || W == 1) {
        cout << H * W << endl;
        return 0;
    }
    ll a = (H + 1) / 2;
    ll b = (W + 1) / 2;
    cout << a * b << endl;
    return 0;
}
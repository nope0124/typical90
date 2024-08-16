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
    ll N; cin >> N;
    vector<string> ans;
    rep (bit, (1LL<<N) ) {
        string cacco = "";
        rep (i, N) {
            if (bit >> i & 1) {
                cacco += '(';
            } else {
                cacco += ')';
            }
        }
        bool flag = true;
        ll sum = 0;
        rep (i, N) {
            if (cacco[i] == '(') {
                sum++;
            } else {
                sum--;
            }
            if (sum < 0) {
                flag = false;
            }
        }
        if (sum != 0 || flag == false) continue;
        ans.push_back(cacco);
    }
    sort(ALL(ans));
    rep (i, ans.size()) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}
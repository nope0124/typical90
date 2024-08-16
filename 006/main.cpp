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
    string S; cin >> S;

    queue<ll> A[26];
    
    rep (i, N) {
        A[S[i] - 'a'].push(i);
    }

    string ans;
    ll curLength = 0;
    ll lastValue = -1;
    rep (i, K) {
        rep (j, 26) {
            while (!A[j].empty()) {
                auto c = A[j].front();
                if (c < lastValue) {
                    A[j].pop();
                } else {
                    break;
                }
            }
            if (A[j].empty()) continue;

            auto c = A[j].front();
            if (N - c >= K - ans.size()) {
                ans += (char)('a' + j);
                A[j].pop();
                lastValue = c;
                break;
            }
        }
    }

    cout << ans << endl;


    return 0;
}
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

struct SegmentTree {
  private:
    int N; //2の冪乗
    vector<ll> node;

  public:
    // [0, N-1) [N-1, 2*N-1)の二つの配列と意識しておくと考えやすいかも 
    SegmentTree(vector<ll> V) {
      N = 1;
      while (N < V.size()) N *= 2; // これにより、NがVのサイズ以上の2冪数になる
      node.resize(2 * N - 1, 0); // nodeのサイズは[1] [1 2] [1 2 3 4] [1 2 ... 2^N]の総和となるため、2*N-1
      for (int i = 0; i < V.size(); i++) node[N - 1 + i] = V[i]; // nodeの後半を埋めておく
      for (int i = N - 1 + (-1); i >= 0; i--) node[i] = node[2 * i + 1] + node[2 * i + 2];
    }

    void add(int ind, ll val) {
      //  + N - 1をして二つ目の配列に写す
      // indは[0, N)だから、ind+N-1は[N-1, 2*N-1)
      ind += N - 1;
      node[ind] += val;
      while (ind > 0) {
        ind = (ind - 1) / 2;
        node[ind] = node[2 * ind + 1] + node[2 * ind + 2];
      }
    }

    // a, bは固定、l, rが今見ている範囲
    ll getSum(int a, int b, int k = 0, int l = 0, int r = -1) { //[a, b) [l, r)
      if (r < 0) r = N;
      if (r <= a || b <= l) return 0;
      if (a <= l && r <= b) return node[k];
      ll vl = getSum(a, b, 2 * k + 1, l, (l + r) / 2);
      ll vr = getSum(a, b, 2 * k + 2, (l + r) / 2, r);
      return vl + vr;
    }
    
    void dis() {
      int ans = 1;
      int id = 0;
      while (1) {
        rep (i, ans) cout << (i ? " " : "") << node[id], id++;
        cout << endl;
        if (ans == N) return;
        ans *= 2;
      }
    }
};


int main() {
    ll N, M; cin >> N >> M;
    vector<pll> V(M);
    rep (i, M) cin >> V[i].first >> V[i].second, V[i].first--, V[i].second--;
    
    ll ans = M * (M - 1) / 2;
    // cout << "ans: " << ans << endl;

    // step1
    ll step1 = 0;
    vector<ll> cnt(N);
    rep (i, M) {
        cnt[V[i].first]++;
        cnt[V[i].second]++;
    }
    rep (i, N) step1 += cnt[i] * (cnt[i] - 1) / 2;
    // cout << "step1 " << step1 << endl;

    // step2
    ll step2 = 0;

    vector<ll> R(N + 2);
    SegmentTree ss(R);
    rep (i, M) ss.add(V[i].second, 1);
    rep (i, M) {
        step2 += ss.getSum(0, V[i].first);
    }
    // cout << "step2 " << step2 << endl;

    // ll cntcnt = 0;
    // rep (i, M) {
    //     rep (j, i) {
    //         // cout << V[i].first << ' ' << V[i].second << endl;
    //         // cout << V[j].first << ' ' << V[j].second << endl;
    //         // cout << endl;
    //         if (V[i].second < V[j].first || V[j].second < V[i].first) cntcnt++;
    //     }
    // }
    // cout << "cnt: " << cntcnt << endl;
    
    // step3
    ll step3 = 0;
    auto cmp = [&](pll a, pll b) -> bool {
        // if (a.second == b.second) {
        //     return a.first < b.first;
        // } else {
        //     return a.second < b.second;
        // }
        return a.second < b.second;
    };
    sort(ALL(V), cmp);
    // rep (i, M) {
    //     cout << V[i].first << ' ' << V[i].second << endl;
    // }
    vector<ll> s(N + 2);
    SegmentTree sg(s);
    rep (i, M) {
        // cout << i << ' ' << sg.getSum(V[i].first + 1, V[i].second) << endl;
        step3 += sg.getSum(V[i].first + 1, V[i].second);
        sg.add(V[i].first, 1);
    }
    // cout << "step3 " << step3 << endl;
    // ll cntcntcnt = 0;
    // rep (i, M) {
    //     rep (j, i) {
    //         if (V[i].first < V[j].first && V[j].second < V[i].second || V[j].first < V[i].first && V[i].second < V[j].second) cntcntcnt++;
    //     }
    // }
    // cout << "cntcntcnt " << cntcntcnt << endl;
    cout << ans - step1 - step2 - step3 << endl;
    
    return 0;
}

// 16 98 - 52 114
// 16 98 - 23 179
// 52 114 - 110 157
// 110 157 - 123 163
// 110 157 - 134 226
// 123 163 - 157 176
// 123 163 - 134 226
// 12 217 - 203 223
// 12 217 - 134 226
// 203 223 - 134 226

// 
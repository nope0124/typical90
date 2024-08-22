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

class LazySegmentTree {
    int n;
    vector<long long> data, lazy;
    vector<bool> lazyFlag;

public:
    LazySegmentTree(int size) {
        n = 1;
        while (n < size) n *= 2;
        data.assign(2 * n - 1, 0);
        lazy.assign(2 * n - 1, 0);
        lazyFlag.assign(2 * n - 1, false);
    }

    // 遅延評価の処理
    void evaluate(int k, int l, int r) {
        if (lazyFlag[k]) {
            data[k] = lazy[k]; // 遅延情報で更新
            if (r - l > 1) { // 葉でない場合は子に伝播
                lazy[2 * k + 1] = lazy[2 * k + 2] = lazy[k];
                lazyFlag[2 * k + 1] = lazyFlag[2 * k + 2] = true;
            }
            lazyFlag[k] = false;
        }
    }

    // 区間更新 [a, b) を値 x に設定
    void update(int a, int b, long long x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        evaluate(k, l, r);
        if (a >= r || b <= l) return; // 完全に範囲外
        if (a <= l && r <= b) { // 完全に範囲内
            lazy[k] = x;
            lazyFlag[k] = true;
            evaluate(k, l, r);
        } else { // 部分的に範囲内
            int mid = (l + r) / 2;
            update(a, b, x, 2 * k + 1, l, mid);
            update(a, b, x, 2 * k + 2, mid, r);
            data[k] = max(data[2 * k + 1], data[2 * k + 2]);
        }
    }

    // 区間 [a, b) の最大値を取得
    long long query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        evaluate(k, l, r);
        if (a >= r || b <= l) return numeric_limits<long long>::min(); // 完全に範囲外
        if (a <= l && r <= b) return data[k]; // 完全に範囲内
        int mid = (l + r) / 2;
        return max(query(a, b, 2 * k + 1, l, mid), query(a, b, 2 * k + 2, mid, r));
    }
};

int main() {
    ll W, N; cin >> W >> N;
    vector<ll> V(W + 2);
    LazySegmentTree sg(W + 2);
    rep (i, N) {
        ll L, R; cin >> L >> R;
        ll value = sg.query(L, R + 1);
        cout << value + 1 << endl;
        sg.update(L, R + 1, value + 1);
    }
    return 0;
}
// int main() {
//     int n = 10;  // 配列のサイズ
//     LazySegmentTree seg(n);

//     // 区間 [2, 5) を 3 で更新
//     seg.update(2, 5, 3);

//     // 区間 [4, 7) を 2 で更新
//     seg.update(4, 7, 2);

//     // 区間 [0, 5) の最大値を取得
//     cout << seg.query(0, 5) << endl;  // 出力：3

//     // 区間 [3, 10) の最大値を取得
//     cout << seg.query(3, 10) << endl;  // 出力：5

//     return 0;
// }
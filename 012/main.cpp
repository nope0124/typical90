#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
#define rep(i, N) for(ll i = 0; i < (ll)N; i++)
#define ALL(V)  (V).begin(), (V).end()
ll dx[4] = {-1, 1, 0, 0};
ll dy[4] = {0, 0, -1, 1};

/* Union-Find木 */

struct UnionFind {
  private:
    vector<int> parent;
  
  public:
    UnionFind(int n) : parent(n, -1) { }
    void init(int n) { parent.assign(n, -1); }
 
    int root(int x) {
      if (parent[x] < 0) return x;
      else return parent[x] = root(parent[x]);
    }
 
    bool issame(int x, int y) {
      return root(x) == root(y);
    }
 
    void merge(int x, int y) {
      x = root(x);
      y = root(y);
      if (x == y) return;
      if (parent[x] > parent[y]) swap(x, y);
      parent[x] += parent[y]; // sizeを調整
      parent[y] = x; // 大きい木の根に小さい木をつける, yの親はx
    }
 
    int size(int x) {
      return -parent[root(x)];
    }
  
};

int main() {
    ll H, W; cin >> H >> W;
    vector<vector<bool>> V(H, vector<bool>(W));
    UnionFind uf(H*W);
    ll Q; cin >> Q;
    rep (i, Q) {
        ll type; cin >> type;
        if (type == 1) {
            ll y, x; cin >> y >> x;
            y--; x--;
            V[y][x] = true;
            rep (k, 4) {
                ll nx = x + dx[k];
                ll ny = y + dy[k];
                if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
                if (!V[ny][nx]) continue;
                uf.merge(y*W+x, ny*W+nx);
            }
        } else if (type == 2) {
            ll y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
            y1--; x1--; y2--; x2--;
            if (V[y1][x1] && V[y2][x2] && uf.issame(y1*W+x1, y2*W+x2)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
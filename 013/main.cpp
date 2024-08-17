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

const ll INF = 1e16;
/* ダイクストラ法 */

const ll MAX_V = 200010; //頂点数
struct edge{
  ll to, cost;
};

vector<edge> graph[MAX_V];
ll dist[MAX_V];
ll dist2[MAX_V];
ll pre[MAX_V];

void dijkstra(ll s){
  priority_queue<pll, vector<pll>, greater<pll>> que; //小さい順に格納
  fill(dist, dist + MAX_V, INF);
  fill(pre, pre + MAX_V, -1);
  dist[s] = 0;
  que.push(pll(0, s)); //pll(距離, 到着点)
  while(!que.empty()){
    auto p = que.top(); que.pop();
    ll v = p.second;
    if(dist[v] < p.first) continue;
    for(auto e: graph[v]){
      if(dist[e.to] > dist[v] + e.cost){
        dist[e.to] = dist[v] + e.cost;
        pre[e.to] = v;
        que.push(pll(dist[e.to], e.to));
      }
    }
  }
}

void dijkstra2(ll s){
  priority_queue<pll, vector<pll>, greater<pll>> que; //小さい順に格納
  fill(dist2, dist2 + MAX_V, INF);
  fill(pre, pre + MAX_V, -1);
  dist2[s] = 0;
  que.push(pll(0, s)); //pll(距離, 到着点)
  while(!que.empty()){
    auto p = que.top(); que.pop();
    ll v = p.second;
    if(dist2[v] < p.first) continue;
    for(auto e: graph[v]){
      if(dist2[e.to] > dist2[v] + e.cost){
        dist2[e.to] = dist2[v] + e.cost;
        pre[e.to] = v;
        que.push(pll(dist2[e.to], e.to));
      }
    }
  }
}

vector<ll> get_path(ll t) {
  vector<ll> path;
  for (ll cur = t; cur != -1; cur = pre[cur]) {
    path.push_back(cur);
  }
  reverse(ALL(path));
}

int main() {
    ll N, M; cin >> N >> M;
    rep (i, M) {
        ll a, b, c; cin >> a >> b >> c; a--; b--;
        graph[a].push_back(edge{b, c});
        graph[b].push_back(edge{a, c});
    }
    dijkstra(0);
    dijkstra2(N - 1);
    rep (i, N) {
        cout << dist[i] + dist2[i] << endl;
    }

    return 0;
}
#include <iostream>
#include <queue>

using namespace std;

#define NMAX 505
#define pb push_back
typedef pair<int,int> pii;

int n, m;
vector <pii> adj[NMAX];
int F[NMAX];

int main() {
    //freopen("1450.inp", "r", stdin);
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int x, y, c;
        cin >> x >> y >> c;
        adj[x].pb({y,c});
    }

    int s, t;
    cin >> s >> t;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto &p : adj[u]){
            int v = p.first, w = p.second;
            if(F[v] < F[u] + w){
                F[v] = F[u] + w;
                q.push(v);
            }
        }
    }
    if(F[t] != 0) cout << F[t];
    else cout <<"No solution";
}

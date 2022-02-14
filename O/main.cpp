#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define  NMAX 105
#define  pb push_back
int n, m;

vector <int> adj[NMAX];
int color[NMAX];

void paint(int u){
    //cout<<"vertex "<<u<<" has color "<<color[u] <<'\n';

    for(int v : adj[u]){

        if(color[v] == - 1){
            color[v] = 1 - color[u];
            //cout<<"vertex "<<v<<" has color "<<color[v] <<'\n';
            paint(v);
        } else if(color[u] == color[v]){
            //cout<<"Error: " << u << " "<<color[u] <<" "<<v <<" " <<color[v]<<'\n';
            cout << "NO";
            exit(0);
        }
    }
}
int main() {
    //freopen("O.inp", "r", stdin);
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    memset(color, -1, sizeof(color));
    for(int i = 1; i <=n ; i++){
        if(color[i] == -1){
            //cout<<"GO: "<<i<<'\n';
            color[i] = 1;
            paint(i);
        }
    }
    cout<<"YES";
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

#define NMAX 105
#define pb push_back

int n;
int inDeg[NMAX];

vector <int> adj[NMAX];
vector <pii> ver;
bool visited[NMAX];

void DFS(int u){
    //cout<<"paint " << u << '\n';
    for(int v : adj[u]){
        if(!visited[v]){
            visited[v] = true;
            DFS(v);
        }
    }
}

int main() {

    /*// gen test
    freopen("N.inp", "w", stdout);
    srand(time(NULL));
    cout << 10 <<'\n';
    for(int i = 1; i <= 10; i++){
        cout << rand() % 10 + 1 <<'\n';
    }
    return 0;*/
    //freopen("N.inp", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        adj[x].pb(i); // key of ith pig located inside xth pig. Got WA since my bad Russian ((
        adj[i].pb(x); // can be solved in undirected graph
    }


    int res = 0;

    for(int i = 1; i <= n; i++){
        if(!visited[i]) {
            ++res;
            //cout<<"GO: \n"<<p.second<<'\n';
            visited[i] = true;
            DFS(i);
        }
    }

    cout << res;
}

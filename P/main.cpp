#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

template <typename T> inline void read (T &x){
    bool nega=0;
    char c;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}

#define NMAX 1005
#define pb push_back

int n;
int a[NMAX][NMAX];
bool adj[NMAX][NMAX];
bool reverse[NMAX][NMAX];
bool visited[NMAX];


void DFS(int u, bool isReverse){
    if(visited[u]) return;
    //cout<<"visited: "<<u <<'\n';
    visited[u] = true;
    for(int v = 1; v <= n; v++){
        if (!visited[v]){
            if(isReverse && reverse[u][v]) DFS(v, isReverse);
            if(!isReverse && adj[u][v]) DFS(v, isReverse);
        }
    }
}

bool check(){
    for(int i = 1; i <= n; i++){
        if(!visited[i]) return false;
    }
    return true;
}
bool isSCC(int min_weight){

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] <= min_weight) adj[i][j] = true, reverse[j][i] = true;
            else adj[i][j] = false, reverse[j][i] = false;
        }
    }

    /*for(int i = 1; i <= n; i++){
        cout <<"from : " << i <<'\n';
        for(int v : adj[i]) cout << v << " ";
        cout <<'\n';
    }*/
    memset(visited, 0 , sizeof(visited)); // blyat I forgot memset
    DFS(1, false);
    if(check()){
        memset(visited, 0 ,sizeof(visited));
        DFS(1, true);
        if(check()) return true;
        else return false;
    }  else return false;

}

int subtask_n2log(){
    int l = 0, r = 1e9;
    int res = 1e9;
    while(l <= r){
        int m = (l + r) >> 1;
        //cout<<"check : " << m  << '\n';
        if(isSCC(m)){
            res = m;
            r = m - 1;
        } else {
            //cout << "wrong: " << m <<'\n';
            l = m + 1;
        }
    }

    return res;
}

int main() {
    //ios_base::sync_with_stdio(false);
    //freopen("P.inp", "w", stdout);
    //freopen("P.inp", "r", stdin);
/*srand(time(NULL));

    int n = 1000;
    cout << n << '\n';
    for(int i = 1 ; i <= n ;i++){
        for(int j = 1; j <= n; j++){
            if(i == j) cout <<0 <<" ";
            else cout << rand() % 1000000000 + 1 <<" ";
        }
        cout<<'\n';
    }
    return 0;*/

    read(n);

    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= n; j++){
            read(a[i][j]);
        }
    }
    write(subtask_n2log()); // 8018293
}



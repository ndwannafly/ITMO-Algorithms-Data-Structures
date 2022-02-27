#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

#define NMAX 50005
#define pb push_back

typedef pair<int,int> pii;

int n;
int w[10];
string s[NMAX];
map<string, int> id;
vector<pii> adj[NMAX];
int F[NMAX];
priority_queue<pii> pq;

int cal_dis(int u, int v){
    int now = 0;
    while(now < 10 && s[u][now] == s[v][now]){
        ++now;
    }
    return now;
}

void make_edge(int u, int v){
    if(u < v) return ;
    int dis = cal_dis(u, v);
    adj[u].pb({v, w[dis]});
    adj[v].pb({u, w[dis]});
}

void replace_one_digit(string &u){
    int id_u = id[u];
    for(int i = 0; i < 10; i++){
        char old = u[i];
        for(int j = 0; j < 10; j++){
            u[i] = char(j + '0');
            if(id.find(u) != id.end()) {
                int id_target = id[u];
                u[i] = old;
                if (id_target && (id_target != id_u)) {
                    make_edge(id_u, id_target);
                }
            }
            u[i] = old;
        }
    }
}

void swap_two_digits(string &u){
    int id_u = id[u];
    for(int i = 0; i < 10; i++){
        for(int j = i+1; j < 10;j++){
            char old_ui = u[i];
            char old_uj = u[j];
            u[i] = old_uj;
            u[j] = old_ui;
            if(id.find(u) != id.end()) {
                int id_target = id[u];
                u[i] = old_ui;
                u[j] = old_uj;
                if(id_target && (id_target != id_u)) {
                    make_edge(id_u, id_target);
                }
            }
            u[i] = old_ui;
            u[j] = old_uj;
        }
    }
}

int main() {

    //freopen("1806.inp", "r", stdin);

    cin >> n;
    for(int i = 0; i < 10; i++) cin >> w[i];

    for(int i = 1; i <= n; i++){
        F[i] = 1e9;
        cin >> s[i];
        id[s[i]] = i;
    }

    for(int i = 1; i <= n; i++){
        replace_one_digit(s[i]);
        swap_two_digits(s[i]);
    }
    //return 0;
    F[1] = 0;
    pq.push({1, F[1]});
    while(!pq.empty()){
        pii top = pq.top();
        int u = top.first;
        int dis = top.second;
        pq.pop();
        if(dis != F[u]) continue;
        for(auto &p : adj[u]){
            int v = p.first, cost = p.second;
            if(F[v] > F[u] + cost){
                F[v] = F[u] + cost;
                pq.push({v, F[v]});
            }
        }
    }

    if(F[n] == 1e9) {
        cout << -1;
        return 0;
    }
    else cout << F[n]<<'\n';

    vector <int> res;

    int now = n;
    res.pb(now);
    while(now != 1){
        for(auto &p : adj[now]){
            int v = p.first, cost = p.second;
            if(F[v] == F[now] - cost){
                now = v;
                res.pb(v);
                break;
            }
        }
    }

    cout << res.size()<<'\n';
    reverse(res.begin(), res.end());
    for(int v : res ) cout << v << ' ';
}

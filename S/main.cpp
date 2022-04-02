#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

#define NMAX 1005

struct cell{
    int x, y, val;
    bool operator < (const cell &other) const{
        return val < other.val;
    }
};

int n, m;
int a[NMAX][NMAX];
int l[NMAX][NMAX], r[NMAX][NMAX], t[NMAX][NMAX], d[NMAX][NMAX];

int root[NMAX * NMAX];

int get(int x, int y){
    return (x-1) * m + y;
}

int find_set(int u){
    if(root[u] < 0) return u;
    return root[u] = find_set(root[u]);
}

void dsu_union(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if(u == v) return ;
    if(root[u] < root[v]){
        root[u] += root[v];
        root[v] = u;
    } else {
        root[v] += root[u];
        root[u] = v;
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    //freopen("S.inp", "r", stdin);
    memset(root, -1, sizeof(root));
    cin >> n >> m;

    for(int i = 0; i <= n+1; i++){ // initially, all elements = -1
        for(int j = 0 ; j <= m+1; j++){
            a[i][j] = -1;
            l[i][j] = -1;
            r[i][j] = -1;
            t[i][j] = -1;
            d[i][j] = -1;
        }
    }

    for(int i = 1; i <= n; i++){
            string s;
            cin>>s;
            for(int j = 0 ; j < m; j++) {
                if(s[j] == '.') a[i][j + 1] = -1;
                else a[i][j + 1] = s[j] - '0';
            }
    }

    /*for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << a[i][j] <<" ";
        }
        cout<<'\n';
    }*/

    //cout<< '\n';
    //cout<<"left:\n";
    for(int i = 1; i <= n; i++){ // left
        for(int j = 1; j <= m; j++){
            if(a[i][j] < 0) continue;
            if(a[i][j-1] >= 0) l[i][j] = l[i][j-1];
            else l[i][j] = j;
            //cout<< i << " " << j <<" "<<l[i][j]<<'\n';
        }
    }
    //cout<<'\n';
    for(int i = 1; i <= n; i++){ // right
        for(int j = m; j >= 1; j--){
            if(a[i][j] < 0) continue;
            if(a[i][j+1] >= 0) r[i][j] = r[i][j+1];
            else r[i][j] = j;
        }
    }

    for(int j = 1; j <= m; j++){ // top
        for(int i = 1; i <= n; i++){
            if(a[i][j] < 0) continue;
            if(a[i-1][j] >= 0) t[i][j] = t[i-1][j];
            else t[i][j] = i;
            //cout<< "(i,j) = "<<i<<","<<j<<" "<<t[i][j]<<'\n';
        }
    }

    for(int j = 1; j <= m; j++){ // down
        for(int i = n; i >= 1; i--){
            if(a[i][j] < 0) continue;
            if(a[i+1][j] >= 0) d[i][j] = d[i+1][j];
            else d[i][j] = i;
        }
    }

    //search for word


    for(int i= 1 ; i <= n; i++){ // horizontally unite
        for(int j = 1; j <= m; j++){
            if(a[i][j] < 0) continue;
            int hor = r[i][j] - l[i][j] + 1;
            //cout<< hor <<'\n';
            int mid = (r[i][j] + l[i][j]) >> 1;
            if (hor & 1){
                if(j < mid) {
                    int pal_r = j + 2 * (mid - j);
                    if(find_set(get(i,j) != find_set(get(i, pal_r)))) {
                        dsu_union(get(i, j), get(i, pal_r));
                        /*cout << "union: " << "(" << i << "," << j << ")" << " with " << "(" << i << ","
                             << pal_r << ")" << '\n';*/
                    }
                }
            } else {
                if(j <= mid){
                    int pal_r = mid + (mid - j + 1);
                    if(find_set(get(i,j)) != find_set(get(i, pal_r))){
                        dsu_union(get(i,j), get(i, pal_r));
                        /*cout << "union: " << "(" << i << "," << j << ")" << " with " << "(" << i << ","
                             << pal_r << ")" << '\n';*/
                    }
                }
            }
        }
    }

    //cout << '\n';
    //cout <<"top-down\n";
    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++){
            if(a[i][j] < 0) continue;
            int ver = d[i][j] - t[i][j] + 1;
            int mid = (d[i][j] + t[i][j]) >> 1;

            if(ver & 1){
                if(i < mid){
                    int pal_d = i + 2 * (mid - i);
                    /*if(i==6 && j == 1){
                        cout<<"test:\n";
                        cout<<pal_d<<'\n';
                        cout<<find_set(get(i,j))<<" "<<find_set(get(pal_d,j))<<'\n';
                    }*/
                    if(find_set(get(i,j)) != find_set(get(pal_d, j))){
                        dsu_union(get(i,j), get(pal_d, j));
                        //cout << "union: " << "(" << i << "," << j << ")" << " with " << "(" << pal_d << ","
                        //     << j << ")" << '\n';
                    }
                }
            } else{
                if(i <= mid){
                    int pal_d = mid + (mid - i + 1);
                    if(find_set(get(i, j) != find_set(get(pal_d, j)))){
                        dsu_union(get(i,j), get(pal_d, j));
                        //cout << "union: " << "(" << i << "," << j << ")" << " with " << "(" << pal_d << ","
                        //     << j << ")" << '\n';
                    }
                }
            }
        }
    }

    int cnt_comp = 0;
    map<int, int> visited;
    int id[NMAX * NMAX];

    //cout<<find_set(get(1,5));
    //return 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!visited[find_set(get(i,j))]){
                visited[find_set(get(i,j))] = ++cnt_comp;
            }
            id[get(i,j)] = visited[find_set(get(i,j))];
            //cout<<"(i,j): "<<"(" << i << "," << j << ")"<<'\n';
            //cout<<"findset: "<<find_set(get(i,j))<<'\n';
        }
    }

    //return 0;

    vector<cell> v[cnt_comp + 1];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            //cout<<"(i,j): "<<"(" << i << "," << j << ")"<<'\n';
            //cout<<id[get(i,j)]<<'\n';
            v[id[get(i,j)]].push_back({i, j, a[i][j]});
        }
    }

    for(int i = 1 ; i <= cnt_comp; i++){
        if(v[i].size() == 1) continue;
        int optimal = 1e9;
        int good_digit = -1;
        for(int d = 0 ; d <= 9; d++){
            int sum = 0;
            for(auto x : v[i]){
                sum += abs(x.val - d);
            }
            if(optimal > sum){
                optimal = sum;
                good_digit = d;
            }
        }
        /*for(auto x : v[i]){
            cout<<"(x, y, val) = " << x.x<<" "<<x.y<<" "<<x.val<<'\n';
        }
        cout<<i<<" "<<optimal<<" "<<good_digit<<'\n';*/
        for(auto x : v[i]){
            //cout<<"update: "<< x.x <<" "<<x.y<<" "<<good_digit<<'\n';
            a[x.x][x.y] = good_digit;
        }
    }
    //cout<<"here\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) {
            //cout<<a[i][j]<<" ";
            if (a[i][j] == -1) cout<<'.';
            else cout<<a[i][j];
        }
        cout<<'\n';
    }


}

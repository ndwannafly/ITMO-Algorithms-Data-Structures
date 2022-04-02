#include <iostream>

using namespace std;

#define NMAX 150000

const int inf = 1e9;

class {
private:
    int node[4 * NMAX];
public:
    void init(){
        for(int i = 0; i < 4 * NMAX; i++) node[i] = inf;
    }

    void update(int id, int l,int r,int pos, int val){
        if(l == r){
            node[id] = min(node[id], val);
            return ;
        }
        int m = (l + r) >> 1;
        if(pos <= m) update(2 * id, l, m, pos, val);
        else update( 2 * id + 1, m+1, r, pos, val);
        node[id] = min(node[id], val);
    }


    int get_min(int id, int l, int r, int u, int v){
        if(l > v || r < u) return inf;
        if(l >= u && r <= v) return node[id];
        int m = (l + r) >>1;
        return min(get_min(2*id, l , m, u, v), get_min(2 * id + 1, m + 1, r, u, v));
    }
} segment_tree;

int n, k;



int main() {
    segment_tree.init();
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        int x;
        cin >>x;
        segment_tree.update(1, 1, n, i, x);
    }
    for(int i = 1; i <= n - k + 1; i++){
        cout << segment_tree.get_min(1, 1, n, i, i + k -1) << " ";
    }
}

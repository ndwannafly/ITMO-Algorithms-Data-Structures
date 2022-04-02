#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define pb push_back
typedef pair<int,int> pii;

int m, n, k, res;
map<pii, bool> isBlack;
vector <pii> black;

int main() {
    //freopen("1628.inp", "r", stdin);
    cin >> m >> n >> k;
    while(k--){
        int x, y;
        cin >> x >> y;
        black.pb({x, y});
        isBlack[{x,y}] = true;
    }
    for(int i = 0 ; i <= m+1; i++){
        black.pb({i, 0});
        black.pb({i, n + 1});
        isBlack[{i,0}] = true;
        isBlack[{i,n+1}] = true;
    }

    for(int i = 0 ; i <= n+1; i++){
        black.pb({0, i});
        black.pb({m+1, i});
        isBlack[{0,i}] = true;
        isBlack[{m+1, i}] = true;
    }

    sort(black.begin(), black.end());
    for(int i = 0 ; i < black.size() - 1; i++){
        int y1 = black[i].second, y2 = black[i+1].second;
        if(y2 - y1 > 2) ++res;
    }

    sort(black.begin(), black.end(), [](pii &p, pii &q){
        if(p.second != q.second) return p.second < q.second;
        return p.first < q.first;
    });

    for(int i = 0 ; i < black.size() - 1; i++){
        int x1 = black[i].first, x2 = black[i+1].first;
        if(x2 - x1 > 2) ++res;
        else if (x2 - x1 == 2){
            int y1 = black[i].second;
            if(isBlack[{x1 +1, y1 -1}] && isBlack[{x1+1, y1+1}]) ++ res;
        }
    }
    cout <<res;
}

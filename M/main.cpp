#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

#define NMAX 1005
#define pb push_back
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
int a[NMAX][NMAX];
int F[NMAX][NMAX];
int trace[NMAX][NMAX];
pii start, finish;

bool inGrid(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main() {
    //freopen("M.inp", "r", stdin);
    cin >> n >> m >> start.first >> start.second >> finish.first >> finish.second;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == '.') a[i][j + 1] = 1;
            else if (s[j] == 'W') a[i][j + 1] = 2;
            else a[i][j + 1] = -1;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            F[i][j] = 1e9;
        }
    }

    F[start.first][start.second] = 0;

    queue<pii> q;
    q.push(start);
    while(!q.empty()){
        pii top = q.front();
        q.pop();
        //cout << top.first <<" "<<top.second<<" "<<F[top.first][top.second]<<'\n';
        for(int i = 0; i < 4; i++){
            int x = top.first + dx[i];
            int y = top.second + dy[i];
            if(inGrid(x, y) && a[x][y] != -1){
                //cout<<"TO: "<< " " << x <<" "<< y<<" "<<F[x][y]<<'\n';
                if(F[x][y] > F[top.first][top.second] + a[x][y]) {
                    F[x][y] = F[top.first][top.second] + a[x][y];
                    trace[x][y] = i;
                    q.push({x,y});
                    //cout<<"push: " << x << " " << y <<'\n';
                }
            }
        }
    }

    if(F[finish.first][finish.second] == 1e9) {
        cout << -1 << '\n';
        return 0;
    }
    else cout <<F[finish.first][finish.second] <<'\n';

    q.push(finish);
    vector<char> res;
    //cout <<"Tracing...!\n";
    while(true){
        if(finish.first == start.first && finish.second == start.second) break;
        int x = finish.first, y = finish.second;
        //cout<<"trace: "<<x<<" "<<y<<" "<<trace[x][y]<<'\n';
        switch (trace[x][y]) {
            case 0:
                res.pb('N');
                break;
            case 1:
                res.pb('E');
                break;
            case 2:
                res.pb('S');
                break;
            case 3:
                res.pb('W');
                break;
        }
        finish.first = x - dx[trace[x][y]];
        finish.second = y - dy[trace[x][y]];
        //cout<<finish.first<<" "<<finish.second<<'\n';
        //exit(0);
    }

    reverse(res.begin(), res.end());
    for(char x : res) cout << x;
}

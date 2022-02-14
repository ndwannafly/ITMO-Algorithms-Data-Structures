#include <iostream>
#include <map>
using namespace std;

#define  NMAX 1005

int n, m;
int a[NMAX][NMAX];

int main() {
    //freopen("Q.inp", "r", stdin);

    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    int res = 0;

    map<int,int> cnt;

    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i > n - i + 1) continue;
            if(j > m - j + 1) continue;
            if(i == n - i + 1){
                if( a[i][j] != a[i][m - j + 1]) ++res;
                continue;
            }
            if(j == m - j + 1){
                //cout << "here " << i << " "<<j <<'\n';
                if(a[i][j] != a[n - i + 1][j]) ++res;
                continue;
            }
            int x1 = a[i][j];
            int x2 = a[i][m - j + 1];
            int x3 = a[n - i + 1][j];
            int x4 = a[n - i + 1][m - j + 1];
            cnt.clear();
            cnt[x1]++;
            cnt[x2]++;
            cnt[x3]++;
            cnt[x4]++;

            int optimal = -1e9;
            optimal = max(optimal, cnt[x1]);
            optimal = max(optimal, cnt[x2]);
            optimal = max(optimal, cnt[x3]);
            optimal = max(optimal, cnt[x4]);
            //cout<<i << " "<< j << " "<< optimal << '\n';
            res += 4 - optimal;
        }
    }

    cout << res;
}

#include <iostream>

using namespace std;

#define NMAX 100005
#define pb push_back

int n, k;
int a[NMAX];

bool check(int dis){
    int cnt = 1;
    int now = a[1];
    for(int i = 1; i <= n-1; i++){
        if(a[i+1] - now >= dis) {
            ++cnt;
            now = a[i + 1];
        }
    }
    return cnt >= k;
}

int main() {
    //freopen("E.inp", "r", stdin);

    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int l = 1 , r = 1e9;
    int res = -1;
    while(l <= r){
        int m = (l + r) >> 1;
        if(check(m)){
            res = m;
            l = m + 1;
        } else r = m-1;
    }

    cout << res;
}

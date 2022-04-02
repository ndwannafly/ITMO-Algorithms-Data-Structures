#include <iostream>

using namespace std;

#define  NMAX 200005

int n;
int a[NMAX];
pair<int,int> res;

bool isGoodSegment(int l, int r){ // for two pointer subtask
    if(r - l < 2) return true;
    if(a[l] == a[l+1] && a[l+1] == a[l+2]) return false;
    if(a[r] == a[r-1] && a[r-1] == a[r-2]) return false;
    return true;
}


int main() {
    ios_base::sync_with_stdio(0);
    //freopen("A.inp", "r", stdin);
    //freopen("A.out", "w", stdout);
    cin>>n;
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
    }

    int l = 0, r = min(1, n - 1);
    int optLength = r - l + 1;
    res = {l, r};
    //cout<< res.first<<" "<<res.second<<'\n';
    while(1){
        if(l > r) break;
        if(l >= n || r >= n )break;
        if(isGoodSegment(l, r)){
            if(optLength < r - l + 1){
                optLength = r - l + 1;
                res = {l ,r};
            }
            ++r;
        }
        else{
            ++l;
        }
    }

    cout << res.first + 1<<" "<<res.second + 1;
}

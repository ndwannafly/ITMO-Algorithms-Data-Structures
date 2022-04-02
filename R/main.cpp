#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define  NMAX 100005
#define  pb push_back

int n, m, s;
int a[NMAX];
vector <int> v;

bool check(int num, int pos){
    //cout<< num <<" " << pos <<'\n';
    int cnt = upper_bound(v.begin(), v.end(), num + m - 1) - v.begin() - pos;
    //cout << "cnt: "<< cnt <<'\n';
    if(cnt + s >= m) return true;
    return false;

}

int main() {

    //freopen("R.inp", "r", stdin);

    ios_base::sync_with_stdio(false);

    cin >> n >> m >> s;

    map<int, bool> exist;

    for(int i = 0 ; i < m; i++){
        cin >> a[i];
        if(!exist[a[i]]){
            exist[a[i]] = true;
            v.pb(a[i]);
        }
    }

    sort(v.begin(), v.end());

    //cout << check(4);
    //return 0;

/*    for(int x : v) cout << x <<" ";
    cout<<'\n';*/

    int res = 0;
    //cout << check(1, 0);
    //return 0;
    for(int i = 0 ; i < v.size(); i++){
        if(!check(v[i],i)) continue;
        int l;
        if(i) l = v[i-1] + 1;
        else l = 1;
        int r = v[i];
        int optimal = r;
        while(l <= r){
            int mid = (l + r) >> 1;
            //cout<< "check: "<< mid << " "<< i << " " << l << " "<< r <<'\n';
            if(check(mid, i)){
                optimal = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        //cout<< i << " "<< v[i] << " "<< optimal << '\n';
        //exit(0);
        if(v[i] + m - 1 > n) { // not exceed n
            if(n - m + 1 < optimal) break;
            res += (n - m + 1) - optimal + 1;
            //cout<<"Get 1: "<< optimal <<" "<< n - m + 1 << " " << (n - m + 1 ) - optimal + 1 << '\n';
        }
        else {
            res += v[i] - optimal + 1;
            //cout<<"Get 2: "<< optimal <<" "<< v[i] << " "<<v[i]-  optimal + 1 << '\n';
        }
    }

    cout<< res;

}

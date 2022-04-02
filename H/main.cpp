#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define  NMAX 100005

int n, k;
int a[NMAX], s[NMAX];

void subtask_dp_n2(){
    int dp[NMAX];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++){
        for(int j = i; j >= 1; j--){
            int free = (i - j + 1) / k;
            dp[i] = max(dp[i], dp[j-1] + s[i] - s[i - free]);
            //cout << i <<" " <<j <<" "<<free<<" "<<dp[i]<<'\n';
        }
    }
    cout<<s[n] - dp[n];
}

void subtask_full(){
    int free = 0;
    int x = k;
    while(x <= n){
        free += a[x];
        x = x + k;
    }

    cout<<s[n] - free;
}

int main() {
    //freopen("H.inp", "r", stdin);

    // gentest
/*    srand(time(NULL));
    freopen("H.inp", "w", stdout);

    cout << 5000 <<" "<< 100<<'\n';
    for(int i = 1; i <= 5000; i++){
        cout << rand() % 10000 + 1<<" ";
     }

    return 0;*/
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a+1, a + n + 1, [](int &x, int &y){
        return x > y;
    });

    for(int i = 1; i <= n; i++){
        //cout << a[i] << " ";
        s[i] = s[i-1] + a[i];
    }

    //cout << '\n';

    if ( n <= 5000){
        subtask_dp_n2();
    } else{
        subtask_full();
    }
}

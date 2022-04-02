#include <iostream>

using namespace std;

typedef long long ll;

ll a, b, c, d, k;

ll solve(ll day){
    ll num = a;
    while(day--){
        num = num * b;
        num = max(num - c , 0ll);
        if(num > d) num = d;
    }
    return num;
}
int main() {
    //freopen("D.inp", "r", stdin);
    cin >> a >> b >> c >> d >> k;

    if(k <= 100000){
        cout << solve(k);
    } else{
        cout <<solve(100000);
    }
}

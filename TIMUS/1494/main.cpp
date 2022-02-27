#include <iostream>
#include <set>
using namespace std;

#define  NMAX 100005
#define  pb push_back

int n;
int a[NMAX];
int l[NMAX];
set<int> v;

int main() {
    //freopen("1494.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        l[i] = max(l[i-1], a[i]);
    }

    for(int i = n; i >= 1; i--){
        //cout << "i: "<<i<<" x: ";
       if(!v.empty()){
           auto x = v.upper_bound(a[i]);
           if(x != v.end()) {
               //cout << *x;
               if(l[i-1] > *x){
                   cout << "Cheater";
                   return 0;
               }
           } else {
               //cout <<"no x";
           }
       }
       //cout<<'\n';
       v.insert(a[i]);
    }

    cout << "Not a proof";

}

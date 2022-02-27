#include <iostream>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
        long long n, k;
        cin >> n >> k;
        long long a, b, x, y;
        a= n/k;
        b= a+1;
        x= k - n%k;
        y= n%k;
        cout << a*b*x*y + x*(x-1)*a*a/2 + y*(y-1)*b*b/2<<'\n';
    }
}
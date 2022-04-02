//
// Created by ndwannafly on 2/10/22.
//
#include "bits/stdc++.h"
using namespace std;

int main(){
    srand(time(NULL));
    freopen("./A.inp", "w", stdout);
    int n = rand() % 2000 + 1;

    cout << n <<'\n';
    for(int i = 1 ; i <= n ; i++){
        cout<< rand() % 5 + 1 <<" ";
    }
}

#include <iostream>
#include <algorithm>

using namespace std;

#define NMAX 105

string s[NMAX];
int n;


int main() {

    //freopen("F.inp", "r", stdin);

    while(cin >> s[++n]);
    --n;
/*    cout << "n: " << n << '\n';
    for(int i = 1; i <= n; i++){
        cout << s[i]<<'\n';
    }
    cout<<'\n';*/
    sort(s + 1, s + n + 1, [](string x, string y){
        string s1 = x + y;
        string s2 = y + x;
        //cout<<"compare: \n"<<x<<'\n'<<y<<'\n'<<s1 <<"\n"<<s2<<'\n';

        for(int i = 0; i < s1.size();i++){
            //cout<<i<<'\n';
            if(s1[i] == s2[i]) continue;
            return s1[i] > s2[i];
        }

        return false;
    });

    //cout <<"Here\n";
    for(int i = 1; i <= n; i++){
        cout << s[i];
    }
}

// 20 201 =>  20201 > 20120

// 20 204 => 20420 > 20204

// 20 20203 => 2020320 > 2020203
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define pb push_back
#define NMAX 100005
int n, cnt;
int ord[NMAX], res[NMAX];
string s;

bool isLowerCase(char c){
    return c >= 'a' && c <= 'z';
}


int main() {
    //freopen("B.inp","r", stdin);

    cin >> s;
    n = s.size();
    for(int i = 0; i < n; i++){
        if(isLowerCase(s[i])) ord[i] = ++cnt;
    }
    stack<pair<char,int>> st;

    for(int i = 0 ; i < s.size(); i++){
        //if(!st.empty()) cout <<st.top().first<<" "<<s[i]<<'\n';
        if(!st.empty() && abs(st.top().first - s[i]) == 32){
            if(isLowerCase(s[i])) res[st.top().second] = ord[i];
            else res[i] = ord[st.top().second];
            //cout<<"hihi"<<'\n';
            st.pop();
            continue;
        }
        st.push({s[i], i});
    }

    if(st.empty()) {
        cout << "Possible\n";
        for(int i = 0; i < n; i++) if(!isLowerCase(s[i])) cout << res[i]<<" ";
    }
    else cout <<"Impossible\n";
}

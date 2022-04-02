#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define pb push_back
typedef pair<int,int> pii;

map<string, int> val; // current value

void recursion(){
    string s;

    vector<pair<string,int>> v; // variable and old value

    while(cin >> s){
        //cout <<'\n';
        if(s[0] == '{'){
            recursion();
            continue;
        }
        if(s[0] == '}'){
            //cout<<"Restore: \n";
            for(int i = v.size() - 1; i >= 0; i--){
                val[v[i].first] = v[i].second;
                //cout <<v[i].first<<" "<<v[i].second<<'\n';
            }
            return ;
        }
        string l = "";
        bool isConstant = false, neg = false;
        int now = 0;
        while(now < s.size()){
            if(s[now] == '='){
                ++now;
                break;
            }
            l += s[now++];
        }

        if(s[now] == '-' || (s[now] >= '0' && s[now] <= '9')) {
            isConstant = true;
            if(s[now] == '-') {
                ++now;
                neg = true;
            }
        }

        string r = "";
        int num = 0;
        while(now < s.size()) {
            if(isConstant) num = num * 10 + s[now] - '0';
            else{
                r = r + s[now];
            }
            ++now;
        }
        if(neg) num = -num;
        if(!isConstant) {
            num = val[r];
            //cout<<"assign: "<< l <<"="<<r<<"\nresult: "<<val[r]<<'\n';
            cout <<num<<'\n';
        }
        v.pb({l, val[l]});
        val[l] = num;
        //cout <<"assign: "<<l<<" "<<num<<'\n';
    }


}

int main() {
    freopen("C.inp", "r", stdin);
    recursion();
}

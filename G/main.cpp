#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> pii;
#define pb push_back

int n;
int w[27];
int cnt[27];
string s;
vector<pii> v;

int main() {

    //freopen("G.inp","r", stdin);

    cin >> s;
    for(int i = 0 ; i < 26; i++) {
        cin >> w[i];
    }

    n = s.size();

    for(char c : s){
        if(!cnt[c - 'a']){
            v.pb({-w[c -'a'], c - 'a'});
        }
        cnt[c -'a']++;
    }



    sort(v.begin(), v.end());

    /*for(auto x : v){
        cout << x.first<<" "<<char(x.second + 'a')<<" " << cnt[x.second]<<'\n';
    }*/

    int now = 0;
    for(auto x : v){
        if(cnt[x.second] >= 2){
            s[now] = char(x.second + 'a');
            s[n - now - 1] = char(x.second + 'a');
            //cout<<"write: "<<now<<" "<<s[now]<<'\n';
            //cout<<"write: "<<n - now - 1 <<" "<<s[now]<<'\n';
            //cout<<'\n';
            cnt[x.second] -= 2;
            ++now;
        }
    }
    for(auto x: v){
        while(cnt[x.second] > 0){
            s[now++] = char(x.second + 'a');
            //cout<<"write: "<<now<<" "<<s[now]<<'\n';
            --cnt[x.second];
        }
    }
    cout << s;
}

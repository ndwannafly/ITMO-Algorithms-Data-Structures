#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
#define NMAX 100005
#define pb push_back

int n, k, p;
int R[500005], L[500005];
int query[500005];
bool used[NMAX];

vector <pii> v;
set<pii> s;

int main() {
    //freopen("I.inp", "r", stdin);
    cin >> n >> k >> p;

    for(int i = 1; i <= p; i++){
        L[i] = 0, R[i] = p+1;
        cin >> query[i];
        v.pb({query[i], i});
    }

    sort(v.begin(), v.end());

    /*for(auto x : v){
        cout << x.first << " " << x.second <<'\n';

    }*/

    for(int i = 0; i < v.size() - 1; i++){
        if(v[i].first == v[i+1].first) {
            R[v[i].second] = v[i + 1].second;
            L[v[i + 1].second] = v[i].second;
        }
    }

/*    for(int i = 1 ; i <= p; i++){
        cout<<i<<" "<<L[i]<<" "<<R[i]<<'\n';
    }
    cout<<'\n';*/
    int res = 0;

    for(int i = 1; i <= p; i++){
        //cout << query[i]<<" ";
        if(s.size() < k){
            if(!used[query[i]]){
                s.insert({-R[i], i});
                used[query[i]] = true;
           /*     cout<<"insert: "<<-R[i]<<" " << i<<'\n';
                cout<<"take: " << query[i]<<"\n\n";*/
                ++res;
            } else{
                s.erase({-i, L[i]});
                s.insert({-R[i], i});
                /*cout<<"insert: "<<-R[i] <<" " << i << '\n';
                cout <<"fixed right: "<<" "<<query[i]<<" "<<R[i]<<"\n\n";*/
            }
        } else{
            if(!used[query[i]]) {
                pii furthest = *s.begin();
                s.erase(s.begin());
                s.insert({-R[i], i});
               /* cout << "insert: " << -R[i] << " " << i << '\n';
                cout << "erase: " << query[furthest.second] << '\n';
                cout << "take: " << query[i] << "\n\n";*/
                used[query[i]] = true;
                used[query[furthest.second]] = false;
                ++res;
            } else{
                s.erase({-i, L[i]});
                s.insert({-R[i], i});
                /*cout<<"insert: "<<-R[i] <<" " << i << '\n';
                cout <<"fixed right: "<<" "<<query[i]<<" "<<R[i]<<"\n\n";*/
            }
        }
    }

    //cout << '\n';
    cout << res;
}

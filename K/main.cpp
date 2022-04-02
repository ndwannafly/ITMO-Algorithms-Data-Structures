#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define  NMAX 100005
typedef pair<int,int> pii;
set<pii> s;

int n, m;
pii record[NMAX];
bool done[NMAX];
map<int,int> trace_left, trace_right;

void allocate(int id, int x){
    //cout<<"allocate "<<x<<'\n';
    if(s.empty()) {
        done[id] = false;
        cout<<-1<<'\n';
        return;
    }
    pii best_segment = *s.begin();
    int free_space = -best_segment.first;
    int start_pos = best_segment.second;
    //cout<<"(free_space, start_pos) = " << "(" <<free_space <<", "<<start_pos<<")\n";
    if(free_space - x  >= 0) {
        s.erase(s.begin());
        cout << start_pos <<'\n';
        //cout<<"allocated: "<<"(l,r) = " << "("<<start_pos <<","<<start_pos + x - 1<<")\n\n";
        record[id] = {start_pos, x};

        if( -free_space + x < 0) {
            s.insert({-free_space + x, start_pos + x}); // narrow the segment
        }

        int r = start_pos + free_space - 1;
        trace_right[start_pos] = 0;
        trace_right[start_pos + x] = r;
        trace_left[r] = start_pos + x;

        done[id] = true;
        return;
    }
    done[id] = false;
    cout<<-1<<'\n';
}


void deallocate(int x){
    if(!done[x]) {
        //cout<<-1<<'\n';
        return;
    }
    //cout<<"Deallocate " << x << '\n';
    int l = record[x].first;
    int r = l + record[x].second - 1;
    //cout<<"(l,r) = " << "("<<l <<","<<r<<")\n";
    //cout<<"trace_right: "<<r+1<<" "<<trace_right[r+1]<<'\n';
    //cout<<"trace_left: "<<l-1<<" "<<trace_left[l-1]<<"\n\n";
    if(!trace_right[r+1] && !trace_left[l-1]) {
        s.insert({-(r - l + 1), l});
        //cout<<"new segment "<<"(l,r) = " << "("<<l <<","<<r<<")\n";

        trace_right[l] = r;
        trace_left[r] = l;
        return;
    }
    if(trace_right[r+1] && trace_left[l-1]){
        int len_right = trace_right[r+1] - (r+1) + 1;
        s.erase({-len_right, r+1});

        int len_left = (l-1) - (trace_left[l-1]) + 1;
        s.erase({-len_left, trace_left[l-1]});

        int rr = trace_right[r+1];
        int ll = trace_left[l-1];

        trace_right[r+1] = 0; // reset
        trace_left[l-1] = 0;

        trace_right[ll] = rr; //expand
        trace_left[rr] = ll;
        s.insert({-(rr - ll + 1), ll});
        //cout<<"new segment "<<"(l,r) = " << "("<<ll <<","<<rr<<")\n";
        return ;
    }

    if(trace_right[r+1]){
        int len_right = trace_right[r+1] - (r+1) + 1;
        s.erase({-len_right, r+1});

        int rr = trace_right[r+1];

        trace_right[r+1] = 0;
        trace_right[l] = rr;
        trace_left[rr] = l;
        s.insert({-(rr - l + 1), l});
        //cout<<"new segment "<<"(l,r) = " << "("<<l <<","<<rr<<")\n";
        return ;
    }

    if(trace_left[l-1]){
        int len_left = (l-1) - (trace_left[l-1]) + 1;
        s.erase({-len_left, trace_left[l-1]});
        //cout <<"trace_left: "<< len_left<<" "<<l<<" "<<trace_left[l-1]<<'\n';
        int ll = trace_left[l-1];
        s.insert({ - (r - ll + 1), ll});

        trace_left[l-1] = 0;
        trace_left[r] = ll;
        trace_right[ll] = r;
        //cout<<"new segment "<<"(l,r) = " << "("<<ll <<","<<r<<")\n";
        return;
    }

}
int main() {
    //freopen("K.inp", "r", stdin);
    //freopen("K.out","w",stdout);
    cin >> n >> m;

    s.insert({-n, 1});
    trace_left[n] = 1;
    trace_right[1] = n;
    for(int i = 1 ; i <= m; i++){
        int x;
        cin >> x;
        //cout<<"size: "<<s.size()<<'\n';
        if(x > 0) allocate(i, x);
        else deallocate(-x);
    }
}

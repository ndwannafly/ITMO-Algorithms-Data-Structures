#include <iostream>
#include <deque>

using namespace std;

// l : 1 -> mid
// r : r -> mid
deque<int> l, r;


int main() {
    //freopen("J.inp", "r", stdin);

    int n;
    cin >> n;
    while(n--){
        char type;
        cin >>type;
        if(type == '+'){
            int num;
            cin >> num;
            r.push_back(num);
        }
        else if(type == '*'){
            int num;
            cin >> num;
            //l.push_back(num);
            r.push_front(num);
        } else if(type == '-'){
            cout<<l.front()<<'\n';
            l.pop_front();
        }
        if(l.size() < r.size()){
            l.push_back(r.front());
            r.pop_front();
        }
    }

}

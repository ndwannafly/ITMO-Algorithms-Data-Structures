#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back
typedef pair<int,int> pii;

int v[8];

char vertex[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

vector <char> res;
void record(char x, char y, char sign){
    res.pb(x);
    res.pb(y);
    res.pb(sign);
    res.pb('\n');
}

void destroy(int a, int b){
    while(v[a] && v[b]){
        record(vertex[a], vertex[b], '-');
        v[a]--;
        v[b]--;
    }
}

void move3(int a,int b, int c){
    while(v[a]){
        record(vertex[b], vertex[c], '+');
        record(vertex[a], vertex[b], '-');
        v[a]--;
        v[c]++;
    }
}
bool isAdjacent(int a, int b){
    if(a > b) swap(a, b);
    if (b - a == 4) return true;
    if (a < 4 && b >= 4) return false;
    if (b - a == 3) return true;
    if(a + 1 == b) return true;
    return false;
}

int main(){

    //freopen("1155.inp","r",stdin);
    for(int i = 0; i < 8; i++) cin >> v[i];

    if(v[0] + v[2] + v[5] + v[7] != v[1] + v[3] + v[6] + v[4]){
        cout <<"IMPOSSIBLE";
        return 0;
    }

    for(int i = 0 ; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(isAdjacent(i, j)){
                destroy(i ,j);
            }
        }
    }
    // all -> A
    if(v[5]) move3(5, 1, 0); // F-> B -> A
    if(v[7]) move3(7, 4, 0); // H -> E -> A
    if(v[2]) move3(2,1, 0); // C -> B -> A

    // all -> B
    if(v[3]) move3(3, 2, 1); // D -> C -> B
    if(v[4]) move3(4, 0, 1); // E -> A -> B
    if(v[6]) move3(6, 2, 1); // G -> C -> B

    destroy(0, 1);
    for(int i = 0; i < 8; i++){
        if(v[i] > 0){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    for(char c: res) cout << c;
}

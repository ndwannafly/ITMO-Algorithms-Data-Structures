#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void read (T &x){
    bool nega=0;
    char c;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}

#define  NMAX 200005
#define  pb push_back
typedef long long ll;



const ll base = 1000000000000000007;


int n;
ll a[NMAX];
ll sum[NMAX];

void add(ll &x, ll y){
    x += y;
    if(x >= base) x -= base;
}

ll fastModularMultiplication(ll x, ll y) { // circle modular method
    x %= base;
    y %= base;
    ll q = (ll)((long double) x * y / base);
    ll r = x * y - q * base;
    while(r < 0) r += base;
    while(r >= base) r -= base;
    return r;
}


ll power2(ll p){
    if(p == 0) return 1ll;
    ll tmp = power2(p/2);
    if(p & 1) return fastModularMultiplication(fastModularMultiplication(tmp,tmp),2);
    return fastModularMultiplication(tmp,tmp) % base;
}

ll subtaskn2log(){
    //cout<<pw(123123123);
    //return 0;
    int res = 0;
    ll upper = (ll)(log2(n));

    //TODO: https://codeforces.com/blog/entry/60737
    // why when I use it's slower???
    unordered_set<ll> marked; // faster than unordered_map
    unordered_map<ll, bool> existPw; // no need to optimize yet because only nlogn operations

    for(int i = 1;  i <= n; i++){ // nlogn
        for(ll j = a[i]; j <= a[i] + upper; j++){
            if(!existPw[j]) marked.insert(power2(j));
            existPw[j] = true;
        }
    }

    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1];
        add(sum[i], power2(a[i]));
        //sum[i] = (sum[i-1] + pw(a[i])) % base;
        //cout<<i<<" "<< sum[i]<<'\n';
    }

    for(int i = 1 ; i <= n; i++){
        for(int j = i; j <= n; j++){
            ll x = sum[j] - sum[i-1];
            add(x, base);
            if(marked.count(x)) ++res;
            //res += marked[x];
        }
    }

    return res;

}

ll brute_force(){
    ll res = 0 ;

    for(int i = 1; i <= n; i++){
        vector <int> v;
        for(int j = i; j <= n; j++){
            v.pb(a[j]);
            map<int, int> record;
            for(int x : v){
                record[x]++;
            }
            while(!record.empty() && record.begin()->second > 1){
                /* if(i== 1 && j == 7){
                    cout<<record.begin()->first<<" "<<record.begin()->second<<" "<<record.size()<<'\n';
                }*/
                record[record.begin()->first + 1]++;
                record.begin()->second -= 2;
                if(record.begin()->second == 0) record.erase(record.begin());
            }

            if(record.size() == 1) {
                //cout<< "(i,j) "<<'('<<i<<','<<j<<")\n";
                ++res;
            }
        }
    }
    return res;
}

int main() {


    //freopen("T.inp", "r", stdin);
    read(n);

    for (int i = 1; i <= n; i++){
        read(a[i]);
    }
    if(n <= 100) write(brute_force());
    else write(subtaskn2log());

}

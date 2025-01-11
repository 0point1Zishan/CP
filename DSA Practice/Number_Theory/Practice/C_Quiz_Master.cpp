#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define int long long
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define print_v(v) for(auto it : v) cout << it << " "; cout << nline;
#define print_v_pair(v) for(auto it: v) cout << it.first << " " << it.second << nline;
#define input_v for(auto &it : v)   cin >> it;

typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << nline;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const int N = 1e5;
vector<int> fac[N+1];

void solve(){

    int n, m;   cin >> n >> m;
    vector<int> v(n), cnt(m+1, 0);

    input_v(v);
    sort(all(v));

    int s = 0, r = 0, k = 0;
    int ans = INT_MAX;
    while(s < n){

        while(r < n && k < m){

            for(auto &it: fac[v[r]]){
                if(it > m)      break;

                cnt[it]++;
                if(cnt[it] == 1)    k++;
            }
            r++;
        }

        if(k == m)  ans = min(ans, v[r-1] - v[s]);
        for(auto &it: fac[v[s]]){

            if(it > m)  break;

            cnt[it]--;

            if(cnt[it] == 0)    k--;
        }
        s++;
    }

    cout << (ans == INT_MAX ?   -1  : ans ) << nline;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    fastio();
    int t = 1;   	
    cin >> t;

    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j+= i){
            fac[j].push_back(i);
        }
    }

    while(t--){     solve(); }
    return 0;
}

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define int long long int
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // less == set, less_equal == multiset;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << nline;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(bool t) {cerr << t;}
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

void solve(){

    int n;  cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    auto isPos = [&](int k){
        vector<bool> a(n+1, 0), b(n+1, 0);
        a[0] = 1;

        for(int i = 0; i < n; i++){
            vector<bool> t_a(n+1, 0), t_b(n+1, 0);

            if(a[i]){
                if(abs(v[i+1] - v[i] <= k) && i + 1 < n)  t_a[i+2] = 1;
                if(k >= 1) t_b[i+1] = 1;
            }
            
            if(b[i]){
                if(abs(v[i+1] - v[i]) <= k && i + 1 < n) t_b[i+2] = 1;
            }
            debug(t_a)
            debug(t_b)
            for(int j = 0; j <= n; j++){
                if(t_a[j]) a[j] = 1;
                if(t_b[j]) b[j] = 1;
            }
        }
        if(a[n] || b[n]){
            return true;
        }
        else return false;
    };
    
    int l = 0, r = 1e18;
    int mn = r;
    int mid = l + (r - l) / 2;
    while(l <= r){
        if(isPos(mid)){
            debug(mid)
            mn = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
        mid = l + (r - l) / 2;
    }
    cout << mn << "\n";

}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    fastio();
    int t = 1;
    cin >> t;
    while(t--){     solve(); }
    return 0;
}
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

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.ss < b.ss;
}

void solve(){

    int n;  cin >> n;
    vector<pair<int, int> > pr(n);
    for(int i = 0; i < n; i++)  cin >> pr[i].ff >> pr[i].ss;

    sort(pr.begin(), pr.end(), cmp);
    // debug(pr)

    int s = 0, e = n-1;
    int ans = 0;

    // int f = 0;
    while(s < e){
        // debug(s)
        // debug(e)
        // debug(pr[s].ss + pr[e].ss)
        if(pr[s].ff < pr[e].ff){
            ans = max(ans, pr[s].ss + pr[e].ss);
            pr[e].ff -= pr[s].ff;
            pr[s].ff = 0;
            s++;
        }

        else if(pr[s].ff > pr[e].ff){
            ans = max(ans, pr[s].ss + pr[e].ss);
            pr[s].ff -= pr[e].ff;
            pr[e].ff = 0;
            e--;
        }
        else{
            ans = max(ans, pr[s].ss + pr[e].ss);
            pr[s].ff = 0;
            pr[e].ff = 0;
            s++;
            e--;
        }
    }

    if(s == e && pr[s].ff > 0)  ans = max(ans, pr[s].ss + pr[s].ss);
    cout << ans << nline;
    
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    fastio();
    int t = 1;   	
    // cin >> t;
    while(t--){     solve(); }
    return 0;
}
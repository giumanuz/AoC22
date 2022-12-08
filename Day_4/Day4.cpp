#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
template<class T> using V = vector<T>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i, a, b) for (int i = (a); i >= b; i--)
#define feach(a, x) for (auto& a : x)
 
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define pb push_back
 
 
void _print(int x) {cerr << x;}
void _print(ll x) {cerr << x;}
void _print(unsigned long long x) {cerr << x;}
void _print(double x) {cerr << x;}
void _print(ld x) {cerr << x;}
void _print(bool x) {cerr << (x ? "true" : "false");}
void _print(char x) {cerr << x;}
void _print(string x) {cerr << x;}
 
template <class T1, class T2> void _print(pair<T1, T2> p) {cerr << "("; _print(p.first); cerr << " "; _print(p.second); cerr << ")";}
template <class T> void _print(vector<T> v) {cerr << "[ "; for (T x : v) {_print(x); cerr << " ";} cerr << "]";}
template <class T> void _print(set<T> s) {cerr << "{ "; for (T x : s) {_print(x); cerr << " ";} cerr << "}";}
//template <class T1, class T2> void _print(map<T1, T2> m) {cerr << "{ "; for (auto x : m) {_print(x); cerr << " ";} cerr << "}";}
 
const int MOD = 1000000007;
const char nl = '\n';
 
/* ---------- Code here ---------- */
 
void solve1() {
    int a,b,c,d,n, result=0;
    char ch;
    ifstream file("Day4_test1.txt");
    string str;
    while (getline(file, str))
    {
        stringstream ss(str);
        ss>>a>>ch>>b>>ch>>c>>ch>>d;
        if (a<=c&&b>=d || a>=c&&b<=d)
            result+=1;
    }
    cout<<result<<nl;
}

void solve2() {
    int a,b,c,d,n, result=0;
    char ch;
    ifstream file("Day4_test2.txt");
    string str;
    while (getline(file, str))
    {
        stringstream ss(str);
        ss>>a>>ch>>b>>ch>>c>>ch>>d;
        if (a<=c&&c<=b || a>c&&a<=d)
            result+=1;
    }
    cout<<result<<nl;
}
 
/* ---------- Main here ---------- */
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    solve1();
    solve2();
}



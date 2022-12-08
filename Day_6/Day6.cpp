#include <bits/stdc++.h>
#include <stdio.h>
#ifdef Giulio
    #include <bits/debug.h>
#else
    #define dbg(...)
#endif

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
 
 
const int MOD = 1000000007;
const char nl = '\n';
 
/* ---------- Code here ---------- */
 
void solve1() {
    int a, result=0;
    ifstream file("test1.txt");
    string str;
    map<char, int> m;
    getline(file, str);
    int i=0, fine=0;

    while(i<str.size()) {
       if (m.size()==4) {dbg(m); break;}
        if (!m.count(str[i]))
            m[str[i]]=i;
        else{
            fine = m[str[i]]+1;
            m[str[i]]=i;
            vi copia;
            for(auto &[key,value]: m)
                if (value<fine) copia.push_back(key);
            feach(x, copia) m.erase(x);
        }
        i+=1;
    }
    cout << i << endl;
}
void solve2() {
    int a, result=0;
    ifstream file("test2.txt");
    string str;
    map<char, int> m;
    getline(file, str);
    int i=0, fine=0;

    while(i<str.size()) {
       if (m.size()==14) {dbg(m); break;}
        if (!m.count(str[i]))
            m[str[i]]=i;
        else{
            fine = m[str[i]];
            m[str[i]]=i;
            vi copia;
            for(auto &[key,value]: m)
                if (value<fine) copia.push_back(key);
            feach(x, copia) m.erase(x);
        }
        i+=1;
        dbg(m,i)
    }
    cout << i << endl;
}
 
/* ---------- Main here ---------- */
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    //solve1();
    solve2();
}
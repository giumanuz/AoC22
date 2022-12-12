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
    ifstream file("test1.txt");
    string str;
    string stringa; int n;
    int tot=1, conta=0, result=0;
    bool trovato=false;
    set<int> numbers{20, 60, 100, 140, 180, 220};
    while (getline(file, str)){
        stringstream ss(str);
        ss >> stringa;
        if (stringa== "addx"){
            ss>>n;
            conta+=1;
            if (numbers.count(conta)==1)
                result+=tot*conta;
            conta+=1;
            if (numbers.count(conta)==1)
                result+=tot*conta;
            tot+=n;
        }
        else{
            conta+=1;
            if (numbers.count(conta)==1)
                result+=tot*conta;
        }        
    }
    cout<<result<<nl;
}
void solve2() {
    ifstream file("test2.txt");
    string result, str, a;
    vll v(42,0);
    ll tot=1;
    v[tot-1]=1; v[tot]=1; v[tot+1]=1;
    int n,conta=0;
    while (getline(file, str)){
        stringstream ss(str);
        ss >> a;
        if (a== "addx"){
            ss>>n;
            dbg(v);
            if(v[conta%40]==1) result+='#';
            else result+=' ';
            conta+=1;

            if(v[conta%40]==1) result+='#';
            else result+=' ';
            conta+=1;

            if (tot-1>=0) v[tot-1]=0; 
            if (tot>=0) v[tot]=0; 
            if (tot+1>=0) v[tot+1]=0;
            tot+=n;
            if (tot-1>=0) v[tot-1]=1; 
            if (tot>=0) v[tot]=1; 
            if (tot+1>=0) v[tot+1]=1;
        }
        else{
            if(v[conta%40]==1) result+='#';
            else result+=' ';
            conta+=1;
        }        
    }
    FOR(i, 0, result.size()){
        cout<<result[i];
        if ((i+1)%40==0)
            cout<<nl;
    }
}

/* ---------- Main here ---------- */
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    solve1();
    solve2();

}



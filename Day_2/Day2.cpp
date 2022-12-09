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
    char a,b;
    int result=0;
    while (getline(file, str)){
        stringstream ss(str);
        ss>>a>>b;
        a-='A';
        b-='X';
        result+=b+1;
        if (a==b) result+=3;
        else if ((a+1)%3 == b)result+=6;
    }
    
    cout<<result<<nl;
}

void solve2() {
    ifstream file("test2.txt");
    string str;
    char a,b;
    int result=0;
    while (getline(file, str)){
        stringstream ss(str);
        ss>>a>>b;
        a-='A';
        b-='X';
        result+=b*3;
        if (b==2) result+=(a+1)%3+1;
        else if (b==1) result+=a+1;
        else result+=(a+2)%3+1;
    }
    
    cout<<result<<nl;
}
 
/* ---------- Main here ---------- */
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    solve1();
    solve2();

}



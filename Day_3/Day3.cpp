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
        string s1=str.substr(0,str.size()/2);
        string s2=str.substr(str.size()/2, str.size()/2);
        set<char> s;
        feach(x, s1) s.insert(x);
        feach(x, s2) 
            if (s.count(x)==1){
                if (x-'A'>26) result+=x-'a'+1;
                else result+=x-'A'+1+26;
                break;
            }
        
    }
    
    cout<<result<<nl;
}

void solve2() {
    ifstream file("test2.txt");
    string str1, str2, str3;
    char a,b;
    int result=0;
    while (getline(file, str1)){
        getline(file, str2);
        getline(file, str3);
        set<char> s1, s2, s3;
        feach(x, str1) s1.insert(x);
        feach(x, str2) s2.insert(x);
        feach(x, str3) s3.insert(x);
        feach(x, s1)
            if (s2.count(x)==1 && s3.count(x)==1){
                if (x-'A'>26) result+=x-'a'+1;
                else result+=x-'A'+1+26;
                break;
            }
    }
    cout<<result<<nl;
}


/* ---------- Main here ---------- */
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    solve1();
    solve2();

}



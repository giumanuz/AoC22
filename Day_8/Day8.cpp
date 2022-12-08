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

bool check(vector<string> v, int i, int j){
    int x=i, y=j;
    while(x-1!=-1 && v[i][j]>v[x-1][y]) x--;
    if (x==0) return true;
    x=i; y=j;
    while(x+1!=v.size() && v[i][j]>v[x+1][y]) x++;
    if (x==v.size()-1) return true;
    x=i; y=j;
    while(y-1!=-1 && v[i][j]>v[x][y-1]) y--;
    if (y==0) return true;
    x=i; y=j;
    while(y+1!=v.size() && v[i][j]>v[x][y+1]) y++;
    if (y==v.size()-1) return true;

    return false;
}

int check2(vector<vector<int>> v, int i, int j){
    int x=i, y=j;
    int result=1;

    while(x-1!=-1 && v[i][j]>v[--x][y]) ;
    if (x!=i) result*=abs(i-x);

    x=i; y=j;
    while(x+1!=v.size() && v[i][j]>v[++x][y]);
    if (x!=i) result*=abs(x-i);

    x=i; y=j;
    while(y-1!=-1 && v[i][j]>v[x][--y]) ;
    if (y!=j) result*=abs(j-y);

    x=i; y=j;
    while(y+1!=v.size() && v[i][j]>v[x][++y]) ;
    if (y!=j) result*=abs(y-j);

    return result;
}

void solve1() {
    ifstream file("test1.txt");
    string str;
    vector<string> v;
    while (getline(file, str))
        v.push_back(str);
    
    int ris=0;
    FOR(i,1,v.size()-1)
        FOR(j,1,v[0].size()-1)
            ris+=check(v,i,j);

    dbg(ris);
    cout<<ris+4*v.size()-4<<endl;
}

void solve2() {
    ifstream file("test2.txt");
    string str;
    vector<vector<int>> v;
    while (getline(file, str)){
        vector<int> temp;
        feach(x,str) 
            temp.push_back(x-'0');
        v.push_back(temp);
    }
    
    int ris=0;
    FOR(i,1,v.size()-1)
        FOR(j,1,v[0].size()-1)
            {   int temp=check2(v,i,j);
                //dbg(temp);
                ris=max(ris, temp );}


    cout<<ris<<endl;
}
 
/* ---------- Main here ---------- */
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    solve1();
    solve2();

}



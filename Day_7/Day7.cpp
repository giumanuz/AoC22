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

int dfs(map<string, vector<string>> &children, map<string, int> &dir_size, string current){
    int result=0;
    if (children.count(current)!=0)
        for(auto& x: children[current])
            result+=dfs(children, dir_size, x);
    result+=dir_size[current];
    return result;
}

void solve1() {
    map<string, int> dir_size;
    map<string, vector<string>> children;
    ifstream file("test.txt");
    string str, current, rubbish, name;
    bool lista=false;
    while (getline(file, str)){
        stringstream ss(str);
        if (str[0]=='$' && str[2]=='c' && str[5]!='.'){
            lista=false;
            ss>>rubbish>>rubbish>>name;
            current=current + "/" + name;
            dir_size[current]=0;
            children[current]=vector<string>();
        }
        else if (str[0]=='$' && str[2]=='c' && str[5]=='.'){
            lista=false;
            int pos=current.find_last_of('/');
            current=current.substr(0, pos);
        }
        else if (str[0]=='$' && str[2]=='l'){
             lista=true;
        }
        else if (str[0]=='d'){
            if (lista){
                ss>>rubbish>>name;
                string temp= current + "/" + name;
                children[current].push_back(temp);
                dir_size[temp]=0;
            }
        }
        else{
            if (lista){
                int weight;
                ss>>weight>>name;
                string temp= current + "/" + name;
                children[current].push_back(temp);
                dir_size[temp]=weight;
            }
        }
    }
    
    dbg(children);
    ll result=0;
    for(auto& [x, array]: children){
        dbg(x);
        int conta=dfs(children, dir_size, x);
        if (conta<100000)
            result+=conta;
    }
    cout << result << endl;
}

void solve2() {
    map<string, int> dir_size;
    map<string, vector<string>> children;
    ifstream file("test2.txt");
    string str, current, rubbish, name;
    bool lista=false;
    while (getline(file, str)){
        stringstream ss(str);
        if (str[0]=='$' && str[2]=='c' && str[5]!='.'){
            lista=false;
            ss>>rubbish>>rubbish>>name;
            current=current + "/" + name;
            dir_size[current]=0;
            children[current]=vector<string>();
        }
        else if (str[0]=='$' && str[2]=='c' && str[5]=='.'){
            lista=false;
            int pos=current.find_last_of('/');
            current=current.substr(0, pos);
        }
        else if (str[0]=='$' && str[2]=='l'){
             lista=true;
        }
        else if (str[0]=='d'){
            if (lista){
                ss>>rubbish>>name;
                string temp= current + "/" + name;
                children[current].push_back(temp);
                dir_size[temp]=0;
            }
        }
        else{
            if (lista){
                int peso;
                ss>>peso>>name;
                string temp= current + "/" + name;
                children[current].push_back(temp);
                dir_size[temp]=peso;
            }
        }
    }
    
    dbg(children);
    ll result=99999999;
    ll unused= 70000000-dfs(children, dir_size, "//");
    ll required= 30000000-unused;
    for(auto& [x, array]: children){
        dbg(x);
        ll size=dfs(children, dir_size, x);
        if (size>=required)
            result=min(result, size);
    }
    cout << result << endl;
}

 
/* ---------- Main here ---------- */
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    solve1();
    //solve2();

}



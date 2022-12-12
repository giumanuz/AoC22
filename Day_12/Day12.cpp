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
//BFS
int bfs(vector<vector<int>> v, pair<int, int> start, pair<int, int> stop){
    queue<pair<pair<int, int>, int>> q;
    set<pair<int, int>> visited;
    q.push({start, 0});
    while(!q.empty()){
        pair<pair<int, int>, int> p=q.front();
        q.pop();
        int x=p.first.first;
        int y=p.first.second;
        int dist=p.second;  
        if (visited.count({x, y})==1)
            continue;
        vector<pair<int, int>> moves({{0,-1}, {0,1}, {-1,0}, {1,0}});
        for(auto [b1, c1]: moves){
            int b=x+b1;
            int c=y+c1;
            if (b>=0 && b<v.size() && c>=0 && c<v[0].size() && v[b][c]-v[x][y]<=1){
                if (b==stop.first && c==stop.second)
                    return dist+1;
                q.push({{b, c}, dist+1});
            }
        }
        visited.insert({x, y});
    }
    return INT_MAX;
}

void solve1() {
    vector<vector<int>> v;
    pair<int, int> start;
    pair<int, int> stop;
    ifstream file("test1.txt");
    string str, s;
    int i=0;

    while(getline(file, str)){
        stringstream ss(str);
        ss>>s;
        v.push_back(vector<int>());
        int j=0;
        feach(letter, s){
            if (letter=='S'){
                start.first=i;
                start.second=j;
                v[i].push_back(0);
            }
            else if (letter=='E'){
                stop.first=i;
                stop.second=j;
                v[i].push_back(25);
            }
            else
                v[i].push_back(letter-'a');
            j+=1;
        }
        i+=1;
    }
    
    set<pair<int, int>> visited;
    visited.insert(start);
    cout<<bfs(v, start, stop)<<endl;
}
void solve2() {
    vector<vector<int>> v;
    pair<int, int> start;
    pair<int, int> stop;
    ifstream file("test2.txt");
    string str, s;
    int i=0;
    set<pair<int, int>> interested;

    while(getline(file, str)){
        stringstream ss(str);
        ss>>s;
        v.push_back(vector<int>());
        int j=0;
        feach(letterter, s){
            if (letterter=='S'){
                start.first=i;
                start.second=j;
                v[i].push_back(0);
            }
            else if (letterter=='E'){
                stop.first=i;
                stop.second=j;
                v[i].push_back(25);
            }
            else
                v[i].push_back(letterter-'a');
            if((letterter-'a')==0)
                interested.insert({i, j});
            j+=1;
        }
        i+=1;
    }
    
    set<pair<int, int>> visited;
    visited.insert(start);
    int result=INT_MAX;
    feach(elem, interested)
        result=min(result, bfs(v, elem, stop));
    cout<<result<<endl;
}

/* ---------- Main here ---------- */
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    solve1();
    solve2();
}
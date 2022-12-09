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
    char l; int n;
    set<pair<int, int>> s {{0,0}};
    pair<int, int> head = {0, 0};
    pair<int, int> tail = {0, 0};
    while (getline(file, str)){
        stringstream ss(str);
        ss >> l >> n;
        FOR(i,0,n){
            switch(l){
                case 'R':
                    head.second++;
                    break;
                case 'L':
                    head.second--;
                    break;
                case 'U':
                    head.first++;
                    break;
                case 'D':
                    head.first--;
                    break;
            }
            if (abs(head.first-tail.first)>=2 || abs(head.second-tail.second) >=2){
                bool trovato = false;
                pair<int, int> mov;
                int dist=abs(head.first-tail.first) + abs(head.second-tail.second);
                FOR(a,-1,2)
                    FOR(b,-1,2)
                        if (abs(head.first-tail.first-a) + abs(head.second-tail.second-b) < dist){
                            dist=abs(head.first-tail.first-a) + abs(head.second-tail.second-b);
                            mov={a,b};
                        }
                tail.first+=mov.first;
                tail.second+=mov.second;
                s.insert(tail);
            }
        }
    }
    cout<<s.size()<<nl;
}

void solve2() {
    ifstream file("test2.txt");
    string str;
    char l; int n;
    set<pair<int, int>> s {{0,0}};
    vector<pair<int, int>> v(10, {0, 0});
    while (getline(file, str)){
        stringstream ss(str);
        ss >> l >> n;
        FOR(i,0,n){
            switch(l){
                case 'R':
                    v[0].second++;
                    break;
                case 'L':
                    v[0].second--;
                    break;
                case 'U':
                    v[0].first++;
                    break;
                case 'D':
                    v[0].first--;
                    break;
            }
            FOR(j,1,10){
                if (abs(v[j-1].first-v[j].first)>=2 || abs(v[j-1].second-v[j].second) >=2){
                    pair<int, int> temp;
                    int dist=abs(v[j-1].first-v[j].first) + abs(v[j-1].second-v[j].second);
                    FOR(a,-1,2)
                        FOR(b,-1,2)
                            if (abs(v[j-1].first-v[j].first-a) + abs(v[j-1].second-v[j].second-b) < dist){
                                dist=abs(v[j-1].first-v[j].first-a) + abs(v[j-1].second-v[j].second-b);
                                temp={a,b};
                            }
                    v[j].first+=temp.first;
                    v[j].second+=temp.second;
                }
            }
            s.insert(v[9]);
        }
    }
    cout<<s.size()<<nl;
}
/* ---------- Main here ---------- */
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    solve1();
    solve2();

}



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

vector<string> split(string s, string delim){
    vector<string> v;
    size_t pos = 0;
    string token;
    while ((pos = s.find(delim)) != string::npos) {
        token = s.substr(0, pos);
        v.push_back(token);
        s.erase(0, pos + delim.length());

    }
    v.push_back(s);
    return v;
}

pair<int, int> findPosition(set<pair<int, int>> &m){
    int x=500;
    int y=0;
    inizio:
        while(m.count(make_pair(x, y+1))==0)  {
            y++;
            if (y==300)
                return {-1, -1};
        }
        if (m.count(make_pair(x-1, y+1))==0) {
            x--;
            goto inizio;
        }
        if (m.count(make_pair(x+1, y+1))==0) {
            x++;
            goto inizio;
        }
    return make_pair(x, y);
}

void solve1() {
    ifstream file("test1.txt");
    string str;

    set<pair<int, int>> m;
    while(getline(file, str)){
        vector<string> temp = split(str, " -> ");
        FOR(i, 0, temp.size()-1){
            if (temp[i].substr(temp[i].find(',')+1) == temp[i+1].substr(temp[i].find(',')+1)){ //VIRGOLA UGUALE
                int virgola=stoi(temp[i+1].substr(temp[i].find(',')+1));
                int massimo=max(stoi((temp[i].substr(0, temp[i].find(',')))), stoi(temp[i+1].substr(0, temp[i].find(','))));
                int minimo=min(stoi((temp[i].substr(0, temp[i].find(',')))), stoi(temp[i+1].substr(0, temp[i].find(','))));

                while(massimo!=minimo){
                    m.insert({massimo, virgola});
                    massimo--;
                }
                m.insert({minimo, virgola});
            }
            else{
                int numero=stoi(temp[i+1].substr(0, temp[i].find(',')));    //NUMERO UGUALE
                int massimo=max(stoi((temp[i].substr(temp[i].find(',')+1))), stoi(temp[i+1].substr(temp[i].find(',')+1)));
                int minimo=min(stoi((temp[i].substr(temp[i].find(',')+1))), stoi(temp[i+1].substr(temp[i].find(',')+1)));
                while(massimo!=minimo){
                    m.insert({numero, massimo});
                    massimo--;
                }
                m.insert({numero, minimo});
            }
        }        
    }

    int i;
    for (i=0; i<100000; i++){
        pair<int, int> pos = findPosition(m);
        if (pos.first==-1)
            break;
        m.insert(pos);
    }
    cout<<i<<endl;
}

void solve2() {
    ifstream file("test2.txt");
    string str;

    set<pair<int, int>> m;
    while(getline(file, str)){
        vector<string> temp = split(str, " -> ");
        FOR(i, 0, temp.size()-1){
            if (temp[i].substr(temp[i].find(',')+1) == temp[i+1].substr(temp[i].find(',')+1)){ //VIRGOLA UGUALE
                int virgola=stoi(temp[i+1].substr(temp[i].find(',')+1));
                int massimo=max(stoi((temp[i].substr(0, temp[i].find(',')))), stoi(temp[i+1].substr(0, temp[i].find(','))));
                int minimo=min(stoi((temp[i].substr(0, temp[i].find(',')))), stoi(temp[i+1].substr(0, temp[i].find(','))));

                while(massimo!=minimo){
                    m.insert({massimo, virgola});
                    massimo--;
                }
                m.insert({minimo, virgola});
            }
            else{
                int numero=stoi(temp[i+1].substr(0, temp[i].find(',')));    //NUMERO UGUALE
                int massimo=max(stoi((temp[i].substr(temp[i].find(',')+1))), stoi(temp[i+1].substr(temp[i].find(',')+1)));
                int minimo=min(stoi((temp[i].substr(temp[i].find(',')+1))), stoi(temp[i+1].substr(temp[i].find(',')+1)));
                while(massimo!=minimo){
                    m.insert({numero, massimo});
                    massimo--;
                }
                m.insert({numero, minimo});
            }
        }        
    }

    int massimo=0;
    for(auto[x,y]: m)
        massimo=max(y, massimo);
    
    FOR(i,300, 750)
       m.insert({i, massimo+2});
    
    int i;

    for (i=0; i<100000; i++){
        pair<int, int> pos = findPosition(m);
        if (pos.first==500 && pos.second==0)
            break;
        m.insert(pos);
    }

    cout<<i+1<<endl;
}

/* ---------- Main here ---------- */
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    solve1();
    solve2();
}
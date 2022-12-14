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
    begin:
        while(m.count(make_pair(x, y+1))==0)  {
            y++;
            if (y==300)
                return {-1, -1};
        }
        if (m.count(make_pair(x-1, y+1))==0) {
            x--;
            goto begin;
        }
        if (m.count(make_pair(x+1, y+1))==0) {
            x++;
            goto begin;
        }
    return make_pair(x, y);
}

void solve1() {
    ifstream file("test1.txt");
    string str;

    set<pair<int, int>> m;
    while(getline(file, str)){
        vector<string> array = split(str, " -> ");
        FOR(i, 0, array.size()-1){
            if (array[i].substr(array[i].find(',')+1) == array[i+1].substr(array[i].find(',')+1)){ //VIRGOLA UGUALE
                int decimal=stoi(array[i+1].substr(array[i].find(',')+1));
                int greater=max(stoi((array[i].substr(0, array[i].find(',')))), stoi(array[i+1].substr(0, array[i].find(','))));
                int lower=min(stoi((array[i].substr(0, array[i].find(',')))), stoi(array[i+1].substr(0, array[i].find(','))));

                while(greater!=lower){
                    m.insert({greater, decimal});
                    greater--;
                }
                m.insert({lower, decimal});
            }
            else{
                int numero=stoi(array[i+1].substr(0, array[i].find(',')));    //NUMERO UGUALE
                int greater=max(stoi((array[i].substr(array[i].find(',')+1))), stoi(array[i+1].substr(array[i].find(',')+1)));
                int lower=min(stoi((array[i].substr(array[i].find(',')+1))), stoi(array[i+1].substr(array[i].find(',')+1)));
                while(greater!=lower){
                    m.insert({numero, greater});
                    greater--;
                }
                m.insert({numero, lower});
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
                int decimal=stoi(temp[i+1].substr(temp[i].find(',')+1));
                int greater=max(stoi((temp[i].substr(0, temp[i].find(',')))), stoi(temp[i+1].substr(0, temp[i].find(','))));
                int lower=min(stoi((temp[i].substr(0, temp[i].find(',')))), stoi(temp[i+1].substr(0, temp[i].find(','))));

                while(greater!=lower){
                    m.insert({greater, decimal});
                    greater--;
                }
                m.insert({lower, decimal});
            }
            else{
                int numero=stoi(temp[i+1].substr(0, temp[i].find(',')));    //NUMERO UGUALE
                int greater=max(stoi((temp[i].substr(temp[i].find(',')+1))), stoi(temp[i+1].substr(temp[i].find(',')+1)));
                int lower=min(stoi((temp[i].substr(temp[i].find(',')+1))), stoi(temp[i+1].substr(temp[i].find(',')+1)));
                while(greater!=lower){
                    m.insert({numero, greater});
                    greater--;
                }
                m.insert({numero, lower});
            }
        }        
    }

    int greater=0;
    for(auto[x,y]: m)
        greater=max(y, greater);
    
    FOR(i,300, 750)
       m.insert({i, greater+2});
    
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
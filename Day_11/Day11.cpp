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

vector<string> split(const string& s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
        if (token!="")
            tokens.push_back(token);
    return tokens;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve1() {
    ifstream file("test1.txt");
    string str;
    map<ll, vector<ll>> m1;
    map<ll, vector<ll>> m2;
    map<ll, pair<ll, ll>> op; //0* 1+ 0old
    map<ll, ll> divisible;
    map<ll, pair<ll, ll>> lancia; //0* 1+ 0old
    vll ris(9,0);
    ll val;
    ll num=0;
    while(getline(file, str)){
        getline(file, str);
        auto v=split(str, ' ');
        FOR(i,2,v.size())
            m1[num].push_back(stoi(v[i]));
        getline(file, str); v=split(str, ' ');
        if (v[4]=="*")
            op[num].first=0;
        else
            op[num].first=1;
        if (v[5]=="old")
            op[num].second=0;
        else
            op[num].second=stoi(v[5]);
        getline(file, str); v=split(str, ' ');
        divisible[num]=stoi(v[3]);
        getline(file, str); v=split(str, ' ');
        lancia[num].first=stoi(v[5]);
        getline(file, str); v=split(str, ' ');
        lancia[num].second=stoi(v[5]);
        num+=1;
        getline(file, str);
    }    
    FOR(i,0,20){
        feach(key, m1){
            feach(vale, key.second){
                if (op[key.first].first==0){
                    if(op[key.first].second!=0)
                        val=vale*op[key.first].second;
                    else
                        val=vale*vale;
                }else{
                    if(op[key.first].second!=0)
                        val=vale+op[key.first].second;
                    else
                        val=vale+vale;
                }
                val=val/3;
                if((val%divisible[key.first])==0){
                    if (lancia[key.first].first < key.first)
                        m2[lancia[key.first].first].push_back(val);
                    else
                        m1[lancia[key.first].first].push_back(val);
                }
                else{
                    if (lancia[key.first].second < key.first)
                        m2[lancia[key.first].second].push_back(val);
                    else
                        m1[lancia[key.first].second].push_back(val);
                }
                ris[key.first]+=1;
            }
        }
        m1.clear();
        m1=m2;
        m2.clear();
    }
    sort(ris.rbegin(),ris.rend());
    cout<<ris[0]*ris[1]<<nl;
}
void solve2() {
    ifstream file("test2.txt");
    string str;
    map<ll, vector<ll>> m1;
    map<ll, vector<ll>> m2;
    map<ll, pair<ll, ll>> op; //0* 1+ 0old
    map<int, int> divisible;
    map<ll, pair<ll, ll>> lancia; //0* 1+ 0old
    vll ris(9,0);
    ll val;
    ll num=0;
    while(getline(file, str)){
        getline(file, str);
        auto v=split(str, ' ');
        FOR(i,2,v.size())
            m1[num].push_back(stoi(v[i]));
        getline(file, str); v=split(str, ' ');
        if (v[4]=="*")
            op[num].first=0;
        else
            op[num].first=1;
        if (v[5]=="old")
            op[num].second=0;
        else
            op[num].second=stoi(v[5]);
        getline(file, str); v=split(str, ' ');
        divisible[num]=stoi(v[3]);
        getline(file, str); v=split(str, ' ');
        lancia[num].first=stoi(v[5]);
        getline(file, str); v=split(str, ' ');
        lancia[num].second=stoi(v[5]);
        num+=1;
        getline(file, str);
    }    
    
    ll mcm = 1;
    for(auto &[num, item]: divisible)
        mcm = mcm * item / gcd(mcm, item);

    FOR(k,0,10000) {
        FOR(i,0,m1.size()) {
            feach (elem, m1[i]) {
                long long new_elem;

                if (op[i].first == 1) // +
                    new_elem = (elem%mcm + (op[i].second == 0 ? elem : op[i].second)%mcm)%mcm;
                else
                    new_elem = (elem%mcm * (op[i].second == 0 ? elem : op[i].second)%mcm)%mcm;

                if (new_elem % divisible[i] == 0)
                    m1[lancia[i].first].push_back(new_elem);
                else
                    m1[lancia[i].second].push_back(new_elem);
            }
            ris[i] += m1[i].size();
            m1[i].clear();
        }
    }

    sort(ris.rbegin(),ris.rend());1
    cout<<ris[0]*ris[1]<<nl;
}

/* ---------- Main here ---------- */
 
 int main() {
    cin.tie(0)->sync_with_stdio(0);

    solve1();
    solve2();

}


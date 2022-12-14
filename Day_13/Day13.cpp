#include <bits/stdc++.h>
#include <stdio.h>
#ifdef Giulio
    #include <bits/debug.h>
#else
    #define dbg(...)
#endif
//g++ -std=gnu++20 -g -fsanitize=address -fsanitize=undefined -fno-sanitize-recover Day13.cpp -DGiulio -o a ; ./a
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


int compare(struttura a, struttura b);
int compare(vector<struttura> a, vector<struttura> b);
int compare(int a, int b);


enum class tipo{
    numero,
    lista
};

struct struttura{
    tipo tipo;
    int numero;
    vector<struttura> lista;
};

bool isIstanceOf(struttura s, tipo t){
    return s.tipo == t;
}

int compare(struttura a, struttura b){
    if(isIstanceOf(a, tipo::numero) && isIstanceOf(b, tipo::numero)){
        return compare(a.numero, b.numero);
    }
    if(isIstanceOf(a, tipo::lista) && isIstanceOf(b, tipo::lista)){
        return compare(a.lista, b.lista);
    }
    if(isIstanceOf(a, tipo::numero) && isIstanceOf(b, tipo::lista)){
        vector<struttura> tmp = {a};
        return compare(tmp, b.lista);
    }
    if(isIstanceOf(a, tipo::lista) && isIstanceOf(b, tipo::numero)){
        vector<struttura> tmp = {b};
        return compare(a.lista, tmp);
    }
}
int compare(vector<struttura> a, vector<struttura> b){
    int i=0;
    while(i<a.size() && i<b.size()){
        int ris= compare(a[i], b[i]);
        if(ris==1) return 1;
        if(ris==-1) return -1;
        i++;
    }
    if (i == a.size()) {
        if (a.size() == b.size()) 
            return 0;
        return 1;
    }
    return -1;
}

int compare(int a, int b) {
    if (a < b) return 1;
    if (a == b) return 0;
    return -1;
}

vector<struttura> parseInput(string s, int index){
    vector<struttura> ans;
    bool primo = true;
    while(index<s.size()){
        if (primo && s[index] == '[') {
            primo = false;
            index++;
            continue;
        }
        if (s[index] == ']') {
            return ans;
        }
        if (s[index] == '[') {
            ans.pb({tipo::lista, 0, parseInput(s, index)});
            index++;
            continue;
        }
        if (s[index] == ',') {
            index++;
            continue;
        }
        int tmp = 0;
        int n= s[index] - '0';
        if (n==1 && s[index+1] == '0') {
            n=10;
            index++;
        } 
        index++;
        ans.pb({tipo::numero, tmp, {}});
        continue;
    }
}

void solve1() {
    ifstream f("test.txt");
    string s1, s2;
    int ans = 0;
    int i = 0;
    while (getline(f, s1)) {
        getline(f, s2);
        vector<struttura> a = parseInput(s1, 0);
        vector<struttura> b = parseInput(s2, 0);
        if (compare(a, b) == 1) {
            ans += i + 1;
        }
        i++;
        getline(f, s1);
    }
    cout << ans << endl;
}

/* ---------- Main here ---------- */
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    solve1();
    //solve2();
}
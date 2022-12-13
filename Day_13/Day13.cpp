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

//ATTENCTION: THIS SOLUTION IS WRONG

int compare(vector<int> a, vector<int> b) {
    int i = 0;
    while (i < a.size() && i < b.size()) {
        int ris= compare(a[i], b[i]);
        if (ris==1)
            return 1;
        if (ris==-1)
            return -1;
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

int compare(int a, vector<int> b) {
    b = {a};
    return compare(b, a);
}

int compare(vector<int> a, int b) {
    a = {b};
    return compare(a, b);
}

void solve1() {
    ifstream fin("test.txt");
    string s;
    int ans = 0;
    int i = 0;
    while (getline(fin, s)) {
        vector<int> a, b;
        feach(let, s) {
            if (let == '[') {
                a.push_back('{');
            } else if (let == '[') {
                a.push_back('{');
            }
        }

        while (getline(fin, s)) {
            if (s == "") {
                break;
            }
            stringstream ss(s);
            int x;
            ss >> x;
            if (t == "a") {
                a.push_back(x);
            } else {
                b.push_back(x);
            }
        }
        if (compare(a, b) == 1) {
            ans += i + 1;
        }
        i++;
    }
    cout << ans << endl;
}

/* ---------- Main here ---------- */
 
int main() {
    cin.tie(0)->sync_with_stdio(0);

    solve1();
    solve2();
}
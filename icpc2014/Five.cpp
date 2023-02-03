#define imax INT_MAX
#define imin INT_MIN
#define sz(x) (int((x).size()))
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define over(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007



#include <bits/stdc++.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct node {
    int val;
    node* next;
    node* prev;
};

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

struct PairHasher{
  size_t operator()(const pii &x) const{
    return x.first ^ x.second;
  }
};

string change(string s, int i){
    vector<string> v;
    int k=0;
    for(int i=0;i<3;++i){
        v.pb("");
        for(int j=0;j<3;++j){
            v[sz(v)-1] += s[k];
            ++k;
        }
    }
    int r = i/3;
    int c = i%3;
    vector<pii> dirs{mk(1,0),mk(0,1),mk(-1,0),mk(0,-1)};
    if(v[r][c] == '.'){
        v[r][c] = '*';
    }else{
        v[r][c] = '.';
    }
    for(auto d:dirs){
        if(r+d.a >= 0 && r+d.a < 3 && c+d.b >= 0 && c+d.b < 3){
            if(v[r+d.a][c+d.b] == '.'){
                v[r+d.a][c+d.b] = '*';
            }else{
                v[r+d.a][c+d.b] = '.';
            }
        }
    }
    string ans = "";
    for(int i=0;i<sz(v);++i){
        for(int j=0;j<sz(v);++j){
            ans += v[i][j];
        }
    }
    return ans;
}


void recursion(string s, umap<string, int>& m, int cur){
    // if(m.find(s) != m.end()) return;
    for(int i=0;i<sz(s);++i){
        string tmp = change(s, i);
        if(m.find(tmp) == m.end()){
            m[tmp] = cur;
            recursion(tmp, m, cur+1);
        }else{
            if(m[tmp] > cur){
                m[tmp] = cur;
                recursion(tmp, m, cur+1);
            }
        }
    }
}




int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int t;
    unsigned int n;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> t;

    umap<string, int> m;
    m["........."] = 0;

    recursion(".........", m, 1);

    for(int i=0; i < t; ++i) { //loops for each case
        string s;
        for(int j=0;j<3;++j){
            string st;
            cin >> st;
            s += st;
        }
        cout << m[s] << endl;
    }

    return 0;
}
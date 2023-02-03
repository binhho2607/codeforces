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
// #define all(x) (x).begin(), (x).end()
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



void solve(vector<string> v, vector<vi> qu){
    vector<vi> m(sz(v),vi(sz(v[0]),0));
    int x = 1;
    for(int i=0;i<sz(qu);++i){
        pii t = mk(qu[i][0]-1,qu[i][1]-1);
        pii s = mk(qu[i][2]-1,qu[i][3]-1);
        if(v[t.a][t.b] != v[s.a][s.b]){
            cout << "neither" << endl;
            continue;
        }
        if(m[t.a][t.b] == 0 && m[s.a][s.b] == 0){
            queue<pii> bfs;
            bfs.push(t);
            m[t.a][t.b] = x;
            while(sz(bfs) > 0){
                pii c = bfs.front();
                bfs.pop();
                vector<pii> dir{mk(-1,0),mk(1,0),mk(0,1),mk(0,-1)};
                for(auto d:dir){
                    if(c.a+d.a >= 0 && c.a+d.a < sz(v) && c.b+d.b >=0 && c.b+d.b < sz(v[0]) && v[c.a+d.a][c.b+d.b] == v[t.a][t.b] && m[c.a+d.a][c.b+d.b] == 0){
                        bfs.push(mk(c.a+d.a, c.b+d.b));
                        m[c.a+d.a][c.b+d.b] = x;
                    }
                }
            }
        }
        
        if(m[t.a][t.b] == m[s.a][s.b]){
            if(v[t.a][t.b] == '0'){
                cout << "binary" << endl;
            }else{
                cout << "decimal" << endl;
            }
        }else{
            cout << "neither" << endl;
        }
        ++x;
    }
    return;

}



int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int r;
    unsigned int c;
    unsigned int w;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> r;
    cin >> c;
    
    vector<string> v;
    bool one = true;
    bool zero = true;
    for(int i=0;i<r;++i){
        string s;
        cin >> s;
        v.pb(s);
    }

    cin >> w;
    vector<vi> q;
    for(int i=0;i<w;++i){
        q.pb(vi());
        for(int j=0;j<4;++j){
            int s;
            cin >> s;
            q[sz(q)-1].pb(s);
        }
    }

    solve(v, q);

    return 0;
}
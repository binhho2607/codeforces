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


void solve(vector<vector<char>> v){
    umap<pii, int, PairHasher> m;
    for(int r=0;r<sz(v);++r){
        for(int c=0;c<sz(v[0]);++c){
            if(r%2 == 1 && c%2 == 1){
                pii p = mk(r, c);
                int cur = 0;
                vector<pii> dir{mk(1,0),mk(0,-1),mk(-1,0),mk(0,1)};
                for(auto d:dir){
                    if(r+d.a >= 0 && r+d.a < sz(v) && c+d.b >= 0 && c+d.b < sz(v) && v[r+d.a][c+d.b] == '.'){
                        cur += 1;
                    }
                }
                m[p] = cur;
                // cout << p.a << " " << p.b << " " << cur << endl;
            }
        }
    }
    int ans = 0;
    while(true){
        int maxempt = imin;
        pii maxdot;
        for(auto p:m){
            if(p.b > maxempt){
                maxempt = p.b;
                maxdot = p.a;
            }
        }
        vector<pii> dir{mk(1,0),mk(0,-1),mk(-1,0),mk(0,1)};
        pii maxedge;
        pii maxnextdot;
        int maxnext = imin;
        for(auto d:dir){
            if(maxdot.a+d.a >= 0 && maxdot.a+d.a < sz(v) && maxdot.b+d.b >= 0 && maxdot.b+d.b < sz(v) && v[maxdot.a+d.a][maxdot.b+d.b] == '.'){
                if(maxdot.a+2*d.a >= 0 && maxdot.a+2*d.a < sz(v) && maxdot.b+2*d.b >= 0 && maxdot.b+2*d.b < sz(v)){
                    if(maxnext < m[mk(maxdot.a+2*d.a,maxdot.b+2*d.b)]){
                        maxnext = m[mk(maxdot.a+2*d.a,maxdot.b+2*d.b)];
                        maxedge = mk(maxdot.a+d.a,maxdot.b+d.b);
                        maxnextdot = mk(maxdot.a+2*d.a,maxdot.b+2*d.b);
                    }
                }else{
                    
                    maxedge = mk(maxdot.a+d.a,maxdot.b+d.b);
                    maxnextdot = mk(maxdot.a+2*d.a,maxdot.b+2*d.b);
                    break;
                }
            }
        }
        // cout << "start" << endl;
        v[maxedge.a][maxedge.b] = '-';
        // cout << maxedge.a << " " << maxedge.b << endl;
        // for(int  r=0;r<sz(v);++r){
        //     for(int c=0;c<sz(v);++c){
        //         cout << v[r][c] << " ";
        //     }
        //     cout << endl;
        // }
        m[maxdot] -= 1;
        m[maxnextdot] -= 1;
        ans += 1;
        if(m[maxdot] == 0 || m[maxnextdot] == 0){
            cout << ans << endl;
            return;
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

    vector<vector<char>> v;
    for(int r=0;r<2*t-1;++r){
        v.pb(vector<char>());
        for(int c=0;c<2*t-1;++c){
            char s;
            cin >> s;
            v[sz(v)-1].pb(s);
            // cout << s << " ";
        }
        // cout << endl;
    }

    solve(v);



    return 0;
}
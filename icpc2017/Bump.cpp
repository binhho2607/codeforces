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

int minDist(umap<int, int> res, umap<int, bool> inc){
    int m = imax;
    int ind;
    for(auto v:res){
        if(inc[v.a] == false && v.b <= m){
            m = v.b;
            ind = v.a;
        }
    }
    return ind;
}

pair<umap<int, ll>, umap<int, bool>> djikstra(umap<int, vector<pii>> adj, int s){
    umap<int, ll> res;
    umap<int, bool> inc;
    for(auto v:adj){
        res[v.a] = LLONG_MAX;
        inc[v.a] = false;
    }
    res[s] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    q.push(mk(0, s));
    while(sz(q) > 0){
        pair<ll,int> p = q.top();
        q.pop();
        inc[p.b] = true;
        res[p.b] = p.a;
        for(int j=0;j<sz(adj[p.b]);++j){
            if(res[adj[p.b][j].a] == LLONG_MAX){
                q.push(mk(res[p.b]+adj[p.b][j].b,adj[p.b][j].a));
            }
            res[adj[p.b][j].a] = min(res[adj[p.b][j].a], res[p.b]+adj[p.b][j].b);
            
        }

    }
    return mk(res, inc);
}

void solve(int n, umap<int, vector<pii>> adj, vector<pii> fl, int s, int t){
    pair<umap<int, ll>, umap<int, bool>> fs = djikstra(adj, s);
    // for(auto p:fs.a){
    //     cout << p.a << " " << p.b << endl;
    // }
    pair<umap<int, ll>, umap<int, bool>> ft = djikstra(adj, t);
    // for(auto p:ft.a){
    //     cout << p.a << " " << p.b << endl;
    // }
    ll ans = fs.a[t];
    for(auto f:fl){
        // if(fs.b[f.a] && ft.b[f.b]){
        ans = min(ans, fs.a[f.a]+ft.a[f.b]);
        // }
        
    }
    cout << ans << endl;
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    int n, m, f, s, t;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> n;
    cin >> m;
    cin >> f;
    cin >> s;
    cin >> t;

    umap<int, vector<pii>> adj; 
    vector<pii> fl;
    for(int i=0;i<n;++i){
        adj[i] = vector<pii>();
    }
    for(int i=0; i < m; ++i) { //loops for each case
        ll s1, s2, s3;
        cin >> s1;
        cin >> s2; 
        cin >> s3;
        // if(adj.find(s1) == adj.end()){
        //     adj[s1] = vector<pii>();
        // }
        // if(adj.find(s2) == adj.end()){
        //     adj[s2] = vector<pii>();
        // }
        adj[s1].pb(mk(s2, s3));
        adj[s2].pb(mk(s1, s3));
    }

    for(int i=0;i<f;++i){
        ll s1, s2;
        cin >> s1;
        cin >> s2;
        fl.pb(mk(s1, s2));
    }

    solve(n, adj, fl, s, t);

    return 0;
}
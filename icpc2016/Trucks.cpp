#define imax INT_MAX
#define imin INT_MIN
#define sz(x) (int((x).size()))
#define ll int
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

pair<umap<int, ll>, umap<int, ll>> djikstra(umap<int, vector<pii>> adj, int s, vi nums){
    umap<int, ll> res;
    umap<int, ll> pick;
    umap<int, bool> inc;
    for(auto v:adj){
        res[v.a] = imax;
        inc[v.a] = false;
        pick[v.a] = 0;
    }
    pick[s] = nums[s];
    res[s] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    q.push(mk(0, s));
    while(sz(q) > 0){
        pair<ll,int> p = q.top();
        q.pop();
        inc[p.b] = true;
        if(p.a > res[p.b]) continue;
        // res[p.b] = p.a;
        for(int j=0;j<sz(adj[p.b]);++j){
            // if(inc[adj[p.b][j].a] == true) continue;
            // ll distance = res[p.b]+adj[p.b][j].b;
            // if(res[adj[p.b][j].a] == LLONG_MAX){
            //     q.push(mk(res[p.b]+adj[p.b][j].b,adj[p.b][j].a));
            // }
            if(res[adj[p.b][j].a] >= res[p.b]+adj[p.b][j].b){
                if(res[adj[p.b][j].a] > res[p.b]+adj[p.b][j].b)
                    q.push(mk(res[p.b]+adj[p.b][j].b,adj[p.b][j].a));
                res[adj[p.b][j].a] = min(res[adj[p.b][j].a], res[p.b]+adj[p.b][j].b);
                
                pick[adj[p.b][j].a] = max(pick[adj[p.b][j].a], pick[p.b]+nums[adj[p.b][j].a]);
            }
            
            
        }


    }
    return mk(res, pick);
}


// pii dfs(int t, int n, umap<int, vector<pii>> adj, vi nums, int curdist, int curpick, uset<int>& visited, int& mindist, int& maxpick){
//     if(t == n){
//         mindist = min(mindist, curdist);
//         return mk(curdist, -curpick);
//     }
//     if(curdist > mindist){
//         return mk(imax, imax);
//     }
//     pii m = mk(imax, imax);
//     for(int i=0;i<sz(adj[t]);++i){
//         if(visited.find(adj[t][i].a) == visited.end()){
//             visited.insert(adj[t][i].a);
//             pii res = dfs(adj[t][i].a, n,adj, nums, curdist+adj[t][i].b, curpick+nums[adj[t][i].a], visited, mindist);
//             if(m>res){
//                 m = res; 
//             }
//             visited.erase(adj[t][i].a);
//         }
//     }
//     return m;
// }


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
    vi nums{0};
    umap<int, vector<pii>> adj;
    for(int i=0; i < t; ++i) { //loops for each case
        cin >> n;
        nums.pb(n);
        adj[i+1] = vector<pii>();
    }
    int m;
    cin >> m;
    
    for(int i=0;i<m;++i){
        int a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        // if(adj.find(a) == adj.end()){
        //     adj[a] = vector<pii>();
        // }
        // if(adj.find(b) == adj.end()){
        //     adj[b] = vector<pii>();
        // }
        adj[a].pb(mk(b, c));
        adj[b].pb(mk(a, c));
    }
    uset<int> visited;
    visited.insert(1);
    int mindist = imax;
    int maxpick = nums[1];
    // pii res = dfs(1, t, adj, nums,0 ,nums[1] ,visited, mindist, maxpick);
    pair<umap<int, ll>, umap<int, ll>> res = djikstra(adj, 1, nums);
    if(res.a[t] == imax){
        cout << "impossible" << endl;
        return 0;
    }
    // if(res.a == imax){
    //     cout << "impossible" << endl;
    //     return 0;
    // }
    // cout << res.a << " " << -1*res.b << endl;
    cout << res.a[t] << " " << res.b[t] << endl;
    return 0;
}
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


int dp(int s, int t, int k1, int k2, umap<int, vector<vi>> adj, uset<int> u){
    
    if(k1 == -1 || k2 == -1){
        return -1;
    }
    // cout << s << endl;
    if(s == t){
        if(k1%2 == 0 && k2%2 == 0){
            return 0;
        }else{
            return -1;
        }
    }
    
    if(adj.find(s) == adj.end()){
        return -1;
    }
    int m = imax;
    for(int i=0;i<sz(adj[s]);++i){
        if(u.find(adj[s][i][0]) == u.end()){
            int res;
            u.insert(adj[s][i][0]);
            if(adj[s][i][2] == 1){
                res = dp(adj[s][i][0], t, k1-1,k2,adj, u);
            }
            else if(adj[s][i][2] == 2){
                res = dp(adj[s][i][0], t, k1,k2-1,adj,u);
                
            }else{
                res = dp(adj[s][i][0], t, k1,k2,adj,u);
            }
            // cout << s << " " << adj[s][i][0] << " " << res+adj[s][i][1] << endl;
            if(res != -1){
                m = min(m, adj[s][i][1]+res);
            }
            u.erase(adj[s][i][0]);
        }
    }
    if(m == imax){
        return -1;
    }
    return m;
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int n;
    unsigned int m;
    unsigned int k1;
    unsigned int k2;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> n;
    cin >> m;
    cin >> k1;
    cin >> k2;

    umap<int, vector<vi>> adj;
    for(int i=0; i < m; ++i) { //loops for each case
        int n1, n2, w, c;
        cin >> n1;
        cin >> n2;
        cin >> w;
        cin >> c;
        if(adj.find(n1) == adj.end()){
            adj[n1] = vector<vi>();
        }
        if(adj.find(n2) == adj.end()){
            adj[n2] = vector<vi>();
        }
        adj[n1].pb(vi{n2, w, c});
        adj[n2].pb(vi{n1, w, c});
    }

    int t;
    int s;
    cin >> s;
    cin >> t;
    // solve(s, t, k1, k2, adj);
    uset<int> u;
    u.insert(s);
    cout << dp(s, t, k1, k2, adj, u) << endl;

    return 0;
}
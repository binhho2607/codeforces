#define imax INT_MAX
#define imin INT_MIN
#define sz(x) ((int)(x).size())
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define vi vector<int>


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

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};



ll fact(ll n, umap<ll, ll>& mp) {
    if(mp.find(n) != mp.end()){
        return mp[n];
    }
    if(n<0){
        mp[n] = 0;
        return 0;
    }
    if (n == 0 || n == 1){
        mp[n] = 1;
        return 1;
    }
    mp[n] = n * fact(n - 1, mp);
    return mp[n];
}

void solve(int n, int m, vector<pii> edges, umap<int, uset<int>> adj)
{
    // umap<int, uset<int>> adj; 
    // for(auto e:edges){
    //     if(adj.find(e.a) == adj.end()){
    //         adj.emplace(e.a, uset<int>());
    //     }
    //     if(adj.find(e.b) == adj.end()){
    //         adj.emplace(e.b, uset<int>());
    //     }
    //     adj[e.a].insert(e.b);
    //     adj[e.b].insert(e.a);
    // }
    ll ans = 0;
    umap<ll, ll> mp; 
    // map<vi,int> overlap;
    // for(auto p:adj){
    //     for(auto q:adj){
    //         if(p.a==q.a){
    //             continue;
    //         }
    //         if(overlap.find(vi{q.a, p.a}) != overlap.end()){
    //             continue;
    //         }
    //         int cur = 0;
    //         // vi v1;
    //         // copy(adj[q].begin(), adj[q].end(),v1.begin());
    //         for(auto t:q.b){
                
    //             if(p.b.find(t) != p.b.end()){
    //                 cur += 1;
    //             }
    //         }
    //         vi v{p.a,q.a};
    //         sort(v.begin(),v.end());
    //         overlap.emplace(v, cur);
    //         overlap.emplace(vi{q.a, p.a}, cur);
    //     }
    // }
    for(auto p:adj){
        for(auto q:p.b){
            // vi v{p.a,q};
            // sort(v.begin(),v.end());
            // int s = overlap[v];
            if(sz(p.b) < 4 || sz(adj[q]) < 2){
                continue;
            }
            int s = 0;
            for(auto t:p.b){
                 if(adj[q].find(t) != adj[q].end()){
                    s += 1;
                }
            }
            
            for(int i=0;i<=min(s,3);++i){
                // cout << sz(p.b) << " " << s << endl;
                if((fact(3-i,mp)*fact(sz(p.b)-1-s-3+i,mp)) != 0 && (fact(i,mp)*fact(s-i,mp)) != 0 && (sz(adj[q])-1-i) > 0){
                    // cout << "stats: " << sz(p.b)-1-s-i << " " << fact(s-i) << " " << i << endl;
                    ans += (fact(sz(p.b)-1-s, mp)/(fact(3-i, mp)*fact(sz(p.b)-1-s-3+i, mp)))*(fact(s, mp)/(fact(i, mp)*fact(s-i, mp)))*(sz(adj[q])-1-i);
                    // cout << p.a << " " << q << " " << (fact(sz(p.b)-1-s)/(fact(3-i)*fact(sz(p.b)-1-s-3+i)))*(fact(s)/(fact(i)*fact(s-i)))*(sz(adj[q])-i) << " " << sz(p.b) <<  " " << sz(adj[q]) << " " << s << endl;
                }
                
                
            }
        }
    }

    cout << ans;

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int n;
    unsigned int m;
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> n;
    cin >> m;
    
    vector<pii> edges;
    umap<int, uset<int>> adj; 
    for(int i=0;i<m;++i){
        int s1;
        int s2;
        cin >> s1;
        cin >> s2;
        // edges.pb(mk(s1, s2));
        if(adj.find(s1) == adj.end()){
            adj.emplace(s1, uset<int>());
        }
        if(adj.find(s2) == adj.end()){
            adj.emplace(s2, uset<int>());
        }
        adj[s1].insert(s2);
        adj[s2].insert(s1);
    }
    solve(n, m, edges, adj);
}
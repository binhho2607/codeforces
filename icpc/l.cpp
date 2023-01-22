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

void solve(int n, int m, vector<pii> edges)
{
    umap<int, vi> adj; 
    for(auto e:edges){
        if(adj.find(e.a) == adj.end()){
            adj.emplace(e.a, vi());
        }
        if(adj.find(e.b) == adj.end()){
            adj.emplace(e.b, vi());
        }
        adj[e.a].pb(e.b);
        adj[e.b].pb(e.a);
    }

    for(auto v:adj){
        if(sz(v.b) >= 4){
            for(auto nei:v.b){
                if(sz(adj[nei]) > 1){
                    
                }
            }
        }
    }

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
    solve(n, m, edges);
}
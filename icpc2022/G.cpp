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

#define umap unordered_map
#define uset unordered_set
#define MOD 10000000007

#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *prev;
};

ll dfs(umap<ll, ll> adj, int cur, uset<int>& u, vector<ll>& v, ll count, ll& ans, uset<ll>& s){
    if(u.find(adj[cur]) == u.end()){
        u.insert(adj[cur]);
        v.pb(adj[cur]);
        ll res = dfs(adj, adj[cur], u, v, count+1, ans, s);
        if(res == cur){
            ans = count;
            return -1;
        }else if(res != -1){
            s.insert(cur);
        }
    }else{
        v.pb(adj[cur]);
        return adj[cur];
    }
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    umap<ll, ll> adj;
    for(ll i=1;i<=n;++i){
        ll s;
        cin >> s;
        adj[i] = s;
    }
    uset<int> u;

    for(int i=1;i<=n;++i){
        if(u.find(i) == u.end()){
            u.insert(i);
            vector<ll> v;
            ll ans = 0;
            uset<ll> s;
            dfs(adj, i, u, v, 0, ans, s);
            for()
        }
    }

}

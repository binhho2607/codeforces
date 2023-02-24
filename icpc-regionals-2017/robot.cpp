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


void solve(int s){
    cout << s << endl;
}

string hashStr(int x, int y){
    return to_string(x) + " " + to_string(y);
}

void dfs(int cur, umap<int, vi> adj, umap<int, int> force, int rand, uset<int>& ans, uset<string>& visited){
//    cout << cur << endl;
    if(force.find(cur) == force.end()){
        ans.insert(cur);
        if(rand == 1) return;
    }
//    if(visited.find(hashStr(cur, rand)) != visited.end()) return;
    if(force.find(cur) != force.end() && (visited.find(hashStr(force[cur], rand)) == visited.end())){
        visited.insert(hashStr(force[cur], rand));
        dfs(force[cur], adj, force, rand, ans, visited);
//        visited.erase(hashStr(force[cur], rand));
    }
    if(rand == 1) return;
    for(auto n:adj[cur]){
        if(visited.find(hashStr(n, 1)) == visited.end()){
            visited.insert(hashStr(n, 1));
            dfs(n, adj, force, 1, ans, visited);
//            visited.erase(hashStr(n, 1));
        }
    }
}



int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/


#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int m, n;
    cin >> n >> m;

    umap<int, vector<int>> adj;
    umap<int, int> force;
    for(int i=0;i<n;++i){
        adj[i] = vi();
    }
    for(int i=0;i<m;++i){
        int s1, s2;
        cin >> s1 >> s2;
        if(s1 > 0){
            adj[s1].pb(s2);
        }else{
//            adj[-1*s1].pb(s2);
            force[-1*s1] = s2;
        }
    }
    uset<int> ans;
    uset<string> visited{hashStr(1, 0)};
    dfs(1, adj, force, 0, ans, visited);
    cout << sz(ans) << endl;
    return 0;
}
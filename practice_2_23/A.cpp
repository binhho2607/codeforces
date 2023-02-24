#define imax INT_MAX
#define imin INT_MIN
#define sz(x) ((int)(x).size())
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define vii vector<vi>
#define umap unordered_map
#define uset unordered_set
#define MOD 100000007

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

struct VectorHasher{
    int operator()(const vi&V) const{
        int hash = V.size();
        for (auto & i : V){
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash>>2);
        }
        return hash;
    }
};

int find(int n , umap<int, int>&parent){
    int p = parent[n];
    while(p != parent[p]){
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return p;
}

bool unionf(int n1, int n2, umap<int, int>& parent, umap<int, int>&rank){
    int p1 = find(n1, parent);
    int p2 = find(n2, parent);
    if (p1 == p2) return false;
    if (rank[p1] >= rank[p2]){
        rank[p1] += rank[p2];
        parent[p2] = p1;
    }else{
        rank[p2] += rank[p1];
        parent[p1] = p2;
    }
    return true;
}

vector<pair<long double, pair<int, int>>> kruskal(int n, vector<pair<long double, pair<int, int>>> &edges, vector<pair<long double, pair<int, int>>> &constructed){
    umap<int, int> parent;
    umap<int, int> rank;

    for (int i = 0; i < n ;++i){
        parent[i] = i;
        rank[i] = 1;
    }
        sort(edges.begin(), edges.end());
        vector<pair< long double, pair<int, int>>> ans;
        for (auto e : constructed){
            unionf(e.b.a, e.b.b, parent, rank);
            ans.pb(e);
        }
        for (auto e : edges){
            if (unionf(e.b.a, e.b.b, parent, rank)){
                ans.pb(e);
            }
//            if (sz(ans) == n - 1) break;
        }
        return ans;

}

void solve(int n, int e, int p){
    vector<pair<long double, long double>>houses(n);
    for (int i = 0; i < n; ++i){
        long double x, y;
        cin>>x>>y;
        houses[i] = mk(x, y);
    }
    vector<pair<long double, pair<int, int>>> edges;
    vector<pair<long double, pair<int, int>>> constructed;
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            if (i < e && j < e){
                constructed.emplace_back(0, mk(i, j));
            }else{
                long double dist = sqrt(pow(houses[i].a - houses[j].a, 2) + pow(houses[i].b - houses[j].b, 2));
                edges.emplace_back(dist, mk(i, j));
            }
        }
    }
    for (int i = 0; i < p ; ++i){
        int u, v;
        cin>>u>>v;
        u--;v--;
        constructed.emplace_back(0, mk(u, v));
    }
    auto prim = kruskal(n, edges, constructed);
    long double cost = 0;
    for (auto line : prim){
        cost += line.a;
    }
    cout<<fixed<<setprecision(6)<<cost<<endl;

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned int t;
    unsigned int n;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int e, p;
    cin>>n>>e>>p;
    solve(n, e, p);

}

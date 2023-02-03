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
#define ldb long double



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


void dijkstra(umap<int, vector<pair<int, ldb>>> adj, int end){
    vector<ldb> distance;
    vector<bool> processed(end+1, false);
    for(int i=0;i<=end;++i){
        distance.pb(imax);
    }
    distance[0] = 0;
    priority_queue<pair<ldb, int>> q;
    q.push(mk(0,0));
    while(!q.empty()){
        ldb x = q.top().b;
        q.pop();
        if(processed[x]) continue;
        processed[x] = true;
        for(auto u:adj[x]){
            ldb y = u.a;
            ldb w = u.b;
            if(distance[x]+w < distance[y]){
                distance[y]=distance[x]+w;
                q.push(mk(-distance[y],y));
            }
        }
    }
    // for(int i=0;i<sz(distance);++i){
    //     cout << i << " " << distance[i] << endl;
    // }
    cout << fixed << setprecision(6) << distance[end] << endl;
}





int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    long double s1, s2;
    int id = 0;
    cin >> s1 >> s2;
    pair<ldb,ldb> start = mk(s1, s2);
    cin >> s1 >> s2;
    pair<ldb,ldb> end = mk(s1, s2);
    int t;
    cin >> t;
    umap<int, vector<pair<int, ldb>>> adj;
    vector<pair<ldb, ldb>> v{start};
    adj[id] = vector<pair<int, ldb>>();
    ++id;
    for(int i=0;i<t;++i){
        cin >> s1 >> s2;
        adj[id] = vector<pair<int, ldb>>();
        for(int j=0;j<sz(v);++j){
            ldb dist = sqrt(pow(s1-v[j].a,2) + pow(s2-v[j].b,2));
            ldb foot = dist/5.0;
            
            ldb cannon = 2+abs(50-dist)/5.0;
            // cout << min(foot, cannon) << endl;
            adj[id].pb(mk(j, min(foot, cannon)));
            if(j==0){
                adj[j].pb(mk(id,foot));
            } else {
                adj[j].pb(mk(id, min(foot, cannon)));
            }
            
        }
        v.pb(mk(s1, s2));
        ++id;
    }

    adj[id] = vector<pair<int, ldb>>();
    for(int j=0;j<sz(v);++j){
        ldb dist = sqrt(pow(end.a-v[j].a,2) + pow(end.b-v[j].b,2));
        ldb foot = dist/5.0;
        ldb cannon = 2+abs(50-dist)/5.0;
        adj[id].pb(mk(j, min(foot, cannon)));
        if(j==0){
            adj[j].pb(mk(id,foot));
        } else {
            adj[j].pb(mk(id, min(foot, cannon)));
        }
    }

    dijkstra(adj, id);
    

    return 0;
}
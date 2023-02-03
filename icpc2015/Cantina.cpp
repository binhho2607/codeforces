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

void dfs(string s, umap<string, vector<string>> adj, uset<string>& black, uset<string>& grey, vector<string>& finish){
    for(auto n:adj[s]){
        if(black.find(n) == black.end() && grey.find(n) == grey.end()){
            grey.insert(n);
            dfs(n, adj, black, grey, finish);
        }
    }
    finish.pb(s);
    black.insert(s);
}

void dfs2(string s, umap<string, vector<string>> tr, uset<string>& black, uset<string>& grey, int& cur){
    for(auto n:tr[s]){
        if(black.find(n) == black.end() && grey.find(n) == grey.end()){
            grey.insert(n);
            cur += 1;
            dfs2(n, tr, black, grey, cur);
        }
    }
    black.insert(s);
}

int solve(umap<string, vector<string>> adj, umap<string, vector<string>> tr){
    uset<string> black;
    int ans = 0;
    vector<string> finish;
    for(auto p:adj){
        if(black.find(p.a) == black.end()){
            uset<string> grey;
            grey.insert(p.a);
            dfs(p.a, adj, black, grey, finish);
        }
    }
    black = uset<string>();
    for(int i=sz(finish)-1;i>=0;--i){
        // cout << finish[i] << endl;
        if(black.find(finish[i]) == black.end()){
            uset<string> grey;
            grey.insert(finish[i]);
            int cur = 1;
            dfs2(finish[i], tr, black, grey, cur);
            ans = max(ans, cur);
        }
    }
    return ans;
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
    umap<string, vector<string>> adj;
    umap<string, vector<string>> tr;
    umap<string, vector<string>> m;
    cin.ignore();
    for(int i=0; i < t; ++i) { //loops for each case
        // cin.ignore();
        string s;
        getline(cin, s);
        // cout << s << endl;
        int space = s.find(' ');
        string name = s.substr(0,space);
        adj[name] = vector<string>();
        tr[name] = vector<string>();
        m[name] = vector<string>();
        s = s.substr(space+1,sz(s)-space);
        while(sz(s) > 0){
            space = s.find(' ');
            string lang = s.substr(0,space);
            m[name].pb(lang);
            // cout << lang << endl;
            // for(auto p:adj){
            //     if(p.a != name && find(m[p.a].begin()+1, m[p.a].end(), lang) != m[p.a].end()){
            //         cout << name << " " << p.a << " " << lang << endl;
            //         adj[name].pb(p.a);
            //         adj[p.a].pb(name);
            //     }
            // }
            if(space == string::npos){
                break;
            }
            s = s.substr(space+1,sz(s)-space);
        }
    }

    for(auto p:m){
        for(auto q:m){
            if(p.a == q.a) continue;
            if(find(q.b.begin(), q.b.end(), p.b[0]) != q.b.end()){
                adj[p.a].pb(q.a);
                tr[q.a].pb(p.a);
            }
        }
        // cout << "neighbors of " << p.a << endl;
        // for(auto v:p.b){
        //     cout << v << " ";
        // }
        // cout << endl;
    }



    cout << t-solve(adj, tr) << endl;
    return 0;
}
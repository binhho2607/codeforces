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


bool dfs(umap<string, vector<string>> adj, string p, string q, uset<string> seen, string cur, string& ans){
    // cout << cur << endl;
    if(p == q){
        ans = cur;
        return true;
    }
    // cout << adj[p][0] << endl;
    for(auto n:adj[p]){
        if(seen.find(n) == seen.end()){
            seen.insert(n);
            if(dfs(adj, n, q, seen, cur+" "+n, ans)) return true;
            seen.erase(n);
        }
    }
    return false;
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
    cin.ignore();
    for(int i=0; i < t; ++i) { //loops for each case
        string s;
        getline(cin, s);
        // cout << s << endl;
        int space = s.find(' ');
        if(space == string::npos){
            if(adj.find(s) == adj.end()){
                adj[s] = vector<string>();
            }
            continue;
        }
        string cur = s.substr(0, space);
        s = s.substr(space+1, sz(s)-space);
        if(adj.find(cur) == adj.end()){
            adj[cur] = vector<string>();
        }
        while(true){
            // cout << "hi" << endl;
            space = s.find(' ');
            if(space == string::npos){
                adj[cur].pb(s);
                if(adj.find(s) == adj.end()){
                    adj[s] = vector<string>();
                }
                adj[s].pb(cur);
                break;
            }
            string t = s.substr(0, space);

            if(adj.find(t) == adj.end()){
                adj[t] = vector<string>();
            }
            adj[cur].pb(t);
            // cout << "add " << adj[cur].back() << endl;
            adj[t].pb(cur);
            s = s.substr(space+1, sz(s)-space);
        }        

    }

    // for(auto n:adj){
    //     cout << "neighbor of " << n.a << endl;
    //     for(auto v:n.b){
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    string p, q;
    cin >> p;
    cin >> q;

    uset<string> seen;
    seen.insert(p);
    string ans = "";
    if(dfs(adj, p, q, seen, p, ans)){
        cout << ans << endl;
    }else{
        cout << "no route found" << endl;
    }

    return 0;
}
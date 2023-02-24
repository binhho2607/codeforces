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

string hash2(int x, int y){
    return to_string(x) + " " + to_string(y);
}


bool dfs(int i, int j, vector<string> v, uset<string>& visited){
//    cout << i << " " << j << endl;
    if(i == sz(v)-1 && j == sz(v[0])-1){
        return true;
    }

    vector<pair<long, long>>dirs{mk(-1,0), mk(0,-1), mk(1,0), mk(0,1)};


    for(auto d:dirs){
        if(i+d.a >= 0 && i+d.a < sz(v) && j+d.b >= 0 && j+d.b < sz(v[0]) && v[i+d.a][j+d.b] != '#' && visited.find(
                hash2(i+d.a, j+d.b)) == visited.end()){
            visited.insert(hash2(i+d.a, j+d.b));
            if(dfs(i+d.a, j+d.b, v, visited)){
                return true;
            }
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
    vector<string> v;
    for(int i=0; i < t; ++i) { //loops for each case
        string s;
        cin >> s;
        v.pb(s);
    }
    vector<pair<long, long>> dirs{mk(-1,0), mk(0,-1)};
    vector<vector<long long>> dp(t, vector<long long>(sz(v[0]), 0));
    dp[0][0] = 1;
    for(int i=0;i<sz(dp);++i){
        for(int j=0;j<sz(dp[i]);++j){
            for(auto d:dirs){
                if(i+d.a >= 0 && i+d.a < sz(dp) && j+d.b >= 0 && j+d.b < sz(dp[0]) && v[i][j] != '#'){
                    dp[i][j] += dp[i+d.a][j+d.b]%((long long)pow(2, 31)-1);
                }
            }
        }
    }

    if(dp.back()[sz(dp.back())-1] != 0){
        cout << (long long)((long long)dp.back()[sz(dp.back())-1]%((long long)pow(2, 31)-1)) << endl;
        return 0;
    }

    uset<string> visited{hash2(0,0)};
    queue<pii> q;
    q.push(mk(0,0));
//    uset<string> visited;
    while(sz(q) > 0){
        pii top = q.front();
        q.pop();
        vector<pair<long, long>>dirs{mk(-1,0), mk(0,-1), mk(1,0), mk(0,1)};
        int i = top.a;
        int j = top.b;
        if(i == t-1 && j == t-1){
            cout << "THE GAME IS A LIE" << endl;
            return 0;
        }
        for(auto d:dirs){
            if(i+d.a >= 0 && i+d.a < sz(v) && j+d.b >= 0 && j+d.b < sz(v[0]) && v[i+d.a][j+d.b] != '#' && visited.find(
                    hash2(i+d.a, j+d.b)) == visited.end()){
                visited.insert(hash2(i+d.a, j+d.b));
                q.push(mk(i+d.a, j+d.b));
            }
        }
    }



//    if(dfs(0,0,v, visited)){
//        cout << "THE GAME IS A LIE" << endl;
//        return 0;
//    }
    cout << "INCONCEIVABLE" << endl;



    return 0;
}
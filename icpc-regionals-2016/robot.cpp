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

string hashStr(int x1, int x2, int x3){
    return to_string(x1)+" "+ to_string(x2) + " " + to_string(x3);
}

// i start at 0
int dp(pii cur, pii end, int i, umap<string, int>& memo, vector<vector<char>> v, string ins, uset<string> path, string fix, int maxLen){
//    cout << fix << endl;
    if(cur.a == end.a && cur.b == end.b){
//        cout << fix << endl;
        return 0;
    }
    if(sz(fix) > maxLen){
        return imax/2;
    }
    if(memo.find(hashStr(cur.a,cur.b,i)) != memo.end()){
        return memo[hashStr(cur.a,cur.b,i)];
    }
    int m = imax/2;
    umap<char, pii> dirs;
    dirs['L'] = mk(0,-1);
    dirs['R'] = mk(0,1);
    dirs['U'] = mk(-1,0);
    dirs['D'] = mk(1,0);
    for(auto dir:dirs){
        auto d = dir.b;
        if(cur.a+d.a >= 0 && cur.a+d.a < sz(v) && cur.b+d.b >= 0 && cur.b+d.b < sz(v[0]) && v[cur.a+d.a][cur.b+d.b] != '#' && path.find(hashStr(cur.a+d.a,cur.b+d.b,i)) == path.end()){
            path.insert(hashStr(cur.a,cur.b,i));
            m = min(m, 1+dp(mk(cur.a+d.a, cur.b+d.b), end, i, memo, v, ins, path, fix+dir.a, maxLen));
            path.erase(hashStr(cur.a+d.a,cur.b+d.b,i));
        }
    }
    if(i+1 < sz(ins)){
        auto d = dirs[ins[i+1]];
        if(cur.a+d.a >= 0 && cur.a+d.a < sz(v) && cur.b+d.b >= 0 && cur.b+d.b < sz(v[0]) && v[cur.a+d.a][cur.b+d.b] != '#'){
            path.insert(hashStr(cur.a+d.a,cur.b+d.b,i+1));
            m = min(m, dp(mk(cur.a+d.a, cur.b+d.b), end, i+1, memo, v, ins, path, fix, maxLen));
            path.erase(hashStr(cur.a+d.a,cur.b+d.b,i+1));

        }else{ // stay in place when hit obstacle
            path.insert(hashStr(cur.a,cur.b,i+1));
            m = min(m, dp(mk(cur.a, cur.b), end, i+1, memo, v, ins, path, fix, maxLen));
            path.erase(hashStr(cur.a,cur.b,i+1));
        }

        path.insert(hashStr(cur.a,cur.b,i+1));
        m = min(m, 1+dp(cur, end, i+1, memo, v, ins, path, fix, maxLen));
    }
    memo[hashStr(cur.a,cur.b,i)] = m;
//    cout << cur.a << " " << cur.b << " " << i << " " << m << endl;
    return m;
}


int bfs(pii start, pii end, vector<vector<char>> v){
    queue<pii> q;
    q.push(end);
    uset<string> visited{hashStr(start.a, start.b, 0)};
    int epoch = 0;
    while(sz(q) > 0){
        int n = sz(q);
        for(int i=0;i<n;++i){
            pii cur = q.front();
            q.pop();
            if(v[cur.a][cur.b] == 'S'){
                return epoch;
            }
//            if(cur.a == start.a && cur.b==start.b){
//                return epoch;
//            }
            vector<pii> dirs{mk(1,0),mk(-1,0),mk(0,1),mk(0,-1)};
            for(auto d:dirs){
                if(cur.a+d.a >= 0 && cur.a+d.a < sz(v) && cur.b+d.b >= 0 && cur.b+d.b < sz(v[0]) && v[cur.a+d.a][cur.b+d.b] != '#' && visited.find(hashStr(cur.a+d.a,cur.b+d.b,0)) == visited.end()){
                    q.push(mk(cur.a+d.a, cur.b+d.b));
                }
            }
        }
        epoch++;
    }
    return -1;
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

    cin >> t >> n;
    vector<vector<char>> v;
    pii start, end;
    for(int i=0; i < t; ++i) { //loops for each case
        v.pb(vector<char>());
        for(int j=0;j<n;++j){
            char s;
            cin >> s;
            v[sz(v)-1].pb(s);
            if(s == 'S') start = mk(i,j);
            if(s == 'G') end = mk(i,j);
        }
    }
    string ins;
    cin >> ins;

    pii cur = start;
    umap<char, pii> dirs;
    dirs['L'] = mk(0,-1);
    dirs['R'] = mk(0,1);
    dirs['U'] = mk(-1,0);
    dirs['D'] = mk(1,0);

    for(auto i:ins){
        auto d = dirs[i];
        if(cur.a+d.a >= 0 && cur.a+d.a < sz(v) && cur.b+d.b >= 0 && cur.b+d.b < sz(v[0]) && v[cur.a+d.a][cur.b+d.b] != '#'){
            v[cur.a+d.a][cur.b+d.b] = 'S';
            cur = mk(cur.a+d.a, cur.b+d.b);
        }
    }

    umap<string, int> memo;
    uset<string> path{hashStr(start.a, start.b, -1)};

    int maxLen = bfs(start, end, v);
    int ans = dp(start, end, -1, memo, v, ins, path, "", maxLen);
    cout << ans << endl;
    return 0;
}
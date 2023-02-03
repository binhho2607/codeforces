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

// return the value of closed cell
// int dp(vector<vi> v, int k, uset<vi, VectorHasher> u){
//     if(k == 0) return 0;
//     int ans = imax;
//     for(int i=0;i<sz(v);++i){
//         for(int j=0;j<2;++j){
//             if(u.find({i,j}) != u.end()) continue;
//             vector<pii> dirs{mk(0,1),mk(0,-1),mk(-1,-1),mk(1,-1),mk(1,1),mk(-1,1)};
//             bool f = true;
//             for(auto d:dirs){
//                 if(i+d.a >= 0 && i+d.a < sz(v) && j+d.b >= 0 && j+d.b < 2 && u.find({i+d.a,j+d.b}) != u.end()){
//                     f = false;
//                     break;
//                 }
//             }
//             if(f){
//                 u.insert({i,j});
//                 ans = min(ans, v[i][j]+dp(v, k-1, u));
//                 u.erase({i,j});
//             }
//         }
//     }
//     return ans;
// }


// int solve(vector<vi> v, int k){
//     int ans = 0;
//     while(k>0){
//         int m=imin;
//         pii mi;
//         vector<pii> dirs{mk(0,1),mk(0,-1),mk(-1,-1),mk(1,-1),mk(1,1),mk(-1,1)};
//         for(int i=0;i<sz(v);++i){
//             for(int j=0;j<2;++j){
//                 if(v[i][j] == -1) continue;
                
//                 bool f = true;
//                 int prof = -v[i][j];
//                 for(auto d:dirs){
//                     if(i+d.a >= 0 && i+d.a < sz(v) && j+d.b >= 0 && j+d.b < 2){
//                         if(v[i+d.a][j+d.b] == -1){
//                             f = false;
//                             break;
//                         }
//                         prof += v[i+d.a][j+d.b];
//                     }
//                 }
//                 if(!f) continue;
//                 if(prof>m){
//                     m = prof;
//                     mi.a = i;
//                     mi.b = j;
//                 }
//             }
//         }
//         ans += v[mi.a][mi.b];
//         v[mi.a][mi.b] = -1;
//         for(auto d:dirs){
//             if(mi.a+d.a >= 0 && mi.a+d.a < sz(v) && mi.b+d.b >= 0 && mi.b+d.b < 2 ){
//                 v[mi.a+d.a][mi.b+d.b] = 0;
//             }
//         }
//         --k;
//     }
//     return ans;
// }

int dp(vector<vi> v, int k, int r, int c, umap<string, int>& memo){
    if(k==0) return 0;
    if(sz(v)-r < k) return imax/2;
    if(r >= sz(v)) return imax/2;
    if(memo.find(to_string(r)+" "+to_string(c)+" "+to_string(k)) != memo.end()){
        return memo[to_string(r)+" "+to_string(c)+" "+to_string(k)];
    }
    int m = imax;
    if(c != 1){
        m = min(v[r][0]+dp(v, k-1,r+1,0, memo), m);
    }
    if(c != 0){
        m = min(v[r][1]+dp(v, k-1,r+1,1, memo), m);
    }
    m = min(dp(v, k,r+1,-1, memo), m);
    memo[to_string(r)+" "+to_string(c)+" "+to_string(k)] = m;
    // cout << m  << " "  << r << " " << c << " " << k << endl;
    return m;
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
    int k;
    cin >> n;
    cin >> k;
    int total = 0;
    vector<vi> v;
    for(int i=0; i < n; ++i) { //loops for each case
        int s1, s2;
        cin >> s1 >> s2;
        v.pb(vi{s1,s2});
        total += (s1+s2);
    }
    // cin.ignore();
    // cin.ignore();
    // cout << total-dp(v, k, uset<vi, VectorHasher>()) << endl;
    // cout << total-solve(v, k) << endl;
    umap<string, int> memo;
    cout << total - dp(v, k, 0, -1, memo) << endl;

    return 0;
}
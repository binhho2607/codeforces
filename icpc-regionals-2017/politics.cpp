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

//pair<long double, int> dp(int cur, vector<vi> v, umap<int, pii>& memo){
////    cout << v[cur][0] << endl;
//    if(cur == sz(v)-1){
////        cout << "hi" << endl;
//        return mk(1.0, 1);
//    }
//    if(memo.find(cur) != memo.end()){
////        cout << "hi" << endl;
//        return memo[cur];
//    }
//    long double prob = 1.0/(v[cur][2]-v[cur][1]+1);
//    pair<long double, int> m = mk(0,0);
//    for(int i=v[cur][1];i<=v[cur][2];++i){
//        for(int j=cur+1;j<sz(v);++j){
//            if(v[j][0] < v[cur][0]+i) continue;
////            cout << "val " << j << endl;
//            pair<long double, int> res = dp(cur+1, v, memo);
////            cout << res.a << " " << res.b << endl;
//            res.a *= prob;
//            ++res.b;
//            cout << res.a*(long double)res.b << " " << res.a << " " << res.b << endl;
//            if(m.a*(long double)m.b < res.a*(long double)res.b){
//                m = res;
//            }
//        }
//    }
//    memo[cur] = m;
//    return m;
//}

long double dp(int cur, vector<vi> v, umap<string, long double>& memo, umap<int, long double>& done){
//    cout << cur << endl;
    if(done.find(cur) != done.end()) return done[cur];
//    memo[hash2(cur, 1)] = 1.0;
    if(cur == sz(v)-1){
        memo[hash2(cur, 1)] = 1.0;
        done[cur] = 1.0;
        return 1.0;
    }
    long double probOne = 1.0/(v[cur][2]-v[cur][1]+1);
    long double m = 0;
    for(int i=0; i<=0; ++i){ // can optimize this
        bool flag = true;
        for(int j=cur+1;j<sz(v);++j){
            if(v[j][0] < v[cur][0]+v[cur][1]) continue;
            if(v[j-1][0] > v[cur][0]+v[cur][2]) break;
            long double prob = (long double)(v[j][0]-(v[cur][0]+v[cur][1])+1)/(long double)(v[cur][2]-v[cur][1]+1);
            if(j > cur+1){
                prob = (long double)(min(v[j][0], v[cur][2])-v[j-1][0]+1)/(long double)(v[cur][2]-v[cur][1]+1);
            }
            cout << prob << endl;
            dp(j, v, memo, done);
            int k = 1;
            while(k <= sz(v)){
                if(memo.find(hash2(j, k)) == memo.end()){
                    ++k;
                    continue;
                }
                if(memo.find(hash2(cur, 1+k)) == memo.end()){
                    memo[hash2(cur, 1+k)] = 0.0;
                }
//                cout << memo[hash2(j, k)]*prob << endl;
                memo[hash2(cur, 1+k)] += memo[hash2(j, k)]*prob;
                m = max(m, memo[hash2(cur, 1+k)]);
                ++k;
            }
            flag = false;
//            break;
        }
        if(flag){
            if(memo.find(hash2(cur, 1)) == memo.end()){
                memo[hash2(cur, 1)] = 0;
            }
            memo[hash2(cur, 1)] += probOne; // can optimize this
            m = max(m, memo[hash2(cur, 1)]);
        }
    }

    done[cur] = m;
//    cout << cur << endl;
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

    cin >> t;
    vector<vector<int>> v{vector<int>{0,0,0}};
    for(int i=0; i < t; ++i) { //loops for each case
        int s, a, b;
        cin >> s >> a >> b;
        v.pb({s,a,b});
    }
    sort(v.begin(), v.end());
    umap<string, long double> memo;
    umap<int, long double> done;
    dp(0,v,memo, done);
    long double ans = 0;
    for(int strat=1;strat<sz(v);++strat){
        int k = 1;
        long double tmpAns = 0;
        long double checksum = 0;
        cout << "start " << strat << endl;
        while(k <= sz(v)){
            if(memo.find(hash2(strat, k)) == memo.end()){
                ++k;
                continue;
            }
            cout << hash2(strat, k) << " " << memo[hash2(strat,k)] << endl;
            checksum += memo[hash2(strat,k)];
            tmpAns += memo[hash2(strat,k)]*(k);
            ++k;
        }
//        cout << tmpAns << endl;
//        cout << checksum << endl;
        ans = max(ans, tmpAns);
    }

    cout << ans << endl;

//    pair<long double, int> ans = dp(0, v, memo);
//    cout << ans.a*(long double)(ans.b-1) << endl;

    return 0;
}
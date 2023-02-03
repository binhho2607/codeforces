#define imax INT_MAX
#define imin INT_MIN
#define sz(x) ((int)(x).size())
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define vi vector<int>


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


// void solve(string s)
// {
//     vector<pii> pl;
//     vector<pii> pr;
//     uset<char> v{'a','e','i','o','u'};
//     pl.pb(mk(0,0));
//     pr.pb(mk(0,0));
//     vector<umap<char, int>> ml;
//     vector<umap<char, int>> mr;
//     for(int i=0;i<sz(s);++i){
//         ml[0][s[i]] = 0;
//         mr[0][s[i]] = 0;
//     }
//     for(int i=1;i<sz(s);++i){
//         pii p = pl[i-1];
//         if(v.find(s[i-1]) != v.end()){
//             p.a = p.a+1;
//         }else{
//             p.b = p.b+1;
//         }
//         pl.pb(p);
//         ml.pb(umap<char, int>());
//         for(auto k:ml[i-1]){
//             if(k.a==s[i]){
//                 ml[i][k] = ml[i-1][k]+1;
//             }else{
//                 ml[i][k] = ml[i-1][k];
//             }
//         }
//     }
//     for(int i=sz(s)-2;i>=0;--i){
//         cout << pr.back().a << " " << pr.back().b << endl;
//         pii p = pr.back();
//         if(v.find(s[i+1]) != v.end()){
//             p.a = p.a+1;
//         }else{
//             p.b = p.b+1;
//         }
//         pr.pb(p);
//         mr.pb(umap<char, int>());
//         for(auto k:mr[sz(mr)-2]){
//             if(k.a==s[i]){
//                 mr[sz(mr)-1][k] = mr[sz(mr)-2][k]+1;
//             }else{
//                 mr[sz(mr)-1][k] = mr[sz(mr)-2][k];
//             }
//         }
//     }
//     reverse(pr.begin(), pr.end());
//     reverse(mr.begin(), mr.end());
//     // for(int i=0;i<sz(pr);++i){
//     //     cout << pr[i].a << " " << pr[i].b << endl;
//     // }
    


//     ll count = 0;
//     for(int i=2;i<sz(s)-2;++i){
        
//         ll l = 0;
//         ll r = 0;
//         for(int j=0;j<i-1;++j){
//             if(v.find(s[j]) != v.end()){ // vowel
//                 l += pr[j].b-pr[i-1].b; // consonant
//             }
//         }
//         for(int j=i+2;j<sz(s);++j){
//             if(v.find(s[j]) != v.end()){ // vowel
//                 r += pl[j].b-pl[i+1].b; // consonant
//             }
//         }
//         // cout << l << " " << r << endl;
//         count += l*r;
//     }
//     cout << count << endl;
// }


int dp(int i, int j, string str, const string& s, umap<int, umap<int, umap<string, int>>>& memo, const vector<int>& v, string index){
    // cout << i << " " << j << " " << s << endl;
    if(j==5){
        // cout << index << endl;
        return 1;

    } 
    if(i==sz(str)-1) return 0;
    if(memo.find(i) != memo.end() && memo[i].find(j) != memo[i].end() && memo[i][j].find(s) != memo[i][j].end()){
        return memo[i][j][s];
    }
    ll cur = 0;
    // cout << "cur " << cur << endl;
    for(int k=i+1;k<sz(str);++k){
        
        if(v[k] == j%2 && s.find(str[k]) == string::npos){
            cur += dp(k, j+1, str, s+str[k], memo, v, index+to_string(k));
        }
    }
    if(memo.find(i) == memo.end()){
        memo[i] = umap<int, umap<string, int>>();
    }
    if(memo[i].find(j) == memo[i].end()){
        memo[i][j] = umap<string, int>();
    }
    memo[i][j][s] = cur;
    return cur;
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int t;
    unsigned int n;

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    vi v;
    for(int i=0;i<sz(s);++i){
        if(tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u'){
            v.pb(0);
        }else{
            v.pb(1);
        }
        
    }
    // solve(s);
    umap<int, umap<int, umap<string, int>>> memo;
    cout << dp(-1,0,s,"",memo, v, "") << endl;
}
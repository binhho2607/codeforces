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
// #define all(x) (x).begin(), (x).end()
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

void solve(string s){
    vector<pair<char,int>> v;
    int c;
    int m;
    for(int i=1;i<sz(s)-1;++i){
        if((s[0]<=s[sz(s)-1] && s[i]>=s[0] && s[sz(s)-1]>=s[i]) || (s[0]>=s[sz(s)-1] && s[i]<=s[0] && s[sz(s)-1]<=s[i])){
            v.pb(mk(s[i],i));
        }
    }
    sort(v.begin(),v.end());
    if(s[0]>s[sz(s)-1]){
        reverse(v.begin(),v.end());
    }
    cout << abs(int(s[0])-int(s[sz(s)-1])) << " " << sz(v)+2 << endl;
    cout << 1 << " ";
    
    for(int i=0;i<sz(v);++i){
        cout << v[i].second+1 << " ";
    }
    cout << sz(s) << endl;
    return;
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

    for(int i=0; i < t; ++i) { //loops for each case
        string s;
        cin >> s; // number of elements in vector
        solve(s);
    }

    return 0;
}
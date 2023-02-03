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


void solve(string s){
    int l = sz(s);
    int m;
    for(int i=0;i<sqrt(l)+1;++i){
        if(i*i >= l){
            m = i;
            break;
        }
    }

    // cout << m << endl;

    vector<vector<char>> v(m, vector<char>(m, '*'));
    int p = 0;
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            v[i][j] = s[p];
            ++p;
            if(p==sz(s)){
                break;
            }
        }
        if(p==sz(s)){
            break;
        }
    }

    // for(int i=0;i<m;++i){
    //     for(int j=0;j<m;++j){
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i=0;i<m;++i){
        for(int j=i+1;j<m;++j){
            swap(v[i][j], v[j][i]);
        }
    }

    for(int i=0;i<m;++i){
        reverse(v[i].begin(), v[i].end());
    }
    string ans = "";
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            if(v[i][j] != '*'){
                ans += v[i][j];
            }
        }
    }
    cout << ans << endl;

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
        cin >> s;
        solve(s);
    }

    return 0;
}
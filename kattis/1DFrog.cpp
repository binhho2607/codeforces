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


void solve(int n, int s, int m, vi nums){
    uset<int> p;
    
    --s;
    p.insert(s);
    if(nums[s] == m){
        cout << "magic" << endl;
        cout << 0 << endl;
        return;
    }
    int h = 0;
    while(true){
        ++h;
        s = nums[s]+s;
        if(s < 0){
            cout << "left" << endl;
            break;
        }
        if(s >= n){
            cout << "right" << endl;
            break;
        }
        if(nums[s] == m){
            cout << "magic" << endl;
            break;
        }
        if(p.find(s) != p.end()){
            cout << "cycle" << endl;
            break;
        }
        p.insert(s);
    }
    cout << h << endl;
    return;
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int n;
    unsigned int s;
    unsigned int m;
    

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> n;
    cin >> s;
    cin >> m;

    vi nums;
    for(int i=0;i<n;++i){
        int k;
        cin >> k;
        nums.pb(k);
    }
    solve(n,s,m,nums);

    return 0;
}
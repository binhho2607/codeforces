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

struct PairHasher{
  size_t operator()(const pii &x) const{
    return x.first ^ x.second;
  }
};


void solve(int s){
    cout << s << endl;
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int w;
    unsigned int s;
    unsigned int c;
    unsigned int k;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> w;
    cin >> s;
    cin >> c;
    cin >> k;
    if(k==0){
        cout << "NO" << endl;
    }else
    if(w == 0 && (s <= k || c <= k)){
        cout << "YES" << endl;
    }else if(s == 0){
        cout << "YES" << endl;
    }else if(c == 0 && (w <= k || s <= k)){
        cout << "YES" << endl;
    }
    else if(s < k || (s==k && w+c-k<=k) || (s>k && w+c<k) || (s<=2*k && w+c<=k)){
        cout << "YES" << endl;
    }
    else if((c+s<=k && c+w <= k) || (w+s<=k && w+c <= k) || (s+w<=k && s+c <= k)){
        cout << "YES" << endl;
    }
    
    else{
        cout << "NO" << endl;
    }

    // for(int i=0; i < t; ++i) { //loops for each case
    //     cin >> n; // number of elements in vector
    //     vi nums;
    //     for (int j=0; j < n; ++j) { // each element of vector
    //         int s;
    //         cin >> s;
    //         nums.pb(s);
    //     }
    // }

    return 0;
}
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

    string a, b;
    cin >> a;
    cin >> b;
    long long ans = 0;
    int left = 0;
    int right = sz(a) - 1;
    while(left < sz(a) && a[left] == b[left]){
        ++left;
    }
    while(right >= 0 && a[right] == b[right]){
        --right;
    }
//    if(left == right){
//        cout << 0 << endl;
//        return 0;
//    }
    string group = a.substr(left, right-left+1);
    reverse(group.begin(), group.end());
    string tmp = a.substr(0,left) + group + a.substr(right+1, sz(a)-right-1);
//    cout << tmp << endl;
    if(tmp != b){
        cout << 0 << endl;
        return 0;
    }
    ans = 1;
    while(left-ans >= 0 && right+ans < sz(a) && a[left-ans] == a[right+ans]){
        ++ans;
    }
    cout << ans << endl;
//    for(int
//    i=0;i<sz(a)-1;++i){
//        for(int j=i;j<sz(a);++j){
//            string group = a.substr(i, j-i+1);
//            reverse(group.begin(), group.end());
//            string tmp = a.substr(0,i) + group + a.substr(j+1, sz(a)-j-1); // may have bound error
//            if(tmp == b) ++ans;
//        }
//    }
//    cout << ans << endl;

    return 0;
}
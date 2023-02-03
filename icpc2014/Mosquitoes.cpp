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
#define ldb long double



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


void solve(vector<pair<ldb,ldb>> v, ldb d){
    int left = 0;
    int right = 0;
    int ans = 0;
    sort(v.begin(), v.end());
    for(auto n:v){
        cout << " (" << n.a << "," << n.b << ") ";
    }
    cout << endl;
    while(right<sz(v)-1){
        while(left < right && v[right].a-v[left].a > d){
            ++left;
        }
        pair<ldb, ldb> avg{0,0};
        for(int i=left;i<=right;++i){
            avg.a += v[i].a;
            avg.b += v[i].b;
        }
        avg.a /= (right-left+1);
        avg.b /= (right-left+1);
        int c = 0;
        for(int i=left;i<=right;++i){
            if(sqrt(pow(avg.a-v[i].a,2) + pow(avg.b-v[i].b,2)) <= d/2){
                ++c;
            }
        }
        cout << left << " " << right << " " << c << endl;
        ans = max(ans, c);
        ++right;
    }
    cout << ans << endl;
}




int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int t;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> t;
    cin.ignore();
    for(int i=0; i < t; ++i) { //loops for each case
        vector<pair<ldb, ldb>> v;
        int n;
        ldb d;
        cin >> n >> d;
        for(int j=0;j<n;++j){
            ldb s1, s2;
            cin >> s1 >> s2;
            v.pb(mk(s1, s2));
        }
        solve(v, d);
        cin.ignore();
    }

    return 0;
}
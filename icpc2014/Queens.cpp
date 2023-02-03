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


    vector<string> v(8, "........");
    uset<int> r, c;
    int count = 0;
    for(int i=0; i < 8; ++i) { //loops for each case
        string s;
        cin >> s;
        v[i] = s;
        for(int j=0;j<8;++j){
            if(s[j] == '.') continue;
            ++count;
            // if(r.find(i) != r.end()){
            //     cout << s << endl;
            //     cout << "invalid" << endl;
            //     return 0;
            // }
            // if(c.find(j) != c.end()){
            //     cout << "invalid" << endl;
            //     return 0;
            // }
            // r.insert(i);
            // c.insert(j);
            vector<pii> dirs{mk(1,1),mk(-1,-1),mk(-1,1), mk(1,-1), mk(1,0), mk(0,1), mk(-1,0), mk(0,-1)};
            for(auto d:dirs){
                for(int k=1;k<=8;++k){
                    if(i+k*d.a >= 0 && i+k*d.a < 8 && j+k*d.b >= 0 && j+k*d.b < 8 && v[i+k*d.a][j+k*d.b] == '*'){
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
                
            }
        }
    }
    if(count == 8){
        cout << "valid" << endl;
    }else{
        cout << "invalid" << endl;
    }
    

    return 0;
}
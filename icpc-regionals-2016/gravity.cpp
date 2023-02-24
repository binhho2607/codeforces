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


void solve(vector<string> m){

    for(int c=0;c<sz(m[0]);++c){
        int free = -1;
        int ptr = sz(m)-1;
        while(ptr >= 0){

            if(m[ptr][c] == '.' && free == -1){
                free = ptr;
            }
            if(m[ptr][c] == '#'){
                free = -1;
            }
            if(m[ptr][c] == 'a' && free != -1){
                m[free][c] = 'a';
                m[ptr][c] = '.';
                while(free >= ptr && m[free][c] != '.'){
                    free -= 1;
                }
                if(free < ptr){
                    free = -1;
                }
            }
            ptr -= 1;
        }
    }
    for(auto s:m){
        cout << s << endl;
    }
    return;
}




int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/
    unsigned int m;
    unsigned int n;

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    cin >> m >> n;
    vector<string> matrix;
    for(int i=0; i < m; ++i) { //loops for each case
        string s;
        cin >> s;
        matrix.pb(s);
    }
    solve(matrix);

    return 0;
}
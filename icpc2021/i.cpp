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


void solve(uset<string> h, vector<vector<string>> c){
    while(true){
        int n = sz(h);
        for(int i=0;i<sz(c);++i){
            if(h.find(c[i].back()) != h.end()){
                continue;
            }
            if(c[i][0]=="and"){
                bool f = true;
                for(int j=1;j<sz(c[i])-1;++j){
                    if(h.find(c[i][j]) == h.end()){
                        f = false;
                        break;
                    }
                }
                if(f){
                    h.insert(c[i].back());
                }
            }else{
                for(int j=1;j<sz(c[i])-1;++j){
                    if(h.find(c[i][j]) != h.end()){
                        h.insert(c[i].back());
                        break;
                    }
                }
            }
        }


        if(n==sz(h)){
            break;
        }
    }
    cout << sz(h) << endl;
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
    uset<string> h;
    vector<vector<string>> c;
    while(t > 0){
        string s;
        cin >> s;
        if(s!="if"){
            h.insert(s);
        }else{
            string s1;
            cin >> s1;
            cin >> s;
            c.pb(vector<string>());
            c.back().pb(s);
            c.back().pb(s1);
            while(s!="then"){
                cin >> s;
                c.back().pb(s);
                cin >> s;
            }
            cin >> s;
            c.back().pb(s);
        }
        --t;
    }
    solve(h, c);

    return 0;
}
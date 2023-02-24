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
    string s;
    getline(cin, s);
//    cout << s[sz(s)-1] << endl;
    int ind = s.find(' ');
    uset<string> u;
    while(ind != string::npos){
        string tmp = s.substr(0,ind);
        if(u.find(tmp) != u.end()){
            cout << "no" << endl;
            return 0;
        }
        u.insert(tmp);
        s = s.substr(ind+1, sz(s)-ind);
        ind = s.find(' ');
    }
    if(u.find(s) != u.end()){
        cout << "no" << endl;
        return 0;
    }
    cout << "yes" << endl;


    return 0;
}
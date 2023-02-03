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


void solve(string s, int n){
    // string p = s.substr(sz(s)-n,n);
    // for(int i=0;i<100;++i){
    //     s += p;
    // }
    // long double d = stod(s)-stoi(s);
    // // cout << fixed << setprecision(15) << d << endl;
    // ll q = 1;
    // ll m = 1;
    // if(q*d-(int)(q*d)<=0.5){
    //     m = (int)(q*d);
    // }else{
    //     m = (int)(q*d)+1;
    // }
    // while(abs(q*d-m) > 1.0/(long double)pow(10,9)){
    //     ++q;
    //     if(q*d-(int)(q*d)<=0.5){
    //         m = (int)(q*d);
    //     }else{
    //         m = (int)(q*d)+1;
    //     }
    // }
    // cout << stoi(s)*q+d*q << "/" << q << endl;
    string p = s.substr(sz(s)-n,n);
    ll n1 = 0;
    for(int i=0;i<n;++i){
        n1 += pow(10, n-i-1)*(int)(p[i]-'0');
    }
    
    int dot = s.find('.');
    int mult = pow(10, sz(s)-n-dot-1);
    ll d1 = (pow(10, n)-1)*mult;
    ll n2 = stod(s.substr(0, sz(s)-n))*mult;
    
    ll r1 = n1*mult+n2*d1;
    ll r2 = d1*mult;
    // cout << n1*mult << " " << n2*d1 << " " << n2 << endl;
    cout << r1/gcd(r1, r2) << "/" << r2/gcd(r1, r2) << endl;
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
    cin >> s;
    cin >> n;
    solve(s, n);

    return 0;
}
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


void encrypt(string s){
    
    vector<int> v;
    string ans = s;
    for(int i=0;i<sz(s);++i){
        if(s[i] == ' '){
            v.pb(0);
        }else{
            v.pb((int)(s[i]-'a')+1);
        }
    }

    for(int i=1;i<sz(v);++i){
        v[i] += v[i-1];
        int m = ((v[i])%27);
        if(m == 0){
            ans[i] = ' ';
        }else{
            ans[i] = char(m+(int)('a')-1);
        }
    }

    // for(int i=0;i<sz(s);++i){
    //     if(s[i] == ' '){
    //         if(i == 0){
    //             v.pb(0);
    //         }else{
    //             v.pb(v[i-1]);
    //         }
            
    //     }else{
    //         if(i == 0){
    //             v.pb((int)(s[i]-'a')+1);
    //         }else{
    //             v.pb((int)(s[i]-'a')+v[i-1]+1);
    //         }
    //     }
    //     if(i == 0){
    //         ans[i] = s[i];
    //     }else{
    //         int m = ((v[i])%27);
    //         if(m == 0){
    //             ans[i] = ' ';
    //         }else{
    //             ans[i] = char(m+(int)('a')-1);
    //         }
            
    //     }

    // }
    cout << ans << endl;
}

void decrypt(string s){
    vector<int> v;
    string ans = s;
    for(int i=0;i<sz(s);++i){
        if(s[i] == ' '){
            v.pb(0);
        }else{
            v.pb((int)(s[i]-'a')+1);
        }
    }
    int prev = (int)(s[0]-'a')+1;
    if(s[0] == ' '){
        prev = 0;
    }
    for(int i=1;i<sz(s);++i){
        // cout << "dec " << i << " " << sz(s) << endl;
        int cur;
        if(s[i] == ' '){
            cur = 0;
        }else{
            cur = (int)(s[i]-'a')+1;
        }
        while(cur < prev){
            cur += 27;
        }
        int m = cur-prev;
        // int m = (cur-prev)%27;
        // while(m < 0){
        //     m += 27;
        // }
        // cout << m << " " << cur << " " << prev << endl;
        if(m == 0){
            ans[i] = ' ';
        }else{
            ans[i] = char(m+(int)('a')-1);
        }
        if(s[i] != ' '){
            prev = (int)(s[i]-'a')+1;
        }else{
            prev = 0;
        }
        
    }
    // for(int i=1;i<sz(v);++i){
    //     while(v[i] < v[i-1]){
    //         v[i] += 27;
    //     }
    // }

    // for(int i=1;i<sz(v);++i){
    //     // v[i] -= v[i-1];
    //     if(v[i]-v[i-1] == 0){
    //         ans[i] = ' ';
    //     }else{
    //         ans[i] = char(v[i]-v[i-1]+(int)('a')-1);
    //     }
    // }
    // for(int i=0;i<sz(v);++i){
    //     if(v[i] == 0){
    //         ans[i] = ' ';
    //     }else{
    //         ans[i] = char(v[i]+(int)('a')-1);
    //     }
    // }

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
        string s1;
        cin >> s1;
        getline(cin, s);
        // getline(cin, s);
        if(s1 == "e"){
            encrypt(s.substr(1,sz(s)-1));
        }else{
            decrypt(s.substr(1,sz(s)-1));
        }
    }

    return 0;
}
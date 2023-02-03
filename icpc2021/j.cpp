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


void solve(stack<int> st){
    string ans = "";
    ll p = 0;
    while(sz(st) > 0){
        
        if (sz(st) == 0) break;
        int val = st.top()+p;
        st.pop();
        if(val==1){
            ans += "1";
            continue;
        }

        while(val > 1){
            if(val%2==0){
                ans += "+";
                ans += "d";
                p += 1;
                val = val/2;
            }else{
                ans += "+";
                ans += "1";
                p += 1;
                val -= 1;
            }
        }
        ans += "11";
    }
    reverse(ans.begin(),ans.end());
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
    stack<int> st;
    for(int i=0; i < t; ++i) { //loops for each case
        int s;
        cin >> s;
        st.push(s);
    }
    solve(st);

    return 0;
}
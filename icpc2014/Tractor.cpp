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


// void solve(int s){
//     cout << s << endl;
// }

void recursion(int a, int b, pii cur, int exp, ll& ans){
    if(cur.a+pow(2,exp-1) <= a){
        ++ans;
        recursion(a, b, mk(cur.a+pow(2,exp-1),cur.b), exp+1, ans);
    }
    if(cur.a+pow(2,exp-1) <= a){
        ++ans;
        recursion(a, b, mk(cur.a+pow(2,exp-1),cur.b), exp+1, ans);
    }
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
        int a, b;
        cin >> a >> b;
        ll ans = 0;
        int j=0;
        // recursion(a, b, {0,0}, 1,ans);
        while(j<30){
            if(pow(2,j)-1 > max(a,b)){
                // cout << i << endl;
                break;
            } 
            if(pow(2,j)-1 <= min(a,b)){
                
                ans += pow(2,j);
                // cout << ans << endl;
            }else{
                ans += min(a,b)+1;
            }
            ++j;
        }
        // cout << min(a,b)-(pow(2,j)-1-max(a,b))+1 << endl;
        if(min(a,b)-(pow(2,j)-1-max(a,b))+1 > 0){
            ans += min(a,b)-(pow(2,j)-1-max(a,b))+1;
        }
        cout << ans << endl;
    }

    return 0;
}
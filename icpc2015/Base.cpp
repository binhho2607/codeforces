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

ll convert(string s, int b){
    ll ans = 0;
    uset<char> u{'0','1','2','3','4','5','6','7','8','9'};
    for(int i=0;i<sz(s);++i){
        if(u.find(s[sz(s)-i-1]) == u.end()){
            if(b != 1 && (int)(s[sz(s)-i-1]-'a')+10 >= b){
                return -1;
            }
            if(b == 1){
                return -1;
            }
            ans += ((int)(s[sz(s)-i-1]-'a')+10)*pow(b, i);
        }else{
            if(b != 1 && (int)(s[sz(s)-i-1]-'0') >= b){
                return -1;
            }
            if(b == 1 && ((int)(s[sz(s)-i-1]-'0') > b || (int)(s[sz(s)-i-1]-'0') == 0)){
                return -1;
            }
            ans += (int)(s[sz(s)-i-1]-'0')*pow(b, i);
        }
        
    }
    return ans;
}

void solve(vector<vector<string>> v){
    for(auto p:v){
        string ans = "";
        for(int i=1;i<=36;++i){
            // cout << p[0] << " " << p[2] << " " << p[4] << endl;
            
            ll x = convert(p[0], i);
            ll y = convert(p[2], i);
            ll z = convert(p[4], i);
            if(x == -1 || y == -1 || z == -1) continue;
            if((p[1] == "+" &&  x+y==z) || (p[1] == "-" &&  x-y==z) || (p[1] == "*" &&  x*y==z) || (p[1] == "/" &&  y != 0 && z*y == x)){
                // cout << x << " " << y << " " << z << " " << i << endl;
                if(i==36){
                    ans += "0";
                }else
                if(i<=9){
                    ans += to_string(i);
                }else{
                    ans += char('a'+i-10);
                }
                
            }
        }
        if(ans == ""){
            cout << "invalid" << endl;
        }else{
            cout << ans << endl;
        }
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

    vector<vector<string>> v;
    for(int i=0; i < t; ++i) { //loops for each case
        v.pb(vector<string>());
        for(int j=0;j<5;++j){
            string s1;
            cin >> s1;
            v[sz(v)-1].pb(s1);
        }
    
    }

    solve(v);

    return 0;
}
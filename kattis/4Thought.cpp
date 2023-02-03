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


void generate(string s, vector<string>& v, int c){
    if(c==4){
        v.pb(s);
        return;
    }
    generate(s+" + 4", v,c+1);
    generate(s+" - 4", v,c+1);
    generate(s+" * 4", v,c+1);
    generate(s+" / 4", v,c+1);
}


void solve(vi nums){
    vector<string> v;
    umap<char, int> m;
    umap<int, string> m2;
    m['+'] = 0;
    m['-'] = 0;
    m['*'] = 1;
    m['/'] = 1;
    generate("4",v,1);
    for(string str:v){
        stack<int> s;
        stack<char> op;
        bool f = true;
        for(int i=0;i<sz(str);++i){
            if(str[i] == ' ') continue;
            if(m.find(str[i]) == m.end()){
                s.push((int)(str[i]-'0'));
            }else{
                while(sz(op) > 0 && m[str[i]] <= m[op.top()]){
                    int v1 = s.top();
                    s.pop();
                    int v2 = s.top();
                    s.pop();
                    int res;
                    if(op.top()=='+'){
                        res = v1+v2;
                    }
                    if(op.top()=='-'){
                        res = v2-v1;
                    }
                    if(op.top()=='*'){
                        res = v1*v2;
                    }
                    if(op.top()=='/'){
                        if(v1 == 0){
                            f = false;
                            break;
                        }
                        res = v2/v1;
                    }
                    s.push(res);
                    op.pop();
                }
                op.push(str[i]);
            }
        }
        if(!f) {
            continue;
        }
        while(sz(op) > 0){
            int v1 = s.top();
            s.pop();
            int v2 = s.top();
            s.pop();
            int res;
            // cout << str << " " << v1 << " " << v2 << endl;
            if(op.top()=='+'){
                res = v1+v2;
            }
            if(op.top()=='-'){
                res = v2-v1;
            }
            if(op.top()=='*'){
                res = v1*v2;
            }
            if(op.top()=='/'){
                if(v1 == 0){
                    f = false;
                    break;
                }
                res = v2/v1;
            }
            s.push(res);
            op.pop();
        }
        if(!f) continue;
        // cout << "map " << str << " " << s.top() << endl;
        m2[s.top()] = str;
    }



    for(int n:nums){
        if(m2.find(n) == m2.end()){
            cout << "no solution" << endl;
        }else{
            cout << m2[n] << " = " << n << endl;
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
    vi nums;
    for(int i=0;i<t;++i){
        int s;
        cin >> s;
        nums.pb(s);
    }
    solve(nums);
    return 0;
}
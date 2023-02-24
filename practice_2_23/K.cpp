#define imax INT_MAX
#define imin INT_MIN
#define sz(x) ((int)(x).size())
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define vii vector<vi>
#define umap unordered_map
#define uset unordered_set
#define MOD 100000007

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

struct VectorHasher{
    int operator()(const vi&V) const{
        int hash = V.size();
        for (auto & i : V){
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash>>2);
        }
        return hash;
    }
};

void process(string &p, vi & prefix){
    prefix[0] = 0;
    int m = p.length();
    int j = 0;
    int i = 1;
    while (i < m){
        if (p[i] ==p[j]){
            j++;
            prefix[i] = j;
            ++i;
        }else{
            if (j != 0){
                j = prefix[j - 1];
            }else {
                prefix[i] = 0;
                ++i;
            }
        }
    }
}

void solve(int s){
    cout <<s<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned int t;
    unsigned int n;
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    uset<string> u;
    string ans = "";
    for(int i=0;i<sz(s);++i){
        for(int j=i;j<sz(s);++j){
            string tmp = s.substr(i,j-i+1);
            if(u.find(tmp) != u.end()){
                if(sz(tmp) > sz(ans)){
                    ans = tmp;
                }
            }
            u.insert(tmp);
        }
    }
    vi prefix(s.length());
    string test = "aa";
    process(s, prefix);
    int max = -1;
    string rep = "";
    for (int i = 0; i < s.length(); ++i){
        if (prefix[i] > max){
            rep = s.substr(i - prefix[i] , prefix[i]);
        }
    }
    cout << rep << endl;
    return 0;
}

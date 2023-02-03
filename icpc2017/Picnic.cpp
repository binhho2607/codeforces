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

struct TreeNode {
    float val;
    string name;
    vector<TreeNode*> next;
    TreeNode* prev;
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

void traverse(TreeNode* root, umap<string, pair<string, float>>& taken){
    if(sz(root->next) == 0){
        if(root->prev == nullptr) return;
        if(taken.find(root->prev->name) == taken.end()){
            taken[root->name] = mk(root->prev->name, (root->val+root->prev->val)/2);
            taken[root->prev->name] = mk(root->name, (root->val+root->prev->val)/2);
        }
        return;
    }
    traverse(root->next[0], taken);
    if(sz(root->next) == 2) traverse(root->next[1], taken);
    if(root->prev == nullptr) return;
    if(taken.find(root->name) == taken.end() && taken.find(root->prev->name) == taken.end()){
        taken[root->name] = mk(root->prev->name, (root->val+root->prev->val)/2);
        taken[root->prev->name] = mk(root->name, (root->val+root->prev->val)/2);
    }
}

void change(TreeNode* root, umap<string, pair<string, float>>& taken){
    if(taken.find(root->name) == taken.end()){
        if(sz(root->next) >= 1){
            if(taken[root->next[0]->name].b < (root->val+root->next[0]->val)/2){
                taken.erase(taken[root->next[0]->name].a);
                
            }
        }
    }
}

void solve(TreeNode* root){
    umap<string, pair<string, float>> taken;
    traverse(root, taken);
    cout << sz(taken) << endl;
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
    // umap<string, pair<float, string>> adj;
    umap<string, pair<TreeNode*, string>> m;
    string tmp;
    getline(cin, tmp);
    for(int i=0; i < t; ++i) { //loops for each case
        string str;
        getline(cin, str);
        string s = str.substr(0, str.find(" "));
        if(m.find(s) == m.end()){
            m[s] = mk(new TreeNode(), "");
            m[s].a->name = s;
        }
        string rest = str.substr(str.find(" ")+1, sz(str)-str.find(" "));
        string n = rest.substr(0, rest.find(" "));
        m[s].a->val = stof(n);
        string s1 = rest.substr(rest.find(" ")+1, sz(rest)-rest.find(" "));
        m[s].b = s1;
        
        if(m.find(s1) == m.end() && s1 != "CEO"){
            m[s1] = mk(new TreeNode(), "");
            m[s1].a->name = s1;
        }
    }
    TreeNode* root = nullptr;
    for(auto p:m){
        if(p.b.b == "CEO"){
            root = p.b.a;
            p.b.a->prev = nullptr;
        }else{
            p.b.a->prev = m[p.b.b].a;
            m[p.b.b].a->next.pb(p.b.a);
        }
        
    }

    solve(root);

    return 0;
}
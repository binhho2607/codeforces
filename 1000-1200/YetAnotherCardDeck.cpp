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

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

struct node {
    int val;
    node* next;
    node* prev;
};


void solve(vi d, vi q){
    // umap<int, queue<int>> m;
    // for(int i=0;i<sz(d);++i){
    //     if(m.find(d[i]) == m.end()){
    //         m.emplace(d[i], queue<int>());
    //         m[d[i]].push()
    //     }
    // }
    node* head = new node();
    node* tail = new node();
    head->next = tail;
    head->prev = nullptr;
    tail->prev = head;
    tail->next = nullptr;
    node* cur = head;
    for(int i=0;i<sz(d);++i){
        node* n = new node();
        n->val = d[i];
        cur->next = n;
        n->prev = cur;
        n->next = tail;
        tail->prev = n;
        cur = n;
    }
    cur = head->next;
    for(int i=0;i<sz(q);++i){
        int j = 0;
        while(cur != tail){
            ++j;
            if(cur->val == q[i]){
                cout << j << " ";
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                cur->next = head->next;
                head->next->prev = cur;
                head->next = cur;
                cur->prev = head;
                break;
            }
            cur = cur->next;
        }
    }
    cout << endl;
    return;
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
    cin >> n;

    vi d;
    vi q;
    for(int i=0; i < t; ++i) { //loops for each case
        int s;// number of elements in vector
        cin >> s;
        d.pb(s);
    }
    for(int i=0; i < n; ++i) { //loops for each case
        int s;// number of elements in vector
        cin >> s;
        q.pb(s);
    }
    solve(d, q);
    return 0;
}
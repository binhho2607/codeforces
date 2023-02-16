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

#define umap unordered_map
#define uset unordered_set
#define MOD 10000000007

#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *prev;
};

struct PairHasher {
    int operator()(const pii &v) const {
        int hash = 2;
        hash ^= v.a+0x9e3779b9 + (hash << 6) + (hash >> 2);
        return hash;
    }
};

void solve(vector<string> m, int t, queue<pii> q, uset<pii, PairHasher> u){
    ll ans = 0;
    while(sz(q) > 0){
        int k = sz(q);
        while(k > 0){
            pii p = q.front();
            q.pop();
            vector<pii> dirs{mk(-1,0),mk(1,0),mk(0,1),mk(0,-1)};
            for(auto d:dirs){
                if(p.a+d.a>=0 && p.a+d.a < sz(m) && p.b+d.b>=0 && p.b+d.b < sz(m[0])
                         && u.find(mk(p.a+d.a,p.b+d.b)) == u.end() && m[p.a+d.a][p.b+d.b] != '#'){
                    u.insert(mk(p.a+d.a, p.b+d.b));
                    q.push(mk(p.a+d.a, p.b+d.b));
                    if(m[p.a+d.a][p.b+d.b]=='P'){
                        ++ans;
                        m[p.a+d.a][p.b+d.b] = '.';
                    }
                }
            }
            --k;
        }
        --t;
        if(t == 0) break;
    }
    cout << ans << endl;

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("../input.txt","r", stdin);
    freopen("../output.txt","w", stdout);

    int n, l ,t;
    cin >> n >> l >> t;
    vector<string> m;
    queue<pii> q;
    uset<pii, PairHasher> u;
    for(int i=0;i<n;++i){
        string s;
        cin >> s;
        m.pb(s);
        for(int j=0;j<sz(s);++j){
            if(s[j] == 'E'){
                q.push(mk(i,j));
                u.insert(mk(i, j));
            }
        }
        // m.pb("");
        // for(int j=0;j<m;++j){
        //     string 
        // }
    }
    solve(m, t, q, u);
}

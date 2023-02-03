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



vi dfs(vector<vi> m, int turn){
    bool f = false;
    vi cur{imin,imin};
    // if(turn%2==0){
    //     cur = vi{imin, 0};
    // }else{
    //     cur = vi{0, imin};
    // }
    for(int i=0;i<sz(m);++i){
        for(int j=0;j<sz(m[i]);++j){
            pii p = mk(i, j);
            if(m[i][j] != 0) continue;
            vector<pii> dirs{mk(1,0),mk(-1,0),mk(0,1),mk(0,-1)};
            for(auto d:dirs){
                if(p.a+d.a >= 0 && p.a+d.a < sz(m) && p.a+2*d.a >= 0 && p.a+2*d.a < sz(m) && p.b+d.b < sz(m[p.a+d.a]) && p.b+d.b >= 0 && p.b+2*d.b < sz(m[p.a+d.a]) && p.b+2*d.b >= 0 && p.b+d.b < sz(m[p.a+2*d.a]) && p.b+d.b >= 0 && p.b+2*d.b < sz(m[p.a+2*d.a]) && p.b+2*d.b >= 0
                    && m[p.a+d.a][p.b+d.b] != 0 && m[p.a+2*d.a][p.b+2*d.b] != 0){
                    
                        // cout << p.a << " " << p.b << " " << d.a << " " << d.b << endl;
                    pii pos1, pos2, pos3;
                    pos1.a = p.a;
                    pos1.b = p.b;
                    pos2.a = p.a+d.a;
                    pos2.b = p.b+d.b;
                    pos3.a = p.a+2*d.a;
                    pos3.b = p.b+2*d.b;


                    // vi t = v;
                    // t[turn%2] += m[pos2.a][pos2.b]*m[pos3.a][pos3.b];

                    int inc = m[pos2.a][pos2.b]*m[pos3.a][pos3.b];
                    swap(m[pos1.a][pos1.b], m[pos3.a][pos3.b]);
                    int tmp = m[pos2.a][pos2.b];
                    m[pos2.a][pos2.b] = 0;
                    // cur[turn%2] += inc;
                    // cout << m[pos2.a][pos2.b] << " " << m[pos3.a][pos3.b] << endl;
                    vi res = dfs(m, turn+1);
                    // cur[turn%2] -= inc;
                    // cout << res.a << " " << res.b << endl;
                    // if(turn == 8){
                    //     cout << res[0]-res[1] << endl;
                    // }
                    if((inc-res[turn%2]) >= cur[turn%2]){
                        f = true;
                        cur = res;
                        cur[turn%2] = inc-cur[turn%2];
                        // cout << cur[turn%2]-cur[(turn+1)%2] << endl;
                    }
                    m[pos2.a][pos2.b] = tmp;
                    swap(m[pos1.a][pos1.b], m[pos3.a][pos3.b]);
            
                    // cur = max(cur, m[p.a+d.a][p.b+d.b]*m[p.a+2*d.a][p.b+2*d.b]);
                }
            }
        }
        
    }
    // if(!f){
    //     cout << cur[0] << " " << cur[1] << endl;
    //     ans = max(ans, cur[0]-cur[1]);
    // }
    // cout << turn << " " << cur[0] << " " << cur[1] << endl;
    // if(!f) return vi{0,0};
    // cout << cur[0] << " " << cur[1] << endl;

    
    for(int i=0;i<sz(m);++i){
        for(int j=0;j<sz(m[i]);++j){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << "cur " << cur[0]-cur[1] << " turn " << turn  << endl;
    return cur;
}


void solve(vector<vi> m, pii t){
    uset<pii, PairHasher> v;
    v.insert(t);
    vi scores{0,0};
    int turn = 0;
    while(true){
        int cur = 0;
        pii pos1, pos2, pos3;
        for(auto p:v){
            vector<pii> dirs{mk(1,0),mk(-1,0),mk(0,1),mk(0,-1)};
            for(auto d:dirs){
                if(p.a+d.a >= 0 && p.a+d.a < sz(m) && p.a+2*d.a >= 0 && p.a+2*d.a < sz(m) && p.b+d.b < sz(m[p.a+d.a]) && p.b+d.b >= 0 && p.b+2*d.b < sz(m[p.a+d.a]) && p.b+2*d.b >= 0 && p.b+d.b < sz(m[p.a+2*d.a]) && p.b+d.b >= 0 && p.b+2*d.b < sz(m[p.a+2*d.a]) && p.b+2*d.b >= 0){
                    // cout << p.a << " " << p.b << " " << d.a << " " << d.b << endl;
                    if(cur <= m[p.a+d.a][p.b+d.b]*m[p.a+2*d.a][p.b+2*d.b]){
                        cur = m[p.a+d.a][p.b+d.b]*m[p.a+2*d.a][p.b+2*d.b];
                        pos1.a = p.a;
                        pos1.b = p.b;
                        pos2.a = p.a+d.a;
                        pos2.b = p.b+d.b;
                        pos3.a = p.a+2*d.a;
                        pos3.b = p.b+2*d.b;
                    }
                    cur = max(cur, m[p.a+d.a][p.b+d.b]*m[p.a+2*d.a][p.b+2*d.b]);
                }
            }
        }
        if(cur == 0){
            break;
        }
        cout << "cur " << cur << " " << pos1.a << " " << pos1.b << endl;
        scores[turn%2] += cur;
        swap(m[pos1.a][pos1.b], m[pos3.a][pos3.b]);
        m[pos2.a][pos2.b] = 0;
        v.insert(pos2);
        v.insert(pos3);
        v.erase(pos1);
        ++turn;
    }
    cout << scores[0] << " " << scores[1] << endl;
}




int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases, remember to check bounds*/


    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif


    vector<vi> m;
    pii t;
    for(int i=0;i<5;++i){
        m.pb(vi());
        for(int j=0;j<=i;++j){
            int s;
            cin >> s;
            if(s == 0){
                t.a = i;
                t.b = j;
            }
            m[sz(m)-1].pb(s);
        }
    }

    // solve(m, t);
    int ans = imin;
    vi res = dfs(m, 0);
    cout << res[0]-res[1] << endl;

    return 0;
}
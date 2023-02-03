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


void solve(int s){
    cout << s << endl;
}

void dfs(umap<string, vector<pair<string, long double>>> m, string p, umap<string, long double>& m2, long double cur, uset<string> u){
    // cout << p << endl;
    for(auto n:m[p]){
        if(u.find(n.a) == u.end()){
            u.insert(n.a);
            m2[n.a] = n.b*cur;
            dfs(m, n.a, m2, n.b*cur, u);
        }
        
    }
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
    
    while(t != 0){
        cin.ignore();
        umap<string, vector<pair<string, long double>>> m;
        string s;
        getline(cin, s);
        uset<string> u;
        
        while(true){
            int space = s.find(' ');
            if(space == string::npos) break;
            string tmp = s.substr(0, space);
            m[tmp] = vector<pair<string, long double>>();
            s = s.substr(space+1, sz(s)-space);
            u.insert(tmp);
            
        }
        
        for(int i=0; i < t-1; ++i) { 
            string s1, s2, s3;
            long double num;
            cin >> s1;
            // cout << s1 << endl;
            // cin.ignore();
            cin >> s3;
            // cout << s3 << endl;
            cin >> num;
            cin >> s2;
            m[s1].pb(mk(s2, (long double)num));
            m[s2].pb(mk(s1, (long double)1/num));
            // cout << s1 << " " << s2 << endl;
            // cout << (long double)num << " and " << (long double)1/num << endl;
            u.erase(s2);
            // cout << s1 << " " << num << " " << s2 << endl;
        }
        long double largest = imax;
        string str;
        umap<string, long double> m2;
        for(auto p:u){
            // umap<string,  umap<string, long double>> m2;
            // cout << p << endl;
            m2[p] = 1;
            dfs(m, p, m2, 1, uset<string>{p});
            for(auto k:m2){
                // cout << k.a << " " << k.b << " " << largest << endl;
                if(k.b < largest){
                    largest = k.b;
                    str = k.a;
                }
                
            }
            break;
            // m3[p] = m2;
        }
        vector<pair<long double, string>> v;
        for(auto k:m2){
            m2[k.a] = m2[k.a]/largest;
            v.pb(mk(m2[k.a], k.a));
        }
        sort(v.begin(), v.end());



        // string largest;
        // for(auto p:m3){
        //     bool f = true;
        //     for(auto q:m3){
        //         if(p.a==q.a) continue;
        //         for(auto n:p.b){
        //             if(q.b.find(n.a) != q.b.end() && n.b < q.b[n.a]){
        //                 f = false;
        //                 break;
        //             }else if(q.b.find(n.a) != q.b.end() && n.b >= q.b[n.a]){
        //                 p.b[q.a] = n.b/q.b[n.a];
        //             }
        //         }
        //     }
        // }

        // vector<pair<int, string>> v;
        // for(auto k:m2){
        //     v.pb(mk(k.b, k.a));
        // }
        // sort(v.begin(), v.end());
        cout << "1" << str;
        for(int i=1;i<sz(v);++i){
            cout << fixed << setprecision(0) << " = " << v[i].a << v[i].b;
        }
        cout << endl;


        cin >> t;
    }


    

    return 0;
}
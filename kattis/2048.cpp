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


void solve(int t, vector<vi> v){
    // if(t==0){
    //     x = 1;
    //     y = 0;
    // }
    // if(t==1){
    //     x = 0;
    //     y = 1;
    // }
    // if(t==2){
    //     x = -1;
    //     y = 0;
    // }
    // if(t==3){
    //     x = 0;
    //     y = -1;
    // }
    vector<vi> m(4, vi(4,0));
    // if(t==0 || t==2){
    //     int i=0;
    //     while(i<4){
    //         int j=0;
    //         while(j<4){
    //             if(j+x >= 0 && j+x < 4 && v[i][j] == v[i][j+x]){
                    
    //             }
    //         }
    //         ++j;
    //         ++i;
    //     }
    // }
    if(t==0){
        int i=0;
        while(i<4){
            int j=0;
            int j1=0;
            while(j<4){
                while(j<4 && v[i][j] == 0){
                    ++j;
                }
                if(j >= 4){
                    break;
                }
                int j2 = j+1;
                while(j2<4 && v[i][j2] == 0){
                    ++j2;
                }
                if(j2 >= 0 && j2 < 4 &&  v[i][j] == v[i][j2]){
                    m[i][j1] = v[i][j]*2;
                    j=j2;
                }else{
                    m[i][j1] = v[i][j];
                }
                ++j;
                ++j1;
            }
            ++i;
        }
    }
    if(t==1){
        int j=0;
        while(j<4){
            int i=0;
            int i1=0;
            while(i<4){
                while(i<4 && v[i][j] == 0){
                    ++i;
                }
                if(i >= 4){
                    break;
                }
                int i2 = i+1;
                while(i2<4 && v[i2][j] == 0){
                    ++i2;
                }
                if(i2 >= 0 && i2 < 4 && v[i][j] == v[i2][j]){
                    m[i1][j] = v[i][j]*2;
                    i=i2;
                }else{
                    m[i1][j] = v[i][j];
                }
                ++i;
                ++i1;
            }
            ++j;
        }
    }
    if(t==2){
        int i=3;
        while(i>=0){
            int j=3;
            int j1=3;
            while(j>=0){
                while(j>=0 && v[i][j] == 0){
                    --j;
                }
                if(j < 0){
                    break;
                }
                int j2 = j-1;
                while(j2>=0 && v[i][j2] == 0){
                    --j2;
                }
                if(j2 >= 0 && j2 < 4 && v[i][j] == v[i][j2]){
                    m[i][j1] = v[i][j]*2;
                    j = j2;
                }else{
                    m[i][j1] = v[i][j];
                }
                --j;
                --j1;
            }
            --i;
        }
    }
    if(t==3){
        int j=3;
        while(j>=0){
            int i=3;
            int i1=3;
            while(i>=0){
                while(i>=0 && v[i][j] == 0){
                    --i;
                }
                if(i < 0){
                    break;
                }
                int i2 = i-1;
                while(i2>=0 && v[i2][j] == 0){
                    --i2;
                }
                // cout << i << " " << j << endl;
                if(i2 >= 0 && i2 < 4 && v[i][j] == v[i2][j]){
                    m[i1][j] = v[i][j]*2;
                    i=i2;
                }else{
                    m[i1][j] = v[i][j];
                }
                --i;
                --i1;
            }
            --j;
        }
    }
    // if(t==1){
    //     x = 0;
    //     y = 1;
    // }
    // if(t==2){
    //     x = -1;
    //     y = 0;
    // }
    // if(t==3){
    //     x = 0;
    //     y = -1;
    // }
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            cout << m[i][j] << " ";
        }
        cout << endl;
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

    vector<vi> v;
    for(int i=0;i<4;++i){
        v.pb(vi());
        for(int j=0;j<4;++j){
            int s;
            cin >> s;
            v[sz(v)-1].pb(s);
        }
    }
    cin >> t;
    solve(t, v);

    return 0;
}
#define imax INT_MAX
#define imin INT_MIN
#define sz(x) ((int)(x).size())
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define vi vector<int>


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

void solve(int n, int m)
{
    vi clus(m);
    vector<long long> left(m);
    vector<long long> right(m);
    umap<ll, int>left_map;
    umap<ll, int>right_map;

    for (int i =0 ; i < m; ++i){
        cin>>clus[i];
        left[i] = (i == 0)? clus[i] : left[i-1] + clus[i];
        left_map[left[i]] = i;
    }
    
    for (int i = m-1 ; i >= 0; --i ){
        right[i] = (i == m-1)? clus[i]: right[i + 1] + clus[i];
        right_map[right[i]] = i;
    }
    
    for (int i =0 ; i <n; ++i){
        int q;
        cin>>q;
        if(q == 0){
            cout << "Yes" << endl; 
        }else
        if (left_map.find(q) != left_map.end() || right_map.find(q) != right_map.end()){
            cout<<"Yes"<<endl;
        }else{
            bool found = false;
            for (auto el : left_map){
                ll diff = q - el.a;
                auto f = right_map.find(diff);
                if (f != right_map.end()){
                    if (el.b < right_map[diff]){
                        cout<<"Yes"<<endl;
                        found = true;
                        break;
                    }
                }
            }
            if (!found){
                cout<<"No"<<endl;
            }
        }
    }
    
    
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int n;
    unsigned int m;

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    cin>>m>>n;
    solve(n,m);
    return 0;
}
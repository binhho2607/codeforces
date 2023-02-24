//#pragma comment(linker, "/STACK:512000000")
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

void solve(int s){
    cout <<s<<endl;
}

char rot(char c){
    if(c == 'A') return 'B';
    if(c == 'B') return 'C';
    if(c == 'C') return 'D';
    if(c == 'D') return 'E';
    if(c == 'E') return 'F';
    if(c == 'F') return 'A';
}

int dp(string cur, umap<string, int>& memo, string target, uset<string>& visited, int stack){
    cout << cur << " " << stack << endl;
    if(cur == target) return 0;
    if(memo.find(cur) != memo.end()) return memo[cur];
    int m = imax/2;
    for(int i=0;i<8;++i){
        string tmp = cur;
        cout << cur[i] << " " << i << endl;
        switch(cur[i]){
            case 'A':
                if(i > 0) cur[i-1] = rot(cur[i-1]);
                if(i < 7) cur[i+1] = rot(cur[i+1]);
                break;
            case 'B':
                if(1 <= i && i <= 6) cur[i+1] = cur[i-1];
                break;
            case 'C':
                cout << "error" << endl;
                cur[7-i] = rot(cur[7-i]);
                break;
            case 'D':
                if(1 <= i && i < 4){
//                    cout << "error" << endl;
                    for(int j =0;j<4;++j){
                        cur[j] = rot(cur[j]);
                    }
                }else if(4 <= i && i <= 7){
                    for(int j=4;j<8;++j){
                        cur[j] = rot(cur[j]);
                    }
                }
                break;
            case 'E':

                if(1 <= i && i < 4){
                    int y = i;
                    cur[i-y] = rot(cur[i-y]);
                    cur[i+y] = rot(cur[i+y]);
                }else if(4 <= i && i < 7){
//                    cout << "here" << endl;
                    int y = 7-i;
                    cur[i-y] = rot(cur[i-y]);
                    cur[i+y] = rot(cur[i+y]);
                }

                break;
            case 'F':
                if(i%2 == 0) cur[(i+10)/2-1] = rot(cur[(i+10)/2-1]);
                else cur[(i+1)/2-1] = rot(cur[(i+1)/2-1]);
                break;
        }
//        cout << "finished" << endl;
        if(tmp != cur && visited.find(cur) == visited.end()){
//            cout << "next " << cur << endl;
            visited.insert(cur);
            m = min(m, 1+dp(cur, memo, target, visited,stack+1));
//            visited.erase(cur);
        }
        cur = tmp;
    }
    memo[cur] = m;
    return m;
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

    string start;
    string target;
    cin >> start >> target;
    umap<string, int> memo;
    uset<string> visited;
    int ans = dp(start, memo, target, visited, 0);
    cout << ans << endl;
    return 0;

}

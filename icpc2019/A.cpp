#define imax INT_MAX
#define imin INT_MIN
#define sz(x) (int((x).size()))
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
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

char AND(char & a, char & b){
    if (a == 'T' && b == 'T'){
        return 'T';
    }
    return 'F';
}

char OR(char &a, char &b){
    if (a == 'T' || b == 'T'){
        return 'T';
    }
    return 'F';
}

char NOT(char & a){
    if (a == 'T'){
        return 'F';
    }
    return 'T';
}


void solve(unordered_map<char, char>& bools, vector<char> & ops){
    stack<char> tree;

    for (int i = 0; i < ops.size(); ++ i){
        char current  = ops[i];
        if (current == '+'){
            char op1 = tree.top();
            tree.pop();
            char op2 = tree.top();
            tree.pop();
            char res = OR(op1, op2);
            tree.push(res);
        }
        else if (current == '*'){
            char op1 = tree.top();
            tree.pop();
            char op2 = tree.top();
            tree.pop();
            char res = AND(op1, op2);
            tree.push(res);
        }
        else if (current == '-'){
            char op1 = tree.top();
            tree.pop();
            char res = NOT(op1);
            tree.push(res);
        }
        else{
            tree.push(bools[current]);
        }
    }

    cout << tree.top() ;

    return;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt","r",stdin);
        freopen("../output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    unordered_map<char, char> bools;
    for(int i=0;i<t;++i){
        char b ;
        cin >> b;
        bools[char('A' + i)] = b;
    }
    string s;
    // cin >> s;
    string s1;
    cin >> s1;
    getline(cin, s);
    s = s1+s;
    // cout << s << endl;
    vector<char> symbols;
    for(auto c:s){
        if(c == ' ') continue;
        symbols.pb(c);
    }
    // for(auto c:symbols){
    //     cout << c << endl;
    // }
    solve(bools, symbols);
    return 0;
}
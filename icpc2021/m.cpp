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

void printWinner(int w){
    if (w == 1){
        cout<<"X wins"<<endl;
    }else{
        cout<<"O Wins"<<endl;
    }
}


void solve(unsigned int state)
{
    vi board(9, 0);
    bool full = true;
    queue<int>spots;
    for (int i = 0; i < 9; ++i){
        int played = state & 1;
        // cout<<played<<endl;
        if (!played){
            board[i] = -1;
            full = false;
        }
        state >>= 1;
    }
    for (int i =0 ; i < 9 && state > 0; ++i){
        int player = state & 1;
        if (board[i] != -1){
            board[i] = player;
        }
        state >>= 1;
    }
    // for (auto i : board){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    int winner = -1;
    // validate winner
    for (int i = 0; i < 3; ++i){
        if (board[i] == board[i + 3] && board[i + 3] == board[i + 6]){
            printWinner(board[i]);
            return;
        }
    }
    // cout<<"here"<<endl;
    for (int i = 0; i < 9; i += 3){
        if (board[i] == board[i + 1] && board[i + 1] == board[i + 2]){
            printWinner(board[i]);
            return;
        }
    }
    if (board[0] == board[4] && board[4] == board[8]){
        printWinner(board[0]);
    }
    if (board[2] == board[4] && board[4] == board[6]){
        printWinner(board[2]);
    }
    if (full){
        cout<<"Cat's"<<endl;
    }else{
        cout<<"In progress"<<endl;
    }

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int t;
    unsigned int n;


    cin>>t;
    for (int i = 0; i < t; ++i){
        cin>>n;
        solve(n);
    }
}
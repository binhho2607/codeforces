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
int N, M;
bool checkBound(int nr, int nc)
{
    return (nr >= 0 && nr < N && nc >= 0 && nc < M);
}
vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int BFS(vector<vector<char>> &maze, vector<vector<bool>> &visited, pii start)
{
    queue<pii> agenda;
    int counter = 0;
    agenda.push(start);
    visited[start.a][start.b] = true;
    while (!agenda.empty())
    {
        auto top = agenda.front();
        agenda.pop();
        for (auto dir : directions)
        {
            int nc = top.a + dir[0];
            int nr = top.b + dir[1];
            if (checkBound(nc, nr) && maze[nc][nr] != '.' && !visited[nc][nr])
            {
                visited[nc][nr] = true;
                counter++;
                agenda.push(mk(nc, nr));
            }
        }
    }
    return counter;
}

void solve(int n, int m)
{
    vector<vector<char>> maze(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pii> entrance;
    N = n;
    M = m;
    int dots = 0;
    for (int i = 0; i < n; ++i)
    {
        string row;
        cin >> row;
        for (int j = 0; i < m; ++j)
        {
            maze[i][j] = row[j];
            if (row[j] == '.')
            {
                dots++;
            }
            if (maze[i][j] != 'X' && maze[i][j] != '.')
            {
                entrance.push(mk(i, j));
            }
        }
    }
    int nums = 0;
    while (!entrance.empty())
    {
        int found = BFS(maze, visited, entrance.front());
        entrance.pop();
        if (found != 0)
        {
            nums++;
            dots -= found;
        }
    }
    cout << nums << " " << dots << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    solve(n, m);
}

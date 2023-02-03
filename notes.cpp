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
#define all(x) (x).begin(), (x).end()
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


int binarySearch(vi nums, int k){
    int left=0;
    int right=sz(nums)-1;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(nums[mid]==k) return mid;
        if(nums[mid]>k){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    // right = largest number smaller than k
    // left - smallest number larger than k
    return -1;
}



// pick as much object as possible
// while stay under constraint
int greedy(vi m, int c){
    int ans = 0;
    sort(m.begin(),m.end());
    for(int i=0;i<sz(m);++i){
        if(c-m[i]<0) break;
        c -= m[i];
        ans += 1;
    }
    return ans;
}

bool canJump(vi nums){
    int cap=nums[0];
    for(int i=1;i<sz(nums);++i){
        if(i>cap) return false;
        cap=max(cap,i+nums[i]);
    }
    return true;
}


int minJump(vi nums){
    int cf=0; //cur furthest
    int f=0; //furthest
    int ans=0; //jump count
    for(int i=0;i<sz(nums)-1;++i){
        if(cf<i) return -1;
        cf=max(cf,nums[i]+i);
        if(i==f){
            f=cf;
            ++ans;
        }
    }
    if(cf<sz(nums)-1) return -1;
    return ans;
}

vector<pii> schedule(vector<pii> v){
    for(int i=0;i<sz(v);++i){
        swap(v[i].a, v[i].b);
    }
    sort(v.begin(),v.end());
    vector<pii> ans;
    int cur=0; // allow edge overlap
    for(int i=0;i<sz(v);++i){
        if(v[i].b>=cur){
            ans.pb(mk(v[i].b,v[i].a));
            cur=v[i].a;
        }
    }
    return ans;
}




struct MinHeapNode{
    char data;
    int freq;

    MinHeapNode *left,*right;

    MinHeapNode(char data,int freq){
        left=right=NULL;
        this->data=data;
        this->freq=freq;
    }
};
struct compare{
    bool operator()(MinHeapNode *l,MinHeapNode *r)
    {
        return (l->freq>r->freq);
    }
};
MinHeapNode* HuffmanCodes(char data[],int freq[],int size){
    struct MinHeapNode *left,*right,*top;
    priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> minheap;
    for(int i=0;i<size;i++){ // leaf nodes for each character
        minheap.push(new MinHeapNode(data[i],freq[i]));
    }
    while(minheap.size()!=1){
        left = minheap.top(); //Extract two nodes from the heap.
        minheap.pop();
        right = minheap.top();
        minheap.pop();
        // make new node
        MinHeapNode* tmp = new MinHeapNode('$',left->freq+right->freq);
        tmp->left = left;
        tmp->right = right;

        minheap.push(tmp);
    }
    return minheap.top();
}


int kadane(vi nums){
    int cur=0;
    int profit=0;
    for(int i=0;i<sz(nums);++i){
        cur += nums[i];
        profit=max(profit,cur);
        if(cur<0) cur=0;
    }
}



vector<pii> insert(vector<pii> v,pii p){
    if(sz(v)==0) return {p};
    sort(v.begin(),v.end());
    vector<pii> res;
    int s = p.a;
    int e = p.b;
    int i=0;
    while(i<sz(v) && v[i].b<s){
        res.pb(v[i]);
        ++i;
    }
    while(i<sz(v) && v[i].a<=e && s<=v[i].b){
        s=min(s,v[i].a);
        e=max(e,v[i].b);
        ++i;
    }
    res.pb(mk(s,e));
    while(i<sz(v)) res.pb(v[i++]);
    return res;
}

vector<pii> merge(vector<pii> v){
    sort(v.begin(),v.end());
    vector<pii> res;
    int i=0;
    while(i<sz(v)){
        // edge collision not allowed
        if(sz(res)==0 || res.back().b<v[i].a){
            res.pb(v[i]);
        }else{
            res[sz(res)-1].b=max(res[sz(res)-1].b,v[i].b);
        }
        ++i;
    }
    return res;
}


int cover(vector<pii> v,pii p){
    sort(v.begin(), v.end());
    v.pb({imax,imax});
    int s = p.a;
    int e = p.a-1;
    int cnt = 0;
    for (int i=0;i<sz(v);) {
        if (v[i].a <= s) {
            e = max(v[i++].b, e);
        }
        else {
            s = e;
            ++cnt;
            if (v[i].a > e || e >= p.b) {
                break;
            }
        }
    }
    if (e < p.b) return -1;
    return cnt;
}


int maxProfit(vi nums){
    int cur=imax;
    int ans=0;
    for(int i=0;i<sz(nums);++i){
        ans=max(nums[i]-cur,ans);
        cur=min(cur,nums[i]);
    }
    return ans;
}

int lengthOfLongestSubstring(string s) {
    int left = 0;
    int right = 0;
    int res = 0;
    vi count(256, 0);
    while (right<sz(s)) {
        ++count[s[right]];
        while(count[s[right]]>1){
            --count[s[left]];
            ++left;
        }
        res = max(res, right-left+1);
        ++right;
    }
    return res;
}

int longestRepeatWithReplacement(string s,int k){
    int left,right;
    left = right = 0;
    int res=0;
    int m=0;
    vi count(256,0);
    while(right<sz(s)){
        ++count[s[right]];
        m=max(count[s[right]],m);
        while(right-left+1-m>k){
            --count[s[left]];
            ++left;
        }
        res=max(res,right-left+1);
        ++right;
    }
}


bool isValid(string s) {
    int n = s.size();
    if (n % 2 == 1) return false; 
    stack<char> stk;
    for (int i = 0; i < n; ++i) {
        if (stk.empty()) {
            stk.push(s[i]);
        } else if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stk.push(s[i]);
        } else if (s[i] == ')') {
            if (stk.top() == '(') {
                stk.pop();
            } else return false;
        }  else if (s[i] == ']') {
            if (stk.top() == '[') {
                stk.pop();
            } else return false;
        }  else if (s[i] == '}') {
            if (stk.top() == '{') {
                stk.pop();
            } else return false;
        }
    }
    if (!stk.empty()) return false;
    return true;
}


void dfs(umap<string,vector<pair<string, int>>> adj, string cur, 
                        uset<string> grey, uset<string> black){
    // do something with current vertex (already added to u)
    for(auto n:adj[cur]){
        if(grey.find(n.a)==grey.end() && black.find(n.a)==black.end()){
            grey.insert(n.a);
            // n.b is the edge weight
            dfs(adj, n.a, grey, black);
        }else if(black.find(n.a)!=black.end()){
            // cross-edge between 2 components
        }else if(grey.find(n.a)!=grey.end()){
            // backedge (cycle)
        }
    }
    black.insert(cur);
}

void backtrack(umap<string,vector<pair<string, int>>> adj, string cur, 
                        uset<string> visited){
    // do something with current vertex (already added to visited)
    for(auto n:adj[cur]){
        if(visited.find(n.a)==visited.end()){
            visited.insert(n.a);
            // n.b is the edge weight
            backtrack(adj, n.a, visited);
            visited.erase(n.a); // backtrack
        }else if(visited.find(n.a)!=visited.end()){
            // backedge
        }
    }
}

void bfs(umap<string,vector<pair<string, int>>> adj, string start){
    uset<string> visited;
    visited.insert(start);
    queue<pair<string, int>> q;
    q.push(mk(start, 0));
    while(sz(q)>0){
        pair<string, int> p=q.front();
        q.pop();
        // do something with the vertex and weight
        for(auto n:adj[p.a]){
            if(visited.find(n.a)==visited.end()){
                visited.insert(n.a);
                q.push(n);
            }else{
                // backedge
            }
        }
    }
}

void epochBfs(umap<string,vector<pair<string, int>>> adj, vector<pair<string, int>> start){
    uset<string> visited;
    queue<pair<string, int>> q;
    for(auto s:start){
        visited.insert(s.a);
        q.push(s);
    }
    while(sz(q)>0){
        int k=sz(q);
        while(k>0){
            pair<string, int> p=q.front();
            q.pop();
            // do something with the vertex and weight
            for(auto n:adj[p.a]){
                if(visited.find(n.a)==visited.end()){
                    visited.insert(n.a);
                    q.push(n);
                }else{
                    // backedge
                }
            }
            --k;
        }
        // finish 1 epoch
    }
}


struct Node {
    int val;
    Node* left;
    Node* right;
};

void preorder(Node* root){
    if(root==nullptr) return;
    // do something with root
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==nullptr) return;
    inorder(root->left);
    // do something with root
    inorder(root->right);
}

void postorder(Node* root){
    if(root==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    // do something with root  
}

// d=0 initially
int diameter(Node* root, int& d){
    if(!root) return 0;
    int left = diameter(root->left,d);
    int right = diameter(root->right,d);
    d = max(d,left+right);
    return 1+max(left,right);
}

int height(Node* root){
    if(!root) return 0;
    int left = height(root->left);
    int right = height(root->right);
    // 1+max(left,right) is current height
    return 1+max(left,right);
}

int subNodes(Node* root){
    if(!root) return 0;
    int left = height(root->left);
    int right = height(root->right);
    // 1+left+right is node count
    // of current subtree (including root)
    return 1+left+right;
}

// if return nullptr --> not found
Node* searchBST(Node* root, int target){
    if(!root) return nullptr;
    if(root->val==target) return root;
    if(root->val > target) 
        return searchBST(root->left, target);
    else
        return searchBST(root->right, target);
        
}

// min = imin, max = imax initially
bool validBST(Node* root, int min, int max){
    if(!root) return true;
                              if(root->val >= max || root->val <= min){
        return false;
    }
    return validBST(root->left, min, root->val)
        && validBST(root->right, root->val, max);
}


Node* lowestCommonAncestor(Node* root, Node* p, Node* q){
    if(!root) return nullptr;
    if(root==p || root==q) return root;
    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);
    return (left&&right) ? root : ((left) ? left : right);
}

void kosarajuDFS(umap<string, vector<string>> adj, string cur,
                uset<string>& grey, uset<string>& black, stack<string>& st){
    for(auto n:adj[cur]){
        if(grey.find(n)==grey.end() && black.find(n)==black.end()){
            grey.insert(n);
            kosarajuDFS(adj, n, grey, black, st);
        }
    }
    black.insert(cur);
    st.push(cur);
}
void kosaraju(umap<string, vector<string>> adj,
                umap<string, vector<string>> transpose){
    uset<string> black;
    stack<string> st;
    for(auto p:adj){
        if(black.find(p.a)==black.end()){
            uset<string> grey{p.a};
            kosarajuDFS(adj, p.a, grey, black, st);
        }
    }
    stack<string> ignore; // don't really do anything
    black = uset<string>();
    while(sz(st)>0){
        string cur = st.top();
        st.pop();
        if(black.find(cur)==black.end()){
            uset<string> grey{cur};
            kosarajuDFS(transpose, cur, grey, black, ignore);
            // found 1 connected component
        }
    }
}

string find(string n, umap<string, string>& parent){
    string p = parent[n];
    while(p!=parent[p]){
        parent[p]=parent[parent[p]];
        p=parent[p];
    }
    return p;
}

bool unionf(string n1, string n2,
            umap<string, string>& parent, 
            umap<string, int>& rank){
    string p1 = find(n1, parent);
    string p2 = find(n2, parent);
    if(p1==p2) return false; // false = cycle
    if(rank[p1] >= rank[p2]){
        rank[p1] += rank[p2];
        parent[p2] = p1;
    }else{
        rank[p2] += rank[p1];
        parent[p1] = p2;
    }
    return true;
}


vector<pair<int, pair<string, string>>> kruskal(vector<string> v, 
                    vector<pair<int, pair<string, string>>> edges){
    umap<string, string> parent;
    umap<string, int> rank;
    for(auto n:v){
        parent[n] = n;
        rank[n] = 1;
    }
    sort(edges.begin(), edges.end());
    vector<pair<int, pair<string, string>>> ans;
    for(auto e:edges){ // take smallest edge first
        if(unionf(e.b.a, e.b.b, parent, rank)){
            ans.pb(e); // take it if it don't make a cycle
        }
        if(sz(ans)==sz(v)-1) break;
    }
    return ans;
}

umap<string, vector<string>> unionFind(vector<string> v, 
                    vector<pair<string, string>> edges){
    umap<string, string> parent;
    umap<string, int> rank;
    for(auto n:v){
        parent[n] = n;
        rank[n] = 1;
    }
    for(auto e:edges){
        unionf(e.a, e.b, parent, rank);
    }
    umap<string, vector<string>> ans;
    for(auto p:parent){
        string q = find(p.a, parent);
        if(ans.find(q)==ans.end()){
            ans[q] = vector<string>();
        }
        ans[q].pb(p.a);
    }
    return ans;
}





void hierholzer(umap<string,vector<string>> adj){
    unordered_map<string,int> edge_count;
    string start;
    for(auto p:adj){
        start = p.a;
        edge_count[p.a] = sz(p.b);
    }
    if (!adj.size()) return; //empty graph
    stack<string> curr_path;
    vector<string> circuit;
    curr_path.push(start);
    string curr_v = start;
    while (!curr_path.empty()){
        if (edge_count[curr_v]){
            curr_path.push(curr_v);
            string next_v = adj[curr_v].back();
            edge_count[curr_v]--;
            adj[curr_v].pop_back();
            curr_v = next_v;
        }else{
            circuit.push_back(curr_v);
            curr_v = curr_path.top();
            curr_path.pop();
        }
    }
    // we've got the circuit, now print it in reverse
    for (int i=circuit.size()-1; i>=0; i--){
        cout << circuit[i];
        if (i)
           cout<<" -> ";
    }
}







int preced(char ch) {
   if(ch == '+' || ch == '-') {
      return 1;              //Precedence of + or - is 1
   }else if(ch == '*' || ch == '/') {
      return 2;            //Precedence of * or / is 2
   }else if(ch == '^') {
      return 3;            //Precedence of ^ is 3
   }else {
      return 0;
   }
}
string inToPost(string infix ) {
   stack<char> stk;
   stk.push('#');               //add some extra character to avoid underflow
   string postfix = "";         //initially the postfix string is empty
   string::iterator it;
   for(it = infix.begin(); it!=infix.end(); it++) {
      if(isalnum(char(*it)))
         postfix += *it;      //add to postfix when character is letter or number
      else if(*it == '(')
         stk.push('(');
      else if(*it == '^')
         stk.push('^');
      else if(*it == ')') {
         while(stk.top() != '#' && stk.top() != '(') {
            postfix += stk.top(); //store and pop until ( has found
            stk.pop();
         }
         stk.pop();          //remove the '(' from stack
      }else {
         if(preced(*it) > preced(stk.top()))
            stk.push(*it); //push if precedence is high
         else {
            while(stk.top() != '#' && preced(*it) <= preced(stk.top())) {
               postfix += stk.top(); 
               stk.pop();
            }
            stk.push(*it);
         }
      }
   }
   while(stk.top() != '#') {
      postfix += stk.top();        //store and pop until stack is not empty.
      stk.pop();
   }
   return postfix;
}






// Function that returns value of
// expression after evaluation.
int evaluate(string tokens){
    int i;
    stack <int> values;
    stack <char> ops;
    for(i = 0; i < tokens.length(); i++){
        if(tokens[i] == ' ') continue;
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        } else if(isdigit(tokens[i])){
            int val = 0;
            while(i < tokens.length() &&
                        isdigit(tokens[i])){
                val = (val*10) + (tokens[i]-'0');
                i++;
            } 
            values.push(val);
            i--;
        } else if(tokens[i] == ')') {
            while(!ops.empty() && ops.top() != '(') {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                // apply op = + - * /
                values.push(applyOp(val1, val2, op));
            }
            if(!ops.empty()) ops.pop();
        } else {
            while(!ops.empty() && precedence(ops.top())
                                >= precedence(tokens[i])){
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                // apply op = + - * /
                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
    }
    while(!ops.empty()){
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop(); // apply op = + - * /
        values.push(applyOp(val1, val2, op));
    }
    return values.top();
}


int evaluatePostfix(string s) {
    stack<int> st;
    for (int i=0;i<sz(s);++i) {
        if (isdigit(s[i])) st.push(s[i]-'0');
        else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch (s[i]) { 
            case '+': st.push(val1+val2); break;
            case '-': st.push(val1-val2); break;
            case '*': st.push(val1*val2); break;
            //watch out for val2 == 0 
            case '/': st.push(val1/val2); break;
            }
        }
    }
    return st.top();
}


vi nextHigher(vi nums){
    vi res(sz(nums),-1);
    stack<pii> st;
    for(int i=0;i<sz(nums);++i){
        while(sz(st)>0 && st.top().a<nums[i]){
            pii p = st.top();
            st.pop();
            res[p.b]=i;
        }
        st.push(mk(nums[i],i));
    }
}

int carfleet(int t,vi pos, vi sp){
    umap<int,int> m;
    for(int i=0;i<sz(pos);++i){
        m[pos[i]] = sp[i];
    }
    stack<int> st;
    int ans=0;
    sort(pos.begin(),pos.end());
    for(auto p:pos){
        // watch out for floats
        while(sz(st)>0 && m[st.top()]!=m[p] 
                && p<=(p-st.top()/(m[st.top()]-m[p])*m[p]+p<=t)){
            st.pop();
        }
        st.push(p);
    }
    return sz(st);
}





int longestCommonSub(string s1, string s2){
    vector<vi> memo(sz(s1)+1, vi(sz(s2),0));
    for(int i=0;i<sz(s1);++i){
        for(int j=0;j<sz(s2);++j){
            if(s1[i]==s2[j]){
                memo[i+1][j+1]=1+memo[i][j];
            }else{
                memo[i+1][j+1]=max(memo[i][j+1],memo[i+1][j]);
            }
        }
    }
    return memo[sz(s1)][sz(s2)];
}


// m = vector of objects
// x is usually current object index
// y is usually price/weight of some sort
int dp(int x, int y, vi m, umap<vi, int, VectorHasher> memo){
    // last object, base case, valid
    if(x == sz(m)){ 
        return 0;
    
    // invalid combination
    if(true){
        return imax;
    }
    if(memo.find(vi{x,y}) != memo.end()){
        return memo[vi{x,y}];
    }
    int cmin = imax;
    // form combination with the remainining objects
    for(int i=x;i<sz(m);++i){
        // Bellman-Ford equation
        cmin = min(cmin, dp(i,y+m[x],m,memo));
    }
    // save to memo
    memo.emplace(vi{x,y}, cmin);
    return cmin;
}


int rob(vi nums) {
    if (sz(nums) > 1){ // base case
        nums[1] = max(nums[1], nums[0]);
    }
    for (int i=2;i<sz(nums);++i){
        // Bellman-Ford equation (choose one or the other)
        nums[i] = max(nums[i-2] + nums[i], nums[i-1]);
    }
    return nums[sz(nums)-1];
}

int coinChange(vi nums, int k){
    vi dp(k+1,imax);
    dp[0] = 0;
    for(int i=0;i<sz(dp);++i){
        for(int j=0;j<sz(c);++j){
            if(c[j]<=i){
                dp[i]=min(dp[i],dp[i-c]+1)
            }
        }
    }
    if(dp.back()==imax){
        return -1;
    }
    return dp.back(); 
}


void rotateMatrix(vector<vi> m){
    vector<vi> m2(sz(m[0]), vi(sz(m),0));
    for(int i=0;i<sz(m);++i){ // reflect across diagonal
        for(int j=0;j<sz(m[i]);++j){
            m2[j][i] = m[i][j];
        }
    }
    for(int i=0;i<sz(m2);++i){ // reverse each row
        reverse(m2[i].begin(), m2[i].end());
    }
}

void spiral(vector<vi> m){
    int u = 0; // up
    int l = 0; // left
    int r = sz(m[0])-1; // right
    int d = sz(m)-1; // down
    int c = 0; // count
    int cell;
    while (c < sz(m)*sz(m[0])) {
        for(int i=l;i<r+1;++i){ // left to right
            cell = m[u][i]; // visit cell
            c += 1;
        }
        for(int i=u+1;i<d+1;++i){ // downwards
            cell = m[i][r]; // visit cell
            c += 1;
        }
        if (u!=d){ // make sure we are on a different row than left to right
            for(int i=r-1;i>l-1;--i){ // right to left
                cell = m[d][i]; // visit cell
                c += 1;
            }
        }
        if (l!=r){ // make sure we are on a different col than upwards
            for(int i=d-1;i>u;--i){ // upwards
                cell = m[i][l]; // visit cell
                c += 1;
            }
        }
        l+=1;
        r-=1;
        u+=1;
        d-=1;
    }
}




void solve(int s){
    cout << s << endl;
}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* number of test cases */
    unsigned short int t;
    unsigned short int n;

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    cin >> t;

    for(int i=0; i < t; ++i) { //loops for each case
        cin >> n; // number of elements in vector
        vector<int> nums;
        for (int j=0; j < n; ++j) { // each element of vector
            int s;
            cin >> s;
            nums.push_back(s);
        }
    }

    return 0;
}
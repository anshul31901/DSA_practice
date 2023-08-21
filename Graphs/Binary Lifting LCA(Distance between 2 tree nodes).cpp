
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 100005
#define ll long long int
#define vi vector<int>
#define pb push_back
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>
#define endl '\n'
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a;i<=b;i++)

//adjacency list
vvi ar(1001);

//our list has 1000 nodes so maxN can have logn ie 10 nodes at max i.e. for each node we can save maxN parents
//where LCA[i][j]= 2^jth parent of node i

const int maxN=10;//maxN = log2(N);
//this stores the depth level of each node
vi level(1001);
//this stores LCA for every node and its size is O(NlogN)
int LCA[1001][maxN+1];


//readable and understandable code :- we run dfs so store first parent for every node i.e. LCA[i][0]
// and also to store level we run dfs
void dfs(int node,int lvl,int parent){
    level[node]=lvl;
    LCA[node][0]=parent;
    for(auto child :ar[node]){
        if(child!=parent){
            dfs(child,lvl+1,node);
        }
    }
}
//init stands for initialization and at first we run dfs to store first parent and levels for each node
void init(int n){
    dfs(1,0,-1);
//we run tabulation to calculate whole LCA table 2^n=2*2^(n-1)
//what i meant by that is for example we have to calculate 2^3=8th parent of node i
    //to do this we will calculate a intermediate parent that is 2^(2)th i.e. 4th parent of i let it be j
    //then we will again calculate 2^2nd parent of j that will be our ans i.e. 8th parent of i

    //if 4th(2^2th) parent of i doesn't exist then its clear that 8th(2^3rd) parent will also not exist
    for(int i=1;i<=maxN;i++)
        for(int j=1;j<=n;j++)
        {
            if(LCA[j][i-1]!=-1){
                int par = LCA[j][i-1];
                LCA[j][i]=LCA[par][i-1];
            }
        }
}

int getLCA(int a,int b){
//we assume that b is always lower tham a
    if(level[b]<level[a])swap(a,b);

    int d=level[b]-level[a];
//it can be thought as representation of d in binary

    while(d>0){
        int i = log2(d);
        b=LCA[b][i];
        d-= 1<<i;
    }
    if(a==b)return a;
//
    for(int i = maxN;i>=0;i--){
        if(LCA[a][i]!=-1 && (LCA[a][i]!=LCA[b][i])){
            a= LCA[a][i],b=LCA[b][i];
        }
    }
    return LCA[a][0];
}

int getDist(int a,int b){
    int lca = getLCA(a,b);
    return level[a]+level[b]-2*level[lca];
}
int main(){

  int n,a,b,q;

  cin>>n;
//initialization of LCA
  for(int i=1;i<=n;i++){
    for(int j=0;j<=maxN;j++)
        LCA[i][j]=-1;
  }
  for(int i=0;i<n-1;i++){
    cin>>a>>b,ar[a].pb(b),ar[b].pb(a);
  }
//initialize the LCA array
  init(n);

  cin>>q;
  while(q--){
    cin>>a>>b;
    cout<<getDist(a,b)<<endl;
  }

}

https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/
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

//stores the parent of ith member
int parent[100005];
//size array:stores the size of groups under the ith parent
int sz[100005];


//DSU function make 
void make(int v){
    parent[v]=v;
    sz[v]=1;
}

//DSU function find
int find(int v){
    if( parent[v]==v)return v;
    return parent[v]=find(parent[v]);
}

//DSU function union
void un( int v,int  u){
    int a = find(u);
    int b = find(v);
    if(a!=b){
        if(sz[b]>sz[a]){swap(a,b);}

        parent[b]=a;
        sz[a]+=sz[b];
    }
    //return a;
}

int main(){
  memset(parent,-1,sizeof(parent));
  memset(sz,-1,sizeof(sz));
  int n,m,a,b,w;
  //total weight of MST
  ll sum=0;
  cin>>n>>m;
  //edges<wt<a,b>>
  vector<pair<int,ii>>edges;
  while(m--){
    cin>>a>>b>>w;
    edges.pb({w,{a,b}});
 
  }
//sort edges by weight in ascending order
  sort(edges.begin(),edges.end());
//take the smallest edge and if a and b belong to different cc/group union them (in other words we take the edge)and sum+=wt
//if both a and b already are connected skip this edge
  for(auto e:edges){
    int a = e.second.first;
    int b = e.second.second;
    int wt= e.first;
    if(parent[a]==-1)make(a);
    if(parent[b]==-1)make(b);

    if(find(a)!=find(b)){
        sum+=wt;
        un(a,b);
    }
    else continue;
  }


  cout<<sum<<endl;

}
//in leetcode format make a seperate dsu class

https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/
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


int parent[100005];
int sz[100005];

void make(int v){
    parent[v]=v;
    sz[v]=1;
}
int find(int v){
    if( parent[v]==v)return v;
    return parent[v]=find(parent[v]);
}
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
  int n,k,a,b;
  cin>>n>>k;
  for(int i=1;i<=n;i++)make(i);
  while(k--){
	cin>>a>>b;
	un(a,b);
  }
  int ct=0;
  for(int i=1;i<=n;i++){
	if(find(i)==i)ct++;
  }
  cout<<ct<<endl;

}

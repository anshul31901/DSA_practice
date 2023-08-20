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
//makes a node/member
void make(int v){
    parent[v]=v;
    sz[v]=1;
}
//returns the ancestor of the node /member
//it is optimised by path compression that means when we call the find function for a member all the childrens for the final parent 
//directly point to the parent . dependence is not hierarchial but the inheritence that is in more than one steps is reduced to one step
//e.g. a->b->c->d ,b->e->f after find(d) will be:--  a->b->e->f,a->c,a->d
int find(int v){
    if( parent[v]==v)return v;
    return parent[v]=find(parent[v]);
}


//un stands for union. i have named this function un instead of union because union is a keyword in C++.
//it merges two groups/cc and it is prioritised by size. The smaller groups parent points to the larger groups parent
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

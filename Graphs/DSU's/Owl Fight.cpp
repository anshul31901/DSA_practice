https://assessment.hackerearth.com/challenges/college/codemania-20/algorithm/owl-fight/
//just alter the union function to make the greater parent  the resultant parent of the join
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

const int MOD = 1e9+7;
vector<int>parent(1e5+1);
// vector<int>siz(1e5+1);

int find(int node){
	//3->2->1
	if(parent[node]==node)return node;
	else return parent[node]= find(parent[node]);
}

void union_(int a ,int b ){
//join b to a
	a = find(a);
	b = find(b);
	if(b>a)swap(a,b);

	if(a!=b){
		parent[b]=a;
	}

}

//         1 2 3 4 5
// size.   3 1 1 2 1
// parent. 1 1 1 4 4






int main(){

	int n,m;
	cin>>n>>m;
	for(int i =1;i<=n;i++){

		parent[i]=i;
	}

	while(m--){
		int a,b;
		cin>>a>>b;
		union_(a,b);
	}

	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;

		int a = find(x);
		int b = find(y);

		if(a==b)cout<<"TIE"<<endl;
		else if(a>b)cout<<x<<endl;
		else cout<<y<<endl;
	}








}



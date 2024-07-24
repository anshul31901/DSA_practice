#include<bits.stdc++.h>
using namespace std;


void bfs(int x,int y,vector<vector<char>>&grid){
	queue<pair<int,int>>q;
	int m = grid.size();
	int n = grid[0].size();
 
	grid[x][y]='v';//visited
	q.push({x,y});
 
	while(!q.empty()){
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
 
		if(i-1>=0&&grid[i-1][j]=='.'){
			grid[i-1][j]='v';
			q.push({i-1,j});
 
		}
		if(i+1<m&&grid[i+1][j]=='.'){
			grid[i+1][j]='v';
			q.push({i+1,j});
 
		}
		if(j-1>=0&&grid[i][j-1]=='.'){
			grid[i][j-1]='v';
			q.push({i,j-1});
 
		}
		if(j+1<n&&grid[i][j+1]=='.'){
			grid[i][j+1]='v';
			q.push({i,j+1});
		}
	}
 
}
 
 
 
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<char>>graph(n,vector<char>(m));
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			cin>>graph[i][j];
		}
	}
	
 
	int rooms=0;
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			if(graph[i][j]=='.'){
				rooms++;
				bfs(i,j,graph);
			}
			
		}
	}
	cout<<rooms<<endl;
 
 
 
 
 
 
 
}

//what to do 
//min path in grids can be found using bfs
//create a vis array for bfs and use it to store distance fromn A(start pt)
// do bfs with constrains that you cannot go to already visited blocks and '#'
// now corresponding to b's co ordinates get their dist from dist/vis array and track back to dist -1 using sidt array till we reach a
//store path all along reverse it and return
//also check for cses when b isnt there and we cannot reach b 

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

const int MOD = 1e9+7;




int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<char>>graph(n,vector<char>(m));
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			cin>>graph[i][j];
		}
	}
	queue<pair<int,int>>q;
	vector<vector<int>>dist(n,vector<int>(m,-5));
	int dest_x=-1,dest_y=-1;
	
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			
			if(graph[i][j]=='A'){
				q.push({i,j});
				dist[i][j]=0;

			}
			if(graph[i][j]=='B'){
				dest_x=i;
				dest_y=j;
			}
		}
	}
	

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(x-1>=0 && dist[x-1][y]==-5&&graph[x-1][y]!='#'){
			dist[x-1][y]= dist[x][y]+1;

			q.push({x-1,y});
		}
		if(x+1<n && dist[x+1][y]==-5&&graph[x+1][y]!='#'){
			dist[x+1][y]= dist[x][y]+1;

			q.push({x+1,y});
		}
		if(y-1>=0 && dist[x][y-1]==-5&&graph[x][y-1]!='#'){
			dist[x][y-1]= dist[x][y]+1;

			q.push({x,y-1});
		}
		if(y+1>=0 && dist[x][y+1]==-5&&graph[x][y+1]!='#'){
			dist[x][y+1]= dist[x][y]+1;

			q.push({x,y+1});
		}



	}
	int x,y;
	x = dest_x;
	y = dest_y;



	if(dist[x][y]==-5||x==-1||y==-1){
		cout<<"NO"<<endl;
		return 0;
	}
	vector<char>path;

	while(x>=0&&y>=0){
		if(dist[x][y]==0)break;

		if(x-1>=0&&dist[x-1][y]==dist[x][y]-1){
			path.push_back('D');
			x--;
		}
		else if(x+1<n&&dist[x+1][y]==dist[x][y]-1){
			path.push_back('U');
			x++;
		}
		else if(y-1>=0&&dist[x][y-1]==dist[x][y]-1){
			path.push_back('R');
			y--;
		}
		else if(y+1>=0&&dist[x][y+1]==dist[x][y]-1){
			path.push_back('L');
			y++;
		}


	}
	reverse(path.begin(),path.end());
	cout<<"YES"<<endl;
	cout<<path.size()<<endl;
	for(int i =0;i<path.size();i++){
		cout<<path[i];
	}
	cout<<endl;




	






}




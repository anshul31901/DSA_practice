https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

//it is just bfs using distance array in a grid. We take initial and final position of the knight. I converted it in 0 base indexing.
//after that we made direction array for both horizontal and vertical directions and a distance array which acts as a visited array for bfs while also storing the number of steps required to reach a cell.
//we pushed the iniutial cordinate in a queue while queue is not empty we pop it and with help of direction array the cells that horse can jump to from here are calculated in all directions.
//if they are valid i.e in the chess board bounds and are visited for the fiorst time we update their dist and mark them visited and then push them in queue.
//in the above step we also check if the obtained cor ordinate from direction array is our target position we return its distance. 
//if for this whole process we cannot find target we end it and return -1;

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
    bool isvalid(int i,int j,vector<vector<int>>&dist){
        int n = dist.size();
        //out of the chessboard
        if(i<0||i>=n||j<0||j>=n)return false;
        //visited once
        if(dist[i][j]!=-1)return false;
        
        return true;
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    vector<vector<int>>dist(n,vector<int>(n,-1));
	    //converting into 0 base indexing
        pair<int,int>initial = {KnightPos[0]-1,KnightPos[1]-1};
	    dist[initial.first][initial.second]=0;
	    
	    pair<int,int>target = {TargetPos[0]-1,TargetPos[1]-1};
	    if(initial ==target)return 0;
    //maintained a clockwise distance array in both x and y directions
	    vector<int>dx ={-2,-1,1,2,2,1,-1,-2};
	    vector<int>dy={1,2,2,1,-1,-2,-2,-1};
	    
	    queue<pair<int,int>>q;
	    q.push(initial);
	    while(!q.empty()){
	        auto cur = q.front();
	        q.pop();
	        int x = cur.first;
	        int y =cur.second;
	       
	        for(int i=0;i<8;i++){
	            int a = x+dx[i];
	            int b = y+dy[i];
	             
	            if(isvalid(a,b,dist)){
	               
	                dist[a][b]=dist[x][y]+1;
                //if it is our target position we do not need to calculate further
	                if(a==target.first&&b==target.second){return dist[a][b];}
	                q.push({a,b});
	                }
	        }
	        
	    }
	    return -1;
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends

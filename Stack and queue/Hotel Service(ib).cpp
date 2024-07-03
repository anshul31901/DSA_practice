
//push all hotels in queue and bfs        

vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) {
    vector<int>res;
    vector<vector<int> > dist(A.size(),vector<int>(A[0].size(),-1));
    int n = A.size();
    int m = A[0].size();
    

    queue<pair<int,pair<int,int>>>q;
    
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(A[i][j]==1){
                q.push({0,{i,j}});
        
                dist[i][j]=0;
            }
        }
    }
    
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        
        int d = p.first;
        int i = p.second.first;
        int j = p.second.second;
        
        if(i-1>=0&&dist[i-1][j]==-1){
           
            dist[i-1][j]=d+1;
            q.push({d+1,{i-1,j}});
            
        }
        if(i+1<n&&dist[i+1][j]==-1){
            
            dist[i+1][j]=d+1;
            q.push({d+1,{i+1,j}});
            
        }
        if(j-1>=0&&dist[i][j-1]==-1){
            
            dist[i][j-1]=d+1;
            q.push({d+1,{i,j-1}});
        }
        if(j+1<m&&dist[i][j+1]==-1){
            
            dist[i][j+1]=d+1;
            q.push({d+1,{i,j+1}});
        }
    }
    for(auto it:B){
        int x = it[0]-1;
        int y = it[1]-1;
        res.push_back(dist[x][y]);
    }
    return res;
    

    
}

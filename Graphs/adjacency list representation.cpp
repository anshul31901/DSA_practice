https://www.codingninjas.com/studio/problems/creating-and-printing_1214551?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector < vector < int >>adj_list(n);
    for(int i=0;i<n;i++){
        adj_list[i].push_back(i);
    }
    for(int i=0;i<m;i++){
    
        int a = edges[i][0];
        int b = edges[i][1]; 
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);

    }
    


    return adj_list;
}

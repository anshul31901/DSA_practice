https://www.codechef.com/problems/PRGCUP01


#include <bits/stdc++.h>
using namespace std;
#define mod 100000007
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



int dis[8][8];
bool isvalid(int i,int j){
    if(i<0||i>=8||j<0||j>=8)return false;
    if(dis[i][j]!=-1)return false;
    return true;
}
void solve(){
        string s1,s2;
        cin>>s1>>s2;
        ii source = {s1[0]-'a',s1[1]-'1'};
        ii target = {s2[0]-'a',s2[1]-'1'};
        dis[source.ff][source.ss]=0;

        int dx[]={-2,-1,1,2,2,1,-1,-2};
        int dy[]={1,2,2,1,-1,-2,-2,-1};


        queue<ii>q;
        q.push(source);
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int x= cur.ff;
            int y = cur.ss;

            for(int i=0;i<8;i++){
                int xi = x+dx[i];
                int yi = y+dy[i];

                if(isvalid(xi,yi)){
                    dis[xi][yi]=dis[x][y]+1;
                    if(xi==target.ff&&yi==target.ss){
                        cout<<dis[xi][yi]<<endl;
                        return;
                    }
                    q.push({xi,yi});
                }
            }


        }
        cout<<-1<<endl;

}
int main() {
    
    int t;
    cin>>t;
    while(t--){
        memset(dis,-1,sizeof(dis));
        solve();

      
    }
}



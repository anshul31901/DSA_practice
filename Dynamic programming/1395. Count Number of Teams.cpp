//solution 1 dp space optimised: qus is how many lis of lenght 3 can we make if we start at idx

//1st iteration //base case : dp[i][1] number of lis of 1 length 1 i.e. 1 include yourself only
//2nd iteration : dp[i][2] = sum(dp[j][1]) for all j>i and j<n
//3rd iteration : dp[i][3] = sum(dp[j][2]) for all j>i and j<n


//for descending teams :then you reverse the array and count sum of 3 length lis again


//tc =O(n^2)
//sc = O(n)

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();

        vector<int>prev(n,1);
        vector<int>cur(n);
        for(int i =1;i<3;i++){
            for(int j =n-1;j>=0;j--){
                cur[j]=0;
                
                for(int k = j+1;k<n;k++){
                    if(rating[k]>rating[j]){
                        cur[j]+=prev[k];
                    }
                }
            }
            prev = cur;

        }
        int ct = 0;
        for(int i =0;i<n;i++){
            ct+=prev[i];
        }
        reverse(rating.begin(),rating.end());
        for(int i =0;i<n;i++){
            prev[i]=1;
            cur[i]=0;
        }
        for(int i =1;i<3;i++){
            for(int j =n-1;j>=0;j--){
                cur[j]=0;
                
                for(int k = j+1;k<n;k++){
                    if(rating[k]>rating[j]){
                        cur[j]+=prev[k];
                    }
                }
            }
            prev = cur;

        }
        for(int i =0;i<n;i++){
            ct+=prev[i];
        }
        return ct;


        
    }
};

// space optimised approach:

// The key insight here is to examine each soldier as a potential middle member. For each such soldier, we need to count:

// How many soldiers to their left have lower ratings
// How many soldiers to their right have higher ratings
// We apply the same logic for descending teams:

// How many soldiers to their left have higher ratings      dp[i] = leftLower*rightHigher+leftHigher*rightLower
// How many soldiers to their right have lower ratings

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        //l/r = left/right. l/h = lower/higher
        int teams=0;
        for(int i=0;i<n;i++){
            int ll = 0;
            int lh = 0;
            int rl =0;
            int rh = 0;
            for(int j=0;j<n;j++){
                if(j<i){
                    if(rating[j]<rating[i])ll++;
                    else lh++;
                }
                if(j>i){
                    if(rating[j]<rating[i])rl++;
                    else rh++;
                }
            }
            teams = teams + (ll*rh)+(lh*rl);
        }
        return teams;
    }
    
};



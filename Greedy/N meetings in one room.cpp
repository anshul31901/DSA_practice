//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    struct meeting{
        int s;
        int e;
    };
    bool static comparator(meeting m1,meeting m2){
        if(m1.e<m2.e) return true;
        else if(m1.e>m2.e)return false;
        else return m1.s>m2.s;
    }
    
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<meeting>v;
        meeting m;
        for(int i=0;i<n;i++){
            m.s = start[i];
            m.e = end[i];
            v.push_back(m);
        }
        sort(v.begin(),v.end(),comparator);
        int ct =0;
        int prev = -1;
        for(int i =0;i<n;i++){
            if(v[i].s>prev){
                ct++;
                prev = v[i].e;
            }
            
        }
        return ct;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends

https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    // 3 2 4 6 5
	    //2 3 4 5 6
	    
	    //4 9 16 25 36
	    
	    sort(arr, arr+n);
        vector<int>vec;
        unordered_set<int>st;
        
        vec.push_back(arr[0]);
        for(int i = 1; i<n; i++){
            if(vec.back()==arr[i])continue;
            else vec.push_back(arr[i]),st.insert(arr[i]);
            
        }
        
        int m = vec.size();
        for(int i = 0;i<m-2;i++){
            for(int j = i+1;j<m-1;j++){
                long a = vec[i];
                long b = vec[j];
                
                int c = sqrt(a*a+b*b);
                
                if(c*c!=a*a+b*b)continue;
                else if(st.find(c)!=st.end())return true;
            }
        }
        return false;
        
	    
	}

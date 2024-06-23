//sort both departure and arrival. for each new train if departure ptr is less than arrival
//move departure to next and ct--

//logic: for an arriving tran check if earliest departure has passed, if so platform will be able to accomodate
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int ct =0;
    	int maxi =0;
    	int j =0;
    	for(int i =0;i<n;i++){
    	    ct++;
    	    while(dep[j]<arr[i]&&j<n){
    	        ct--;
    	        j++;
    	    }
    	    maxi = max(ct,maxi);
    	}
    	return maxi;
    	
    	
    }
    
    // 900 940 950 1100 1500 1800
    // 910 1120 1130 1200 1900 2000
};

https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    void merge_sort(long long arr[],int start,int end,long long int &inv){
        if(start>=end)return;
        int mid= start+(end-start)/2;
        
        merge_sort(arr,start,mid,inv);
        merge_sort(arr,mid+1,end,inv);
        merge(arr,start,mid,end,inv);
        return;
    }
    void merge(long long arr[],int start,int mid,int end,long long int &inv){
        int l=start;
        int m= mid+1;
    
        vector<long long int>temp;
        while(l<=mid&&m<=end){
            if(arr[l]<=arr[m]){
                temp.push_back(arr[l]);
                l++;
            }
            else{
                inv+=(mid-l+1);
                temp.push_back(arr[m]);
                m++;
            }
        }
        if(l<=mid){
            while(l<=mid){
                temp.push_back(arr[l]);
                l++;
            }
        }
         
        if(m<=end){
            while(m<=end)
            {temp.push_back(arr[m]);
            m++;}
        }
        for(int i=start;i<=end;i++){
            arr[i]=temp[i-start];
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long int inv=0;
        merge_sort(arr,0,N-1,inv);
        return inv;
    }

};

#define ll long long int;
class Solution {
public:
void mergeSort(vector<int>&arr, int l, int r, long long &inv) {
    if (l >= r) return;
    
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid, inv);
    mergeSort(arr, mid + 1, r, inv);
    merge(arr, l, mid, r, inv);
}

void count_inv(vector<int>& arr, int l, int m, int r, long long &inv){
    int x = l;
    int y = m + 1;   
    long long ct =0;

    while(x<=m&&y<=r){
        if(1ll*arr[x]>2ll*arr[y]){
            ct++;
            y++;
        }
        else{
            inv+=ct;
            x++;
        }

        
    }
    while(x<=m)inv+=ct,x++;
    
}
void merge(vector<int>& arr, int l, int m, int r, long long &inv) {
    int x = l;
    int y = m + 1;

    
    count_inv(arr,l,m,r,inv);
    vector<long long> temp(r - l + 1);  // This line caused a compilation error
    
    int k = 0;
    while (x <= m && y <= r) {
        if (arr[x] < arr[y]) {
           

            temp[k] = arr[x];
            x++;
        } else {
            int p = x;
            temp[k] = arr[y];
            y++;
            
        }
        k++;
    }
    
    while (x <= m) {
        temp[k] = arr[x];
        k++;
        x++;
    }
    
    while (y <= r) {
        temp[k] = arr[y];
        k++;
        y++;
    }
    
    // Copy sorted elements from temp back to arr
    for (int i = 0; i < temp.size(); i++) {
        arr[l] = temp[i];
        l++;
    }
}

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        long long inv=0;
        mergeSort(nums,0,n-1,inv);
        return (int)inv;
        
    }
};









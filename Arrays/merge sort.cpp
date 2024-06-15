//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends

class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int x = l;
         int y = m+1;
         
         vector<int>temp(r-l+1);
       
         int k =0;
         while(x<=m&&y<=r){
             if(arr[x]<=arr[y]){
               temp[k]=arr[x];
                x++;
             }
             else{
                 temp[k]=arr[y];
                 y++;
             }
             k++;
             
     
         }
         while(x<=m){
             temp[k]=arr[x];
             k++;
             x++;
           
         }
         while(y<=r){
            temp[k]=arr[y];
             k++;
             y++;
        
         }
         
         for(int i =0;i<temp.size();i++){
             arr[l]=temp[i];
             l++;
         }
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r)return;
        int mid = l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends

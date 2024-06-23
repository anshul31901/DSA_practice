class Solution {
  public:
      bool static comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
      }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        sort(arr,arr+n,comp);
        double ans =0;
        int i =0;
        while(w>0&&i<n){
            if(w>=arr[i].weight){
                ans+= arr[i].value;
                w-= arr[i].weight;
            }
            else if(w<arr[i].weight){
                ans += (1.0*w/(1.0*arr[i].weight))*arr[i].value;
                w-=w;
            }
            i++;
        }
        return ans;
    }
};

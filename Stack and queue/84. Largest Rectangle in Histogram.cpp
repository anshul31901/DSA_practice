class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        

        //2 1 5 6 2 3
        //0 1 2 3 4 5

        //0
        // 1--1*2





        stack<int>st;
        int n = heights.size();
        int ans = 0;

        
        //for every element max area : height[element]*(nse idx - pse idx -1)
                                                //length  *breadth

        for(int i =0;i<=heights.size();i++){

          //jab tak increasing hai push into stack as pse would pe prev element in stack and -1 if stack is empty

          //when we observe 1st element breaking ascending order it will be next smaller for all elements in the array so compute their areas
          // compute areas with nse = i and pse = st.top till heights[i]>st.top();

          //alse for last for last element(n-1 idx) nse is at idx n. so run loop till <=n and is last element maintains asc order 
          //then for all elements in the stack nse will be n

            while(!st.empty()&&(i==n||heights[i]<heights[st.top()])){
                int ele = st.top();
                st.pop();

                int pse = st.empty()? -1:st.top();

                int nse = i;
                ans = max(ans,(nse-pse-1)*heights[ele]);


            }
            st.push(i);
        }
        return ans;

        
        
    }
};

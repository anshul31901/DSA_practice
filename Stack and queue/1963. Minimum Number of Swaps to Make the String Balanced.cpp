//using 1 swap we can balance 2 pairs at max so we will balance 2 pairs with 1 swap until no pairs or a single pair is left.
// if a single is left it would utilize full 1 swap
//  therefore answer = ceil(total unbalanced pairs/2)
// e.g ]]][][[[ --swap--> []][][[]--(cut balanced)-->][--(swap)--> balanced
// 3 unbalanced pairs = 1 for 2 pairs + 1 for single left pair swaps = 3 swaps


class Solution {
public:
    int minSwaps(string s) {


        int ct = 0;

        stack<char>st;
        //]]][][[[

        for(int i = 0;i<s.size();i++){

            if(s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
                else ct++;
            }

        }
        return ceil(ct/2.0);
        
    }

};

//space optimization .. maintain a counter for  '[' instead of using a stack.

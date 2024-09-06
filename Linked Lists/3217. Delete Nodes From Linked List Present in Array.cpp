/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {


public:

//prev temp
    // ListNode* deleteNode(ListNode*temp,ListNode*prev){

    //     if(prev==NULL)return temp->next;
    //     else{
    //         prev->next = temp->next;
    //         return prev;
    //     }



    // }


    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>to_delete;

        for(int i =0; i<nums.size();i++){
            to_delete.insert(nums[i]);
        }
        //traversing the list if head belongs to to_delete we update value of head to next 
        // otherwise if temp belongs to the to_delete 

        ListNode* temp = head;
        ListNode*prev = NULL;


        while(temp){
            // if prev is null it means temp is head node 
            
            if(prev==NULL){
                if(to_delete.find(temp->val)!=to_delete.end()){
                    head = temp->next;
                }
                else{
                    prev = temp;

                }

                temp = temp->next;
            }
            else{
                if(to_delete.find(temp->val)!=to_delete.end()){
                    prev->next = temp->next;
                }
                else{
                    prev = temp;
                }
                temp=temp->next;
            }
        }

        return head;





        
    }
};

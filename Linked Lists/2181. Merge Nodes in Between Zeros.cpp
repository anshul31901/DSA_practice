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
    ListNode* mergeNodes(ListNode* head) {
      
        ListNode* s  = head->next;
        ListNode* f = head->next;
//there are no consecutive nodes with values = 0;
        int sum = 0;
        while(f){

            if(f->val==0){
                s->val = sum;
                sum=0;
                s->next = f->next;
                s=s->next;

            }
            else{
                sum+=f->val;
            }
            f=f->next;

        }
        return head->next;





 
        
    }
};

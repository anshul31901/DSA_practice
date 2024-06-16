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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        int carry =0;

        ListNode* temp = dummy;
        


        while(l1||l2||carry){
            int sum =0;
            if(l1)sum+=l1->val,l1=l1->next;
            if(l2)sum+=l2->val,l2=l2->next;
            if(carry)sum+=1;

            if(sum>=10)carry =1;
            else carry = 0;

            sum= sum%10;

            temp->next = new ListNode(sum);
            temp = temp->next;
            

        }
        return dummy->next;
    }
};

//wrongly done 
        // if(!l1&&!l2)return 0;
        // ListNode* head ;
        // l1?head=l1:l2;

        // ListNode*temp=head;

        // int carry =0 ;
        // while(l1||l2||carry){
        //     int sum =0;
        //     if(l1)sum+=l1->val,temp->next = l1;
        //     if(l2)sum+=l2->val,temp->next = l2;

        //     if(!l1&&!l2)temp->next=nullptr;
        //     if(carry)sum+=carry;

        //     if(sum>=10)carry=1,sum=sum%10;
        //     else carry =0;

            
        //     if(!temp->next)temp->next=new ListNode(1);
        //     else temp->val= sum;
            
        //     temp = temp->next;
        //     if(l1)l1 = l1->next;
        //     if(l2)l2 = l2->next;

            
        // }
        // return head;

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* forward=head;
        while(n--)forward=forward->next;

        ListNode* prev = nullptr;
        ListNode * temp = head;

        while(forward){
            forward= forward->next;
            prev = temp;
            temp = temp->next;
        }
        if(prev){
            prev->next=temp->next;
            delete temp;
            return head;
        }
        else{
            prev = head->next;
            delete head;
            return prev;
        }

    }
};

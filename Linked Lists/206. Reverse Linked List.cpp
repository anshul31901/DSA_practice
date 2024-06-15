//recursive solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    
    ListNode*prev = NULL;
    ListNode*temp = A;
    ListNode*front = NULL;
    while(temp){
        front = temp->next;
        temp->next= prev;
        prev = temp;
        
        temp = front;
    }
    return prev;
}
//iterative solution 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* NXT = nullptr;
        while (current != nullptr) {
            NXT = current->next;
            current->next = prev;
            prev = current;
            current = NXT;
        }
        return prev;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* l = headA;
            ListNode* r = headB;

            while(l!=r){
                l = (l)?l->next:headB;
                r = (r)?r->next:headA;
            }
            return l;
    }
};

https://leetcode.com/problems/split-linked-list-in-parts/?envType=daily-question&envId=2024-09-08

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
    int get_size(ListNode* head){
        int ct =0;

        while(head!=NULL){
            ct++;
            head= head->next;
            //1 2 3 4 5
        }
        return ct;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int n = get_size(head);

        int c = n/k;
        int r = n%k;
        vector<ListNode*> res;


        if(c<1){
            while(k--){
                if(head!=NULL){
                    res.push_back(new ListNode(head->val));
                    head= head->next;
                }
                else res.push_back(NULL);
            }
            return res;
        }
        else{
            ListNode* cur = head;
            ListNode* prev = NULL;

            while(k--){
                res.push_back(cur);
                for(int i = 0;i<c;i++){
                    prev = cur;
                    cur = cur->next;
                    
                }
                if(r>0){
                    prev = cur ;
                    cur = cur->next;
                    r--;
                }
                if(k!=0)prev->next =NULL;
            }
            return res;
        }

        
    }
};

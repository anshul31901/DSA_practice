space complexity O(n) solution using stack;
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
    bool isPalindrome(ListNode* head) {
        stack<int>st;
        ListNode* temp = head;
        while(temp){
            st.push(temp->val);
            temp=temp->next;

        }
        temp = head;
        while(!st.empty()){
            if(st.top()==temp->val){
                st.pop();
                temp=temp->next;
            }
            else return false;
        }
        return true;
        
    }
};


// space complexity O(1) solution = 1.find middle element 2. find 2nd head = middle element (if even)/midle+1(if odd0     3.reverse from second head 4.simultaniously check for 1st and 2nd list
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
    ListNode* reverseList(ListNode*head){
        ListNode*prev = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* front = cur->next;
            cur->next = prev;
            prev = cur;
            cur = front;
        }
        return prev;
     
    }
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)return true;

        ListNode* slow =head->next;
        ListNode* fast = slow->next;

        while(fast&&fast->next){
            slow= slow->next;
            fast = fast->next->next;
        }
        if(fast)slow = slow->next;
        slow = reverseList(slow);
        ListNode * temp = head;

        while(slow){
            if(slow->val==temp->val){
                slow = slow->next;
                temp = temp->next;
            }
            else return false;
        }
        return true;
        
    }
};

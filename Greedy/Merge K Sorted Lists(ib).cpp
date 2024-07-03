//same as merge k sorted arrays
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>heap;
    for(auto node:A){
        heap.push({node->val,node});
    }
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    while(!heap.empty()){
        auto p = heap.top();
        heap.pop();
        temp->next = new ListNode(p.first);
        temp = temp->next;
        
        auto node = p.second;
        if(node->next){
            heap.push({node->next->val,node->next});
        }
        
        
    }
    return dummy->next;
    
}

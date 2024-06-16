ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(!A||!A->next)return A;
    
    ListNode * prev = A;
    ListNode* cur = A->next;
    
    while(cur){
        if(prev->val==cur->val){
            prev->next = cur->next;
            cur=cur->next;            
        }
        else{
            prev = cur;
            cur = cur->next;
        }

 
    }
    return A;
    
    
}

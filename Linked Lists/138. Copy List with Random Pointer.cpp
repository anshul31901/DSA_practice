/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

       
        if(head==NULL)return head;

        Node* temp = head;

        while(temp){
            Node* forward = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = forward;
            temp = forward;
        }
        temp = head;

        while(temp){
            if(temp->random){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        temp = head->next;

        Node* original = head;
        Node* copy_head = head->next;
        Node* copy = copy_head;

        //restore original list

        //1->1->2->2

        while(original && copy){
            original ->next = original ->next->next;
            original = original->next;

            if(copy->next){
                copy->next=copy->next->next;
            }
            copy=copy->next;

        }
        return copy_head;




    }
};

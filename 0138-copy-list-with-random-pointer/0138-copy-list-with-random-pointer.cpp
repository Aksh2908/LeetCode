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
        if(!head) return head;
        Node* temp=head;

        while(temp){
            Node* clone=new Node(temp->val);
            clone->next=temp->next;
            temp->next=clone;
            temp=clone->next;
        }

        temp=head;
        while(temp){
            if(temp->random){
                temp->next->random = temp->random->next;
            }
            temp=temp->next->next;
        }

        temp=head;
        Node* cloneHead = head->next;
        Node* clone=cloneHead;
        while(temp){
            temp->next=temp->next->next;
            if(clone->next) clone->next=clone->next->next;
            temp=temp->next;
            clone=clone->next;
        }
        return cloneHead;
    }
};
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
    ListNode* removeElements(ListNode* head, int val) {
    if(!head) return head;
    ListNode *temp=NULL;
    while(head && head->val==val){
        temp=head;
        head=head->next;
        delete temp;
    }
    ListNode *curr=head;
    while(curr && curr->next){
        if(curr->next->val==val){
            temp=curr->next;
            curr->next=temp->next;
            delete temp;
        }
        else curr=curr->next;
    }
    return head;
    }
};
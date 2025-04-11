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
        if(!head) return head;
        int len=0;
        ListNode* node=head;
        while(node){
            len++;
            node=node->next;
        }
        if(len<n) return head;
        int pos=len-n;
        if(!pos){
            head=head->next;
            return head;
        }
        len=0;
        node=head;
        while(node && len!=pos-1){
            len++;
            node=node->next;
        }
        ListNode* temp=node->next;
        node->next=temp->next;
        delete(temp);
        return head;
    }
};
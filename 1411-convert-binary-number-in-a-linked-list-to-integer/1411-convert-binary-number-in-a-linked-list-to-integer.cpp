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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode *prev=NULL,*curr=head;
        while(curr){
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

    int getDecimalValue(ListNode* head) {
        if(!head) return 0;
        head=reverseList(head);
        unsigned long long ans=0,bin_pos=1;
        ListNode *temp=head;
        while(temp!=NULL){
            if(temp->val==1){
                ans+=bin_pos;
            }
            bin_pos*=2;
            temp=temp->next;
        }
        return ans;
    }
};
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        map<int,int> mpp;
        ListNode *temp=head;
        while(temp){
            mpp[temp->val]++;
            temp=temp->next;
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *curr=dummy;
        for(auto it:mpp){
            curr->next=new ListNode(it.first);
            curr=curr->next;
        }
        return dummy->next;
    }
};
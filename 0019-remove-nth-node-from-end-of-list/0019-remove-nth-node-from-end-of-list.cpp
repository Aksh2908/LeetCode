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
        ListNode* fast=head;
        ListNode* slow=head;
        while(n--) fast=fast->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        if(!fast) return head->next;
        ListNode* temp=slow->next;
        slow->next=slow->next->next;
        delete temp;
        return head;
    }
};
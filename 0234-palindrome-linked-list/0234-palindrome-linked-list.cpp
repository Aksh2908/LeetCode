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
private:
    ListNode* findMid(ListNode* head){
        if(!head||!head->next) return head;
        ListNode *slow=head,*fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* newHead=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr; 
        return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        ListNode* mid=findMid(head);
        ListNode* right=reverseList(mid->next);
        ListNode* temp=head,*sec=right;
        while(sec){
            if(temp->val!=sec->val){
                //mid->next=reverse(right);
                return false;
            }
            temp=temp->next;
            sec=sec->next;
        }
        //mid->next=reverse(right);
        return true;
    }
};
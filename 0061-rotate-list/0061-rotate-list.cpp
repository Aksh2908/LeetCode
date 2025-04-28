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
    // ListNode* reverse(ListNode* head){
    //     if(!head || !head->next) return head;
    //     ListNode* newHead = reverse(head->next);
    //     ListNode* front = head->next;
    //     front->next=head;
    //     head->next=nullptr;
    //     return newHEad;
    // }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* temp=head;
        int len=1;
        while(temp->next){
            ++len;
            temp=temp->next;
        }
        temp->next=head;

        if(k>=len) k=k%len;
        int d=len-k;

        while(d--){
            temp=temp->next;
        }
        
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};
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
    ListNode* findKth(ListNode* head, int k){
        while(head && k--){
            head=head->next;
        }
        return head;
    }

    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* newHead=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newHead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;

        ListNode* temp=head;

        ListNode* dummy=new ListNode(-1);
        ListNode* mover=dummy;

        while(temp){
            ListNode* kNode=findKth(temp,k-1);
            if(kNode==nullptr){
                mover->next=temp;
                break;
            }
            ListNode* nextNode=kNode->next;
            kNode->next=nullptr;
            
            mover->next=reverse(temp);
            mover=temp;

            temp=nextNode;
        }

        return dummy->next;
    }
};
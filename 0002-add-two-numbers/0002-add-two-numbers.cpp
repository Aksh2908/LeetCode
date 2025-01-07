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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) return NULL;
        ListNode *dummyNode= new ListNode(-1);
        ListNode *temp1=l1,*temp2=l2,*headNew=dummyNode;
        unsigned int carry=0,sum=0;
        while(temp1 || temp2 || carry){
            sum=0;
            if(temp1) {
                sum+=temp1->val;
                temp1=temp1->next;
            }
            if(temp2) {
                sum+=temp2->val;
                temp2=temp2->next;
            }
            sum+=carry;
            ListNode *curr= new ListNode;
            curr->val=(sum%10);
            carry=(sum/10);
            headNew->next=curr;
            headNew=headNew->next;
        }
        return dummyNode->next;
    }
};
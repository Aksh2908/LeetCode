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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }

    ListNode* kthNode(ListNode* temp, int k){
        while(temp && k!=1){
            k--;
            temp=temp->next;
        }
        return temp;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* prevNode=nullptr,*nextNode=nullptr;
        ListNode* temp=head;
        while(temp){
            ListNode* kNode = kthNode(temp,k);
            if(!kNode){
                prevNode->next = temp;
                break;
            }
            nextNode = kNode->next;
            kNode->next=nullptr;
            ListNode* newHead = reverse(temp);
            if(temp==head){
                head=newHead;
            }
            else{
                prevNode->next=newHead;
            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};
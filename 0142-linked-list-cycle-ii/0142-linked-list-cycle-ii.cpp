/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next) return nullptr;
        unordered_map<ListNode*,int> mpp;
        ListNode* temp=head;
        while(temp){
            auto it=mpp.find(temp);
            if(it!=mpp.end())
                return it->first;
            mpp[temp]=1;
            temp=temp->next;
        }
        return nullptr;
    }
};
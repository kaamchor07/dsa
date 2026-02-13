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
    bool hasCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return false;
        ListNode* mid=head;
        ListNode* current=head;
        int count=0;
        while(current!=nullptr){
            count++;
            current=current->next;
            if(mid==current)return true;
            if(count%2==1) mid=mid->next;
            
        }
        return false;
    }
};

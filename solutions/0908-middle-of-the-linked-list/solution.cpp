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
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        int count=0;
        ListNode* current=head;
        ListNode* mid=head;
        bool flag=true;
        while(current!=nullptr){
            count++;
            if(count%2==0){
                mid=mid->next;
            }
            current=current->next;
        }
        return mid;
    }
};

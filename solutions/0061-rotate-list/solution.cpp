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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* pt1=head;
        ListNode* pt2=head;
        int len=1;
        while(pt2->next!=nullptr){
            len++;
            pt2=pt2->next;
        }
        k=k%len;
        pt2->next=head;
        for(int i=1;i<len-k;i++){
            pt1=pt1->next;
        }
        ListNode* dummy=pt1->next;
        pt1->next=nullptr;
        return dummy;
    }
};

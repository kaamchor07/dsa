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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==1)return head;
        ListNode* pt1=head;
        ListNode* pt2=head;
        ListNode* dummy=new ListNode(0,head);
        ListNode*prev=dummy;
        while(pt2!=nullptr){
            for(int i=1;i<k;i++){
                pt2=pt2->next;
                if(pt2==nullptr)return dummy->next;
            }
            ListNode* nextgrp=pt2->next;
            reverseList(pt1,nextgrp);
            prev->next=pt2;
            prev=pt1;
            pt1=pt1->next;
            pt2=pt1;
        }
        return dummy->next;
    }
private:
    void reverseList(ListNode* head,ListNode* end) {
        if(head==nullptr ||head->next==nullptr) return;
        ListNode* current=head;
        ListNode* back=end;
        ListNode* forward=head->next;
        while(current!=end){
            forward=current->next;
            current->next=back;
            back=current;
            current=forward;
        }
    }
};

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
        if(l1==nullptr)return l2;
        if(l2==nullptr)return l1;
        int carry=0;
        ListNode* ans=new ListNode(0,nullptr);
        ListNode* anshead=ans;
        while(l1!=nullptr && l2!=nullptr){
            ans->next=new ListNode(0,nullptr);
            ans=ans->next;
            ans->val=(l1->val+l2->val+carry)%10;
            carry=(l1->val+l2->val+carry)/10;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1==nullptr){
            while(l2){
            ans->next=new ListNode(0,nullptr);
            ans=ans->next;
            ans->val=(l2->val+carry)%10;
            carry=(l2->val+carry)/10;
            l2=l2->next;
            }
        }else if(l2==nullptr){
            while(l1){
            ans->next=new ListNode(0,nullptr);
            ans=ans->next;
            ans->val=(l1->val+carry)%10;
            carry=(l1->val+carry)/10;
            l1=l1->next;
            }
        }
        if(carry==1){
            ans->next=new ListNode(carry,nullptr);
        }
        anshead=anshead->next;
        return anshead;
    }
};

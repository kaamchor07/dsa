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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int counterA=0;
        int counterB=0;
        if(headA==nullptr || headB==nullptr){
            return nullptr;
        }
        ListNode* A=headA;
        ListNode* B=headB;
        while(headA){   
            counterA++;
            headA=headA->next;
        }
        while(headB){   
            counterB++;
            headB=headB->next;
        }
        headB=B;
        headA=A;
        if(counterB>=counterA){
            for(int i=0;i<counterB-counterA;i++){
                headB=headB->next;
            }
        }else{
            for(int i=0;i<counterA-counterB;i++){
                headA=headA->next;
            }
        }
        while(headB!=headA){
            headB=headB->next;
            headA=headA->next;
        }
        if(headB==headA){
            return headA;
        }else{
            return nullptr;
        }
        return nullptr;
    }
};

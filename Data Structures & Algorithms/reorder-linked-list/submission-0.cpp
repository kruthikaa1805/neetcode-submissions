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
    void reorderList(ListNode* head) {
        // go to mid;reverse from mid to end and then add one from start ;one from the reversed list
        //finding mid;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=slow;
        ListNode* temp=NULL;
        while(curr!=NULL)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        ListNode* r1=prev;
        ListNode* l1=head;
        
        while(r1->next!=NULL)
        {
              ListNode* l2=l1->next;
             ListNode* r2=r1->next;
             l1->next=r1;
             l1=l2;
             r1->next=l2;
             r1=r2;
              
        }
     
    }
};

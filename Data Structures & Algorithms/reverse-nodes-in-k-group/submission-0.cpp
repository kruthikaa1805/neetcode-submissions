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
    ListNode* reversell(ListNode* node)
    {
        ListNode* prev=NULL;
        ListNode* curr=node;
        ListNode* temp=NULL;
        while(curr!=NULL)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
         //find the kth node;send it to the reverse function as a separate list ;
         //before breaking the link store the next node;
         //after reversing store the last node or you can store the first node before reversing
         //connect this node to the next node after reversing the next set.
         if(head==NULL)
         return NULL;
         int i=1;
         
         ListNode* temp=head;
         while(i<k && temp!=NULL)
         {
              temp=temp->next;
              i++;
         }
         if(temp==NULL)
         return head;
         ListNode* aage=temp->next;
         temp->next=NULL;
         ListNode* first=reversell(head);
         head->next=reverseKGroup(aage,k);
         return first;


    }
};

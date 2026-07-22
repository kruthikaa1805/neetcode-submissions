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
     void reversell(ListNode* node)
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
        return;
    }
    ListNode* getKthnode(ListNode* node,int k)
    {
        int i=1;
        ListNode* curr=node;
        while(i<k)
        {
           if(curr==NULL)
           return NULL;
           curr=curr->next;
           i++;
        }
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
        return NULL;
       ListNode* temp=head;
       ListNode* prev=NULL;
       while(temp!=NULL)
       {
         ListNode* kthnode=getKthnode(temp,k);
         if(kthnode==NULL)
         {
            if(prev!=NULL)
            prev->next=temp;
            break;
         }
         ListNode* nextnode=kthnode->next;
         kthnode->next=NULL;
         reversell(temp);
         if(temp==head)
         {
            head=kthnode;
         }
         else
         prev->next=kthnode;
         prev=temp;
         temp=nextnode;
       }
       
        return head;
    }
};

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
    }
    ListNode* getkthnode(ListNode* node,int k)
    {
        int i=1;
        ListNode* temp=node;
        while(i<k && temp!=NULL)
        {
             temp=temp->next;
             i++;
        }
        if(temp==NULL)
        return NULL;
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
         //find the kth node;send it to the reverse function as a separate list ;
         //before breaking the link store the next node;
         //after reversing store the last node or you can store the first node before reversing
         //connect this node to the next node after reversing the next set.
        /* if(head==NULL)
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
         return first;*/
         if(head==NULL)
         return NULL;
         ListNode* temp=head;
         ListNode* prev=NULL;
         while(temp!=NULL)
         {
            ListNode* kthNode=getkthnode(temp,k);
            if(kthNode==NULL && prev!=NULL)
            {
                prev->next=temp;
                break;
            }
            ListNode* nextnode=kthNode->next;
            kthNode->next=NULL;
            reversell(temp);
            if(temp==head)
            head=kthNode;
            else
            {
                prev->next=kthNode;
               
            }
             prev=temp;
                temp=nextnode;
         }

       return head;
    }
};

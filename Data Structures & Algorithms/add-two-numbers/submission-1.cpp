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
   /* ListNode* reverseLL(ListNode* curr,ListNode* prev)
    {
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a=reverseLL(l1,NULL);
        ListNode* b=reverseLL(l2,NULL);
        int sum1=0;
        int sum2=0;
        while(a!=NULL)
        {
            sum1=sum1*10+a->val;
            a=a->next;
        }
        while(b!=NULL)
        {
            sum2=sum2*10+b->val;
            b=b->next;
        }
        int sum=sum1+sum2;
        int r=sum%10;
        ListNode* head=new ListNode(r);
        ListNode* prev=head;
        sum=sum/10;
        while(sum>0)
        {
            int rem=sum%10;
            ListNode* temp=new ListNode(rem);
            prev->next=temp;
            prev=temp;
            sum=sum/10;
        }
        return head;*/
         ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummy=new ListNode(0);
             ListNode* curr=dummy;
             int carry=0;
            while(l1!=NULL || l2!=NULL ||carry>0)
            {
               int sum=carry;
               if(l1!=NULL)
               {
                sum+=l1->val;
                l1=l1->next;
               }
               if(l2!=NULL)
               {
                sum+=l2->val;
                l2=l2->next;
               }
              curr->next=new ListNode(sum%10);
              carry=sum/10;
              curr=curr->next;
            }
         return dummy->next;
    }
};

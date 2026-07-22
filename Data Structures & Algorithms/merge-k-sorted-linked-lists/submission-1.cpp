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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct cmp{
            bool operator()(ListNode*a,ListNode* b)
            {
                return a->val >b->val;
            }
        };
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        int k=lists.size();
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        for(ListNode* head:lists)
        {
            if(head!=NULL)
            pq.push(head);
        }
        while(!pq.empty())
        {
            ListNode* small=pq.top();
            pq.pop();
            temp->next=small;
            temp=small;
            if(small!=NULL && small->next!=NULL)
            {
                pq.push(small->next);
            }
        }
       /* ListNode* realhead=dummy->next;
        delete(dummy);
        return realhead;*/
        return dummy->next;
    }
};

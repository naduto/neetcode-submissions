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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;   
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for(auto it:lists)
        {
            if(it)
            {
                pq.push(it);
            }
        }
        ListNode dummy(0);
        ListNode* merged=&dummy;
        while(!pq.empty())
        {
            ListNode* head=pq.top();
            pq.pop();

            merged->next=head;
            merged=merged->next;

            if(head->next)pq.push(head->next);
        }
        return dummy.next;

    }
};

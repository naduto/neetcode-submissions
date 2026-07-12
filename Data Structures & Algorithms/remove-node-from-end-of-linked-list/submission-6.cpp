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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* ptr1=&dummy;
        for(int i=0;i<n;i++)
        {
            ptr1=ptr1->next;
        }
        ListNode* ptr2=&dummy;
        while(ptr1->next)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        cout<<ptr2->val<<endl;
        ptr2->next=ptr2->next->next;
        ptr2=head;
        return dummy.next;
    }
};

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
        int n=lists.size();
         ListNode dummy(0);
        ListNode* merged = &dummy;
        while(true)
        {
            ListNode* mini=nullptr;
            int index=-1;
            for(int i=0;i<n;i++)
            {
                if(lists[i]&&(mini==nullptr||(lists[i]->val)<(mini->val)))
                {
                    mini=lists[i];
                    index=i;
                }

            }
            if (index==-1)break;
            merged->next=mini;
            merged=merged->next;
            lists[index]=lists[index]->next;
        }
        return dummy.next;
    }
};

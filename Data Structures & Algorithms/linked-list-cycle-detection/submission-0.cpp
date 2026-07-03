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
    bool hasCycle(ListNode* head) {
        map<int,bool>vis;
        while(head!=nullptr)
        {
            ListNode* nextt=head->next;
            if(nextt!=nullptr&&vis[nextt->val])
            {
                return true;
            }
            else
            {
                if(nextt!=nullptr)
                vis[nextt->val]=true;
                head=nextt;
            }
        }
        return false;
    }
};

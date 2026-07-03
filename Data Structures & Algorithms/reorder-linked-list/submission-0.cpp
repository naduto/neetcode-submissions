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
    ListNode* reverseList(ListNode* temp) {
        ListNode* next_node=temp->next;
        ListNode* prev_node=nullptr;
        while(temp!=nullptr)
        {
            next_node=temp->next;
            temp->next=prev_node;
            prev_node=temp;
            temp=next_node;
        }
        return prev_node;
    }
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;
        ListNode* middle=head;
        ListNode* last=head;
        while(last!=nullptr&&last->next!=nullptr)
        {
            middle=middle->next;
            last=last->next->next;
        }
        ListNode* second = middle->next;
        middle->next = nullptr;
        ListNode* reversed=reverseList(second);
        ListNode* temp=head;
        while(head!=nullptr&&reversed!=nullptr)
        {
           ListNode* temp1=temp->next;
           ListNode* temp2=reversed->next;
           temp->next=reversed;
           reversed->next=temp1;
           
           temp=temp1;
           reversed=temp2;
        }
    }
};

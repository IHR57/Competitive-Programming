/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode *hare = head, *tortoise = head->next;
        
        while(tortoise != NULL && hare != tortoise){
            hare = hare->next;
            tortoise = tortoise->next;
            if(tortoise != NULL)
                tortoise = tortoise->next;
        }
        
        return hare == tortoise;
    }
};
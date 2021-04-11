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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *root = head;
        ListNode *temp = head;
        ListNode *ans = root;
        
        if(root == 0)
            return root;
        int prev = temp->val;
        temp = temp->next;
        while(temp != NULL){
            if(temp->val != prev){
                root->next = temp;
                root = root->next;
            }
            prev = temp->val;
            temp = temp->next;
        }
        root->next = NULL;
        
        return ans;
    }
};
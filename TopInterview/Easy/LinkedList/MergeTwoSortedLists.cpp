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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        // 8ms, 14.8MB
        // Choose between updated l1 and l2 !!
        // Connect one by one
        
        // manage empty inputs
        if(!l1 && !l2)
            return l1;
        else if(!l1)
            return l2;
        else if(!l2)
            return l1;
        
        
        // Initialize
        ListNode* first;
        ListNode* last;
        ListNode* temp;
        
        if(l1->val <= l2->val){
            first = l1;
            last = l1;
            l1 = l1->next;
        }
        else{
            first = l2;
            last = l2;
            l2 = l2->next;
        }
        
        
        // Iterate through given list and connect smaller number
        while(l1 || l2){
            if(!l1){
                last->next = l2;
                break;
            }
            else if(!l2){
                last->next = l1;
                break;
            }
            if(l1->val <= l2->val){
                temp = l1->next;
                last->next = l1;
                last = l1;
                l1 = temp;
            }
            else{
                temp = l2->next;
                last->next = l2;
                last = l2;
                l2 = temp;
            }
        }
        
        return first;
    }
};
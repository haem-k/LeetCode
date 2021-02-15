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
    
    // M1) Recursively (4ms, 8.6MB)
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        
        ListNode* newHead = pointPrevious(nullptr, head);
        return newHead;
    }
    
    ListNode* pointPrevious(ListNode* prev, ListNode* current){
        // termination condition
        if(!(current->next)){
            current->next = prev;
            return current; // new head
        }
        else{
            ListNode* newHead = pointPrevious(current, current->next);
            current->next = prev;
            return newHead;
        }
    }
    
    
    /*
    // M2) Iteratively (8ms, 8.3MB)
    ListNode* reverseList(ListNode* head) {
        // return if empty list
        if(!head)
            return head;

        ListNode* current = head;
        ListNode* previous = nullptr;   // otherwise, starts with garbage value
        
        while(current){
            ListNode* temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }
        
        return previous;
    }
    */
};
class Solution {
public:
    //Runtime: 16 ms
    //Memory Usage: 15.7 MB
    
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)
            return true;
        
        // Two pointer: front & back
        ListNode* result = checkOneNumber(head, head);
        
        if(result == nullptr)
            return false;
        
        return true;
    }
    
    ListNode* checkOneNumber(ListNode* front, ListNode *current){
        // if current node is nullptr
        if(current == nullptr)
            return nullptr;
        
        // if currect node is the last one in the list
        if(current->next == nullptr){
            if(front->val != current->val)
                return nullptr;
            return front;
        }
        
        else{
            front = checkOneNumber(front, current->next);
            if(front == nullptr)
                return nullptr;
                
            front = front->next;
            if(front->val != current->val)
                return nullptr;
        }
        
        return front;
    }
};
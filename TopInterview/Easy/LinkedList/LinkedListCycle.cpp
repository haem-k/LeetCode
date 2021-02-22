class Solution {
public:
    
//     // Takes too long.. and too much
//     bool hasCycle(ListNode *head) {
//         if(head == nullptr){
//             return false;
//         }
        
//         unordered_map<ListNode*, int> nodes;
//         bool result;
        
//         ListNode* current = head;
        
//         while(1){
//             // there is duplicate
//             if(nodes.find(current) != nodes.end()){
//                 result = true;
//                 break;
//             }
//             else if(current->next == nullptr){
//                 result = false;
//                 break;
//             }
//             else{
//                 nodes[current] = 1;
//                 current = current->next;
//             }
//         }
        
//         return result;
        
//     }

    bool hasCycle(ListNode *head) {
       ListNode* fast = head;
       ListNode* slow = head;
       while(fast && fast->next){
           fast = fast->next->next;
           slow = slow->next;
           if(fast == slow) return true;
       }
       return false;
    }
};
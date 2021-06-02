// M1) Making new linked list
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode();
    ListNode* index = result;
    int add = 0;
    
    // Iterate if one of them has the value
    while(l1 != NULL || l2 != NULL){
        int sum = 0;
        
        if(l1 != NULL)
            sum += l1->val;
        if(l2 != NULL)
            sum += l2->val;
        
        sum += add;
        add = sum/10;
        sum -= sum/10 * 10;
        index->next = new ListNode(sum);
            
        // Move on to next node
        if(l1 != NULL)
            l1 = l1->next;
        if(l2 != NULL)
            l2 = l2->next;
        index = index->next;
        
    }
    
    if(add != 0)
        index->next = new ListNode(add);
    
    return result->next;
    
}
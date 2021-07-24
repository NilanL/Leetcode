/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* createNode()
{
    struct ListNode* temp = malloc(sizeof(struct ListNode));
    temp->val = 0;
    temp->next = NULL;
    
    return temp;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum, remainder = 0;

    struct ListNode* sumLL = createNode();
    struct ListNode* head = sumLL;
    
    while (l1 != NULL) // O(n)
    {
        if (sumLL->next == NULL && (l1->next != NULL)) sumLL->next = createNode();
        
        sumLL->val += l1->val;
        
        sumLL = sumLL->next;
        l1 = l1->next;
    }
    
    sumLL = head;
    while (l2 != NULL) // O(n)
    {
        if (sumLL->next == NULL && (l2->next != NULL)) sumLL->next = createNode();
        
        sumLL->val += l2->val;
        
        if (sumLL->val >= 10)
        {
            if (sumLL->next == NULL) sumLL->next = createNode();
            sumLL->val -= 10;
            sumLL->next->val += 1;
        }
        
        sumLL = sumLL->next;
        l2 = l2->next;
    }
    
    sumLL = head;
    while (sumLL != NULL || remainder == 1) // O(n)
    {   
        sumLL->val += remainder;
        if (sumLL->val >= 10)
        {
            if (sumLL->next == NULL) sumLL->next = createNode();
            sumLL->val -= 10;
            remainder = 1;
        }
        else
        {
            remainder = 0;
        }
        
        sumLL = sumLL->next;
    }
    
    return head;
}

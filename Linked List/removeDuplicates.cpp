void removeDuplicates(struct Node* head)
{
    struct Node* nodeptr = head;
    struct Node* next;
    while(nodeptr->next) {
        
        if(nodeptr->data != nodeptr->next->data) {
            nodeptr=nodeptr->next;
        } else {
            next = nodeptr->next->next;
            free(nodeptr->next);
            nodeptr->next=next;
        }
    }
    
}

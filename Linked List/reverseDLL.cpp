struct Node* reverseDLL(struct Node * head)
{
    if(!head) return NULL;
    if(!head->next) return head;
    struct Node* cur = head;
    struct Node* temp;
    struct Node* prev = NULL;
    while(cur) {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
        prev = cur;
    }
    
    // swap head and tail pointers
    if(temp) {
        prev = temp->prev;
    }
    return prev;
}

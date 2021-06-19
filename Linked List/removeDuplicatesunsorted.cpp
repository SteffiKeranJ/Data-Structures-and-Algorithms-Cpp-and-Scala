class Solution
{
    public:
    int map[10001] =  {0};
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     if(!head) return NULL;
     Node* nodeptr = head;
     Node* nextptr;
     map[head->data] +=1;
     while(nodeptr->next) {
         map[nodeptr->next->data]+=1;
         if(map[nodeptr->next->data] > 1) {
             nextptr = nodeptr->next->next;
             free(nodeptr->next);
             nodeptr->next = nextptr;
         } else {
             nodeptr=nodeptr->next;
         }
     }
     return head;
     
    }
};

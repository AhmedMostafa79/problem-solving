DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode*newnode=new DoublyLinkedListNode(data),*cur=llist;
    newnode->prev=newnode->next=NULL;
    while(cur->next and cur->data<data)cur=cur->next;
    if(!cur->next and cur->data<data){
        newnode->prev=cur;
        cur->next=newnode;
    }
    else if(cur==llist){
        newnode->next=cur;
        cur->prev=newnode;
        llist=newnode;
    }
    else {
        newnode->next=cur;
        newnode->prev=cur->prev;
        cur->prev=newnode;
        newnode->prev->next=newnode;
    }
    return llist;
}

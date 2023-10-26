SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
SinglyLinkedListNode*newnode=new SinglyLinkedListNode(data),*cur=llist,*after=NULL;
    if(cur==NULL){
        llist=newnode;
        return llist;    
    }
    while(cur!=NULL and position){
        after=cur;
        position--;
        cur=cur->next;
    }
    after->next=newnode;
    newnode->next=cur;
    return llist;
}

int getNode(SinglyLinkedListNode* llist, int p) {
    SinglyLinkedListNode*cur=llist;
    int size=0;
    while(cur){
        size++;
        cur=cur->next;
    }
    p=size-p;
    cur=llist;
    while(cur and p>1){
        p--;
        cur=cur->next;
    }
    return cur->data;
}


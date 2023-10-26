
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
SinglyLinkedListNode*cur=llist,*temp=llist;
    while(cur){
        while(temp and temp->data==cur->data){
            temp=temp->next;
        }
        cur->next=temp;
        cur=cur->next;
    }
    return llist;
}

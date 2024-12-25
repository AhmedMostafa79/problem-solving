DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode*before=NULL,*after=NULL,*cur=llist;
   while(cur){
     after=cur->next;
     cur->next=before;
     if(before)
        before->prev=cur;
     before=cur;
     cur=after;
   }
    return before;
}

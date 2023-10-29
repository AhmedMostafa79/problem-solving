SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    SinglyLinkedListNode*cur=head,*after=NULL;
    if(position==0){
        head=head->next;
        delete cur;
        return head;
    }
        
    while(cur!=NULL and position){
        after=cur;
        cur=cur->next;
        position--;
    }
    after->next=cur->next;
    delete cur;
    return head;
}

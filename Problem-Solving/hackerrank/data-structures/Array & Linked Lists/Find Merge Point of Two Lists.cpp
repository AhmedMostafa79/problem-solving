int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode*cur=head1,*cur2=head2;
    int res;
    while(cur2!=NULL){
        cur=head1;
        while(cur and cur!=cur2){
            cur=cur->next;
        }
        if(cur==cur2){
            return  cur2->data;
        }
        cur2=cur2->next;
    }
    return res;
}

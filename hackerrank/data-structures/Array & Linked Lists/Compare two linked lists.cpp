bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
while(head1 and head2 and head1->data==head2->data){
    head1=head1->next;
    head2=head2->next;
}
return head1==NULL and NULL==head2;
}

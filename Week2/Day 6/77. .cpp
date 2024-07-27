void sortList(Node *head) 
{
    Node *ptr = head; 

    while (ptr != NULL) 
    { 
        count[ptr->data] += 1; 
        ptr = ptr->next; 
    } 
 
    int i = 0; 
    ptr = head; 
    { 
        if (count[i] == 0) 
            ++i; 
        else
        { 
            ptr->data = i; 
            --count[i]; 
            ptr = ptr->next; 
        } 
    } 
} 

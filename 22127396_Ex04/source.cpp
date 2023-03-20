#include "header.h"

Node* stringtolist(string str){
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < str.length(); i++)
    {
        int digit = str[i] - '0';

        Node* newnode = new Node(digit);
        if (!head) {
            head = newnode;
            tail = newnode;
        }
        else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = tail->next;
        }
    }
    
    return head;
}

Node* sumof2list(Node* &head1, Node* &tail1, int size1, Node* head2, Node* tail2, int size2)
{
    //assuming the list1 is longer than list2
    int temp = 0;
    Node* cur = tail1;
    while(cur->prev)
    {
        if (!tail2)
        {
            if ((cur->val + temp) > 9)
            {
                cur->val = (cur->val + temp) % 10;
                temp = 1;
            }
            else
            {
                cur->val += temp;
                temp = 0;
            }
            cur = cur->prev;
            continue;
        }
        if (tail2 && (cur->val + tail2->val + temp) > 9)
        {
            cur->val = (cur->val + tail2->val + temp) % 10;
            temp = 1;
        }
        else
        {
            cur->val += (tail2->val + temp);
            temp = 0;
        }

        cur = cur->prev;
        tail2 = tail2->prev;
    }
    //head of the list
    if (cur && tail2)
    {
        if (cur->val + tail2->val + temp > 9)
        {
            cur->val = (cur->val + tail2->val + temp) % 10;
            Node* newnode = new Node(1);
            newnode->next = cur;
            cur->prev = newnode;
            head1 = newnode;
            cur = cur->prev;
        }
        else
            cur->val = cur->val + tail2->val + temp;
    }
    else
    {
        if (cur->val + temp > 9)
        {
            cur->val = (cur->val + temp) % 10;
            Node* newnode = new Node(1);
            newnode->next = cur;
            cur->prev = newnode;
            head1 = newnode;
            cur = cur->prev;
        }
        else
            cur->val += temp;        
    }

    return head1;
}

void sumof2bignumbers(Node* &head1, Node* &head2)
{
    string str1, str2;
    cin>>str1>>str2;

    head1 = stringtolist(str1);
    head2 = stringtolist(str2);
    
    Node* tail1 = head1;
    Node* tail2 = head2;
    int size1 = 0;
    while (tail1->next)
    {
        tail1 = tail1->next;
        size1++;
    }

    int size2 = 0;
    while (tail2->next)
    {
        tail2 = tail2->next;
        size2++;
    }

    if (size1 >= size2)
        head1 = sumof2list(head1, tail1, size1, head2, tail2, size2);
    else
        head1 = sumof2list(head2, tail2, size2, head1, tail1, size1);

}

void outputlist(Node* head)
{
    while (head)
    {
        cout<<head->val;
        head = head->next;
    }
}
#ifndef header04
#define header04

#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int n)
    {
        val = n;
        next = NULL;
        prev = NULL;
    }
};

Node* stringtolist(string str);
Node* sumof2list(Node* &head1, Node* &tail1, int size1, Node* head2, Node* tail2, int size2);
void sumof2bignumbers(Node* &head1, Node* &head2);
void outputlist(Node* head);

#endif
#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void traverse(Node *head)
{

    Node *curr = head;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
}

/**
 * @brief To delete element at the beginning we move the head to head->next and de-allocate the memory for head.
 *
 * Time complexity : O(1)
 * Auxillary space : O(1)
 *
 * @param head
 * @param data
 */
void deleteAtBegin(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked list empty" << endl;
        return;
    }
    Node *head_ref = head;
    head = head->next;
    delete head_ref;
}
int main()
{
    int a;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    traverse(head);
    deleteAtBegin(head);
    traverse(head);

    return 0;
}
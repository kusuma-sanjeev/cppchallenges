#include <iostream>
using namespace std;
class Node
{
    public:
        int value;
        Node *next;

        Node( int v )
        {
            value = v ;
            next = nullptr;
        }
};

class DivideLL {
    public:
        static Node* twoLLFromOne ( Node * head )
        {
            if ( head == nullptr )
                return nullptr;

            Node* slow = head;
            Node* fast = head;

            while ( fast->next != nullptr)
            {
                fast = fast->next; // 1st step
                if(fast->next != nullptr)
                {
                    fast = fast->next; // 2nd step
                    slow = slow->next;
                }
            }

            // slow next will be head of second list
            Node *head2 = slow->next;
            slow->next = nullptr;
            return head2;
        }
};


int main()
{
    Node *head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(7);
    head->next->next->next = new Node(8);

    Node *head2 = DivideLL::twoLLFromOne(head);

    Node *temp = head;
    cout << "List 1 contents " << endl;
    while( temp != nullptr)
    {
        cout << temp->value << endl;
        temp = temp->next;
    }

    cout << " List 2 contents"  << endl;
    temp = head2;
    while ( temp != nullptr)
    {
        cout << temp->value << endl;
        temp =temp->next;
    }

    return 0;


}

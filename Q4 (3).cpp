#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;

    Node(char x) {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

int main() {
    Node* head = new Node('M');
    Node* second = new Node('A');
    Node* third = new Node('D');
    Node* fourth = new Node('A');
    Node* fifth = new Node('M');

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    Node* start = head;
    Node* end = fifth;

    bool palindrome = true;

    while (start != end && start->prev != end) {
        if (start->data != end->data) {
            palindrome = false;
            break;
        }

        start = start->next;
        end = end->prev;
    }

    if (palindrome)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}


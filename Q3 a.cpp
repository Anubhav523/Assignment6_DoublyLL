#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

int main() {
    Node* head = new Node(20);
    head->next = new Node(40);
    head->next->prev = head;
    head->next->next = new Node(60);
    head->next->next->prev = head->next;

    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "Size of Doubly Linked List: " << count;

    return 0;
}

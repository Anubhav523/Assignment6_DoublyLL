#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

int main() {
    Node* head = new Node(20);
    head->next = new Node(40);
    head->next->next = new Node(60);
    head->next->next->next = new Node(80);

    head->next->next->next->next = head;

    int count = 0;
    Node* temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    cout << "Size of Circular Linked List: " << count;

    return 0;
}

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

class CircularList {
    Node* head;

public:
    CircularList() {
        head = NULL;
    }

    void insertFirst(int x) {
        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertLast(int x) {
        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int value, int x) {
        if (head == NULL)
            return;

        Node* temp = head;

        do {
            if (temp->data == value) {
                Node* newNode = new Node(x);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void insertBefore(int value, int x) {
        if (head == NULL)
            return;

        if (head->data == value) {
            insertFirst(x);
            return;
        }

        Node* temp = head;

        while (temp->next != head) {
            if (temp->next->data == value) {
                Node* newNode = new Node(x);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
    }

    void deleteNode(int x) {
        if (head == NULL)
            return;

        Node* temp = head;
        Node* prev = NULL;

        do {
            if (temp->data == x) {
                if (temp == head) {
                    if (head->next == head) {
                        delete head;
                        head = NULL;
                        return;
                    }

                    Node* last = head;

                    while (last->next != head)
                        last = last->next;

                    head = head->next;
                    last->next = head;
                    delete temp;
                    return;
                }

                prev->next = temp->next;
                delete temp;
                return;
            }

            prev = temp;
            temp = temp->next;

        } while (temp != head);
    }

    void search(int x) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        int pos = 1;

        do {
            if (temp->data == x) {
                cout << "Found at position: " << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;

        } while (temp != head);

        cout << "Not found\n";
    }

    void display() {
        if (head == NULL)
            return;

        Node* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main() {
    CircularList list;
    int choice, x, value;

    do {
        cout << "\n1. Insert First";
        cout << "\n2. Insert Last";
        cout << "\n3. Insert After";
        cout << "\n4. Insert Before";
        cout << "\n5. Delete Node";
        cout << "\n6. Search";
        cout << "\n7. Display";
        cout << "\n8. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            list.insertFirst(x);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> x;
            list.insertLast(x);
            break;

        case 3:
            cout << "Enter node value: ";
            cin >> value;
            cout << "Enter new value: ";
            cin >> x;
            list.insertAfter(value, x);
            break;

        case 4:
            cout << "Enter node value: ";
            cin >> value;
            cout << "Enter new value: ";
            cin >> x;
            list.insertBefore(value, x);
            break;

        case 5:
            cout << "Enter node to delete: ";
            cin >> x;
            list.deleteNode(x);
            break;

        case 6:
            cout << "Enter value to search: ";
            cin >> x;
            list.search(x);
            break;

        case 7:
            list.display();
            break;

        case 8:
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 8);

    return 0;
}


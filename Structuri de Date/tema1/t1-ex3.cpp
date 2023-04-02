#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* prev;
    Node* next;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insert(int key) {
        Node* node = new Node;
        node->key = key;

        if (head == NULL) {
            node->prev = NULL;
            node->next = NULL;
            head = node;
            tail = node;
        }
        else {
            node->prev = NULL;
            node->next = head;
            head->prev = node;
            head = node;
        }

        // inserarea semnului opus al key la sfarsitul listei 
        int oppositeKey = -key;
        Node* oppositeNode = new Node;
        oppositeNode->key = oppositeKey;

        oppositeNode->prev = tail;
        oppositeNode->next = NULL;
        tail->next = oppositeNode;
        tail = oppositeNode;
    }
    
    void extract(int key) {
        Node* current = head;
        bool key_found = false;
        while (current != NULL) {
            if (current->key == key) {
                key_found = true;
                break;
            }
        current = current->next;
    }

    if (!key_found) {
        printf("Key not found\n");
        return;
    }

    Node* oppositeNode = NULL;
    if (current->key + current->prev->key == 0) {
        oppositeNode = current->prev;
    } else if (current->key + current->next->key == 0) {
        oppositeNode = current->next;
    }

    if (oppositeNode != NULL) {
        if (head == tail) {
            head = tail = NULL;
        } else if (oppositeNode == head) {
            head = oppositeNode->next;
            head->prev = NULL;
        } else if (oppositeNode == tail) {
            tail = oppositeNode->prev;
            tail->next = NULL;
        } else {
            oppositeNode->prev->next = oppositeNode->next;
            oppositeNode->next->prev = oppositeNode->prev;
        }
        delete oppositeNode;
    }

    if (head == tail) {
        head = tail = NULL;
    } else if (current == head) {
        head = current->next;
        head->prev = NULL;
    } else if (current == tail) {
        tail = current->prev;
        tail->next = NULL;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    delete current;
}

    void print() {
        Node* current = head;

        while (current != NULL) {
            cout << current->key << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    DoubleLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.print(); 
    list.extract(-1);
    list.print(); 
    list.insert(-4);
    list.print(); 
    list.extract(2);
    list.print(); 
    return 0;
}

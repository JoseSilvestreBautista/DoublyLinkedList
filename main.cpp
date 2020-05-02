#include <iostream>

class list {
public:
    struct node {
        int data;
        node *next;
        node *prev;
    };

public:
    node *head = nullptr;
    node *rear = nullptr;

    void insert_front(int element) {

        node *tNode;
        tNode = new node;
        tNode->data = element;

        if (head == nullptr) {
            tNode->next = nullptr;
            tNode->prev = nullptr;
            head = tNode;
            rear = tNode;
        } else {
            tNode->next = nullptr;
            tNode->prev = head;
            head->next = tNode;
            head = tNode;
        }
    }

//    void insert_front(void *element) {
//        node *tNode;
//        tNode = new node;
//
//    }

    void insert_rear(int element) {

        node *tNode;
        tNode = new node;
        tNode->data = element;

        if (rear == nullptr) {
            rear = tNode;
            head = tNode;
            tNode->prev = nullptr;
            tNode->next = nullptr;
        } else {
            tNode->next = rear;
            tNode->prev = nullptr;
            rear->prev = tNode;
            rear = tNode;
        }
    };

    void remove_front_i() {

        if (head == nullptr) {/// no elements
            empty();
            return;
        } else if (head == rear) {/// one element
            node *current;
            current = head;
            head = nullptr;
            rear = nullptr;
            delete current;
        } else { /// two elements
            struct node *current = head;
            head = head->prev;
            head->next = nullptr;
            delete current;

        }

    };

    void remove_rear_i() {

        if (rear == nullptr) {/// no elements
            empty();
            return;
        } else if (rear == head) {/// one element
            node *current;
            current = rear;
            head = nullptr;
            rear = nullptr;
            delete current;
        } else { /// two elements
            node *current;
            current = rear;
            rear = rear->next;
            rear->prev = nullptr;
            delete current;
        }

    };

    int empty() {
        std::cout << "There is nothing" << std::endl;
        return 0;
    };

    void printList() {
        struct node *temp;
        temp = rear;
        while (temp != nullptr) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        puts("");
    }
};


int main() {

    list test;

    int choice;
    while (true) {

        //// Test cases: it builds a small list and then empties the list.

        std::cout << "Choose:\n" << "1. insert to front\n" << "2. insert to rear\n" << "3. Delete front\n"
                  << "4. Delete rear\n" << "5. exit " << std::endl;
        std::cin.clear();
        std::cin >> choice;
        if (choice == 1) {
            int element;
            std::cout << "Enter element" << std::endl;
            std::cin >> element;
            test.insert_front(element);
            test.printList();
        } else if (choice == 2) {
            int element;
            std::cout << "Enter element" << std::endl;
            std::cin >> element;
            test.insert_rear(element);
            test.printList();
        } else if (choice == 3) {
            test.remove_front_i();
            test.printList();
        } else if (choice == 4) {
            test.remove_rear_i();
            test.printList();
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "fuuuuc!!!" << std::endl;
        }
    }
    return 0;

}
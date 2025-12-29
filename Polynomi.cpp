#include <iostream>
using namespace std;

struct Node {
    int pow, coff;
    Node* next;
};

Node* first = nullptr;

// Initialize list
void init() {
    first = nullptr;
}

// Create polynomial list (sorted by power)
Node* create_List(int p, int c) {
    if (first == nullptr) {
        first = new Node{p, c, nullptr};
        return first;
    }

    Node* temp = first;
    Node* prev = nullptr;

    while (temp != nullptr && temp->pow > p) {
        prev = temp;
        temp = temp->next;
    }

    // Insert at beginning
    if (temp == first && first->pow < p) {
        Node* newNode = new Node{p, c, first};
        first = newNode;
    }
    // Insert at end
    else if (temp == nullptr) {
        Node* newNode = new Node{p, c, nullptr};
        prev->next = newNode;
    }
    // Same power → add coefficient
    else if (temp->pow == p) {
        temp->coff += c;
    }
    // Insert in between
    else {
        Node* newNode = new Node{p, c, temp};
        prev->next = newNode;
    }

    return first;
}

// Display polynomial
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "pow = " << temp->pow
             << "\tcoff = " << temp->coff << endl;
        temp = temp->next;
    }
}

// Add two polynomial lists
Node* add_lists(Node* l1, Node* l2) {
    init(); // reset first for result list
    Node* finalList = nullptr;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->pow > l2->pow) {
            finalList = create_List(l1->pow, l1->coff);
            l1 = l1->next;
        }
        else if (l2->pow > l1->pow) {
            finalList = create_List(l2->pow, l2->coff);
            l2 = l2->next;
        }
        else {
            finalList = create_List(l1->pow, l1->coff + l2->coff);
            l1 = l1->next;
            l2 = l2->next;
        }
    }

    while (l1 != nullptr) {
        finalList = create_List(l1->pow, l1->coff);
        l1 = l1->next;
    }

    while (l2 != nullptr) {
        finalList = create_List(l2->pow, l2->coff);
        l2 = l2->next;
    }

    return finalList;
}

int main() {
    Node *l1, *l2, *l3;

    // First polynomial
    init();
    l1 = create_List(2, 4);
    l1 = create_List(5, 7);
    l1 = create_List(4, 6);
    l1 = create_List(7, 9);

    // Second polynomial
    init();
    l2 = create_List(2, 4);
    l2 = create_List(3, 2);
    l2 = create_List(6, 3);
    l2 = create_List(5, 1);

    cout << "Polynomial 1:\n";
    display(l1);

    cout << "\nPolynomial 2:\n";
    display(l2);

    // Add polynomials
    l3 = add_lists(l1, l2);

    cout << "\nSum Polynomial:\n";
    display(l3);

    return 0;
}

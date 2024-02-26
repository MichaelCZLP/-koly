#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node* next;

    // Konstruktor
    Node(int v) : val(v), next(nullptr) {}

    // Vytiskne hodnotu uzlu
    void print_node() {
        cout << val << " ";
    }

    // Vytiskne všechny uzly od tohoto uzlu dále
    void print_LL() {
        Node* current = this;
        while (current != nullptr) {
            current->print_node();
            current = current->next;
        }
        cout << endl;
    }

    // Přidá nový uzel s hodnotou na konec seznamu
    void push_back_val(int v) {
        Node* new_node = new Node(v);
        Node* current = this;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }

    // Vloží nový uzel s hodnotou na zadanou pozici
    void insert_val(int idx, int v) {
        Node* new_node = new Node(v);
        Node* current = this;
        for (int i = 0; i < idx - 1; ++i) {
            if (current->next == nullptr) {
                cerr << "Index out of bounds." << endl;
                return;
            }
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    // Vrátí pointer na uzel na dané pozici
    Node* operator[](int index) {
        Node* current = this;
        for (int i = 0; i < index; ++i) {
            if (current->next == nullptr) {
                cerr << "Index out of bounds." << endl;
                return nullptr;
            }
            current = current->next;
        }
        return current;
    }

    // Odstraní uzel na dané pozici
    void delete_node(int idx) {
        Node* current = this;
        for (int i = 0; i < idx - 1; ++i) {
            if (current->next == nullptr) {
                cerr << "Index out of bounds." << endl;
                return;
            }
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
};

int main()
{
    Node LL(0);

    LL.push_back_val(1);
    LL.push_back_val(2);
    LL.push_back_val(3);

    LL.print_LL();
    LL[1]->print_node();

    LL.insert_val(2, 4);
    LL.delete_node(3);
    LL.print_LL();

    return 0;
}

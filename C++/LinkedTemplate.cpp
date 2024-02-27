#include <iostream>
#include <locale>

// Raději jsem zvolil nový kód pro celý LinkedList

template <typename T>
class Node {
public:
    T data;
    Node* next;

    // Konstruktor
    Node(T newData) : data(newData), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    // Konstruktor
    LinkedList() : head(nullptr) {}

    // Metoda pro přidání prvku na začátek seznamu
    void addFirst(T newData) {
        Node<T>* newNode = new Node<T>(newData);
        newNode->next = head;
        head = newNode;
    }

    // Metoda pro přidání prvku na konec seznamu
    void addLast(T newData) {
        Node<T>* newNode = new Node<T>(newData);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Metoda pro vypsání obsahu seznamu
    void printList() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor
    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    // Smažený sýr
    // Bez práce s daty string je implementace češtiny mnohem snažší
    std::setlocale(LC_ALL, "Czech");

    // Vytvoření instance seznamu pro celá čísla
    LinkedList<int> intList;

    // Přidání prvků
    // Pouze int
    intList.addFirst(3);
    intList.addFirst(2);
    intList.addFirst(1);
    intList.addLast(4);
    intList.addLast(5);

    // Vypsání seznamu
    std::cout << "Seznam celých čísel: ";
    intList.printList();

    return 0;
}

#include <iostream>

// You should use templates when you do not know what type of data will be
// stored in List
template<typename T>
// In Node we store value of a current node and a pointer for next node
struct Node {
    T data;
    Node* nextNode;
};

template<typename T>
// This class is responsible for creating, inserting and deleting nodes or
// values in our List
class List{
private:
    Node<T>* listHead;
    Node<T>* listTail;
public:
    List() :listHead(nullptr), listTail(nullptr) {}
    void createNode(T value);
    void insertValue(T value);
    void insertValueAtPosition(int pos, T value);
    void deleteFirstElement();
    void deleteLastElement();
    void deleteElementAtPosition(int pos);
    void showElementsOfList();
};

template<typename T>
void List<T>::createNode(T value)
{
    Node<T>* tmp = new Node<T>;
    tmp->data = value;
    tmp->nextNode = nullptr;

    if (listHead == nullptr) {
        listHead = tmp;
        listTail = tmp;
        tmp = nullptr;
    } else {
        listTail->nextNode = tmp;
        listTail = tmp;
    }
}

template<typename T>
void List<T>::insertValue(T value)
{
    Node<T>* tmp = new Node<T>;
    tmp->data = value;
    tmp->nextNode = listHead;
    listHead = tmp;
}

template<typename T>
void List<T>::insertValueAtPosition(int pos, T value)
{
    Node<T>* pre = new Node<T>;
    Node<T>* current = new Node<T>;
    Node<T>* tmp = new Node<T>;

    current = listHead;

    for (int i = 1; i < pos; i++) {
        pre = current;
        current = current->nextNode;
    }

    tmp->data = value;
    pre->nextNode = tmp;
    tmp->nextNode = current;
}

template<typename T>
void List<T>::deleteFirstElement()
{
    Node<T>* tmp = new Node<T>;
    tmp = listHead;
    listHead = listHead->nextNode;
    
    delete tmp;
}

template<typename T>
void List<T>::deleteLastElement()
{
    Node<T>* current = new Node<T>;
    Node<T>* previous = new Node<T>;

    current = listHead;

    while (current->nextNode != nullptr) {
        previous = current;
        current = current->nextNode;
    }

    listTail = previous;
    previous->nextNode = nullptr;
    
    delete current;
}

template<typename T>
void List<T>::deleteElementAtPosition(int pos)
{
    Node<T>* current = new Node<T>;
    Node<T>* previous = new Node<T>;

    current = listHead;

    for (int i = 1; i < pos; i++) {
        previous = current;
        current = current->nextNode;
    }
    previous->nextNode = current->nextNode;
}

template<typename T>
void List<T>::showElementsOfList()
{
    Node<T>* tmp = new Node<T>;
    tmp = listHead;

    while (tmp != nullptr) {
        std::cout<<tmp->data<<"\n";
        tmp = tmp->nextNode;
    }
}

int main()
{
    List<int> objList;
    objList.createNode(21);
    objList.createNode(37);
    objList.createNode(14);
    objList.createNode(88);

    objList.showElementsOfList();

    return 0;
}

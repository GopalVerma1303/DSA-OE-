#include <iostream>
using namespace std;

struct Node {
  string data;
  struct Node* next;
  struct Node* prev;
};

void Push(struct Node** head, string data) {
  struct Node* newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  struct Node* temp = *head;
  if (*head == NULL) {
    newNode->prev = NULL;
    *head = newNode;
    return;
  }
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = newNode;
  newNode->prev = temp;
}

void displayList(struct Node* node) {
  struct Node* last;
  while (node != NULL) {
    cout << node->data << " <-> ";
    last = node;
    node = node->next;
  }
  if (node == NULL)
    cout << "NULL\n";
}

int main() {
  struct Node* head = NULL;
  Push(&head, "Pankaj Verma(43)");
  Push(&head, "Manisha Verma(42)");
  Push(&head, "Gopal Verma(19)");
  Push(&head, "Govind Verma(16)");
  displayList(head);
}

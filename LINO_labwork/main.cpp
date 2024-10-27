#include <iostream>

/*
������� ���� 24��1
������� � ������������ �������� ������, ��� ���������������� ������� ������ ����� �����.
������ ������������ ����� ������� - N.
����������� ���������� ������������ LIFO - ��������� ������, ������ ����
�������:
� ��������� ������� � ������� +
� ������� ������� ������� +
� ������� ������� ���������� ������� +
� ������� ����� ������� +
� ������� �����
� ������� ���������
*/

using std::cout;
using std::endl;

struct Queue {
     const int size;
     int length;
     int value;
     Queue* next;
};

Queue* addElement(Queue*, int);
int getElement(Queue**);
void showElements(Queue*);
int queueLength(Queue*);
bool queueIsEmpty(Queue*);
bool queueIsFull(Queue*);

int main() {
     setlocale(LC_ALL, "RUS");

     const int N = 3;
     Queue* newQueue = new Queue(N);
     bool isEmpty = queueIsEmpty(newQueue);
     bool isFull = queueIsFull(newQueue);
     cout << "������� �����? - " << isEmpty << endl;
     cout << "������� ���������? - " << isFull << endl;
     newQueue = addElement(newQueue, 1);
     newQueue = addElement(newQueue, 2);
     newQueue = addElement(newQueue, 3);
     cout << "�������: ";
     showElements(newQueue);
     isFull = queueIsFull(newQueue);
     isEmpty = queueIsEmpty(newQueue);
     cout << "������� �����? - " << isEmpty << endl;
     cout << "������� ���������? - " << isFull << endl;
     int length = queueLength(newQueue);
     cout << "�����: " << length << endl;
     int n1 = getElement(&newQueue);
     cout << "�������: " << n1 << endl;
     cout << "�������: ";
     showElements(newQueue);
     length = queueLength(newQueue);
     cout << "�����: " << length << endl;
     isEmpty = queueIsEmpty(newQueue);
     isFull = queueIsFull(newQueue);
     cout << "������� �����? - " << isEmpty << endl;
     cout << "������� ���������? - " << isFull << endl;
     n1 = getElement(&newQueue);
     n1 = getElement(&newQueue);
     isEmpty = queueIsEmpty(newQueue);
     isFull = queueIsFull(newQueue);
     cout << "�������: ";
     showElements(newQueue);
     cout << "������� �����? - " << isEmpty << endl;
     cout << "������� ���������? - " << isFull << endl;
     n1 = getElement(&newQueue);
     cout << "���� ������� �����, �� �������: " << n1;
     return 0;
}

Queue* addElement(Queue* queue, int value) {
     if (queue->size >= queue->length+1) {
          Queue* newQueue = new Queue(queue->size);
          newQueue->value = value;
          newQueue->next = queue;
          newQueue->length = queue->length + 1;
          return newQueue;
     }
     return queue;
}

int getElement(Queue** queue) {
     if ((*queue)->length > 0) {
          int num = (*queue)->value;
          *queue = (*queue)->next;
          return num;
     }
     return -1e6;
}

void showElements(Queue* queue) {
     while (queue->length > 0) {
          cout << queue->value << " ";
          queue = queue->next;
     }
     cout << endl;
}

int queueLength(Queue* queue) {
     return queue->length;
}

bool queueIsEmpty(Queue* queue) {
     return queue->length == 0;
}

bool queueIsFull(Queue* queue) {
     return queue->length == queue->size;
}
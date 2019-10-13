#include "ProducerConsumer.hpp"
#include <iostream>
using namespace std;

ProducerConsumer::ProducerConsumer() {
  queueEnd = 0;
  queueFront = 0;
}

bool ProducerConsumer::isEmpty() {
  if (queueEnd == queueFront && queue[queueEnd] == "") {
    return true;
  }
  return false;
}

bool ProducerConsumer::isFull() {
  if (queueEnd == queueFront && queue[queueEnd] != "") {
    return true;
  }
  return false;
}

void ProducerConsumer::enqueue(std::string item) {
  if (!isFull()) {
    queue[queueEnd] = item;
    queueEnd++;
    queueEnd = queueEnd % 20;
    counter++;
  } else {
    cout << "Queue full, cannot add new item" << endl;
  }
}

void ProducerConsumer::dequeue() {
  if (!isEmpty()) {
    queue[queueFront] = "";
    queueFront++;
    queueFront = queueFront % 20;
    counter--;
  } else {
    cout << "Queue empty, cannot dequeue an item" << endl;
  }
}

std::string ProducerConsumer::peek() {
  if (!isEmpty()) {
    return queue[queueFront];
  } else {
    cout << "Queue empty, cannot peek" << endl;
    return "";
  }
}

int ProducerConsumer::queueSize() {
  return counter;
}

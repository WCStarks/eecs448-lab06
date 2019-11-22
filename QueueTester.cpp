#include <iostream>
#include "QueueTester.h"


void QueueTester::testIsEmpty() {
  std::cout << "\nTesting isEmpty ... \n";
  std::cout << "-----------------------\n";
  Q = new Queue();

  std::cout << "Test 1) isEmpty returns true for new Queue: ";
  std::cout << (Q->isEmpty() ? "PASS\n" : "FAIL\n");

  for (int i = 0; i < 10; i++) {
    Q->enqueue(i);
  }
  std::cout << "Test 2) isEmpty returns false after items are enqueued: ";
  std::cout << (!Q->isEmpty() ? "PASS\n" : "FAIL\n");

  for (int i = 0; i < 10; i++) {
    Q->dequeue();
  }
  std::cout << "Test 3) isEmpty returns true when all items are dequeued: ";
  std::cout << (Q->isEmpty() ? "PASS\n" : "FAIL\n");

  std::cout << '\n';
  delete Q;

}

void QueueTester::testEnqueue() {
  std::cout << "\nTesting enqueue\n";
  std::cout << "-----------------------\n";
  Q = new Queue();

  Q->enqueue(12);
  std::cout << "Test 1) Queue is not empty after enqueue: ";
  std::cout << (!Q->isEmpty() ? "PASS\n" : "FAIL\n");

  Q->enqueue(27);
  Q->enqueue(3);
  Q->enqueue(86);
  std::cout << "Test 2) Enqueue on nonempty queue does not affect front: ";
  std::cout << ((Q->peekFront() == 12) ? "PASS\n" : "FAIL\n");

  for (int i = 0; i < 3; i++) {
      Q->dequeue();
  }
  std::cout << "Test 3) Most recently enqueued item is added to back: ";
  std::cout << ((Q->peekFront() == 86) ? "PASS\n" : "FAIL\n");
  std::cout << "   a) Enqueue a total 4 items\n";
  std::cout << "   b) Dequeue 3 times\n";
  std::cout << "   c) Verify that peekFront returns the fourth item Queued\n";
  std::cout << '\n';
  Q->dequeue();

  delete Q;
}

void QueueTester::testDequeue() {
  std::cout << "\nTesting dequeue\n";
  std::cout << "-----------------------\n";
  Q = new Queue();

  std::cout << "Test 1) Attempting to dequeue empty queue throws an exception: ";
  try {
    Q->dequeue();
    std::cout << "FAIL\n";
  }
  catch (std::runtime_error e) {
    std::cout << "PASS\n";
  }

  for (int i = 1; i <= 5; i++) {
    Q->enqueue(i);
  }

  Q->dequeue();
  std::cout << "Test 2) Front of queue changes after dequeue: ";
  std::cout << ((Q->peekFront() != 1) ? "PASS\n" : "FAIL\n");

  for (int i = 1; i <= 3; i++) {
    Q->dequeue();
  }
  std::cout << "Test 3) Back of queue unaffected by dequeue: ";
  std::cout << ((Q->peekFront() == 5) ? "PASS\n" : "FAIL\n");
  std::cout << "   a) Enqueue 5 times\n";
  std::cout << "   b) Dequeue 4 times\n";
  std::cout << "   c) Verify that peekFront returns item expected at back\n";

  delete Q;
}

void QueueTester::testPeekFront() {
  std::cout << "\nTesting peekFront\n";
  std::cout << "-----------------------\n";
  Q = new Queue();

  std::cout << "Test 1) calling peekFront() an empty queue throws an exception: ";
  try {
    Q->peekFront();
    std::cout << "FAIL\n";
  }
  catch (std::runtime_error e) {
    std::cout << "PASS\n";
  }

  Q->enqueue(46);
  std::cout << "Test 2) peekFront returns only enqueued item when queue size is 1: ";
  std::cout << ((Q->peekFront() == 46) ? "PASS\n" : "FAIL\n");

  Q->enqueue(2);
  Q->enqueue(-5);
  Q->enqueue(93);
  std::cout << "Test 3) peekFront returns front after additional items are enqueued: ";
  std::cout << ((Q->peekFront() == 46) ? "PASS\n" : "FAIL\n");

  delete Q;
}

void QueueTester::runAllTests() {
  std::cout <<"\nRunning all tests\n";
  this->testIsEmpty();
  this->testEnqueue();
  this->testDequeue();
  this->testPeekFront();

  std::cout << "\nAll tests complete.";
}

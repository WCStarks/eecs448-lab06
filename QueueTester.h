#ifndef QUEUE_TEST_H
#define QUEUE_TEST_H

#include "Queue.h"

class QueueTester {
private:
  Queue* Q;

public:
  void testIsEmpty();
  void testEnqueue();
  void testDequeue();
  void testPeekFront();

  void runAllTests();

};

#endif

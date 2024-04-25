#include "test.h"
test::test() {
  Serial.begin(9600);
  Serial.println("class finished");
};

void test::print() {
  Serial.println("class:test");
}
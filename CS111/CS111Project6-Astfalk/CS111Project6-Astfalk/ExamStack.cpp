#include "ExamStack.h"

ExamStack::ExamStack() {
	head = NULL;
}

ExamStack::~ExamStack() {
	if(!isEmpty())
		std::cout << "Removed " << head->getStudentName();
	while (head != NULL) {
		ExamClassPtr t = head;
		head = head->getNext();
		t->setNext(NULL);
		delete t;
	}
}
void ExamStack::push(ExamClassPtr& examClass) {
	examClass->setNext(head);
	head = examClass;
	examClass = NULL;
}

ExamClassPtr ExamStack::pop() {
	if (isEmpty()) {
		std::cout << "The stack is empty\n";
		return NULL;
	}

	ExamClassPtr temp = head;
	head = head->getNext();
	temp->setNext(NULL);
	return temp;
}
bool ExamStack::isEmpty() {
	if (head == NULL)
		return true;
	return false;
}
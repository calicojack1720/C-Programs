#pragma once

#include<iostream>
#include "ExamClass.h"

class ExamStack
{
private:
	ExamClassPtr head;
public:
	ExamStack();
	~ExamStack(); //prints "Removed " and student name
	void push(ExamClassPtr& examClass);
	ExamClassPtr pop();
	bool isEmpty();
};


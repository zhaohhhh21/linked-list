#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
//---------------------------
struct student
{
	long number;
	float score;
	student* next;
};
//---------------------------
student* head;
//---------------------------
student* getNode()
{
	long number;
	float score;
	cin >> number >> score;
	if (!number)
		return NULL;
	student* p = new student;              //开辟内存
	p->number = number;
	p->score = score;
	p->next = NULL;
	return p;
}
//---------------------------
void Create()
{
	if ((head = getNode()) == 0)
		return;
	for (student* pE = head, *pS; pS = getNode(); pE = pS)
	{
		pE->next = pS;
	}
}
//---------------------------
void Show()
{
	cout << "链表内容为" << endl;
	for (student* temp = head; temp; temp = temp->next)
	{
		cout << temp->number << "," << temp->score << endl;
	}
}
//---------------------------
void Delete(long setNumber)
{
	student* temp = head;
	student* temp_1 = NULL;
	if (temp->number == setNumber)               //删除头节点
	{
		student* Node = head;
		head = head->next;
		delete Node;
		return;
	}
	else
	{
		while (temp)
		{
			if (temp->number == setNumber)
			{
				student* Node = temp;
				temp_1->next = temp->next;
				delete Node;
				return;
			}
			temp_1 = temp;
			temp = temp->next;
		}
	}
}
//---------------------------
void Insert(student& stu)                        //根据Number大小决定顺序
{
	student* Node = new student;
	student* temp = head;
	student* temp_1 = NULL;
	if (stu.number < head->number)
	{
		*(Node) = stu;
		Node->next = head;
		head = Node;
		return;
	}
	while (temp)
	{
		if (stu.number < temp->number)
		{
			*(Node) = stu;
			Node->next = temp;
			temp_1->next = Node;
			return;
		}
		temp_1 = temp;
		temp = temp->next;
	}
}
//---------------------------
void  Reverse()
{
	student* temp = head;
	student* temp_1 = NULL;
	student* Node = new student;
	if (!head->next)
		return;
	while (temp->next)
	{
		temp = temp->next;
	}
	Node->next = temp;
	Node->number = head->number;
	Node->score = head->score;
	temp = head;
	while (head->next)
	{
		while (temp->next)
		{
			temp_1 = temp;
			temp = temp->next;
		}
		temp->next = temp_1;
		if (temp_1 == head)
			temp->next = NULL;
		temp_1->next = NULL;
		temp = head;
		temp_1 = NULL;
	}
	temp = head;
	head = Node;
	delete temp;
}
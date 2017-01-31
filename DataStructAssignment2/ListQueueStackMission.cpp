#include "DetectMemoryLeak.h"
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::stack;
using std::queue;

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    <John Doe>
 *  \date      2015 
 *  \note      <Admin ID>
 */

//*******************************************************************//
// Linked list stuff
//*******************************************************************//
LinkedList::LinkedList() : head_(NULL)
{
	
}

LinkedList::~LinkedList()
{ 
}

void LinkedList::push_front(int data)
{
	Node *newNode = new Node();
	newNode->data = data;
	newNode->next = head_;
	head_ = newNode;
}

void LinkedList::push_back(int data)
{
	Node *curr = head_;
	Node *newNode = new Node();
	newNode->data = data;
	while (curr->next)
		curr = curr->next;
	curr->next = newNode;
	newNode->next = NULL;
}

int LinkedList::pop_front()
{
	if (size() > 0)
	{
		Node** temp = &head_;
		int dataPopped = head_->data;
		head_ = (*temp)->next;
		*temp = NULL; //Setting pointer to NULL so that it can be deleted
		delete *temp;
		return dataPopped;
	}

	else
    return 0;
}

int LinkedList::pop_back()
{
	if (size() > 0)
	{
		Node** end = &head_->next;
		int dataPopped = 0;

		while ((*end)->next != NULL)
			*end = (*end)->next;

		dataPopped = (*end)->data;
		*end = NULL;
		delete *end;
		return dataPopped;
	}

	else
    return 0;
}

void LinkedList::insert_at(int pos, int data)
{    
	if (size() == 0)
	{
		push_front(data);
	}
	else
	{
		Node* prev = head_;
		Node* curr = head_->next;
		Node* newNode = new Node();
		newNode->data = data;
		int count = 0;

		if (pos < 0)
			pos = 0;

		if (pos == 0)
			push_front(data);


		else
		{
			while (curr != NULL)
			{
				count++;
				if (pos == count)
				{
					prev->next = newNode; //Inserting new node if at the right position
					newNode->next = curr;
				}
				else
				{
					prev = curr;
					curr = curr->next;
				}
			}
			if (pos > count) //if the value is over the number of positions
				push_back(data);
		}
	}
	
}

int LinkedList::pop_at(int pos)
{
	Node** prev = &head_;
	Node** curr = &head_->next;
	int nodePopped = 0;
	int count = 0;

	if (pos < 0)
		pos = 0;

	if (pos == 0)
	{
		nodePopped = head_->data;
		pop_front();
		return nodePopped;
	}

	else
	{
		while (*curr != NULL)
		{
			count++;
			if (pos == count)
			{
				nodePopped = (*curr)->data;
				if ((*curr)->next != NULL)
				{
					(*prev)->next = (*curr)->next; //Removing node if at the right position
					*curr = NULL;
					delete *curr;
					return nodePopped;
				}

				else
				{
					pop_back();
				}
			}
			else
			{
				*prev = *curr;
				*curr = (*curr)->next;
			}
		}
		if (pos > count) //if the value is over the number of positions
			return 0;
	}
   
}

size_t LinkedList::size()
{
	Node* curr = head_;
	size_t counter = 0;
	while (curr)
	{
		counter++;
		curr = curr->next;
	}
    return counter;
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue() 
{
}

Queue::~Queue()
{   
}

void Queue::enqueue(int data)
{   
}

int Queue::dequeue()
{
    return 0;
}

size_t Queue::size()
{
    return 0;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack()
{

}

Stack::~Stack()
{
}

void Stack::push(int data)
{
}

int Stack::pop()
{
    return 0;
}

size_t Stack::size()
{
    return 0;
}



// Balanced parenthesis
bool Brackets(const string& input)
{
    return true;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
}
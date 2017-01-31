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
	Node *newNode = new Node(data);
	newNode->next = head_;
	head_ = newNode;
}

void LinkedList::push_back(int data)
{
	Node *curr = head_;
	Node *newNode = new Node(data);
	while (curr->next)
		curr = curr->next;
	curr->next = newNode;
	newNode->next = NULL;
}

int LinkedList::pop_front()
{
	if (head_ != NULL)
	{
		Node* temp = head_->next;
		int dataPopped = head_->data;
		head_ = NULL; //Setting pointer to NULL so that it can be deleted
		delete head_;
		head_ = temp;
		return dataPopped;
	}

	else
    return 0;
}

int LinkedList::pop_back()
{
	if (head_ != NULL)
	{
		Node* nextToEnd = head_;
		Node* lastNode = head_->next;
		int dataPopped = 0;

		if (lastNode == NULL)
		{
			return pop_front();
		}

		else
		{
			while (lastNode->next != NULL)
			{
				nextToEnd = lastNode;
				lastNode = lastNode->next;
			}


			dataPopped = lastNode->data;
			lastNode = NULL;
			delete lastNode;
			nextToEnd->next = NULL;
			return dataPopped;
		}
		
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
		Node* newNode = new Node(data);
		int count = 0;

		if (pos < 0) //For negative positions
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
					prev = curr; //Moving through the list
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

	if (pos < 0) //For negative positions
		pos = 0;

	if (pos == 0)
	{
	    return	pop_front();
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
					return pop_back();
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
	if (head_ == NULL)
		counter = 0;
	else
	{
		while (curr)
		{
			counter++;
			curr = curr->next;
		}
	}

    return counter;
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue() : front_(NULL), back_(NULL)
{
}

Queue::~Queue()
{   
}

void Queue::enqueue(int data)
{   
	Node* newNode = new Node(data);
	if (front_ == NULL) //If this is the first time making a new list
	{
		front_ = newNode;
		back_ = newNode;
	}	
	else
	{
		back_->next = newNode;
		back_ = newNode;
	}

}

int Queue::dequeue()
{
	if (front_ != NULL)
	{
		Node** temp = &front_;
		int dataPopped = front_->data;
		Node* transfer = (*temp)->next;
		*temp = NULL; //Setting pointer to NULL so that it can be deleted
		delete *temp;
		front_ = transfer;
		return dataPopped;
	}
	else
    return 0;
}

size_t Queue::size()
{
	Node* curr = front_;
	size_t counter = 0;
	if (front_ == NULL)
		counter = 0;
	else
	{
		while (curr)
		{
			counter++;
			curr = curr->next;
		}
	}

	return counter;
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
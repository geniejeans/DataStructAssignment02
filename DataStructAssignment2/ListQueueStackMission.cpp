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
{ //Deleting any left over nodes
	if (size() != 0)
	{
		Node *deleteNode = head_;
		while (deleteNode)
		{
			Node *next = deleteNode->next;
			delete deleteNode;
			deleteNode = next;
		}
	}
}

void LinkedList::push_front(int data)
{
	if (head_ != NULL)
	{
		Node *newNode = new Node(data);
		newNode->next = head_;
		head_ = newNode;
	}

}

void LinkedList::push_back(int data)
{
	if (head_ != NULL)
	{
		Node *curr = head_;
		Node *newNode = new Node(data);
		while (curr->next) //Finding last node
			curr = curr->next;
		curr->next = newNode;
		newNode->next = NULL; //Emptying next of last node
	}
}

int LinkedList::pop_front()
{
	if (head_ != NULL)
	{
		Node* temp = head_->next;
		int dataPopped = head_->data; //Value of data popped
		delete head_; //Deleting head
		head_ = temp; //Reassigning head
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
		int dataPopped = 0; //Value of data popped

		if (lastNode == NULL) //Checking for if the list only has one Node
		{
			return pop_front();
		}

		else
		{
			while (lastNode->next != NULL) //Finding the last node
			{
				nextToEnd = lastNode;
				lastNode = lastNode->next;
			}


			dataPopped = lastNode->data;
			delete lastNode; //Deleting the last node
			nextToEnd->next = NULL; //Emptying the last node
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
	{
		return	pop_front();
	}

	else if (pos == 0)
	{
	    return	pop_front();
	}

	else
	{
		if (head_ != NULL)
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
			//Returning values outside of for loop
			if (pos > count) //if the value is over the number of positions
				return 0;
		}
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
	//Deleting any left over nodes
	if (size() != 0)
	{
		Node *deleteNode = front_;
		while (deleteNode)
		{
			Node *next = deleteNode->next;
			delete deleteNode;
			deleteNode = next;
		}
	}
}

void Queue::enqueue(int data)
{   
	Node* newNode = new Node(data);
	if (front_ == NULL) //If this is the first time making a new list
	{
		front_ = newNode; //front and back pointing to same node
		back_ = newNode;
	}	
	else
	{
		back_->next = newNode;
		back_ = newNode; //Moving back pointer to new node
	}

}

int Queue::dequeue()
{
	if (front_ != NULL)
	{
		Node* temp = front_;
		int dataPopped = front_->data;
		Node* transfer = temp->next; //Skipping first node of the queue 
		delete temp; //deleting front node
		front_ = transfer; //Reassigning front node 
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
Stack::Stack() : top_(NULL)
{

}

Stack::~Stack()
{
	//Deleting any left over nodes
	if (size() != 0)
	{
		Node *deleteNode = top_;
		while (deleteNode)
		{
			Node *next = deleteNode->next;
			delete deleteNode;
			deleteNode = next;
		}
	}
}

void Stack::push(int data)
{
	Node *push = new Node(data); //pointer to new data 
	push->next = top_; //setting top as next node 
	top_ = push; //new top assigned
}

int Stack::pop()
{
	if (top_ != NULL)
	{
		Node *nodePop = top_; //Pointing to top
		int nodePopped = top_->data;
		Node *nextNode = nodePop->next; //Ignoring first node of top, pointing to second node
		delete nodePop;
		top_ = nextNode; //Top is reassigned to its next node
		return nodePopped;
	}


	else
    return 0;
}

size_t Stack::size()
{
	Node* curr = top_;
	size_t counter = 0;
	if (top_ == NULL)
		return 0;
	else
	{
		while (curr)
		{
			counter++;
			curr = curr->next;
		}
		return counter;
	}
}



// Balanced parenthesis
bool Brackets(const string& input)
{
	bool result = true;
	vector<char> data; //Contains half of input & turning input string into a char
	vector<char> reversedData;
	int stringSize = input.size();
	int counter = 0; //counter for accessing the vector
	if (stringSize % 2 != 0)
		return false;
	for (int i = 0; i <= (stringSize / 2 - 1); i++) //Only getting half of the input, which is the opening parenthesis 
	{
		if ((input[i] == '(') || (input[i] == '{') || (input[i] == '[') || (input[i] == '<')) //Checking for opening parenthesis only 
			data.push_back(input[i]);
		else
		{
			result = false;
			break;
		}
	}
	//Reversing data
	for (unsigned i = data.size(); i-- > 0;)
	{
		reversedData.push_back(data.at(i));
	}

   for (int i = stringSize / 2; i <= stringSize - 1; i++)
   {
	   //Conditions for if the parenthesis don't match up to its closing parenthesis
	   if ((reversedData.at(counter) == '(') && (input[i] != ')'))
	   {
		   result = false;
		   break;
	   }
	
	   else if ((reversedData.at(counter) == '{') && (input[i] != '}'))
	   {
		   result = false;
		   break;
	   }
	   else if ((reversedData.at(counter) == '[') && (input[i] != ']'))
	   {
		   result = false;
		   break;
	   }
	   else if ((reversedData.at(counter) == '<') && (input[i] != '>'))
	   {
		   result = false;
		   break;
	   }
	   counter++;
   }

   return result;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
	for (std::vector<int>::const_iterator queryNum = queries.begin(); queryNum != queries.end(); ++queryNum) //accessing queries' elements one by one
	{
		int counter = 0;
		for (std::vector<int>::const_iterator dataNum = data.begin(); dataNum != data.end(); ++dataNum) //checking through the whole list of data
		{
			if (*queryNum == *dataNum)
			{
				counter++;
			}
		}
		results.push_back(counter); 
	}
}
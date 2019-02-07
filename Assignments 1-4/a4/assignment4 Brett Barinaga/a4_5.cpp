// Brett Barinaga
// Problem 5
#include <iostream>

using namespace std;

class NumberList
{

private:
	// Declare a structure for the list 
	struct ListNode
	{
		double value; // The value in this node
		struct ListNode *next; // To point to the next node 
	};

	ListNode *head; // List head pointer

public:
	// Constructor
	NumberList()
	{
		head = nullptr;
	}

	// Destructor
	//~NumberList();

	// Linked list operations
	/* void appendNode(double);
	void insertNode(double);
	void deleteNode(double);
	void displayList() const;
	int search(double); */



	void displayList() const {

		ListNode *nodePtr; // To move through the list
		// Position nodePtr at the head of the list. 
		nodePtr = head;
		// While nodePtr points to a node, traverse the list.
		while (nodePtr)
		{

			// Display the value in this node. 
			cout << nodePtr->value << endl;
			// Move to the next node.
			nodePtr = nodePtr->next;
		}
	}

	void appendNode(double num)
	{
		ListNode *newNode; 		// To point to a new node 
		ListNode *nodePtr; 		// To move through the list

		// Allocate a new node and store num there. 
		newNode = new ListNode;
		newNode->value = num;
		newNode->next = nullptr;
		// If there are no nodes in the list 
		// make newNode the first node.

		if (!head)
			head = newNode;
		else 	// Otherwise, insert newNode at end. 
		{
			// Initialize nodePtr to head of list. 
			nodePtr = head;

			// Find the last node in the list. 
			while (nodePtr->next)
				nodePtr = nodePtr->next;
			// Insert newNode as the last node.
			nodePtr->next = newNode;
		}
	}

	int search(double n)
	{
		ListNode *currentNode;
		currentNode = head;
		int counter = 0;

		while (currentNode != nullptr)
		{
			if (currentNode->value == n)
			{
				return counter;
			}
			else
			{
				currentNode = currentNode->next;
				counter++;
			}
		}
		return -1;
	}

	//New Function Added Here
	void deleter(int num)
	{
		ListNode *currentNode; // creates pointer
		ListNode *previousNode = nullptr;
		currentNode = head;
		int counter = 0; // keeps track of position

		if (!head) // If there are no nodes we cant delete anything
			return;
		
		
		if (counter == num) // if our counter (position) is the same as the number specified, we delete the node
		{
			currentNode = head->next;
			delete head;
			head = currentNode;
		}
		else // otherwise we keep checking to see if our current node position is the specified one to be deleted
		{
			currentNode = head;
			
			while (currentNode != nullptr && counter != num)
			{
				previousNode = currentNode;
				currentNode = currentNode->next;
				counter++;
			}

			if (currentNode)
			{
				previousNode->next = currentNode->next;
				delete currentNode;
			}
			if (currentNode == nullptr) // of the given posiiton is greater than the length of the list, it will tell the user and not delete a node.
			{
				cout << "The specified value is greater than the lenght of the list. " << endl;
				return;
			}
		}
	}
};

int main()
{
	NumberList list; 
	list.appendNode(3.3);
	list.appendNode(23.2);
	list.appendNode(9.2);

	int position;
	cout << "Enter position of node to be deleted: ";
	cin >> position;
	
	list.deleter(position);

	list.displayList();

	system("pause");
	return 0;
}
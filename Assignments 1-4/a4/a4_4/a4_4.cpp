// Brett Barinaga
// Problem 4
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

	void deleteNode(double num)
	{

		ListNode *nodePtr; // To traverse the list 
		ListNode *previousNode = nullptr; // The previous node

		// If there are no nodes in the list
		//make newNode the first node
		if (!head)
			return;
		// Determine if the first node is the one.
		if (head->value == num)
		{
			nodePtr = head->next;
			delete head;
			head = nodePtr;
		}
		else
		{
			// Initialize nodePtr to head of list
			nodePtr = head;

			// Skip all nodes whose value member is
			// not equal to num.

			while (nodePtr != nullptr && nodePtr->value != num)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}

			// If nodePtr is not at the end of the list,
			// link the previous node to the node after
			// nodePtr, then delete nodePtr.

			if (nodePtr)
			{
				previousNode->next = nodePtr->next;
				delete nodePtr;
			}
		}
	}

	// New function added here

	int search(double n)
	{
		ListNode *currentNode; // creates pointer
		currentNode = head; // sets pointer to first node
		int counter = 0; // tracks position

		while (currentNode != nullptr) // while we still have a nother pointer left, keep searching
		{
			if (currentNode->value == n) // if the nodes value is the specified value, we are done
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
};

int main()
{
	NumberList list;
	double num;

	list.appendNode(1.3);
	list.appendNode(5.2);
	list.appendNode(22.2);
	
	cout << "Enter search value: ";
	cin >> num;
	cout << num << " is located at index: " << list.search(num) << endl;


	system("pause");
	
	return 0;
}
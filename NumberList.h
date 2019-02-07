// Specification file for the NumberList class
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

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
			{ 	head = nullptr; }

 	// Destructor
		~NumberList();

	// Linked list operations
		void appendNode(double);
		void insertNode(double);
		void deleteNode(double);
		void displayList() const;
};

void NumberList::appendNode(double num)
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

NumberList::~NumberList()
{
	ListNode *nodePtr; // To traverse the list
	ListNode *nextNode; // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}

void NumberList::insertNode(double num)
{
	ListNode *newNode; // A new node
	ListNode *nodePtr; // To traverse the list 
	ListNode *previousNode = nullptr; // The previous node

	//Allocate a new node and store num there
	newNode = new ListNode;
    newNode->value = num;

    // If there are no nodes in the list
    //make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else //otherwise insert newNode
	{
		//Position nodePtr at the head of the list
		nodePtr = head;

		// Initialize previousNode to nullptr. 
		previousNode = nullptr;	

		//Skip all nodes whose value is less than num. 
		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		//Ifthenewnodeistobethe1stinthelist, insert it before all other nodes.
 		if (previousNode == nullptr)
 		{
 			head = newNode;
			newNode->next = nodePtr;
 		}
 		else // Otherwise insert after the previous node.
 		{
 			previousNode->next = newNode;
			newNode->next = nodePtr;
 		}
	}
}		

void NumberList::deleteNode(double num)
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

void NumberList::displayList() const {

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

void NumberList::





#endif

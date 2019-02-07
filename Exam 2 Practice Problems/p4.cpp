NumberList::~NumberList()
{
	ListNode *nodePtr, *nextNode;
	nodePtr = head;
	while (nodePtr != nullptr)
		{
			nextNode = nodePtr->next; 
			nodePtr->next = nullptr; // delete nodePtr;
			nodePtr = nextNode;
		}
} 
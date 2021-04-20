#include<iostream>
#include<vector>
using namespace std;

struct element
{
	int number;
	element* next;
};

int End() {
	int IsRunning;
	cout << "Continue (1) or stop (0)?" << endl;
	cin >> IsRunning;
	return IsRunning;
}

element* getSecondMaxElement(element* head, int second_max)
{
	element* second_max_element;
	second_max_element = head;
	//find element with second max number
	while (second_max_element != NULL) {
		if (second_max_element->number == second_max)
		{
			break;
		}
		else
		{
			second_max_element = second_max_element->next;
		}
	}
	return second_max_element;
}

element* moveSecondLargestElement(element*secondMaxElement, element*head) {
	element* headNext = head->next;
	element* currentElement = head;
	element* previous = NULL;
	element* tail = NULL;
	
	//find previous and last element
	while (currentElement->next != NULL) {
		if (currentElement->next == secondMaxElement) {
			previous = currentElement;
		}
		currentElement = currentElement->next;
	}
	
	//reordering elements
	tail = currentElement;
	tail->next = secondMaxElement;
	previous->next = secondMaxElement->next;
	secondMaxElement->next = NULL;
	
	//find out if the head has changed
	if (secondMaxElement == head) {
		return headNext;
	}
	else {
		return head;
	}
}

std::vector<element*> getAllSecondMaxElements(element* head, int second_max)
{
	vector<element*>allSecondMaxElements;
	element* currentElement = head;
	//if elements number is second max number, put the element in vector
	while (currentElement != NULL) {
		if (currentElement->number == second_max) {
			allSecondMaxElements.push_back(currentElement);
		}
		currentElement = currentElement->next;
	}
	return allSecondMaxElements;
}

element* moveAllSecondMaxElementsToEnd(element* head) {
	int first_max = INT_MIN, second_max = INT_MIN;
	element* p = head;
	//find second max element number
	while (p != NULL) {
		if (p->number > first_max) {
			second_max = first_max;
			first_max = p->number;
		}
		else if (p->number > second_max) {
			second_max = p->number;
		}
		p = p->next;
	}

	//in case there is no second max element, return message
	if (second_max == first_max || second_max == INT_MIN) {
		cout << "Did not find second largest number" << endl;
		return head;
	}

	//find where is second max element
	element* secondMaxElement = getSecondMaxElement(head, second_max);
	
	//create a vector with all second max elements(incase there is more than one)
	vector<element*> allSecondMaxElements = getAllSecondMaxElements(head, second_max);
	
	//move all of the second max elements to the end
	for (auto it = allSecondMaxElements.begin(); it != allSecondMaxElements.end(); ++it) {
		head = moveSecondLargestElement(*it, head);
	}
	return head;
}

void print(element* head) {
	element* p = head;
	while (p != NULL) {
		cout << p->number << " ";
		p = p->next;
	}
	cout << endl;
}

void remove(element*& head) {
	while (head->next != NULL) {
		element* p = head->next;
		delete head;
		head = p;
	}
}
void InsertNewNode(int data, element** head)
{
	element* new_node = new element;
	new_node->number = data;
	new_node->next = NULL;
	
	element* next_pointer = *head;
	while (next_pointer->next != NULL) {
		next_pointer = next_pointer->next;
	}
	//insert new element in the end of the list
	next_pointer->next = new_node;
}
int main() {
	int IsRunning = 1;
	while (IsRunning == 1) {

		vector<int> inputList;
		int inputNumber;

		cout << "Input list of numbers: " << endl;
		cin >> inputNumber;

		element* head = new element;
		//head->number = inputNumber;
		head->next = NULL;
		//inputList.push_back(inputNumber);

		while (inputNumber != 0) {
			inputList.push_back(inputNumber);
			cin >> inputNumber;
		}

		for (int i = 0; i < inputList.size(); i++) {
			InsertNewNode(inputList[i], &head);
		}

		cout << "Your list:" << endl;
		print(head);

		moveAllSecondMaxElementsToEnd(head);

		cout << "New list:" << endl;
		print(head);
		break;
		/*if (secondLargestElement(head) == 1) {
			cout << "Did not find second largest number" << endl;

			remove(head);

			if (End() == 1)
			{continue;}
			else
			{break;}
		}
		else {

		}*/

		/*
		vector<int> inputList;
		int inputNumber, count;
		cout << "Input count of numbers in list: " << endl;
		cin >> count;
		cout << "Input list of numbers: " << endl;
		cin >> inputNumber;

		element* head = new element;
		//head->number = inputNumber;
		head->next = NULL;
		//inputList.push_back(inputNumber);

		while (inputNumber != 0) {
			inputList.push_back(inputNumber);
			cin >> inputNumber;
		}

		for (int i = 0; i < count; i++) {
			cin >> inputNumber;
			InsertNewNode(inputNumber, &head);*/
		}
	}
}



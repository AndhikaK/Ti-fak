#include <iostream>
#include <algorithm>
 
using namespace std;

struct Node {
	char symbol;
	int n;
	Node *next;
};
Node *head, *tail;

bool isEmpty() {
	return head == NULL;
}

void push(int givenN, char givenSymbol) {
	Node *temp;
	temp = new Node;
	temp->n = givenN;
	temp->symbol = givenSymbol;
	temp->next = NULL;
	
	if (isEmpty()) {
		head = tail = temp;
		head->next = NULL;
		tail->next = NULL;
	} else {
		tail->next = temp;
		tail = temp;
		tail->next = NULL;
	}
	cout << "Saved!";
}

void printList() {
	Node *temp;
	temp = head;

	if (isEmpty())
		cout << "Empty";
	else {
		do {
			cout << temp->n << " " << temp->symbol << endl;
			temp = temp->next;
		} while (temp != tail->next);
	}
	cout << endl;
}


void runCode (string input) {
	int huruf[26] = {0};
	
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	
	int i = 0, j;
	while(input[i] != '\0') {
		if(input[i] >='a' && input[i] <= 'z') {
			j = input[i] - 'a';
			++huruf[j];
		}
		++i;
	}
	
	for(i = 0; i < 26; i++) {
		if (huruf[i] > 0) {
			push(huruf[i], char(i+'a'));
		}
	}
	
}

int main () {
	string getInput = "Andhika Kurniawan";
	
	runCode(getInput);

	printList();
	
	
	
	return 0;
}

//Encode.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <queue>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::priority_queue;
const string INPUT_FILE = "input.txt";

struct CharacterNode{
	CharacterNode * next = nullptr;
	char key;
	int frequency = 1;
	bool addedToTree = false;
};

class Node{
public:
	const int freq;
protected:
	Node(int freq): freq(freq) {}
};

class ParentNode : public Node{
public:
	Node * leftChild;
	Node * rightChild;

	ParentNode(Node * lhs, Node * rhs): Node(lhs->freq + rhs->freq), leftChild(lhs), rightChild(rhs) {}
};

class LeafNode : public Node{
public:
	const char nodesCharacter;

	LeafNode(int freq, char nodesCharacter) : Node(freq), nodesCharacter(nodesCharacter) {}
};

class List{
private:
	int size = 0;
	CharacterNode * headptr = nullptr;
public:
	CharacterNode * searchList(char c);
	void countFrequencies(string fileName);
	void insert(char c);
	void insert2(int freq, char c2);
	void displayFrequencies();
	CharacterNode * getMinimumFrequency();
};

CharacterNode* List::searchList(char c) {
	if (headptr == nullptr) {
		return nullptr;
	} else {
		CharacterNode * traverser = headptr;
		while (traverser->key != c) {
			if (traverser->next == nullptr) {
				return nullptr;
			} else {
			traverser = traverser->next;
			}
		}
		return traverser;
	}
}

void List::countFrequencies(string fileName) {
	char c;
	ifstream readfile;
	readfile.open(fileName);
	CharacterNode * temp;

	while (readfile.get(c)) {
		if (c != EOF) {
			temp = searchList(c);
			if (temp != nullptr) {
				temp->frequency++;
			} else {
				insert(c);			
			}
		} else {
			break;
		}
	}
	readfile.close();
}

void List::insert(char c) {
	CharacterNode * temp = new CharacterNode;
	CharacterNode * traverser = headptr;
	temp->key = c;
	
	if (traverser == nullptr) {
		headptr = temp;
		return;
	}
	while(traverser->next != nullptr) {
		traverser = traverser->next;
	}
	traverser->next = temp;
}

void List::insert2(int freq, char c2){
	
}

void List::displayFrequencies() {
	CharacterNode * traverser = headptr;
	while (traverser->next != nullptr) {
		cout << traverser->key << ": " << traverser->frequency << endl;
		traverser = traverser->next;
	}
}

CharacterNode * List::getMinimumFrequency(){
	CharacterNode * minNode = headptr;
	CharacterNode * traverser = headptr;

	while(traverser->next != nullptr) {
		if(traverser->frequency < minNode->frequency && traverser->addedToTree == false){
			minNode = traverser;
		}
		traverser = traverser->next;
	}
	minNode->addedToTree = true;
	return minNode;
}

int List::getAvailableNodes(){
	int numNodes = 0;
	CharacterNode * traverser = headptr;
	while(traverser->next != nullptr){
		if(traverser->addedToTree == false){
			numNodes++;
		}
		traverser = traverser->next;
	}
}

Node * BuildTree(){
	
	priority_queue<


}

int main(){
	List list;
	list.countFrequencies(INPUT_FILE);
	list.displayFrequencies();
}
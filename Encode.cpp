//Encode.cpp

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

const string INPUT_FILE = "input.txt";

struct CharacterNode{
	CharacterNode * next = nullptr;
	char key;
	int frequency = 1;
};

class List{
private:
	int size = 0;
	CharacterNode * headptr = nullptr;
public:
	CharacterNode * searchList(char c);
	void countFrequencies(string fileName);
	void insert(char c);
	void displayFrequencies();
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

void List::displayFrequencies() {
	CharacterNode * traverser = headptr;
	while (traverser->next != nullptr) {
		cout << traverser->key << ": " << traverser->frequency << endl;
		traverser = traverser->next;
	}
}

int main(){
	List list;
	list.countFrequencies(INPUT_FILE);
	list.displayFrequencies();
}
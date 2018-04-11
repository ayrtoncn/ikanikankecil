#include <iostream>
#include "LinkedList.hpp"
using namespace std;

int main(){
	Node<int> *n = new Node<int>(0);
	LinkedList<int> ls = LinkedList<int>();
	cout << "test" << endl;
	for(int i = 0; i < 100; i++){
		ls.add(i);
		cout << ls[i] << endl;
	}
	LinkedList<int> l1 = LinkedList<int>(ls);
	cout << l1[3] << endl;
	LinkedList<int> lj = LinkedList<int>(n);
	cout << lj[0] << endl;
}
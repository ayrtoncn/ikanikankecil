#include <iostream>
#include "LinkedList.hpp"
using namespace std;

int main(){
	Node<int> *n = new Node<int>(2);
	LinkedList<int> ls = LinkedList<int>();
	cout << "test add" << endl;
	for(int i = 0; i < 10; i++){
		ls.add(i);
	}
	cout << "test cout expect 0 - 9" << endl;
	cout << ls;
	cout << "test cctor expect 4" << endl;
	LinkedList<int> l1 = LinkedList<int>(ls);
	cout << l1[4] << endl;
	cout << "test ctor node expect 2" << endl;
	LinkedList<int> lj = LinkedList<int>(n);
	cout << lj[0] << endl;
	cout << "test find expect 3" << endl;
	cout << ls.find(3) << endl;
	cout << "test isEmpty expect 0" << endl;
	cout << ls.isEmpty() << endl;
	cout << "test isEmpty expect 1" << endl;
	cout << (LinkedList<int>()).isEmpty() << endl;
	cout << "test getAmount expect 10" << endl;
	cout << ls.getAmount() << endl;
	cout << "test getNode expect 3" << endl;
	cout << ls.getNode(3)->getVal() << endl;
	cout << "test remove expect 1 3" << endl;
	ls.remove(0);
	ls.remove(2);
	for(int i = 0; i < 2; i++){
		cout << ls[i] << " ";
	}
	cout << endl;
	cout << "test del expect 3 4 6" << endl;
	ls.del(0);
	ls.del(2);
	for(int i = 0; i < 3; i++){
		cout << ls[i] << " ";
	} 
	cout << endl;
	cout << "All function tested" << endl;
}
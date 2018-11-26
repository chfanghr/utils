#include <string>
#include <iostream>

#include "utils.hpp"
using std::string;
using std::cout;
using std::cin;
using std::endl;
using utils::queue;

int main() {
	queue<int> q(0);
	for (auto i = 0; i < 10000; i++)
		q.push(i);
	cout << q.size() << endl;
	for (auto i = 0; i < 10000; i++) {
//		cout << q.front() << " ";
		q.pop();
	}
	cout << q.size() << endl;

	for (auto i = 0; i < 10000; i++)
		q.push(i);
	q.reset();
	cout << q.size() << endl;
	cin.get();
	return 0;
}
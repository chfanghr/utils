#include <string>
#include <iostream>

#include "utils.hpp"

using utils::list;
using std::cout;
using std::cin;
using std::endl;

int main() {
	list<int> l;
	for (auto i = 0; i < 100; i++)
		l.add(i);
	cin.get();
	for (auto i = 0; i < 100; i++)
		l.pop();
	cin.get();
}
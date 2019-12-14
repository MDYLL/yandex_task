#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
struct p {
	int s;
	p* left;
	p* right;
};

void print(p* tail)
{
	while (tail->left->s != 0)
	{
		cout << tail->left->s << endl;
		tail = tail->left;
	}
}
int main() {

	p head, tail, ring;
	head.s = 0;
	head.left = &ring;
	tail.s = 999;
	tail.right = &ring;
	head.right = &tail;
	tail.left = &head;
	unordered_map<int, p*> event;
	vector<p> ev(1000);
	int cur = 0;
	while (true)
	{
		int ss;
		cin >> ss;
		if (event.find(ss) == event.end())
		{
			ev[cur].s = ss;
			ev[cur].right = &tail;
			ev[cur].left = tail.left;
			tail.left->right = &ev[cur];
			tail.left = &ev[cur];
			event[ss] = &ev[cur];
			cur++;
			print(&tail);
		}
		else
		{
			p* cur = event[ss];
			cur->left->right = cur->right;
			cur->right->left = cur->left;
			cur->right = &tail;
			cur->left = tail.left;
			tail.left->right = cur;
			tail.left = cur;
			print(&tail);
		}
	}
	return 0;
}

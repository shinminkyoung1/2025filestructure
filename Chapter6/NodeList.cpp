
#include <iostream>
#include "NodeList.h"

using namespace std;

NodeList::Iterator::Iterator(Node* u)		// constructor from Node*
  { v = u; }

Elem& NodeList::Iterator::operator*()		// reference to the element
  { return v->elem; }
											// compare positions
bool NodeList::Iterator::operator==(const Iterator& p) const
  { return v == p.v; }

bool NodeList::Iterator::operator!=(const Iterator& p) const
  { return v != p.v; }
											// move to next position
NodeList::Iterator& NodeList::Iterator::operator++()
  { v = v->next; return *this; }

// 후위 증가 연산자 
// NodeList::Iterator NodeList::Iterator::operator++(int) {
//     Iterator temp = *this;   // 현재 위치를 저장
//     ++(*this);               // 전위 증가 연산 사용
//     return temp;             // 증가 전 위치 반환
// }
											// move to previous position
NodeList::Iterator& NodeList::Iterator::operator--()
  { v = v->prev; return *this; }

NodeList::NodeList() {						// constructor
    n = 0;									// initially empty
    header = new Node;						// create sentinels
    trailer = new Node;
    header->next = trailer;					// have them point to each other
    trailer->prev = header;
}

int NodeList::size() const 					// list size
    { return n; }

bool NodeList::empty() const 				// is the list empty?
    { return (n == 0); }

NodeList::Iterator NodeList::begin() const	// begin position is first item
    { return Iterator(header->next); }

NodeList::Iterator NodeList::end() const	// end position is just beyond last
    { return Iterator(trailer); }

void NodeList::insert(const NodeList::Iterator& p, const Elem& e) {
  Node* w = p.v;							// p's node
  Node* u = w->prev;						// p's predecessor
  Node* v = new Node;						// new node to insert
  v->elem = e;
  v->next = w;  w->prev = v;				// link in v before w
  v->prev = u;  u->next = v;				// link in v after u
  n++;
}

void NodeList::insertFront(const Elem& e)	// insert at front
  { insert(begin(), e); }

void NodeList::insertBack(const Elem& e)	// insert at rear
  { insert(end(), e); }

void NodeList::erase(const Iterator& p) {	// remove p
  Node* v = p.v;							// node to remove
  Node* w = v->next;						// successor
  Node* u = v->prev;						// predecessor
  u->next = w;  w->prev = u;				// unlink p
  delete v;									// delete this node
  n--;										// one fewer element
}

void NodeList::eraseFront()					// remove first
  { erase(begin()); }

void NodeList::eraseBack()					// remove last
  { erase(--end()); }

void NodeList::display() const {			// display node list
	Iterator t = begin();

	cout << " Node List : ";
	while ( t != end() ) {
		cout << *t << " ";
		++t;
	}
	cout << endl;
}

// // copy constructor
// NodeList::NodeList(const NodeList& other) {
//     n = 0;
//     header = new Node;
//     trailer = new Node;
//     header->next = trailer;
//     trailer->prev = header;

//     for (Iterator t = other.begin(); t != other.end(); ++t) {
//         insertBack(*t);  // 값 복사
//     }
// }

// // assignment operator
// NodeList& NodeList::operator=(const NodeList& other) {
//     if (this != &other) {
//         // 기존 노드 제거
//         while (!empty()) {
//             eraseFront();
//         }

//         // 새로운 리스트 복사
//         for (Iterator it = other.begin(); it != other.end(); ++it) {
//             insertBack(*it);
//         }
//     }
//     return *this;
// }

// // destructor
// NodeList::~NodeList() {
//     while (!empty()) {
//         eraseFront();  // 노드 하나씩 제거
//     }
//     delete header;
//     delete trailer;
// }

// int main() {

// 	NodeList v;
// 	NodeList::Iterator p = v.begin();
// 	NodeList::Iterator q = v.end();

// 	v.insertFront(8);				v.display();
// 	p = v.begin();
// 	cout << " p = " << *p << ", "; 	v.display();
// 	v.insertBack(5);				v.display();
// 	q = p; ++q;
// 	cout << " q = " << *q << ", ";	v.display();
// 	cout << " " << boolalpha << (p == v.begin()) << ", "; v.display();
// 	v.insert(q,3);					v.display();
//     *q = 7;							v.display();
// 	v.insertFront(9);				v.display();
// 	v.eraseBack();					v.display();
// 	v.erase(p);						v.display();
// 	v.eraseFront();					v.display();

//   // copy constructor 테스트
// 	cout << "copy constructor: " << endl;
// 	NodeList copiedList = v;        // 복사 생성자 호출
// 	copiedList.display();

// 	// assignment operator 테스트
// 	cout << "assignment operator: " << endl;
// 	NodeList assignedList;
// 	assignedList.insertBack(100);   // 먼저 다른 값을 넣고
// 	assignedList = copiedList;      // 대입 연산자 호출
// 	assignedList.display();

// 	// destructor 테스트 (destructor 실행을 통한 빈 리스트 대입 수행)
// 	cout << "empty List: " << endl;
// 	NodeList emptyList;
// 	NodeList anotherList;
// 	anotherList.insertBack(1);
// 	anotherList.insertBack(2);
// 	anotherList = emptyList; // 빈 리스트 대입 
// 	anotherList.display();

//   // post-increment operator 테스트
// 	cout << "post-increment operator: " << endl;
// 	NodeList postTestList;
// 	postTestList.insertBack(10);
// 	postTestList.insertBack(20);
// 	postTestList.insertBack(30);

// 	NodeList::Iterator it = postTestList.begin();
// 	cout << "현재 it = " << *it << endl;

// 	NodeList::Iterator result = it++;  // 후위 증가 연산자 호출
// 	cout << "it++ 이전 값(result) = " << *result << endl;
// 	cout << "it++ 이후 값(it) = " << *it << endl;

// 	cout << "전체 리스트 출력: ";
// 	postTestList.display();

// 	return EXIT_SUCCESS;
// }

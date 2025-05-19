#include <iostream>

using namespace std;

template <typename K, typename V>
class OrderedMap {
private:
    struct Node {
        K key;
        V value;
        Node* prev;
        Node* next;
        Node(K k, V v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int n;

public:
    OrderedMap() : head(nullptr), tail(nullptr), n(0) {}

    ~OrderedMap() {
        Node* cur = head;
        while (cur) {
            Node* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }

    int size() const { return n; }

    bool empty() const { return n == 0; }

    void put(const K& key, const V& value) {
        Node* cur = head;

        // 빈 리스트
        if (!cur) {
            head = tail = new Node(key, value);
            n++;
            return;
        }

        while (cur) {
            if (cur->key == key) {
                cur->value = value; // update
                return;
            } else if (cur->key > key) {
                Node* newNode = new Node(key, value);
                newNode->next = cur;
                newNode->prev = cur->prev;
                if (cur->prev) cur->prev->next = newNode;
                else head = newNode;
                cur->prev = newNode;
                n++;
                return;
            }
            cur = cur->next;
        }

        Node* newNode = new Node(key, value); // tail insert
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        n++;
    }

    bool remove(const K& key) {
        Node* cur = head;
        while (cur) {
            if (cur->key == key) {
                if (cur->prev) cur->prev->next = cur->next;
                else head = cur->next;

                if (cur->next) cur->next->prev = cur->prev;
                else tail = cur->prev;

                delete cur;
                n--;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    V* get(const K& key) {
        Node* cur = head;
        while (cur) {
            if (cur->key == key) return &cur->value;
            cur = cur->next;
        }
        return nullptr;
    }

    void display() const {
        Node* cur = head;
        std::cout << "{ ";
        while (cur) {
            std::cout << "(" << cur->key << ", " << cur->value << ") ";
            cur = cur->next;
        }
        std::cout << "}\n";
    }

    Node* firstEntry() const { return head; }
    Node* lastEntry() const { return tail; }

    Node* ceilingEntry(const K& key) const {
        Node* cur = head;
        while (cur) {
            if (cur->key >= key) return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    Node* floorEntry(const K& key) const {
        Node* cur = tail;
        while (cur) {
            if (cur->key <= key) return cur;
            cur = cur->prev;
        }
        return nullptr;
    }

    Node* lowerEntry(const K& key) const {
        Node* cur = tail;
        while (cur) {
            if (cur->key < key) return cur;
            cur = cur->prev;
        }
        return nullptr;
    }

    Node* higherEntry(const K& key) const {
        Node* cur = head;
        while (cur) {
            if (cur->key > key) return cur;
            cur = cur->next;
        }
        return nullptr;
    }
};


int main() {
    OrderedMap<int, std::string> map;
    map.put(10, "A");
    map.put(5, "B");
    map.put(15, "C");
    map.put(7, "D");
    map.put(5, "Updated");

    map.display();  // { (5, Updated) (7, D) (10, A) (15, C) }

    if (auto* v = map.get(7)) 
        cout << "Get 7: " << *v << "\n";

    auto* first = map.firstEntry();
    if (first) 
        cout << "First: (" << first->key << ", " << first->value << ")\n";

    auto* ceil = map.ceilingEntry(8);
    if (ceil) 
        cout << "Ceiling of 8: (" << ceil->key << ", " << ceil->value << ")\n";

    auto* floor = map.floorEntry(8);
    if (floor) 
        cout << "Floor of 8: (" << floor->key << ", " << floor->value << ")\n";

    auto* higher = map.higherEntry(10);
    if (higher) 
        cout << "Higher than 10: (" << higher->key << ", " << higher->value << ")\n";

    auto* lower = map.lowerEntry(10);
    if (lower) 
        cout << "Lower than 10: (" << lower->key << ", " << lower->value << ")\n";

    map.remove(7);
    map.display();  // { (5, Updated) (10, A) (15, C) }

    return 0;
}

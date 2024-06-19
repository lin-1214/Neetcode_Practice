# include <iostream>
# include <vector>
using namespace std;

class LinkedList {
    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        int get(int index) {
            int i = 0;
            Node* cur = head;
            if (cur == nullptr) {
                return -1;
            } else if (index > size - 1) {
                return -1;
            }

            while (cur->next != nullptr && i < index) {
                // printf("cur->val: %d\n", cur->val);
                cur = cur->next;
                i++;
            }
            // printf("prev->val: %d\n", prev->val);
            // printf("index: %d\n", i);
            // printf("cur->val: %d\n", cur->val);
            return cur->val;
        }

        void insertHead(int val) {
            // change head to new node, new node points to old head
            Node* newNode = new Node();
            newNode->val = val;
            newNode->next = head;
            if (tail == nullptr) {
                tail = newNode;
                head = newNode;
            } else {
                head = newNode;
            }

            size++;
        }
        
        void insertTail(int val) {
            // printf("size: %d\n", size);
            // change tail to new node, old tail points to new node
            Node* newNode = new Node();
            newNode->val = val;
            newNode->next = nullptr;
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
            size++;
        }

        bool remove(int index) {
            int i = 0;
            Node* cur = head;
            Node* prev = nullptr;
            if (cur == nullptr) {
                return false;
            } else if (index > size - 1) {
                return false;
            } 

            while (i < index) {
                prev = cur;
                cur = cur->next;
                i++;
            }

            if (prev == nullptr) {
                // only one node
                head = cur->next;
            } else {
                prev->next = cur->next;
                if (cur->next == nullptr) {
                    // remain one node
                    head = prev;
                    tail = prev;
                }
            }
            delete cur;
            size--;
            // printf("size: %d\n", size);
            // printf("head->val: %d\n", head->val);
            return true;
        }

        vector<int> getValues() {
            vector<int> values;
            for (int i = 0; i < size; i++) {
                // get value of each node
                values.push_back(get(i));
            }

            return values;
        }

    private:
        struct Node {
            int val;
            Node* next;
        };
        Node* head;
        Node* tail;
        int size;

};

int main() {
    LinkedList list;
    list.insertTail(1);
    list.insertTail(2);
    list.remove(1);
    list.insertTail(2);
    list.get(1);
    // printf("list.get(1): %d\n", list.get(1));
    list.get(0);
    // printf("list.get(0): %d\n", list.get(0));
    return 0;
}
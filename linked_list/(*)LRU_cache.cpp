class ListNode {
public:
    int key;
    int val;
    ListNode *prev, *next;
    ListNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
    ListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};


class LRUCache {
public:
    int cap;
    unordered_map<int, ListNode*> cache;
    ListNode* left;
    ListNode* right;

    void removeNode(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertNode(ListNode* node) {
        right->prev->next = node;
        node->next = right;
        node->prev = right->prev;
        right->prev = node;
    }

    LRUCache(int capacity) {
        cap = capacity;
        left = new ListNode();
        right = new ListNode();
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        
        ListNode* node = cache[key];

        // move to the recently used position
        removeNode(node);
        insertNode(node);
        return node->val;
        
    }
    
    void put(int key, int value) {
        // node exists, update value and move to the recently used position
        if (cache.find(key)!= cache.end()) {
            removeNode(cache[key]);
        }
        
        ListNode* node = new ListNode(key, value);
        cache[key] = node;
        insertNode(node);

        if (cache.size() > cap) {
            ListNode* lru = left->next;
            removeNode(lru);
            cache.erase(lru->key);
            delete lru;
        }
        
    }
};
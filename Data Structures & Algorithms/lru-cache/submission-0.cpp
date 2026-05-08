class LRUCache {
private:

    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;

    unordered_map<int, Node*> cache;

    Node* head;
    Node* tail;

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if (cache.find(key) == cache.end()) {
            return -1;
        }

        Node* node = cache[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {

        if (cache.find(key) != cache.end()) {

            Node* existing = cache[key];

            remove(existing);

            existing->value = value;

            insert(existing);

            return;
        }

        if (cache.size() == capacity) {

            Node* lru = tail->prev;

            remove(lru);

            cache.erase(lru->key);

            delete lru;
        }

        Node* node = new Node(key, value);

        insert(node);

        cache[key] = node;
    }
};
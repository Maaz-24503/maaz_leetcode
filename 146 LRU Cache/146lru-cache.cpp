class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* left;
        Node* right;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int sz;
    int cap;
    unordered_map<int, Node*> ret;

    LRUCache(int capacity) {
        cap = capacity;
        sz = 0;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        if (ret.find(key) == ret.end())
            return -1;

        Node* node = ret[key];

        if (node != head) {
            if (node == tail) {
                tail = node->left;
                if (tail)
                    tail->right = nullptr;
            } else {
                node->left->right = node->right;
                node->right->left = node->left;
            }

            node->right = head;
            node->left = nullptr;
            if (head)
                head->left = node;
            head = node;
        }

        return node->val;
    }

    void put(int key, int value) {
        if (ret.find(key) != ret.end()) {
            Node* node = ret[key];
            node->val = value;
            get(key);
            return;
        }

        Node* newNode = new Node(key, value);

        if (sz == cap) {
            ret.erase(tail->key);
            if (tail == head) {
                delete tail;
                head = tail = newNode;
            } else {
                Node* prevTail = tail;
                tail = tail->left;
                if (tail)
                    tail->right = nullptr;
                delete prevTail;
            }
        } else {
            sz++;
        }

        newNode->right = head;
        if (head)
            head->left = newNode;
        head = newNode;
        if (!tail)
            tail = newNode;

        ret[key] = newNode;
    }

    void prnt() {
        for (Node* temp = head; temp != nullptr; temp = temp->right)
            cout << temp->key << ": " << temp->val << endl;
        cout << "done" << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
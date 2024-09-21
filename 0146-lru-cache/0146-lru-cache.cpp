class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int capacity;
    unordered_map<int, node*> m;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        temp->prev = newnode;
        head->next = newnode;
        newnode->prev = head;
    }
    void deletenode(node* delnode) {
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
    }
    int get(int key) {
        if (m.find(key) != m.end()) {
            node* temp = m[key];
            int res = temp->val;
            m.erase(key);
            deletenode(temp);
            addnode(temp);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            node* currnode = m[key];
            m.erase(key);
            deletenode(currnode);
        }

        if (m.size() == capacity) {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
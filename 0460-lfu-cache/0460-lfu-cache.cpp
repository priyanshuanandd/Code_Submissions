class LFUCache {
public:
    class node {
    public:
        int key, val, cnt;
        node* next;
        node* prev;
        node(int key, int val) {
            this->key = key;
            this->val = val;
            cnt = 1;
        }
    };

    class list {
    public:
        int size;
        node* head;
        node* tail;
        list() {
            head = new node(0, 0);
            tail = new node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addfront(node* newnode) {
            node* temp = head->next;
            newnode->next = temp;
            newnode->prev = head;
            head->next = newnode;
            temp->prev = newnode;
            size++;
        }

        void removenode(node* delnode) {
            node* delprev = delnode->prev;
            node* delnext = delnode->next;
            delprev->next = delnext;
            delnext->prev = delprev;
            size--;
        }
    };

    map<int, node*> keynode;
    map<int, list*> freqlist;
    int maxsizecache;
    int minfreq;
    int cursize;

    LFUCache(int capacity) {
        maxsizecache = capacity;
        minfreq = 0;
        cursize = 0;
    }

    void updatefreqlistmap(node* currnode) {
        keynode.erase(currnode->key);
        freqlist[currnode->cnt]->removenode(currnode);

        if (currnode->cnt == minfreq && freqlist[currnode->cnt]->size == 0) {
            minfreq++;
        }

        currnode->cnt++;

        if (freqlist[currnode->cnt] == nullptr) {
            freqlist[currnode->cnt] = new list();
        }
        freqlist[currnode->cnt]->addfront(currnode);
        keynode[currnode->key] = currnode;
    }

    int get(int key) {
        if (keynode.find(key) != keynode.end()) {
            node* currnode = keynode[key];
            int value = currnode->val;
            updatefreqlistmap(currnode);
            return value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (maxsizecache == 0) return;

        if (keynode.find(key) != keynode.end()) {
            node* currnode = keynode[key];
            currnode->val = value;
            updatefreqlistmap(currnode);
        } else {
            if (cursize == maxsizecache) {
                list* listwithminfreq = freqlist[minfreq];
                keynode.erase(listwithminfreq->tail->prev->key);
                listwithminfreq->removenode(listwithminfreq->tail->prev);
                cursize--;
            }

            node* newnode = new node(key, value);
            if (freqlist[1] == nullptr) {
                freqlist[1] = new list();
            }
            freqlist[1]->addfront(newnode);
            keynode[key] = newnode;
            cursize++;
            minfreq = 1;
        }
    }
};

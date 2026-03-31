class LRUCache {
public:
    struct Node{
        int key;
        int val;
        struct Node* next;
        struct Node* prev;
        Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    };
    unordered_map<int, Node*> hash;
    struct Node* head = nullptr;
    struct Node* tail = nullptr;
    int length;

    LRUCache(int capacity) {
        length = capacity;
        head = new Node(0, 0);  // dummy head
        tail = new Node(0, 0);  // dummy tail

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) return -1;
        struct Node* cur = hash[key];        
        int ret = cur->val;
            if (tail->prev != cur){
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            cur->prev = tail->prev;
            tail->prev->next = cur;
            cur->next = tail;
            tail->prev = cur;
        }return ret;
    }
    
    void put(int key, int value) {
        struct Node* cur = head;
        if (hash.find(key) == hash.end()){
            struct Node* temp = new Node(key, value);
            temp->val = value;
            temp->key = key;   

            temp->prev = tail->prev;
            temp->next = tail;
            tail->prev->next = temp;
            tail->prev = temp;


            hash[key] = temp;
            int tsize = hash.size();

            if (tsize > length){
                hash.erase(head->next->key);
                struct Node* rem = head->next;
                head->next = head->next->next;
                delete(rem);
                head->next->prev = head;
            }
        }else{//there already exists an entry in the hashmap
            struct Node* temp = hash[key];
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->prev = tail->prev;
            temp->next = tail;
            temp->prev->next = temp;
            tail->prev = temp;
            temp->val = value;
        }
    }
};

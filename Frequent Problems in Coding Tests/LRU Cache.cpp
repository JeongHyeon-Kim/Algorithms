// problem source: https://leetcode.com/problems/lru-cache/
// discussion reference: https://dheldh77.tistory.com/entry/LRU-Cache
// discussion reference2: https://leetcode.com/problems/lru-cache/discuss/1350355/C%2B%2B-Solutions-with-and-without-STL-Linked-List
class LRUCache {
    unordered_map<int, int> map;
    unordered_map<int, list<int>::iterator> bridge;
    list<int> list;
    int cap = 0;

    LRUCache(int capacity) {
        map.clear();
        list.clear();
        cap = capacity;
    }

    void addFront(int key)
    {
        list.push_front(key);
        bridge[key] = list.begin();
    }

    void update(int key)
    {
        list.erase(bridge[key]);
        addFront(key);
    }

    int get(int key) {
        if(!(map.count(key)))
            return -1;
        update(key);
        return map[key];
    }

    void put(int key, int value) {
        if(map.count(key)) {
            update(key);
            map[key] = value;
        } else if(cap > 0) {
            cap--;
            map[key] = value;
            addFront(key);
        } else if(cap == 0) {
            int evict_key = list.back();
            map.erase(evict_key);
            bridge.erase(evict_key);
            list.pop_back();
            addFront(key);
            map[key] = value;
        }
    }

// try code
// private:
//     class Node {
//     public:
//         int stored_key;
//         int stored_value;
//         Node *prev;
//         Node *next;
//         Node(int key, int value) {
//             stored_key = key;
//             stored_value = value;
//             next = nullptr;
//             prev = nullptr;
//         }
//     };
//     unordered_map<int, Node*> map;
//     int stored_capacity;
//     Node *head;
//     Node *tail;
// public:
//     LRUCache(int capacity) {
//         stored_capacity = capacity;
//         head = new Node(0, 0);
//         tail = new Node(0, 0);
//         head->next = tail;
//         tail->prev = head;
//     }
//
//     void remove (Node *node) {
//         node->prev->next = node->next;
//         node->next->prev = node->prev;
//         map.erase(node->stored_key);
//     }
//
//     void insertToHead(Node *node) {
//         head->next->prev = node;
//         node->next = head;
//         node->prev = head;
//         map.insert(make_pair(node->stored_key, node));
//     }
//
//     void put(int key, int value) {
//         Node *node = new Node(key, value);
//         if (map.find(key) != map.end()) {
//             auto it = map.find(key);
//             remove(it->second);
//         } else {
//             if (map.size() >= stored_capacity) {
//                 Node *del = tail->prev;
//                 remove(del);
//             }
//         }
//         insertToHead(node);
//     }
//
//     int get(int key) {
//         if (map.find(key) == map.end())
//             return -1;
//         auto it = map.find(key);
//         Node *node = it->second;
//         remove(node);
//         insertToHead(node);
//         return node->stored_value;
//     }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

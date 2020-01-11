// Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.
//
// Implement these functions in your linked list class:
//
//
// 	get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
// 	addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
// 	addAtTail(val) : Append a node of value val to the last element of the linked list.
// 	addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
// 	deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
//
//
//  
//
// Example:
//
//
// Input: 
// ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
// [[],[1],[3],[1,2],[1],[1],[1]]
// Output:  
// [null,null,null,null,2,null,3]
//
// Explanation:
// MyLinkedList linkedList = new MyLinkedList(); // Initialize empty LinkedList
// linkedList.addAtHead(1);
// linkedList.addAtTail(3);
// linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
// linkedList.get(1);            // returns 2
// linkedList.deleteAtIndex(1);  // now the linked list is 1->3
// linkedList.get(1);            // returns 3
//
//
//  
// Constraints:
//
//
// 	0 <= index,val <= 1000
// 	Please do not use the built-in LinkedList library.
// 	At most 2000 calls will be made to get, addAtHead, addAtTail,  addAtIndex and deleteAtIndex.
//
//


class MyLinkedList {    
    struct node_t {        
        node_t(int val, node_t* prev, node_t* next) : val(val), prev(prev), next(next) {}
        node_t *prev, *next;
        int val;        
    };
    node_t sentinel; // one-past-first/last element
    
    inline void insert_(node_t* prev, int val) {
        auto node = new node_t(val, prev, prev->next);
        prev->next = node->next->prev = node;
    }
    
    inline void erase_(node_t* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
    
    node_t* fetch_(int index) {
        if (index < 0)
            return &sentinel;
        
        node_t* node = sentinel.next;
        for (int i = 0; i < index && node != &sentinel; ++i)
            node = node->next;       
        return node;
    }
    
    inline node_t const * fetch_(int index) const {
        return const_cast<MyLinkedList*>(this)->fetch_(index);
    }
    
public:
    MyLinkedList() : sentinel(0, nullptr, nullptr) {
        sentinel.next = sentinel.prev = &sentinel;
    }
    
    inline int get(int index) const {   
        auto node = fetch_(index);
        return (node == &sentinel) ? -1 : node->val;
    }
    
    inline void addAtHead(int val) {
        insert_(&sentinel, val);
    }
    
	inline void addAtTail(int val) {
        insert_(sentinel.prev, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index <= 0) 
            return addAtHead(val);
        
        auto node = fetch_(index-1);
        if (node != &sentinel)
            insert_(node, val);
    }
    
    void deleteAtIndex(int index) {
        auto node = fetch_(index);
        if (node != &sentinel)
            erase_(node);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

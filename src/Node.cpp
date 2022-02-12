
template<typename T>
Node<T>::Node()
    : next(nullptr)
{
} // default constructor

template<typename T>
Node<T>::Node(const T& item)
    : item(item)
    , next(nullptr) // this makes this new node to be a "tail node"
{
} // constructor for adding an item

template<typename T>
Node<T>::Node(const T& item, Node<T>* nextNodePtr)
    : item(item) // sets the item
    , next(nextNodePtr) // links the node to be in the middle of the chain
{
} // constructor for adding an item at a specific place


template<typename T>
void Node<T>::setItem(const T& newItem){
    item = newItem;
} // sets the item to newItem

template<typename T>
void Node<T>::setNext(Node<T>* nextNodePtr){
    next = nextNodePtr;
} // sets next node pointer

template<typename T>
T Node<T>::getItem() const{
    return item;
} // gets item

template<typename T>
Node<T>* Node<T>::getNext() const{
    return next;
} // gets next node pointer
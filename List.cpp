template<typename T>
List<T>::List(){
    
}


template<typename T>
bool List<T>::isEmpty() const{
    return itemCount == 0;
}

template<typename T>
int List<T>::getLength() const{
    return itemCount;
}

template<typename T>
bool List<T>::insert(int newPosition, const T& newEntry){
    Node<T> newNodePtr = new Node<T>(newEntry, getNodePtr(newPosition));

	if (newPosition == 1) headPtr = newNodePtr; // check if edge case?
	itemCount++;

	return true;
} // inserts newEntry at newPosition

template<typename T>
bool List<T>::remove(int position){
    // save position to delete pointer
	// link the position -1 to position +1
	// ^^ this effectively unlinks the node at position
	// delete the saved node
} // removes entry at position

template<typename T>
void List<T>::clear(){
    while (itemCount > 0){
        remove(itemCount);
        itemCount--;
    } // check if this is the right implementation
} // calls remove "getLength" times

template<typename T>
T List<T>::getEntry(int position) const{
    // iterate through the back from itemCount to the position
}

template<typename T>
T List<T>::replace(int position, const T& newEntry){
    if (insert(getLength(), newEntry)){
		Node<T>* save = getNodePtr(position);
		Node<T>* newNodePtr = getNodePtr(getLength());
		getNodePtr(position) = newNodePtr;
		newNodePtr = save;
	} // check if these go out of scope and if this actually works lmao
	// creates new node at end
	// copies node at position to a save
	// copies newNode to position
	// copies save to newNode's old position (at end)
} // replaces position with newEntry

template<typename T>
List<T>::~ListInterface(){
    
}

template<typename T>
Node<T>* List<T>::getNodePtr(int position){

} // gets the node pointer at the position
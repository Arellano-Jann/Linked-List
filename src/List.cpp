template<typename T>
List<T>::List(){
    itemCount = 0;
    headPtr = nullptr;
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
    Node<T>* newNodePtr = new Node<T>(newEntry, getNodePtr(newPosition));

	if (newPosition == 1){
		newNodePtr->setNext(headPtr); // not sure if necessary because getNodePtr(1) essentially does this same thing???
		headPtr = newNodePtr; // check if the stars align
	} 
	itemCount++;

	return true;
} // inserts newEntry at newPosition

template<typename T>
bool List<T>::remove(int position){
	Node<T>* save = getNodePtr(position); // save position to delete pointer
	Node<T>* beforePosition = getNodePtr(position - 1);
	Node<T>* afterPosition = getNodePtr(position)->getNext();
	beforePosition->setNext(afterPosition); // is this valid??
	// link the position -1 to position +1
	// ^^ this effectively unlinks the node at position
	delete save; // delete the saved node

	return true;
} // removes entry at position

template<typename T>
void List<T>::clear(){
    while (itemCount > 0){
        remove(itemCount);
        itemCount--;
    } // check if this is the right implementation
} // calls remove "itemCount" times

template<typename T>
T List<T>::getEntry(int position) const{
	return getNodePtr(position)->getItem();
}

template<typename T>
T List<T>::replace(int position, const T& newEntry){
    if (insert(getLength() + 1, newEntry)){	// creates new node at end
		Node<T>* save = getNodePtr(position); // copies node at position to a save
		Node<T>* newNodePtr = getNodePtr(getLength()); // copies newNode to an easy to use variable
		getNodePtr(position) = newNodePtr; // copies newNode to position
		newNodePtr = save; // copies the save to newNodes old position (at the end)
	}
	return getEntry(getLength()); // check if these go out of scope and if this actually works lmao
} // replaces position with newEntry

template<typename T>
List<T>::~ListInterface(){
	clear();
}

template<typename T>
Node<T>* List<T>::getNodePtr(int position){
	Node<T>* currentPtr = headPtr; // sets the currentPtr to the start of the list
	if (checkValidity(position)){
		for (int i = 0; i < position; i++){ // might need i = 1
			currentPtr = currentPtr->getNext; // sets currentPtr to be the next pointer so it can iterate through it
		}
	} //checks if valid
	return currentPtr;
	
} // gets the node pointer at the position

template<typename T>
bool List<T>::checkValidity(int position){
	if (position > 0 && position < itemCount){
		return true;
	}
	return false;
}
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
	if (newPosition == 1 || checkValidity(newPosition - 1)){
		Node<T>* newNodePtr = new Node<T>(newEntry, getNodePtr(newPosition));

		if (newPosition == 1){
			newNodePtr->setNext(headPtr); // not sure if necessary because getNodePtr(1) essentially does this same thing???
			headPtr = newNodePtr; // check if the stars align
		}
		else{ getNodePtr(newPosition - 1)->setNext(newNodePtr); }
		itemCount++;

		return true;
	}
	return false;
} // inserts newEntry at newPosition

template<typename T>
bool List<T>::remove(int position){
	if (checkValidity(position)){
		Node<T>* save = getNodePtr(position); // save position to delete pointer
		if (position == 1){
			headPtr = getNodePtr(position)->getNext();

		}
		else{
			Node<T>* beforePosition = getNodePtr(position - 1);
			Node<T>* afterPosition = getNodePtr(position)->getNext();
			beforePosition->setNext(afterPosition); // is this valid??
			// link the position -1 to position +1
			// ^^ this effectively unlinks the node at position
		}
		delete save; // delete the saved node
		itemCount--;
		return true;
	}
	return false;
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
	if (checkValidity(position)){
		// std::cout << "in the if state";
		return getNodePtr(position)->getItem();
	}
	// std::cout << "out of the if state";
	return nullptr;
}

template<typename T>
T List<T>::replace(int position, const T& newEntry){
	if (checkValidity(position)){ // somewhat broken
		if (checkValidity(position)){ // somewhat broken
    			Node<T>* save = getNodePtr(position);
    			T item = save->getItem();
    			getNodePtr(position)->setItem(newEntry);
    			return item;
		}
	return nullptr;

} // replaces position with newEntry

template<typename T>
List<T>::~List(){
	clear();
}

template<typename T>
Node<T>* List<T>::getNodePtr(int position) const{
	Node<T>* currentPtr = headPtr; // sets the currentPtr to the start of the list
	if (checkValidity(position)){
		for (int i = 0; i < position-1; i++){
			currentPtr = currentPtr->getNext(); // sets currentPtr to be the next pointer so it can iterate through it
		}
		return currentPtr;
	} //checks if valid
	// else if (position == 0) return currentPtr;
	return nullptr;
	
} // gets the node pointer at the position

template<typename T>
bool List<T>::checkValidity(int position) const{
	if (position > 0 && position <= itemCount){
		return true;
	}
	return false;
}

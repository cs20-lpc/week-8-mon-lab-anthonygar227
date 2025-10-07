template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    // TODO
    if (i <= 0){
        i = 100;
    }
    buffer = new T[i];
    maxSize = i;
    this->length = 0;
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    // TODO
    delete[] buffer;
    buffer = nullptr;
    maxSize = 0;
    this->length = 0;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    // TODO
    maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    if (maxSize > 0){
        buffer = new T[maxSize];
    } else {
        buffer = nullptr;
    }
    int i = 0;
    while (i < this->length) {
        buffer[i] = copyObj.buffer[i];
        i++;
    }
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    // TODO
    if (isEmpty()){
        throw string("Cannot peek an empty stack");
    }
    return buffer [this->length - 1];
}

template <typename T>
void ArrayStack<T>::pop() {
    // TODO
    if (isEmpty()){
        throw string("Cannot pop from an empty stack");
    }
    this->length--;
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    // TODO
    if (isFull()){
        throw string("Cannot push to a full stack");
    }
    buffer[this->length++] = elem;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TODO
    if (isEmpty()){
        throw string("Cannot rotate an empty stack");
    }
    if (this->length <= 1) {
        return;
    }

    if (dir == Stack<T>::RIGHT){
        T top = buffer[this->length - 1];
        int i = this->length - 1;
        while (i > 0) {
            buffer[i] = buffer[i - 1];
            i--;
        }
        buffer[0] = top;
    } else {
        T bottom = buffer[0];
        int i = 0;
        while (i < this->length - 1){
            buffer[i] = buffer[i + 1];
            i++;
        }
        buffer[this->length - 1] = bottom;
    }
}


template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}


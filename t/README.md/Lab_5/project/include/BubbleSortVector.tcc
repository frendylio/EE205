template <typename T>
void BubbleSortVector<T>::sort() {
    // Lookup the bubble sort algorithm online.
    //
    // The algorithm is so-named "bubble sort" because
    // lesser valued elements "bubble up" to the "top" (front)
    // of the array/container/sequence.
    //
    // You'll have to perform a lot of swaps for the algorithm.
    //
    // You are free to write your own swap helper function
    // if you so desire.
// void bubble <t>::sort(int n)

    int i = 1;
    while (i < this->size()) {
        int j = i;
        while (j > 0 && (*this)[j-1] > (*this)[j]) {
            T temp = (*this)[j];
            (*this)[j] = (*this)[j-1];
            (*this)[j-1] = temp;    
            j = j-1;
        }
        i = i+1;
    }
}

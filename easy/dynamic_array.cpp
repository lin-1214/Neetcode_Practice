class DynamicArray {
    public:
        DynamicArray(int capacity) {
            this->capacity = capacity;
            this->size = 0;
            this->arr = new int[capacity];
        }

        int get(int i) {
            return arr[i];
        }

        void set(int i, int n) {
            arr[i] = n;
        }

        void pushback(int n) {
            if (size == capacity) {
                resize();
            }
            arr[size++] = n;
        }

        int popback() {
            if (size > 0) size--;       // size should be greater than 0
            return arr[size];
        }

        void resize() {
            // double the capacity, delete origin array, create new array with double capacity
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }

        int getSize() {
            return size;
        }

        int getCapacity() {
            return capacity;
        }
    
    private:
        int* arr;
        int size;
        int capacity;
};

//in java this is called arraylist
// in c++ this is called vector

class GrowArray {
private:
    int* data;
    int used;
    int capacity;
    void grow() {
        //double each time!
    }
    void checkGrow() {
        if (used == capacity)
            grow();
    }
public:
    void addEnd(int v){
        checkGrow();
    }
}
#include <vector>
using namespace std;

class Heap
{
    public:
    void insert(int value);
    void remove(int index_to_remove);
    void heapify(int index);
    void print();

    private:
    vector<int> values;
};


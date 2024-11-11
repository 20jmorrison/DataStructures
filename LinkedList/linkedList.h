class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
    };

    public:
    LinkedList();
    void insert_at_index(int value, int index);
    void remove_at_index(int index);
    int size();
    void print();

    private:
    int num_nodes;
    Node *head;
    void insert_into_empty(Node*& node_to_insert);
    void insert_at_beginning(Node*& node_to_insert);
    void insert_at_end(Node*& node_to_insert);
    void remove_only_node();
    void remove_at_beginning();
    void remove_at_end();

};
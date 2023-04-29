template<typename T>
class Node{
    public:
    T data;
    Node* next;
    Node(T data){
        this->data=data;
        next=nullptr;
    }
    ~Node(){
        delete next;
    }
};
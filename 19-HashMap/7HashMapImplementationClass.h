#include<string>
using namespace std;

template<typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key ,V value){
        this->key=key;
        this->value=value;
        next=nullptr;
    }
    ~MapNode(){
        delete next;
    }
};

template<typename V>
class ourmap{
    MapNode<V>** buckets;
    int count;
    int numBuckets;

    public:
    ourmap(){
        count=0;
        numBuckets=5;
        buckets=new MapNode<V>*[numBuckets];
        for(int i=0;i<numBuckets;i++){
            buckets[i]=nullptr;
        }
    }
    ~ourmap(){
        for(int i=0;i<numBuckets;i++){
            delete  buckets[i];
        }
        delete [] buckets;
    }

    int size(){
        return count;
    }

    V getValue(string key){
        int bucketIndex = getBucketIndex(key);

        MapNode<V>* head = buckets[bucketIndex];
        while(head!=nullptr){
            if(head->key==key){
                return head->value;
            }
            head =head->next;
        }
        return 0;
    }
    private:
    int getBucketIndex(string key){
        int hashCode =0;

        int currentCoeff=1;

        for(int i=key.length()-1;i>=0;i--){
            hashCode+=key[i]*currentCoeff;
            hashCode=hashCode % numBuckets;

            currentCoeff*=37;
            currentCoeff=currentCoeff % numBuckets;

        }
        return hashCode;
    }

    void rehash(){
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[2*numBuckets];
        for(int i=0;i<2*numBuckets;i++){
            buckets[i]=nullptr;
        }

        int oldBucketCount = numBuckets;
        numBuckets*=2;
        count=0;

        for(int i=0;i<oldBucketCount;i++){
            MapNode<V>* head = temp[i];
            while(head!=nullptr){
                string key=head->key;
                V value=head->value;
                insert(key,value);
                head=head->next;
            }
        }
        for(int i=0;i<oldBucketCount;i++){
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp;
    }
    public:
    double getLoadFactor(){
        return (1.0*count)/numBuckets;
    }
    void insert(string key,V value){
        int bucketIndex = getBucketIndex(key);

        MapNode<V>* head = buckets[bucketIndex];
        while(head!=nullptr){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V>* node = new MapNode<V>(key,value);
        node->next = head;
        buckets[bucketIndex]=node;
        count++;
        double loadFactor = (1.0*count)/numBuckets;
        if(loadFactor>0.7){
            rehash();
        }

    }

    V remove(string key){
        int bucketIndex = getBucketIndex(key);

        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* pre =NULL;
        while(head!=NULL){
            if(head->key==key){
                if(pre==NULL){
                    buckets[bucketIndex]=head->next;
                }else{
                    pre->next=head->next;
                }
                V value=head->value;
                head->next = nullptr;
                delete head;
                count--;
                return value;
            }
            pre=head;
            head=head->next;
        }
        return 0;
    }
};
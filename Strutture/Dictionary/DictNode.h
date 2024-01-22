#ifndef DICTNODE_H
#define DICTNODE_H


template <typename Key, typename Value > class Dict;

template <typename Key, typename Value>
class DictNode{

    private:
        Key key;
        Value value;
        DictNode<Key, Value>* left;
        DictNode<Key,Value>* right;
        DictNode<Key, Value>* parent;
        friend class Dict<Key,Value>;

    public: 
        DictNode(const Key& k, const Value& v, DictNode<Key,Value>* l = nullptr, DictNode<Key,Value>* r = nullptr, DictNode<Key,Value>* p = nullptr): value{v}, key{k},
        left{l}, right{r}, parent{p} {}
        
        

};



#endif
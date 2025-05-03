class Trie{
private:
    struct Node{
        vector<Node*>v;
        vector<int>id;
        Node(){
            v = vector<Node*>(26);
        }
    };
    Node*root;
    void destroy(Node* p){
        for(int j = 0;j < 26;j++){
            if(p->v[j] !=nullptr)destroy(p->v[j]);
        }
        delete p;
    }
public:
    Trie(){
        root = new Node();
    }
    ~Trie(){
        destroy(root);
    }
    void insert(const string&s,int idx){
        Node*tmp = root;
        for(auto&ch : s){
            if(tmp->v[ch - 'a'] == nullptr){
                tmp->v[ch - 'a'] = new Node();
            }
            tmp = tmp->v[ch - 'a'];
            tmp->id.push_back(idx);
        }
        tmp->id.pop_back();
    }
    vector<int> get(const string&s){
        Node*tmp = root;
        for(auto&ch : s){
            if(tmp->v[ch - 'a'] == nullptr)return {};
            tmp = tmp->v[ch - 'a'];
        }
        return tmp->id;
    }
};

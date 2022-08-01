class SingleObj {
public:
    static SingleObj* instance();
private:
    SingleObj();
    ~SingleObj();
    SingleObj(const SingleObj& a);
    SingleObj& operator=(const SingleObj& a);
};

//SingleObj* SingleObj::instance() {
//    static SingleObj obj;
//    return &obj;
//}

SingleObj* SingleObj::instance() {
    static SingleObj* obj = new SingleObj;
    return obj;
}
#include <iostream>
#include <memory>

using std::cout,std::endl;

struct Student {
    std::string _id;
    std::string _name;
};

class SmartPointer {
    Student* _data {nullptr};
    explicit SmartPointer(Student* data) : _data(data) {}
public:
    Student* get() {return _data;}
    static SmartPointer make_smartpointer() {
        cout << "Allocating new student" << endl;
        return SmartPointer(new Student());
    }
    SmartPointer(SmartPointer&& ptr) noexcept {
        _data = ptr._data;
        ptr._data = nullptr;
    }
    Student* operator->() noexcept { return _data;}
    bool operator==(Student* s) {return _data == s;}
    ~SmartPointer() {
        if (_data) cout << "Deallocating student" << endl;
        delete _data;
    }
};

int main() {
    auto print = [](auto& desc, auto& s) {
        cout << desc << s->_name << " (" << s->_id << ")" << endl;
    };
    {
        // regular pointers
        auto s = new Student {"W111222","john"};
        print("OLD PTR: ",s);

        delete s;
    }
    cout << "------------------" << endl;
    {
        // Custom smart pointer
        auto sp1 = SmartPointer::make_smartpointer();
        sp1->_id = "W222333";
        sp1->_name = "Jane";
        print("ORIGINAL: ",sp1);

        // Borrow a reference to the data
        auto student = sp1.get();
        print("REFERENCED: ",student);

        // Give ownership to another veriable
        auto sp2 = std::move(sp1);
        print("MOVED: ",sp2);

        auto s = (sp1 == nullptr) ? "EMPTY" : sp1->_name + " (" + sp1->_id + ")";
        cout << "ILLEGAL: " << s << endl;
    }
    cout << "------------------" << endl;
    {
        // STL version
        auto up1 = std::make_unique<Student>();
        up1->_id = "W444555";
        up1->_name = "Jake";
        print("UNIQUE: ", up1);

        // Reference the object
        auto student = up1.get();
        print("REFERENCED: ",student);

        // Give ownership
        auto up2 = std::move(up1);
        print("MOVED: ",up2);
    }


    return 0;
}
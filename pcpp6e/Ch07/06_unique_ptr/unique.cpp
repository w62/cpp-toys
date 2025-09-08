import std;

using namespace std;

class Simple {
 private:
  /* data */
 public:
  Simple(/* args */) { println("Simple constructor called."); }
  void go() { println("青春agogo"); }
  ~Simple() { println("Simple destructor called."); }
  void setValue(int value) {m_value = value;};
  void getValue() {println("Value is {}", m_value);}
  private:
   int m_value {10};
};

void processData(Simple* simple);

void notLeaky() {
  auto mySimpleSmartPtr{make_unique<Simple>()};
  mySimpleSmartPtr->go();
  processData(mySimpleSmartPtr.get());
  mySimpleSmartPtr.reset();
}

unique_ptr<Simple> create (int value){
    auto ptr {make_unique<Simple>()};
    ptr->setValue(value);
    return ptr;
}

void processData(Simple* simple) { simple->go(); }
int main() {
  notLeaky();
  auto mySimpleSmartPtr{make_unique<Simple>()};
  Simple* simple{mySimpleSmartPtr.release()};
  delete simple;
  simple = nullptr;

  Simple* mySimple{new Simple{}};
  shared_ptr<Simple> smartPtr1{mySimple};
 // shared_ptr<Simple> smartPtr2{mySimple};

 auto mS {create(30)};

 mS->getValue();
 println("歡樂今宵再會。");
}
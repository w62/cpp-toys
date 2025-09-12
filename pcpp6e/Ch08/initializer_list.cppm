export module initializer_list;
import std;
using namespace std;

export class EvenSequence {
 public:
  EvenSequence(initializer_list<double> values);
  void print() const;

 private:
  vector<double> m_sequence;
};
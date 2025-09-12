module initializer_list;

using namespace std;

 EvenSequence::EvenSequence (initializer_list<double> values){

  if (values.size() % 2 != 0) {
throw invalid_argument { "initializer_list should "
"contain even number of elements." };
}
m_sequence.reserve(values.size());
for (const auto& value : values) {
m_sequence.push_back(value);
}
 }

  void EvenSequence::print() const {
    for (const auto& value : m_sequence){
      std::print("{}, ", value);
    }
    std::println("");
  }
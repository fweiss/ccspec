#include <iomanip>
#include <sstream>
#include "ccspec/support/inspect.h"

namespace ccspec {
namespace support {

using std::ios;
using std::ios_base;
using std::ostringstream;
using std::string;
using std::streambuf;
using std::ostream;
using std::setprecision;

string inspect(char val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

// [issue-8] since uint8_t is an unsigned char, we need to force
// ostringstream to use numerical value
string inspect(unsigned char val) {
  ostringstream ss;
  ss << static_cast<int>(val);
  return ss.str();
}

string inspect(bool val) {
  ostringstream ss;
  ss << std::boolalpha << val;
  return ss.str();
}

string inspect(short val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

string inspect(unsigned short val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

string inspect(int val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

string inspect(unsigned int val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

string inspect(long val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

string inspect(unsigned long val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

string inspect(long long val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

string inspect(unsigned long long val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

string inspect(float val) {
  ostringstream ss;
  ss << setprecision(5) << val;
  return ss.str();
}

string inspect(double val) {
  ostringstream ss;
  ss << setprecision(15) << val;
  return ss.str();
}

string inspect(long double val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

// issue-12, don't rely on operator<<(void*) to print pointer values
// as it may not be portable across different platforms
string inspect(void* val) {
  ostringstream ss;
  ss << std::showbase << std::hex << reinterpret_cast<uintptr_t>(val);
  return ss.str();
}

string inspect(const char* s) {
  return string(s);
}

string inspect(const string& s) {
  return s;
}

}  // namespace support
}  // namespace ccspec

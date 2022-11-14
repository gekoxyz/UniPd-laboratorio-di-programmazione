#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(const string& s);
bool is_palindrome(const char s[], int length);
bool is_palindrome(const char* first, const char* last);

int main() {
  cout << "metodo 1:" << endl;
  cout << "boh " << is_palindrome("boh") << endl;
  cout << "itopinonavevanonipoti " << is_palindrome("itopinonavevanonipoti") << endl;
  cout << endl;
  cout << "metodo 2:" << endl;
  string temp = "boh";
  cout << "boh " << is_palindrome(temp.c_str(), temp.length()) << endl;
  temp = "itopinonavevanonipoti";
  cout << "itopinonavevanonipoti " << is_palindrome(temp.c_str(), temp.length()) << endl;
  cout << endl;
  cout << "metodo 3:" << endl;
  string s = "boh";
  cout << "boh " << is_palindrome(&s[0], &s[s.length()]) << endl;
  s = "itopinonavevanonipoti";
  cout << "itopinonavevanonipoti " << is_palindrome(&s[0], &s[s.length()]) << endl;
  cout << endl;
  return 0;
}

bool is_palindrome(const string& s) {
  for (int i = 0; i < (s.length()/2); i++) {
    // cout << s[i] << " " << s[s.length() - i - 1] << endl;
    if (s[i] != s[s.length() - i - 1]) return false;
  }
  return true;
}

bool is_palindrome(const char s[], int length) {
  for (int i = 0; i < length/2; i++) {
    if (s[i] != s[length - i - 1]) return false;
  }
  return true;
}

bool is_palindrome(const char* first, const char* last) {
  int length = (last - first) / sizeof(char);
  // cout << "lunghezza della stringa: " << (last - first) / sizeof(char) << endl;
  for (int i = 0; i < (length/2); i++) {
    // cout << first[i] << " " << last[-i-1] << endl;
    if (first[i] != last[-i-1]) return false;
  }
  return true;
}

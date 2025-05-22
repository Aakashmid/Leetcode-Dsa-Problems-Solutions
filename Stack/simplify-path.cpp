/*
Problem Statement:
Given a string path, which is an absolute path (starting with '/') to a file or directory in a Unix-style file system,
convert it to the simplified canonical path.

Approach:
1. Use a vector as stack to store directories
2. Split path by '/' and process each component:
   - Ignore empty and '.' components
   - Pop from stack for '..'
   - Push valid directory names
3. Build final path from stack components
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
  string simplifyPath(string path) {
      vector<string> stack;
      string currentDir;
    
      // Split path into components
      for (char c : path + '/') {
          if (c == '/') {
              if (currentDir == "..") {
                  if (!stack.empty()) {
                      stack.pop_back();
                  }
              }
              else if (!currentDir.empty() && currentDir != ".") {
                  stack.push_back(currentDir);
              }
              currentDir.clear();
          }
          else {
              currentDir += c;
          }
      }
    
      // Build canonical path
      if (stack.empty()) {
          return "/";
      }
    
      string result = "";
      for (const string& dir : stack) {
          result += "/" + dir;
      }
    
      return result;
  }
int main()
{
    string path = "/a/./b/../../c/";
    cout << simplifyPath(path) << endl;
}
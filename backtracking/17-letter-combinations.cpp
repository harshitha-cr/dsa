#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> letterCombinations(string digits) {
  vector<string> ans{""};
  unordered_map<char, string> keepad{{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                     {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                     {'8', "tuv"}, {'9', "wxyz"}};

  vector<string> result = {""};

  /*
  Process each digit in the digits string
  - for each exisiting string in result, append a letter from respective keepad
  string.
  */

  // for each loop best use case.
  for (char digit : digits) {
    string letters = keepad.at(digit);

    // Temporary vector to store new combinations
    vector<string> newCombinations;

    for (const string &existingCombination : result) {
      for (char letter : letters) {
        newCombinations.push_back(existingCombination + letter);
      }
    }

    // Replace result with the new combinations
    result = move(newCombinations);
  }

  return result;
}

int main() {
  vector<string> ans{"as", "", "fg"};
  // for (int i = 0; i < ans.size(); i++)
  // {
  //   string f = ans[i];
  //   string add = "kay";
  //   cout << f + add << endl;
  // }
}
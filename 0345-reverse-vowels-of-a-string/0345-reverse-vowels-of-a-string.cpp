#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
       
        unordered_set<char> vowels = {
            'a','e','i','o','u','A','E','I','O','U'
        };
        
        int n = s.size();
        int i = 0;
        int j = n - 1;
        
     
        while (i < j) {
            bool isLeftVowel = (vowels.find(s[i]) != vowels.end());
            bool isRightVowel = (vowels.find(s[j]) != vowels.end());
            
           
            if (isLeftVowel && isRightVowel) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
           
            else if (!isLeftVowel) {
                i++;
            }
            
            else if (!isRightVowel) { 
                j--;
            }
        }
        
        return s;
    }
};
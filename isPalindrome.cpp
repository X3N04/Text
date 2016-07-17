/*
 * isPalindrome.cpp
 * Daniel Salazar
 * 7/14/16
 * Prints 1 if string is a palindrome
 * Prints 0 if string isn't a palindrome
 */
#include<iostream>
#include<string>
bool isPalindrome(std::string s)
{
   if(s.empty() || s.length() == 1)
      return true;
   else if(s[0] == s[s.length() - 1])
      return isPalindrome(s.substr(1, s.length() - 2));
   else
      return false;
}
int main()
{
   std::string s = "tattattat";
   std::cout << isPalindrome(s) << std::endl;
   s = "erhmehgerd";
   std::cout << isPalindrome(s) << std::endl;
   return 0;
}


#include<iostream>
#include<string>

int main()
{
	std::string s;
	int count = 0;
	bool word = false;
	std::cout << "Enter a string: ";
	std::getline(std::cin, s);
	for (int i = 0; s.length() != 0 && i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
			word = true;
		if (word && (s[i] == ' ' && s[i+1] != ' ' || i == s.length() - 1))
			count++;
	}
	std::cout << "\nString\"" << s << "\" has " << count << " word(s) in it." << std::endl;
	system("pause");
	return 0;
}
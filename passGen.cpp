#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
int main()
{
	std::string uppercaseLetters[26][2] = { {"A", "0"}, {"B", "0"}, {"C", "0"}, {"D", "0"}, {"E", "0"}, {"F", "0"}, {"G", "0"}, \
		{"H", "0"}, {"I", "0"}, {"J", "0"}, {"K", "0"}, {"L", "0"}, {"M", "0"}, {"N", "0"}, {"O", "0"}, {"P", "0"}, {"Q", "0"}, \
		{"R", "0"}, {"S", "0"}, {"T", "0"}, {"U", "0"}, {"V", "0"}, {"W", "0"}, {"X", "0"}, {"Y", "0"}, {"Z", "0"}
	};
	std::string lowercaseLetters[26][2] = { {"a", "0"}, {"b", "0"}, {"c", "0"}, {"d", "0"}, {"e", "0"}, {"f", "0"}, {"g", "0"}, \
		{"h", "0"}, {"i", "0"}, {"j", "0"}, {"k", "0"}, {"l", "0"}, {"m", "0"}, {"n", "0"}, {"o", "0"}, {"p", "0"}, {"q", "0"},
		{"r", "0"}, {"s", "0"}, {"t", "0"}, {"u", "0"}, {"v", "0"}, {"w", "0"}, {"x", "0"}, {"y", "0"}, {"z", "0"}
	};
	std::string numbers[10][2] = { {"0", "0"}, {"1", "0"}, {"2", "0"}, {"3", "0"}, {"4", "0"}, {"5", "0"}, {"6", "0"}, \
		{"7", "0"}, {"8", "0"}, {"9", "0"}
	};
	std::string symbols[32][2] = { {"`", "0"}, {"~", "0"}, {"!", "0"}, {"@", "0"}, {"#", "0"}, {"$", "0"}, {"%", "0"}, {"^", "0"}, \
		{"&", "0"}, {"*", "0"}, {"(", "0"}, {")", "0"}, {"_", "0"}, {"-", "0"}, {"+", "0"}, {"=", "0"}, {"{", "0"}, {"}", "0"}, \
		{"[", "0"}, {"]", "0"}, {"\\", "0"}, {"|", "0"}, {":", "0"}, {";", "0"}, {"\"", "0"}, {"'", "0"}, {"<", "0"}, {">", "0"}, \
		{",", "0"}, {".", "0"}, {"?", "0"}, {"/", "0"}
	};
	srand (time(0));
	int len, countC = 0, countN = 0, countS = 0;
	bool finished = false;
	std::string password = "";
	// Prompt user for length
	cout << "Enter length of password." << endl;
	cin >> len;
	int *array = new int[len];
	while (!finished)
	{
		for (int i = 0; i < len; ++i)
		{
			array[i] = rand() % 3;
			if (i != 0)
				while (array[i - 1] == array[i])
					array[i] = rand() % 4;
		}
		for (int j = 0; j < len; ++j)
		{
			int type = array[j], character;
			bool correct = false;
			if (type == 0 || type == 1)
			{
				while (!correct)
				{
					character = rand() % 25;
					if (uppercaseLetters[character][1] != "1" ||
					        lowercaseLetters[character][1] != "1")
					{
						password.append((type == 0) ? (uppercaseLetters[character][0]) : \
						                (lowercaseLetters[character][0]));
						uppercaseLetters[character][1] = "1";
						lowercaseLetters[character][1] = "1";
						correct = true;
					}
				}
				++countC;
			}
			else if (type == 2)
			{
				while (!correct)
				{
					character = rand() % 9;
					if (numbers[character][1] != "1")
					{
						password.append(numbers[character][0]);
						numbers[character][1] = "1";
						correct = true;
					}
				}
				++countN;
			}
			else
			{
				while (!correct)
				{
					character = rand() % 31;
					if (symbols[character][1] != "1")
					{
						password.append(symbols[character][0]);
						symbols[character][1] = "1";
						correct = true;
					}
				}
				++countS;
			}
		}
		if (countN && countC && countS)
		{
			finished = true;
		}
		else
			password = "";
	}
	cout << password;
	delete[] array;
	return 0;
}


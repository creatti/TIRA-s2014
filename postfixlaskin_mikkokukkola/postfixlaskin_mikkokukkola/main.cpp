// Postfixlaskin
#include "Stack.h"

int main(int argc, char* argv[])
/*
Post: The program has executed simple arithmetic
commands entered by the user.
Uses: The class Stack and the functions
introduction, instructions, do_command, and get_command.
*/
{

	Stack stored_numbers;
	stored_numbers.introduction();
	stored_numbers.instructions();

	if (argc > 1)
	{
		for (int i = 1; i < argc; ++i) {
			string arg = argv[i];

			if (arg == "-p")
			{
				while (stored_numbers.do_command(stored_numbers.get_command(), stored_numbers))
				{
					cout << ".." << endl;
				}
			}
		}
	}
	else
		stored_numbers.new_interface(stored_numbers);

	system("pause");
	return 0;
}
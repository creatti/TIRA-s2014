#include "Stack.h"
#include <String>

Stack::Stack()
/* Pre: None.
Post: The stack is initialized to be empty. */
{
	count = 0;
}


Error_code Stack::push(const Stack_entry &item)
/*
Pre:  None.
Post: If the Stack is not full, item is added to the top
of the Stack.  If the Stack is full,
an Error_code of overflow is returned and the Stack is left unchanged.
*/

{
	Error_code outcome = success;
	if (count >= maxstack)
		outcome = overflow;
	else
		entry[count++] = item;
	return outcome;
}


Error_code Stack::pop()
/*
Pre:  None.
Post: If the Stack is not empty, the top of
the Stack is removed.  If the Stack
is empty, an Error_code of underflow is returned.
*/

{
	Error_code outcome = success;
	if (count == 0)
		outcome = underflow;
	else --count;
	return outcome;
}


Error_code Stack::top(Stack_entry &item) const
/*
Pre:  None.
Post: If the Stack is not empty, the top of
the Stack is returned in item.  If the Stack
is empty an Error_code of underflow is returned.
*/

{
	Error_code outcome = success;
	if (count == 0)
		outcome = underflow;
	else
		item = entry[count - 1];
	return outcome;
}

bool Stack::empty() const
/* Pre: None.
Post: If the Stack is empty, true is returned. Otherwise false is returned. */
{
	bool outcome = true;
	if (count > 0) outcome = false;
	return outcome;
}

char Stack::get_command()
{
	char command;
	bool waiting = true;
	cout << "Select command and press <Enter>:";

	while (waiting) {
		cin >> command;
		command = tolower(command);
		if (command == '?' || command == '=' || command == '+' ||
			command == '-' || command == '*' || command == '/' ||
			command == 'x' || command == 's' || command == 'a' ||
			command == 'q') waiting = false;


		else {
			cout << "Please enter a valid command:" << endl
				<< "[?]push to stack   [=]print top" << endl
				<< "[+] [-] [*] [/] [x] [s] [a]   are arithmetic operations" << endl
				<< "[Q]uit." << endl;
		}
	}
	return command;
}

bool Stack::do_command(char command, Stack &numbers)
/*
Pre:  The first parameter specifies a valid calculator command.
Post: The command specified by the first parameter
has been applied to the Stack of numbers given by the second parameter.
A result of true is returned unless command == 'q'.
Uses: The class Stack.
*/

{
	double p, q;
	switch (command) {
	case '?':
		cout << "Enter a real number: " << flush;
		cin >> p;
		if (numbers.push(p) == overflow)
			cout << "Warning: Stack full, lost number" << endl;
		break;

	case '=':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else
			cout << p << endl;
		break;

	case '+':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}

			else {
				numbers.pop();
				if (numbers.push(q + p) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
			}
		}
		break;

	case '-':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}
			else {
				numbers.pop();
				if (numbers.push(q - p) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
			}
		}
		break;

	case '*':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}
			else {
				numbers.pop();
				if (numbers.push(q * p) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
			}
		}
		break;

	case '/':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}
			else {
				numbers.pop();
				if (numbers.push(q / p) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
			}
		}
		break;

	case 'x':		// 2. piste
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}
			else{
				numbers.pop();
				numbers.push(p);
				numbers.push(q);
			}
		}
		break;

	case 's':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}
			else{
				numbers.sum(numbers);
			}
		}
		break;

	case 'a':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}
			else{
				numbers.average(numbers);
			}
		}
		break;

	case '%':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}
			else {
				numbers.pop();
				if (numbers.push(fmod(q,p)) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
			}
		}
		break;

	case '^':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			numbers.pop();
			if (numbers.top(q) == underflow) {
				cout << "Stack has just one entry" << endl;
				numbers.push(p);
			}
			else {
				numbers.pop();
				if (numbers.push(pow(q,p)) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
			}
		}
		break;

	case 'v':
		if (numbers.top(p) == underflow)
			cout << "Stack empty" << endl;
		else {
			numbers.pop();
				numbers.pop();
				if (numbers.push(sqrt(p)) == overflow)
					cout << "Warning: Stack full, lost result" << endl;
		}
		break;

	case 'q':
		cout << "Calculation finished.\n";
		return false;
	}
	return true;
}

void Stack::introduction()
{
	cout << "T\x84m\x84 on postfix laskin, Harjoitusty\x94 1 (Mikko Kukkola)" << endl;
}
void Stack::instructions()
{
	cout << "Katotaan miten kay" << endl;
}

void Stack::sum(Stack &numbers)	// kolmen pisteen työvaihe (kaikkien lukujen summa)
{
	double var = 0;
	double result = 0;
	while (!numbers.empty())
	{
		numbers.top(var);
		numbers.pop();
		result += var;
	}
	numbers.push(result);
}

void Stack::average(Stack &numbers)	// neljän pisteen työvaihe (keskiarvo)
{
	double var = 0;
	double result = 0;
	int size = count;
	while (!numbers.empty())
	{
		numbers.top(var);
		numbers.pop();
		result += var;
	}
	result = result / size;
	numbers.push(result);
}

void Stack::new_interface(Stack &numbers) // viiden pisteen työvaihe
{
	bool end = false;
	while (end == false)
	{
		string input;
		getline(cin, input);

		int length = input.length();

		for (int i = 0; i < length; i++)
		{
			int kerroin = 0;
			double luku = 0;
			int x = 1;
			if (input[i] == '0' || input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4' || input[i] == '5' || input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9')
			{
				while (input[i + x] == '0' || input[i + x] == '1' || input[i + x] == '2' || input[i + x] == '3' || input[i + x] == '4' || input[i + x] == '5' || input[i + x] == '6' || input[i + x] == '7' || input[i + x] == '8' || input[i + x] == '9')
				{
					kerroin++;
					x++;
				}

				x = 0;
				double temp = 0;
				if (kerroin >= 1)
				{
						temp = atof(input.c_str() + (i + x));
						luku = temp;
						x++;
				}
				else
					luku = atof(input.c_str() + (i));
				numbers.push(luku);
			}
			else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == 'x' || input[i] == 's' || input[i] == 'a' || input[i] == '%' || input[i] == '^' || input[i] == 'v')
			{
				numbers.do_command(input[i], numbers);
			}
			else if (input[i] == 'q')
				end = true;
			else
				;
			i += kerroin;
		}
		if(end == false)
			numbers.do_command('=', numbers);
	}
	cout << "Calculation finished.\n";
}
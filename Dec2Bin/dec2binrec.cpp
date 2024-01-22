#include <iostream>
using std::cin;
using std::cout;



// Decimal to binary conversion
// using recursion
int find(int decimal_number)
{
	if (decimal_number == 0)
		return 0;
	else
		return (decimal_number % 2 + 10 * find(decimal_number / 2));
}

// Driver code
int main()
{
    int decimal_number;
    cout << "insert the number: " ; 
	cin >> decimal_number;
	cout << find(decimal_number);
	return 0;
}
// This code is contributed by shivanisinghss2110

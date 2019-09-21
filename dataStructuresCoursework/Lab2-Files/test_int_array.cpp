#include "terrible_dynamic_size_array_unsorted1.h"

using namespace std;

int errors = 0;

int main()
{
	int_array arraytest;
	init(arraytest);
	if(arraytest.count==0 && arraytest.data != nullptr)
	{
		cout<<"Empty array created (correct)"<<endl;
	}
	else
	{
		cout<<"Error in array creation (error)"<<endl;
		errors++;
	}

	// test clear
	clear(arraytest);
	if(arraytest.count==0)
	{
		cout<<"Array cleared of data (correct)"<<endl;
	}
	else
	{
		cout<<"Error in clear function (error)"<<endl;
		errors++;
	}

	// test adding numbers 0,2,4,...24
	for(unsigned int i=0;i<25;i+=2)
	{
		if(arraytest.count < arraytest.DEFAULT_CAPACITY)
		{
			add(arraytest,i);
			print(arraytest);
		}
		else
		{
			add(arraytest,i);
			print(arraytest);
		}
	}

	// test numbers added to right place in array
	if(arraytest.data[1] == 2)
	{
		cout << "Adding test 1 passed (correct)" << endl;
	}
	else
	{
		cout << "Adding wrong, number in wrong place (error)" << endl;
		errors++;
	}

	for(unsigned int i=1;i<25;i+=2)
	{
		if(arraytest.count < arraytest.DEFAULT_CAPACITY)
		{
			add(arraytest,i);
			print(arraytest);
		}
		else
		{
			add(arraytest,i);
			print(arraytest);
		}
	}

	// test resize function
	if(arraytest.capacity == 2*arraytest.DEFAULT_CAPACITY)
	{
		cout<<"Resize function works properly"<<endl;
	}
	else
	{
		cout<<"Resize not working properly (error)"<<endl;
		errors++;
	}

	// test 'contains' function
	if(contains(arraytest,6))
	{
		cout<<"Number 6 present in Array"<<endl;
	}
	else
	{
		cout<<"Number 6 not in Array: Contains not working properly (error)"<<endl;
		errors++;
	}
	if(contains(arraytest,30))
	{
		cout<<"Number 30 present in Array: Contains not working properly (error)"<<endl;
		errors++;
	}
	else
	{
		cout<<"Number 30 not in Array"<<endl;
	}
	if(remove(arraytest,23) && arraytest.count == 24)
	{
		cout<<"Number 23 removed from Array"<<endl;
	}
	else
	{
		cout<<"Number 23 not in Array error in remove (error)"<<endl;
		errors++;
	}
	if(remove(arraytest,24) && arraytest.count == 23)
	{
		cout<<"Number 24 removed from Array"<<endl;
	}
	else
	{
		cout<<"Number 24 not in Array error in remove (error)"<<endl;
		errors++;
	}
	if(remove(arraytest,0) && arraytest.count == 22)
	{
		cout<<"Number 0 removed from Array"<<endl;
	}
	else
	{
		cout<<"Number 0 not in Array error in remove (error)"<<endl;
		errors++;
	}
	if(remove(arraytest,35))
	{
		cout<<"Error in remove function (error)"<<endl;
		errors++;
	}
	else
	{
		cout<<"Number not in Array"<<endl;
	}
	destr(arraytest);
	if(arraytest.data == nullptr)
	{
		cout<<"Array destroyed"<<endl;
	}
	else
	{
		cout<<"Error in destroy (error)"<<endl;
		errors++;
	}

	if(errors)
	{
		cout << "\n " << errors <<
						" tests failed, errors present!" << endl;
	}
	else
	{
		cout << "\nCONGRATS, WORKING PROGRAM!!!" << endl;
	}

	return 0;
}

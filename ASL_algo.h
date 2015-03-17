#include <iostream>
using namespace std;

int total_nodes = 0;
int e[2];         // global array for storing the entry values for both lines
int x[2];         // global array for storing the exit values for both lines
int a[2][50];     // global array to store station time for both lines
int t[2][50];     // global array to store transaction time for both lines
int f1[50];       // global array to store values for line 1
int f2[50];       // global array to store values for line 2
int l[2][50];      // storing the optimal path
int le;
int q;
void print_all_stations();

void fastest_way_algo()
{
	int fe;
	f1[0] = e[0] + a[0][0]; // storing first value for line 1
	f2[0] = e[1] + a[1][0]; // storing first value for line 2
	int j;

	// for each station checking the values and storing the optimal station number and line number
	for (j = 1; j<total_nodes; ++j)
	{
		if ((f1[j - 1] + a[0][j]) <= (f2[j - 1] + t[1][j - 1] + a[0][j]))
		{
			f1[j] = f1[j - 1] + a[0][j];
			l[0][j] = 1;
		}
		else
		{
			f1[j] = f2[j - 1] + t[1][j - 1] + a[0][j];
			l[0][j] = 2;
		}
		if ((f2[j - 1] + a[1][j]) <= (f1[j - 1] + t[0][j - 1] + a[1][j]))
		{
			f2[j] = f2[j - 1] + a[1][j];
			l[1][j] = 2;
		}
		else
		{
			f2[j] = f1[j - 1] + t[0][j - 1] + a[1][j];
			l[1][j] = 1;
		}
	}
	if ((f1[total_nodes - 1] + x[0]) <= (f2[total_nodes - 1] + x[1]))
	{
		
		le = 1;
	}
	else
	{
		
		le = 2;
	}
	
	q = le;
	cout << "*******Optimal path found is*******\n";

	for (j = 1; j<total_nodes; ++j)
	{
		q = l[q - 1][j];
		cout << "line ";
		cout << q;
		cout << " station ";
		cout << j;
		cout << "\n";
	}
	q = le;
	cout << "line "<<q<< " station "<<total_nodes<<endl;
	
	
}


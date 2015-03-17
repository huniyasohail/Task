#include"ASL_algo.h"
int main(){

	cout << "********************Assembly Line Scheduling********************\n";
	cout << "\n\n \t //////****Number of nodes in both lines****//////\n";
	cin >> total_nodes;
	cout << "\n\n \t////// ENTRY VALUES OF LINE//////****\n";
	for (int i = 0; i < 2; i++){
		cin >> x[i];

	}
	cout << "\n\n \t////// EXIT VALUES OF LINE//////****\n";
	for (int i = 0; i < 2; i++){
		cin >> e[i];
	}

	cout << "\n\nLINE 1 STATION TIME\n";
	for (int i = 0; i < total_nodes; i++){
		cin >> a[0][i];
	}
	cout << "\n\nLINE 2 STATION TIME\n";
	for (int i = 0; i < total_nodes; i++){
		cin >> a[1][i];
	}

	cout << "\n\n LINE 1 TRANSFER TIME\n";
	for (int i = 0; i < total_nodes-1; i++){
		cin >> a[0][i];
	}
	cout << "\n\n LINE 2 TRANSFER TIME\n";
	for (int i = 0; i < total_nodes-1; i++){
		cin >> a[1][i];
	}

	fastest_way_algo();
	int total_cost;
	q = 1;
	cout << "\n\n^^^^^^For Path^^^^^^ ";
	cout << q;
	cout << "\n";
	int j=0;
	while(j<total_nodes)
	//found path for line 1
	{
		cout << "S[";
		cout << q;
		cout << "][";
		cout << j + 1;
		cout << "]=";
		cout << f1[j];
		cout << "    ";
		j++;
	}
	total_cost = f1[total_nodes - 1] + x[0];
	cout << "Total Cost ";
	cout << total_cost;
	cout << "\n";

	q = 2;
	cout << "\n\n^^^^^^For Path^^^^^^ ";//found path for line 2
	cout << q;
	cout << "\n";
	 j=0;
	while(j<total_nodes){
	
		cout << "S[";
		cout << q;
		cout << "][";
		cout << j + 1;
		cout << "]=";
		cout << f2[j];
		cout << "    ";
		j++;
	}
	total_cost = f2[total_nodes - 1] + x[1];
	cout << "Total Cost ";
	cout << total_cost;
	cout << "\n";

	getchar();
	getchar();
	return 0;

}

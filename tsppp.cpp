#include <list>   
#include <iostream>   
using namespace std ;   

typedef list<int> LISTINT;   

LISTINT listAnother;   
LISTINT list_result;   

int d[4][4]={{0,2,9,99999},{1,0,6,4},{99999,7,0,8},{6,3,99999,0}}; //  
int matrix_length=4;   

int getPath(int n,LISTINT list_org)   
{   

	LISTINT::iterator i;   

	int minValue;   
	if(n==1)  
	{   
		i=list_org.begin();   
		minValue= d[*i-1][0];   
		if(list_org.size()==matrix_length-1)  
		{   
			list_result=list_org;   
		}   
	}   
	else  
	{   
		int temp;   
		i=list_org.begin();   
		temp=*i;   
		list_org.erase(i);   
		i=list_org.begin();   
		minValue=d[temp-1][*(i)-1]+getPath(n-1,list_org);   
		if(list_org.size()==matrix_length-1)  
		{   
			list_result=list_org;   
		}   

		for(int j=2;j<n;j++)   
		{   
			i=list_org.begin();   
			for(int k=1;k<j;k++)  
			{   
				i++;   
			}   

			int tempvalue=*i;   
			list_org.erase(i);   
			list_org.push_front(tempvalue);   
			i=list_org.begin();   
			tempvalue=d[temp-1][*(i)-1]+getPath(n-1,list_org);   

			if(tempvalue<minValue)  
			{   
				if(list_org.size()==matrix_length-1)  
				{   
					list_result=list_org;   
				}   
				minValue=tempvalue;   
			}   

		}   
	}   
	return minValue;   
}   
int main(int argc, char* argv[])   
{   

	LISTINT list_org;   
	LISTINT::iterator h;   
	list_org.push_front(4);   
	list_org.push_front(3);   
	list_org.push_front(2);   
	list_org.push_front(1);   
	cout<<""<<endl;   
	cout<<" ?-1?"<<endl;   
	for(int j=0;j<matrix_length;j++){   
		cout<<endl;   
		for(int k=0;k<matrix_length;k++){   
			cout<<" "<<d[j][k];   
		}   
	}   
	cout<<endl;   


	cout<<":"<<getPath(4,list_org)<<endl;   
	list_result.push_front(1);   
	list_result.push_back(1);   
	cout<<":---->:";   
	for (h = list_result.begin(); h != list_result.end(); ++h)   

		cout << *h << " ";   


	cout << endl;   
	int i;   
	cin>>i;   
	return 0;   
} 

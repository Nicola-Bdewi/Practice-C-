#include<iostream>
#include<string>
#include <iomanip>
using namespace std; 
int main(){
	
	string name, YN;
	int height, width, Nhouse = 0;  
	
	cout << "What is your name? " << endl; 
	cin >> name; 
	cout << endl << "Well " << name << ", welcome to my house drawing program.\n\n"; 
	
	cout << "Do you want me to draw a simple house for you? (yes/no)" << endl; 
	cin >> YN; 
	cout << endl; 
	
	
	
	 if (YN == "no") {
		
		cout << "Ok have a nice day" << endl; 
	}
	
	
	while (YN == "yes"){
		
		cout << "Enter the height of the house " << endl; 
		cin >> height;
		
		cout << "Please enter an even number for the width of the house" << endl; 
		cin >> width; 
		cout << endl;  
		
		 
			int c =1;  
			while (width % 2 != 0 || width < 3 && c <= 3) {                               // 3 tries for the user to enter even number or else the program ends with the if statement
				cout << "You entered " << width <<". Width should be an even number greater than 2" << endl; 
				cin >> width;
				c++; 
				if (c==3 && width % 2 != 0 || width < 3 ){
				
					cout << "Please relaunch the program and enter an even number" << endl; 
					return 0;   
					
				}
			} // end while
				
			


		for (int i=1 ; i<=width/2  ; i++) {                          // As the hint says we need width/2 rows
		
			for (int s=(width/2)-i ; s>0 ; s--){                     // Making space for the start of each row so that it will not print a right triangle
				cout << " "; 
			}
			
			for(int j = 1; j <= i; j++)                              // This loop for printing roof
        {
            cout << "**";
        }
        cout << endl;
		
		}
	
	
		for (int i = 1 ; i <= height ; i++){                     	// Drawing the walls
		
			cout << "|" << setw(width-1) << "|" << endl;
					
		}
		
		for (int LastLine = 1 ; LastLine <= width ; LastLine ++){    	 	// Last line (floor) drawing
			cout << "-"; 
		}
		
		cout << endl; 
		
	
		Nhouse ++;                                                   	 	// A counter for calculating the number of houses 
		cout << endl << "Would you like to draw another house?" << endl; 
		cin >> YN; 
		
		if (YN == "no")
			cout << endl << "Hope you like your " << Nhouse << " house(s)" << endl; 

} // end the big while 
				
	return 0;
	 
} // end main

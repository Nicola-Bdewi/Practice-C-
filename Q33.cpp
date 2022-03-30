#include<iostream>
#include<array>
#include<string>
using namespace std; 

int  count=0; 																	// counter to calculate the display command
void Right ( array <int, 100> ROBOT ); 
void Left ( array <int, 100> ROBOT );
void Display_Position(); 
int  Reboot(); 
void Show_Array(array <int, 100> ROBOT);
bool Exit_Program(string);
void Cancel_Pos (array <int, 100> ROBOT); 
void Replay_Pos(array <int, 100> ROBOT);

int main(){
	
	int right, left, reboot, n;
	string Display, ShowGrid, Exit;  
	string press; 
	array <int, 100> ROBOT; 
	
	cout << "The command are exactly as these options (case sensetive): " << endl << "right | left | reboot | display | show grid | cancel | replay " << endl << endl; 
	cout << "Enter the command : " << endl;
	getline(cin, press, '\n'); 

	while  (Exit_Program (press) != 1 ){
	
	if (press == "right"){
		Right(ROBOT);
		count++;
		if (count > 100 ){  
			cout << "You went out of bounds! You can enter display and see how much you need to go to the left to be back to the last position" << endl; 
			getline(cin, press, '\n');
		}
		else 
			getline(cin, press, '\n');
	
	}
	
	else if (press == "left"){ 
		Left(ROBOT);
		count --;
		if (count < 0 ){ 
			cout << "You went out of bounds! You can enter display and see how much you need to go to the right to be back to the first position" << endl; 
			getline(cin, press, '\n');
		}
		else 
			getline(cin, press, '\n');
			
	}
	
	else if (press == "reboot"){
		cout << Reboot() << endl;
		getline(cin, press, '\n'); 
	}
	
	else if (press == "display"){
		Display_Position();
		getline(cin, press, '\n'); 
	}
	
	else if (press == "show grid"){
		    Show_Array (ROBOT);
			getline(cin, press, '\n');      
	}
	
	else if(press== "cancel"){
		 Cancel_Pos (ROBOT);
		 getline(cin, press, '\n');
	}
	
	else if(press == "replay"){
			Replay_Pos(ROBOT);
			getline(cin, press, '\n');
	}
	
	else {  
		getline(cin, press, '\n');
	}
}
	
	return 0;
	 
} // end main


	void Right ( array <int, 100> ROBOT ) {
		
		string press; 
		int i=0;
		while(press=="right"){
			ROBOT[i] = ROBOT[i+1];
			i++;
	}
		
} // end Right function
	
	
	void Left ( array <int, 100> ROBOT ) {
		string press; 
		int i=0;
		while(press=="left"){
			ROBOT[i] = ROBOT[i-1];	
			i++;
	
	}
} // end Left function 
	
	
	void Display_Position(){
		cout << count << endl; 	
} // end Display function	
	

	int Reboot(){
		count =0; 
		return count; 
		
} // end Reboot function

	bool Exit_Program(string press){
		 
		if (press == "exit"){ 
			cout << "Your program has been termineted" << endl; 
			return true; 
	}   
} // end Exit_Program function 

	
	void Show_Array(array <int, 100> ROBOT){ 
		
		for (int i=0; i<= count; i++){
			cout << i << " " ; 
		}
		cout << endl <<"The last number is where you are now!" << endl; 
		
} // end Show_Array function 

	void Cancel_Pos (array <int, 100> ROBOT){
		
		int n;
		cout << "How many steps you would like to go back?" << endl; 
		cin >> n ;
		
		
		for (int i=0; i<ROBOT.size()-1; i++ ){                 // shift allement by n to the left
			ROBOT[i] = ROBOT [i+n];	
		}  
		
		cout << endl; 
		
		for (int i=0; i<ROBOT.size()-1; i++){
			cout << ROBOT[i] << " " ; 
		}
			 
	} // end Cancel_Pos function


	void Replay_Pos(array <int, 100> ROBOT){
		 
		int n;
		cout << "How many steps you would like to retrieve?" << endl; 
		cin >> n ; 
		
		for(int i=ROBOT.size()-1;i>=0;i--){                        // shift all element to the right
			ROBOT[i+1] = ROBOT[i];
		}
 
 		for (int i=0; i<ROBOT.size()-1; i++){
			cout << ROBOT[i] << " " ; 
		}
		
} // end Replay_Pos function 
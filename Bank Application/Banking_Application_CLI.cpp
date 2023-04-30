/* The Bank Management System is a terminal-based application 
 that allows users to create and manage their bank accounts.
 This project uses Object Oriented Programming.
*/
#include "iostream"
#include "vector"
#include "string"
#include "cstdlib"
using namespace std;
class openAccount{
	private:
		string name;
		string mob;
		int pin;
		unsigned int acc=0;
		float balance;
	public:
		openAccount(string name,string mob,int pin,int acc)
		{
			this->name = name;
			this->mob = mob;
			this->pin = pin;
			this->acc = acc;
			this->balance=0;
		}
		void display()
		{
		cout << "Account Number: " << acc << endl;
        cout << "Name: " << name << endl;
        cout << "Mobile: " << mob << endl;
        cout << "Balance: Rs." << balance << endl;
		}
		void setPin(int pin)
	    {
	        this->pin = pin;
	    }
	 	bool verifyPin(int pin)
    	{
        	return this->pin == pin;
    	}
		void deposit(double amount)
		{
	        balance = balance + amount;
	        cout << "Amount has been deposited successfully.. into your account "<<endl<<"New balance: Rs. " << balance << endl;
	    }  
		void withdraw(double amount) 
		{
	        if (amount > balance) {
	            cout << "Insufficient balance in your Account..!" << endl;
	        } else {
	            balance -= amount;
	            cout << "Amount has been withdrawn successfully! "<<endl<<" New balance: Rs." << balance << endl;
	        }
    	}  
    	
    	void updateAccountDetails(string name, string mob, int pin) {
        this->name = name;
        this->mob = mob;
        this->pin = pin;
        cout << " Successfully Account details updated..!" << endl;
    	}
    	
    	void deleteAccount() 
		{
	        name = " ";
	        mob = " ";
	        pin = 0;
	        balance = 0;
	        cout << "Deleted Account Successfully..!" << endl;
   		 }
   		 
   		 int getAccountNumber() {
        return acc;
    }

    int getPin() {
        return pin;
    }
};

int findAccount(vector<openAccount>& accounts, int accountNumber) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accountNumber) {
            return i;
        }
    }
    return -1;
}

int main()
{
	
    vector<openAccount> accounts;
    int choice;
    int accountNumber;
    int pin;
    string name;
    string mobile;
    double amount;
    int index;
	
	
	do{
		cout<<endl;
cout<<"<-----------================---------->"<<endl;
	cout<<"Welcome to Banking Feature App "<<endl;	
	cout<<"-------------------------------"<<endl;
	cout<<"1. Open New Account "<<endl;
	cout<<"2. Show Account Details "<<endl;
	cout<<"3. Deposit  "<<endl;
	cout<<"4. Withdraw Amount "<<endl;
	cout<<"5. Edit Account"<<endl;
	cout<<"6. Delete Account "<<endl;
	cout<<"7. Exit "<<endl;
	cout<<"-------------------------------"<<endl;
  	cout<<"Enter the Choice between (1 - 7): "<<endl;
	cin>>choice;
	cout<<"<-----------================---------->"<<endl;
	switch(choice)
	{
		case 1:  //1. Open New Account
                cout << "Enter Account holder name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter your mobile: ";
                getline(cin, mobile);
                cout << "Enter your 4 digits pin : ";
                cin >> pin;
                accountNumber = accounts.size() + 1;
                accounts.push_back(openAccount(name, mobile, pin, accountNumber));
                cout << "Account created successfully...!"<<endl<<" Account Number is: " << accountNumber << endl;
                break;
        case 2: 
        		//2. Show Account Details 
   				cout << "Enter account number: ";
    			cin >> accountNumber;
   				index = findAccount(accounts, accountNumber);
    			if (index != -1)
    			{
       				int enteredPin;
        			  cout << "Please Enter your 4 digit PIN number  : ";
        			cin >> enteredPin;
        			if (accounts[index].verifyPin(enteredPin))
        			{
            			accounts[index].display();
        			}
        			else
        			{
       			    	cout << "-----You have Entered an Incorrect PIN!-----" << endl;
        			}
    			}
    			else
    			{
    		    	cout << "-----Account not exist!-----" << endl;
    			}
    			break;
    	case 3:
    			
    			//For Deposit
    			cout << "Enter the Account number: ";
    			cin >> accountNumber;
    			index = findAccount(accounts, accountNumber);
    			if (index != -1)
    			{
        			int enteredPin;
        			cout << "Please Enter your 4 digit PIN number  : ";
        			cin >> enteredPin;
        			if (accounts[index].verifyPin(enteredPin))
        			{
            			cout << "Enter the deposit amount in : Rs.";
            			cin >> amount;
            			accounts[index].deposit(amount);
        			}
        			else
        			{
            			cout << "You have Entered an Incorrect PIN!" << endl;
        			}
    			}
    			else
    			{
  			     	cout << "Account does not exist!" << endl;
    			}
    			break;
					
		case 4: 
				
    			// Withdraw
    			cout << "Enter account number: ";
    			cin >> accountNumber;
    			index = findAccount(accounts, accountNumber);
    			if (index != -1)
    			{
        			int enteredPin;
        			cout << "Please Enter your 4 digit PIN number  : ";
        			cin >> enteredPin;
        			if (accounts[index].verifyPin(enteredPin))
        			{
            		cout << "Enter withdrawal amount: Rs.";
            		cin >> amount;
            		accounts[index].withdraw(amount);
        			}
        			else
        			{
            				cout << "You have Entered an Incorrect PIN!" << endl;
        			}
    			}
    			else
    			{
        		cout << "Account does not exist!" << endl;
    			}
				break;
			 	
		case 5: 
				
			    //To Edit account details
 		    	cout << "Enter account number: ";
    			cin >> accountNumber;
    			index = findAccount(accounts, accountNumber);
    			if (index != -1)
    			{
        			int enteredPin;
        		cout << "Please Enter your 4 digit PIN number  : ";
        			cin >> enteredPin;
        			if (accounts[index].verifyPin(enteredPin))
       				{
            			cout << "Enter New Name: ";
            			cin.ignore();
            			getline(cin, name);
            			cout << "Enter the New mobile Number : ";
            			getline(cin, mobile);
            			cout << "Enter your New 4 digit PIN number : ";
            			cin >> pin;
            			accounts[index].updateAccountDetails(name, mobile, pin);
        			}
        			else
        			{
            		cout << "You have Entered an Incorrect PIN!" << endl;
        			}
    			}
    			else
    			{	
        		cout << "Account does not exist!" << endl;
    			}
    			break;
    	case 6:
    			
    			// Delete account
    			cout << "Enter Your existing account number: ";
    			cin >> accountNumber;
    			index = findAccount(accounts, accountNumber);
    			if (index != -1)
    			{
        			int enteredPin;
        			cout << "Please Enter your 4 digit PIN number  : ";
        			cin >> enteredPin;
        			if (accounts[index].verifyPin(enteredPin))
        			{
        	    		accounts[index].deleteAccount();
            			accounts.erase(accounts.begin() + index);
        			}
        			else
        			{
            		cout << "You have Entered an Incorrect PIN!" << endl;
        			}				
    			}
    			else
    			{
        			cout << "Account does not exist!" << endl;
    			}
    			break;
    	case 7:

                cout << "Thank you for using Bank Management System. Goodbye!" << endl;
                return 0;
                break;
        default:
                cout << "Invalid choice. Please try again." << endl;
        }
		}while(choice>=1 && choice <= 7);
    
					
 return 0;
}
			 

		 		
	
	
	




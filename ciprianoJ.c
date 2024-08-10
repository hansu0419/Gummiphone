/*********************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in studying and applying the
concepts learned. I have constructed the functions and their respective algorithms and corresponding code by
myself. The program was run, tested, and debugged by my own efforts. I further certify that I have not copied in
part or whole or otherwise plagiarized the work of other students and/or persons.
 JOHANS VENEDICT LOYOLA CIPRIANO, DLSU ID# 12205540
*********************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<MMsystem.h>

#define MAX_MESSAGE 1000
#define MAX_USER 30
#define MAX_PASS 20 
#define MAX_STRING 50
#define MAX_SECURE 100

#define BBLU "\e[1;34m"
#define BHRED "\e[1;91m"
#define YEL "\e[0;33m"
#define RST "\x1b[0m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define MAG "\e[0;35m"

typedef char message[MAX_MESSAGE];
typedef char announce[500];
typedef char str[MAX_STRING];
typedef char secure[MAX_SECURE];
//typedef char secure[20][MAX_SECURE];

typedef struct
{
	int j;
	str link[MAX_USER];
	str username;
}grouping;

typedef struct
{
	str sender;
	str subj;
	str receiver;
	str group;
	message mail;
	announce announcement;
	
}mess[MAX_MESSAGE];

typedef struct
{
	message description;
	str name;
	str username;
	char password[MAX_PASS];
	secure question;
	secure user_question;
	char answer[MAX_SECURE];
	grouping connect;
	int Locked;
	int IDRequest;

}acc[MAX_USER];

void displayCreateanAccount()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n"); 
    printf("==========             CREATE AN ACCOUNT             ==========\n"); 
    printf("===============================================================\n\n");
}

void displayLoginAccount()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n"); 
    printf("==========                  LOG-IN                   ==========\n"); 
    printf("===============================================================\n\n");

}
void displayModifyName()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n");
    printf("==========               Modifying Name              ==========\n"); 
    printf("===============================================================\n\n");
}

void displayIndividualMess()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n");
    printf("==========               Compose Message             ==========\n"); 
    printf("===============================================================\n\n");
	
}

void displayGroupMess()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n");
    printf("==========           Compose Group Message           ==========\n"); 
    printf("===============================================================\n\n");
}

void displayAnnouncement()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n");
    printf("==========            Compose Announcement           ==========\n"); 
    printf("===============================================================\n\n");
}

void displayInbox()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n");
    printf("==========                    Inbox                  ==========\n"); 
    printf("===============================================================\n\n"); 
}

void displayModifySecurity()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n");
    printf("==========          Modify Account Security          ==========\n"); 
    printf("===============================================================\n\n");
}

void displayModifyPassword()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n");
    printf("==========               Modify Password             ==========\n"); 
    printf("===============================================================\n\n");
}

void displaySecurityAnswer()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n");
    printf("==========           Modify Security Answer          ==========\n"); 
    printf("===============================================================\n\n");
	
}

void displayPasswordModule()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n");
    printf("==========           Change Admin Password           ==========\n"); 
    printf("===============================================================\n\n");
	
}

void displayModifyUser()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n");
    printf("==========                Modify User                ==========\n"); 
    printf("===============================================================\n\n");	
}

void displayBrowseUser()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n");
    printf("==========               Browse Users                ==========\n"); 
    printf("===============================================================\n\n");	
}

void displayforgotPassword()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n");
    printf("==========              Forgot Password              ==========\n"); 
    printf("===============================================================\n\n");		
}

void displayRefreshPassword()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n");
    printf("==========              Refresh Password             ==========\n"); 
    printf("===============================================================\n\n");
}

void displaySent()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n");
    printf("==========               Sent Messages               ==========\n"); 
    printf("===============================================================\n\n");
}

void displayMessagesModule()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n");
    printf("==========              Messages Module              ==========\n"); 
    printf("===============================================================\n\n");
}

void displayDeleteUser()
{
	printf("===============================================================\n");
	printf("==========                                           ==========\n");
    printf("==========                Delete User                ==========\n"); 
    printf("===============================================================\n\n");
}

/* funcaddUser 

	Description - This function gets user input of:
		1) Name
		2) Username
		3) Password
		4) Security Answer for a Random Security question
	This is then saved to the acc user Structure.

 @param user - A structure containing all of a Potential user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nQuestions - contains the number of security questions added into the program
 
	(A void Function == does not return anything)
*/

void addUser(acc user, int *nUsers, int *nQuestions)
{
	str stringLine;		//Contains user's input for Username and Password
	str stringLine2;	//Contains user's input for Name
	secure answer;		//Contains user's input for Security Answer
	int nValid, bStop = 0; //Checking whether a user's input is valid or not
	char cont;	//Contains user's input on whether they want to continue or not
	int rand_question; //Contains Randomized Number from 0 - *nQuestions
	int i; //Used in loops. i = 0;
	
	
	if (*nUsers >= 0 && *nUsers < MAX_USER) //Checking whether the no. of users is more than 0 and less than MAX_USER = 30
	{
	
		do{
			nValid = 0;			
			fflush(stdin);
			// Get Name, place and placing it at str name
			system("cls");
			displayCreateanAccount();
			//printf("%d\n", *nUsers); 
			printf("Enter Your Name: ");
			fgets(stringLine2,sizeof(stringLine2), stdin);	//Input of Name
			stringLine2[strlen(stringLine2)-1] = '\0';
		
			system("cls");
			displayCreateanAccount();
			// Get Username, place and placing it at str username
			
			fflush(stdin);
			printf("Enter new Username: ");
			fgets(stringLine,sizeof(stringLine), stdin);	//Input of Username
			stringLine[strlen(stringLine)-1] = '\0';
			
			
			if(*nUsers == 0)	//If this is the first User being created
			{
				strcpy(user[*nUsers].username, stringLine);	//stringLine is copied to user structure (username)
				strcpy(user[*nUsers].name, stringLine2);	//stringLine2 is copied to user structure (name)
				nValid = 0;
			}
			else if (*nUsers > 0 && *nUsers < MAX_USER) //If there is more than 1 user in the program
			{
				for (i = 0; i < *nUsers && nValid == 0; i++)		//Loops until it reaches the total number of users and (stringLine == a user's username)
				{
					if(strcmp(user[i].username, stringLine) == 0)
						nValid = 1;									//A new user's username should be unique, if not, nValid = 1;
					else if (strcmp(user[i].username, stringLine) != 0)	
					{
						strcpy(user[*nUsers].username, stringLine); //stringLine is copied to user structure (username)
						strcpy(user[*nUsers].name, stringLine2);	//stringLine is copied to user structure (name)
						nValid = 0;									
					}
				}
			}
			
		}while(nValid == 1);		//loops until Username is unique from previous usernames
		
		
		fflush(stdin);
		system("cls");
		displayCreateanAccount();   
		
		// Get Password, place and placing it at char password[MAX_PASS]
			printf("Enter password (MAX = 20): ");						
			fgets(stringLine,sizeof(stringLine), stdin);				//Input of Password
			stringLine[strlen(stringLine)-1] = '\0';
			strcpy(user[*nUsers].password, stringLine);
			
			while(strlen(user[*nUsers].password) > 20)				//Loops until Password's length is less than 20 char
			{
				system("cls");
				displayCreateanAccount();
				printf(BHRED "Password SIZE over the limit.\n" RST);		
				printf(BHRED "TRY AGAIN!\n\n" RST);
				
				printf("Enter password (MAX = 20): ");
				fgets(stringLine,sizeof(stringLine), stdin);		//Input of Password
				stringLine[strlen(stringLine)-1] = '\0';
				strcpy(user[*nUsers].password, stringLine);			//Copies current Password
			}
			
			printf("Confirm password: ");
			fgets(stringLine,sizeof(stringLine), stdin);		//Re-input password
			stringLine[strlen(stringLine)-1] = '\0';
			
			while(strcmp(user[*nUsers].password, stringLine) != 0)	//inputs until the two inputs of passwords are not equal
			{
				system("cls");
				displayCreateanAccount();
				printf(BHRED "Passwords do not match. Please try again.\n" RST);
				
		        printf("Enter password (MAX = 20): ");
				fgets(stringLine,sizeof(stringLine), stdin);	//Input of Password
				stringLine[strlen(stringLine)-1] = '\0';
				strcpy(user[*nUsers].password, stringLine);		//Copies current Password
				
				while(strlen(user[*nUsers].password) > 20)		//Loops until Password's length is less than 20 char
				{
					system("cls");
					displayCreateanAccount();
					printf(BHRED "Password Size over the limit.\n" RST);
					printf("TRY AGAIN!\n\n");
					
					printf("Enter password (MAX = 20): ");
					fgets(stringLine,sizeof(stringLine), stdin);	//Input of Password
					stringLine[strlen(stringLine)-1] = '\0';
					strcpy(user[*nUsers].password, stringLine);		//Copies current Password
				}
			
				printf("Confirm password: ");
				fgets(stringLine,sizeof(stringLine), stdin);	//Comfirm current Password
				stringLine[strlen(stringLine)-1] = '\0';
			}
			
			strcpy(user[*nUsers].description, "'DEFAULT USER'");  //DEFAULT DESCRIPTION of a New User
			
			srand(time(NULL));
			rand_question = rand() % *nQuestions;								//Randomly choose a security question
			strcpy(user[*nUsers].user_question, user[rand_question].question);	//Copies user's random question to the User Structure (question)
			
			system("cls");
			displayCreateanAccount();
			printf("SECURITY QUESTION\n");
			printf("%s\n", user[rand_question].question);			//Displays Rendomized Security Question
			printf("Answer (MAX = 100 characters): ");
			fgets(answer, sizeof(answer), stdin);			
			answer[strlen(answer) - 1] = '\0';
			
			while(strlen(answer) > 100)				//Loops until Answer size > 100
			{
				system("cls");
				displayCreateanAccount();
				printf(BHRED "Answer Size over the limit.\n" RST);
				printf(BHRED "TRY AGAIN!\n\n" RST);
				
				printf("SECURITY QUESTION\n");
				printf("%s\n", user[rand_question].question);			//Displays Rendomized Security Question
				printf("Answer (MAX = 100 characters): ");
				fgets(answer, sizeof(answer), stdin);				//Inputs Security Answer
				answer[strlen(answer) - 1] = '\0';
				
			}
			
			strcpy(user[*nUsers].answer, answer);				//Copies User's Answer
			
		do{
		system("cls");
		displayCreateanAccount();
		
		/*
			Prints the Final Information of the User
		*/
		printf("================= \n");
		printf(GRN "Final Information \n" RST);
		printf("================= \n\n");
		printf("Name = %s\n", user[*nUsers].name);
		printf("Username = %s\n", user[*nUsers].username);
		printf("Password = %s\n", user[*nUsers].password);
		printf("Security Question = %s\n", user[*nUsers].user_question);
		printf("Security Answer = %s\n\n\n", user[*nUsers].answer);
		
		printf("[P]ress to Continue: ");
		cont = getchar();
		
		if(cont == 'P')
			bStop = 1;
		else if (cont == 'p')
			bStop = 1;
		else
			bStop = 0;
		
		}while (bStop != 1);		//Loops until user input 'p' or 'P'
		
		(*nUsers)++; // Add 1 to the total no. of users
	}
	else if(*nUsers > MAX_USER)		//If *nUsers is greater than MAX_USER = 30
	{
		do{
		
			system("cls");
			displayCreateanAccount();
			printf("MAXIMUM NUMBER OF USERS HAS BEEN REACHED!\n");
			printf("[P]ress to go back: ");
			cont = getchar();
			
			if(cont == 'P')
				bStop = 1;
			else if (cont == 'p')
				bStop = 1;
			else
				bStop = 0;
		
		}while (bStop != 1);	//Loops until user input 'p' or 'P'
	}
}

/* funcforgotPassword

	Description - This function gets user input of:
		1) Security Answer for a user's Security question
		
	This function casks for the Admin's request.
	This is then saved to the acc user Structure.

 @param user - A structure containing all of a user's information
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 
	(A void Function == does not return anything)
*/

void forgotPassword(acc user, int *nIndex)
{
	str stringLine;		//Contains User Input of Security Answer
	int bStop = 1, bStop2 = 1;	//Checks whether or not user's input is valid
	int choose;	//user's input if they want to continue or not
	
	do{
		system("cls");
		fflush(stdin);
		displayforgotPassword();
		printf("Answer the Security Question\n");
		printf("%s\n", user[*nIndex].user_question);		
		printf("\nAnswer: ");
		fgets(stringLine, sizeof(stringLine), stdin);	//Inputs answer
		stringLine[strlen(stringLine) - 1] = '\0';
		
		if(strcmp(stringLine, user[*nIndex].answer) == 0)	//if the input is equal to the user's security answer
			bStop = 0;
		else
			bStop = 1;
		
	}while(bStop == 1);	//loops until input == security answer
	
	do{
	
		system("cls");
		displayforgotPassword();
		
		user[*nIndex].IDRequest = 1;			//ID request == 1 when they ask for a request
		
		/*
		Display to user that the request has been sent
		and provides the Default Password.
		It will only work when the Admin approves
		*/
		printf(GRN "Your request has been sent! \n" RST);
		printf("[1] Default Password =");
		printf(GRN " DLSU122\n" RST);
		printf("[2] Type Default Password once Admin approves\n");
		printf("[3] Admin's approval takes 2-3 business days\n");
		
		printf("Type [-1] to go back: ");
		scanf("%d", &choose);
	
		if (choose == -1)
			bStop2 = 0;
		else
			bStop2 = 1;
		
	}while(bStop2 == 1);	//loops until choose == -1
	
	
}


/* funclogInuser

	Description - This function gets user input of:
		1) Userame
		2) Password
		
	This is then compared to the acc user Structure.
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 
	@returns nValid
*/

int logInUser(acc user, int *nUsers, int *nIndex)
{
	str stringLine;		//input for username and password
	int i = 0;			//used for loops
	int userVal = 1, passVal = 1;	//check if Username and password are TRUE
	int nValid = 1;	//check if both username and password are TRUE
	int nAttempt = 0; //check if User attempted 3 times for password
	int nValid2; //Check if password is TRUE
	int k = 3; //Provide the User on how many attempts are left
	int choose; //User's input

		do{
			
			fflush(stdin);
			system("cls");
			displayLoginAccount();
			/*This is only used for debugging*/
		
			
			printf("Enter Username: ");
			fgets(stringLine,sizeof(stringLine), stdin); //Get username
			stringLine[strlen(stringLine)-1] = '\0';
			for(i = 0; i < *nUsers && userVal == 1; i++)
			{
				if(strcmp(user[i].username, stringLine) == 0)	//Check if input is equal to one of the current user's usernames in the program
				{
					userVal = 0;
					*nIndex = i;		//user's ID
				}
			}
		}while(userVal != 0);	//loops until username == one of the usernames in the user structure
		
		if (user[*nIndex].Locked == 1 && user[*nIndex].IDRequest == 0)	//check whether user's account is locked and requested for password change
		{
			system("cls");
			displayLoginAccount();
			printf(BHRED "Your Account has been LOCKED!\n" RST);
			printf("Request to Reset Password in order to Log-in\n\n");
			printf("Press any No. to Request Password\n");
			printf("Or Type [-1] to go back: ");
			scanf("%d", &choose);
			
			if(choose == -1)
				nValid = 0;
			else
			{
				forgotPassword(user, nIndex);	//Requesting for password change from Admin
				nValid = 0; 
			}
		}
		else if (user[*nIndex].Locked == 1 && user[*nIndex].IDRequest == 1)	//check whether user's account is locked and requested for password change
		{
			system("cls");
			displayLoginAccount();
			printf(BHRED "Your Account is still LOCKED!\n" RST);
			printf("Wait for Admin's Approval\n\n");
			printf("Press any No. to go back: ");
			scanf("%d", &choose);
				nValid = 0;
		}
		else	//the user's account is unlocked and did not request for password change
		{
		
			do{
				nValid2 = 1;
					
				system("cls");
				displayLoginAccount();
				printf("Enter Password (" ); //Displays number of attempts (3 attempts only)
				printf(BHRED "%d " RST, k);
				printf("Attempts left): ");
				fgets(stringLine,sizeof(stringLine), stdin);	//Gets user input on password
				stringLine[strlen(stringLine)-1] = '\0';
				for(i = 0; i < *nUsers && passVal == 1; i++)	//loops until user input is == to user's password
				{
					if(strcmp(user[*nIndex].password, stringLine) == 0)
					{
						passVal = 0;					//password has been obtained
						user[*nIndex].Locked = 0;		//user's account is not locked
					}
				}
				
				if (passVal == 1)	//if input != to user's password
				{
					nAttempt += 1;	//Attempt increases by 1
					k -= 1;			
					
					if (nAttempt > 2)	//if attempt is equal to 3
					{
						user[*nIndex].Locked = 1;	//user account is locked
						nValid2 = 0;				
					}
				}
				else if (passVal == 0)	//if input == user's password
				{
					nValid2 = 0;
				}
				
			}while(nValid2 == 1);	
			
			
			if(passVal == 1 && userVal == 1)	//username and password are Valid
				nValid = 0;
			else if (passVal == 1 && userVal == 0)	//password is not valid
				nValid = 0;
		}

	return (nValid);
}

/* funcModifyName

	Description - This function gets user input of:
		1) Name
		2) Password
		
	This is then compared to the acc user Structure.
	Function modifies Real Name.
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 
	(void function == does not return anything)
*/

void ModifyName( acc user, int *nUsers, int *nIndex)
{
	str stringLine; //input
	str stringLine2; //input
	int bStop = 0; //Checking whether a user's input is valid or not
	char choose; 
	int nValid; //Checking whether a user's input is valid or not
	int nAttempts = 1; //Checking User's number of attempts for password input
	
	fflush(stdin);
	
	do{
		fflush(stdin);
		system("cls");
		displayModifyName();
		printf("Enter your password: ");
		fgets(stringLine,sizeof(stringLine), stdin);	//Password Input
		stringLine[strlen(stringLine)-1] = '\0';
		nValid = 0;
		
		while(strcmp(user[*nIndex].password, stringLine) != 0 && nAttempts <= 3)	//Loops until Password is correct and attempts is less than 4
		{
			system("cls");
			displayModifyName();
			printf(BHRED "WRONG PASSWORD!\n" RST);
			
	        printf("Enter your password: ");
			fgets(stringLine,sizeof(stringLine), stdin);
			stringLine[strlen(stringLine)-1] = '\0';
			
			if(strcmp(user[*nIndex].password, stringLine) != 0)
			{
				nValid = 1;
				nAttempts++;
			}
			else
				nValid = 0;
		}
		
		if(nValid == 0)		//If password is correct
		{
			system("cls");
			displayModifyName();
			printf("Current Name: %s\n", user[*nIndex].name);
			printf("Enter new Name: ");
			fgets(stringLine2,sizeof(stringLine2), stdin);
			stringLine2[strlen(stringLine2)-1] = '\0';
		
			strcpy(user[*nIndex].name, stringLine2);
			
			system("cls");
			displayModifyName();
			printf("Your new Name is: %s\n", user[*nIndex].name);
			
			printf("Wanna change it again? \n");
			printf("TYPE [Y]es or [N]o: ");
			choose = getchar();
			
			if (choose == 'Y')
				bStop = 0;
			else if (choose == 'y')
				bStop = 0;
			else if (choose == 'N')
				bStop = 1;
			else if (choose == 'n')
				bStop = 1;
		}
		else if (nValid == 1)
		{
			system("cls");
			displayModifyName();
			printf(BHRED "Invalid Password\n" RST);
			
			printf(BHRED "Try Again later! \n" RST);
			printf("TYPE [Y]es to go back: ");
			choose = getchar();
			
			if (choose == 'Y')
				bStop = 1;
			else if (choose == 'y')
				bStop = 1;
		}
			
	}while(bStop == 0);
}

/* funcModifyDescription

	Description - This function gets user input of:
		1) Description
		2) Password
		
	This is then compared to the acc user Structure.
	Function modifies user's description
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 
	(void function == does not return anything)
*/

void ModifyDescription(acc user, int *nUsers, int *nIndex)
{
	str stringLine; //input
	message stringLine2; //input
	int bStop = 0; //Checking whether a user's input is valid or not
	char choose;
	int nValid; //Checking whether a user's input is valid or not
	int nAttempts = 1; //Checking number of attempts
	
	fflush(stdin);
	
	do{
		system("cls");
		displayModifyName();
		printf("Enter your password: ");
		fgets(stringLine,sizeof(stringLine), stdin);	//input password
		stringLine[strlen(stringLine)-1] = '\0';
		nValid = 0;
		
		while(strcmp(user[*nIndex].password, stringLine) != 0 && nAttempts <= 3)	//loops until attempts is less than 4 and password is incorrect
		{
			system("cls");
			displayModifyName();
			printf(BHRED "WRONG PASSWORD!\n" RST);
			
	        printf("Enter your password: ");
			fgets(stringLine,sizeof(stringLine), stdin);
			stringLine[strlen(stringLine)-1] = '\0';
			
			if(strcmp(user[*nIndex].password, stringLine) != 0)
			{
				nValid = 1;
				nAttempts++;
			}
			else
				nValid = 0;
		}
		
		if(nValid == 0)
		{
			system("cls");
			displayModifyName();
			printf("Current Description: %s\n", user[*nIndex].description);
			printf("Enter new Description (MAX = 1000 char): ");
			fgets(stringLine2,sizeof(stringLine2), stdin);					//input new description
			stringLine2[strlen(stringLine2)-1] = '\0';
		
			strcpy(user[*nIndex].description, stringLine2);
			
			system("cls");
			displayModifyName();
			printf("Your new Description: %s\n", user[*nIndex].description);
			
			printf("Wanna change it again? \n");
			printf("TYPE [Y]es or [N]o: ");
			choose = getchar();
			
			if (choose == 'Y')
				bStop = 0;
			else if (choose == 'y')
				bStop = 0;
			else if (choose == 'N')
				bStop = 1;
			else if (choose == 'n')
				bStop = 1;
		}
		else if (nValid == 1)
		{
			system("cls");
			displayModifyName();
			printf(BHRED "Invalid Password\n" RST);
			
			printf(BHRED "Try Again later! \n" RST);
			printf("TYPE [Y]es to go back: ");
			choose = getchar();
			
			if (choose == 'Y')
				bStop = 1;
			else if (choose == 'y')
				bStop = 1;
		}
			
	}while(bStop == 0);
}

/* funcindividualMessage

	Description - This function gets user input of:
		1) Username
		2) Subject
		3) Message
		
	This is then compared to the acc user Structure.
	Function sends message to a particular individual.
	The individual has to be a personal connection.
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 @param *nMess - contains the total number of messages added into the program.
 @param allmessages - A structure conataining all of the messages.
 
	(void function == does not return anything)
*/

void individualMessage(acc user, int *nUsers, int *nIndex, int *nMess, mess allmessages)
{
	str stringLine;		//input
	message stringLine2;	//input
	int i; 				//used for loop
	int nValid, max;	//nValid is used to check if it is valid or not. Max is used it check the number of connections
	int bStop = 0;		//check if they want to go back or not
	
	system("cls");
	displayIndividualMess();
	
	do{
		nValid = 1;
		
		fflush(stdin);
		printf("Send to: ");
		fgets(stringLine, sizeof(stringLine), stdin);
		stringLine[strlen(stringLine) - 1] = '\0';
		
		for (i = 0; (max = strlen(user[*nIndex].connect.link[i])) != 0 && nValid == 1; i++)
		{	
			if (strcmp(user[*nIndex].connect.link[i], stringLine) == 0)
			{
				nValid = 0;
				system("cls");
				displayIndividualMess();
				printf("Send to: '%s'", user[*nIndex].connect.link[i]);
				strcpy(allmessages[*nMess].sender, user[*nIndex].username);
				strcpy(allmessages[*nMess].receiver, stringLine);
				
				//strcpy(message[*nMess].sender, user[*nIndex].username);
				//strcpy(user[*nIndex].message.mess[*nMess].sender, user[*nIndex].username);
				//strcpy(message[*nMess].receiver, stringLine);
				//strcpy(user[*nIndex].message.mess[*nMess].receiver, stringLine);
			}
		}
		
		if (nValid == 0)			//if there is a personal connection
		{
			printf("\nSubject: ");
			fgets(stringLine, sizeof(stringLine), stdin);
			stringLine[strlen(stringLine) - 1] = '\0';
	
			strcpy(allmessages[*nMess].subj, stringLine);
			
			printf("\n");
			printf("Message: ");
			fgets(stringLine2, sizeof(stringLine2), stdin);
			stringLine2[strlen(stringLine2) - 1] = '\0';
		
			strcpy(allmessages[*nMess].mail, stringLine2);

			*nMess+=1;
			bStop = 1;
			
		}
		else if (nValid == 1)
		{
			bStop = 1;
		}
		
	}while(bStop == 0);
	
}

/* funcgroupMessage

	Description - This function gets user input of:
		2) Subject
		3) Message
		
	This is then compared to the acc user Structure.
	Function sends an individual message to a user's personal connections.
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 @param *nMess - contains the total number of messages added into the program.
 @param allmessages - A structure conataining all of the messages.
 
	(void function == does not return anything)
*/

void groupMessage(acc user, int *nUsers, int *nIndex, int *nMess, mess allmessages)
{
	str stringLine;	//input
	message stringLine2;	//input
	int j;	//for loop
	int max;	
	int bStop = 0;
	
	system("cls");
	displayGroupMess();
	
	do{
		fflush(stdin);
		max = strlen(user[*nIndex].connect.link[0]);
			
			if (max != 0)
			{
				printf("\nSubject: ");
				fgets(stringLine, sizeof(stringLine), stdin);
				stringLine[strlen(stringLine) - 1] = '\0';
				
				printf("\n");
				printf("Message: ");
				fgets(stringLine2, sizeof(stringLine2), stdin);
				stringLine2[strlen(stringLine2) - 1] = '\0';
				
				for (j = 0; (max = strlen(user[*nIndex].connect.link[j])) != 0; j++)
				{
					strcpy(allmessages[*nMess].sender, user[*nIndex].username);
					strcpy(allmessages[*nMess].group, user[*nIndex].connect.link[j]);
					strcpy(allmessages[*nMess].subj, "(GROUP MESSAGE) ");
					strcat(allmessages[*nMess].subj, stringLine);
					strcpy(allmessages[*nMess].mail, stringLine2);
					(*nMess)++;
				}
				
				bStop = 1;

			}
			else if (max == 0)
			{
				bStop = 1;
			}
		
	}while(bStop == 0);
}

/* funcannouncementMessage

	Description - This function gets user input of:
		2) Subject
		3) Message
		
	This is then compared to the acc user Structure.
	Function sends message to every user in the program.
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 @param *nMess - contains the total number of messages added into the program.
 @param allmessages - A structure conataining all of the messages.
 
	(void function == does not return anything)
*/
void announcementMessage(acc user, int *nUsers, int *nIndex, int *nMess, mess allmessages)
{
	str stringLine;
	message stringLine2;
	int bStop = 0;
		
	do{
	
		system("cls");
		fflush(stdin);
		displayAnnouncement();
		
		printf("\nSubject: ");
		fgets(stringLine, sizeof(stringLine), stdin);
		stringLine[strlen(stringLine) - 1] = '\0';
		
		strcpy(allmessages[*nMess].subj, stringLine);
		strcpy(allmessages[*nMess].sender, user[*nIndex].username);
		
		printf("\n");
		printf("Message: ");
		fgets(stringLine2, sizeof(stringLine2), stdin);
		stringLine2[strlen(stringLine2) - 1] = '\0';
		
		strcpy(allmessages[*nMess].announcement, stringLine2);
		
		*nMess+=1;
		bStop = 1;
		
		
	}while(bStop == 0);
}

/* funccomposeMessage

	Description - This function gets user input of:
		1) Choice
		
	Function allows user on whether or not they want to send an:
	1) individual message
	2) Group Message
	3) Announcement Message
	4) Go back
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 @param *nMess - contains the total number of messages added into the program.
 @param allmessages - A structure conataining all of the messages.
 
	(void function == does not return anything)
*/
void composeMessage(acc user, int *nUsers, int *nIndex, int *nMess, mess allmessages)
{
	int choose;
	int bStop = 0;
	
	do{
		system("cls"); 
		printf("===============================================================\n");
		printf("==========                                           ==========\n"); 
    	printf("==========              Compose Message              ==========\n"); 
    	printf("===============================================================\n\n");
	    printf("                           MENU\n\n"); 
	    printf("                       [1] Individual\n");
	    printf("                       [2] Group Message\n");
	    printf("                       [3] Announcement\n");
	    printf("                       [4] Get out :(\n");
	    printf("\n                       TYPE CHOICE: ");
	    scanf("%d", &choose);											//User input on where they want to go
	    system("cls");
	    
	    if (choose == 1)
			individualMessage(user, nUsers, nIndex, nMess, allmessages);
		else if (choose == 2)
			groupMessage(user, nUsers, nIndex, nMess, allmessages);
		else if (choose == 3)
			announcementMessage(user, nUsers, nIndex, nMess, allmessages);
		else if (choose == 4)
			bStop = 1;
		else
			bStop = 0;
		
	}while(bStop == 0);
}

/* funcinbox

	Description - This function gets user input of:
		1) whether they want to reply
		2) Subject
		3) Message
		
		Function 
		- allows user to see the messages they received
		- allows user to reply
		- allows user to go back
		
	This is then compared to the user and allmessages Structure.
	Function sends reply to the messgae.
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 @param *nMess - contains the total number of messages added into the program.
 @param allmessages - A structure conataining all of the messages.
 
	(void function == does not return anything)
*/

void inbox(acc user, int *nUsers, int *nIndex, int *nMess, mess allmessages)
{
	
	int choose, max;
	int bStop = 1;
	int i, j;
	int copyIndex, copyUser;
	message stringLine2;

	do{
		system("cls");
		displayInbox();
		fflush(stdin);
		j = 0;
		if (*nMess == 1)
		{
			if(strcmp(user[*nIndex].username, allmessages[0].receiver) == 0 && strlen(allmessages[0].group) == 0)
			{
				printf(BBLU "ID [0] " RST);
				printf(" Sender: %s\n", allmessages[0].sender);
				printf("Subject: %s\n", allmessages[0].subj);
				printf("Message: %s\n", allmessages[0].mail);
			}
			else if(strcmp(user[*nIndex].username, allmessages[0].receiver) != 0 && strlen(allmessages[0].group) != 0)
			{
					printf(BBLU "ID [0] " RST);
					printf(" Sender: %s\n", allmessages[0].sender);
					printf("\nSubject: %s\n", allmessages[0].subj);
					printf("Message: %s\n", allmessages[0].mail);
			}
			
			printf("\nType ID [0] if you want to REPLY\n");
			printf("Or Type [-1] to leave: ");
			scanf("%d", &choose);
			
			if(choose == -1)
				bStop = 0;
			else if (choose == 0 && strcmp(user[*nIndex].username, allmessages[0].receiver) == 0)
			{
				fflush(stdin);
				copyIndex = 0;
				
				if(strlen(allmessages[0].group) == 0)
				{
					strcpy(allmessages[*nMess].sender, user[*nIndex].username);
					strcpy(allmessages[*nMess].receiver, allmessages[0].sender);
			
					strcpy(allmessages[*nMess].subj, allmessages[0].subj);
					
					printf("\n");
					printf("Reply: ");
					fgets(stringLine2, sizeof(stringLine2), stdin);
					stringLine2[strlen(stringLine2) - 1] = '\0';
				
					strcpy(allmessages[*nMess].mail, BBLU "(REPLY) " RST);
					strcat(allmessages[*nMess].mail, stringLine2);
		
					*nMess+=1;
					bStop = 0;
				}
				else if (strlen(allmessages[0].group) != 0)
				{
					fflush(stdin);
					for(i = 0; i < *nUsers; i++)
					{
						if (strcmp(user[i].username, allmessages[0].sender) == 0)
						{
							copyIndex = i;
						}
					}
					printf("\n");
					printf("Reply: ");
					fgets(stringLine2, sizeof(stringLine2), stdin);
					stringLine2[strlen(stringLine2) - 1] = '\0';
	
					for (j = 0; (max = strlen(user[copyIndex].connect.link[j])) != 0; j++)
					{
						strcpy(allmessages[*nMess].sender, user[*nIndex].username);
						if(strcmp(user[copyUser].connect.link[j], user[*nIndex].username) != 0)
						{
							strcpy(allmessages[*nMess].group, user[copyUser].connect.link[j]);
						}
						strcpy(allmessages[*nMess].subj, BBLU "(GROUP MESSAGE) " RST);
						strcpy(allmessages[*nMess].mail, BBLU "(REPLY) " RST);
						strcat(allmessages[*nMess].mail, stringLine2);
						*nMess+=1;
					}
					strcpy(allmessages[*nMess].sender, user[*nIndex].username);
					strcpy(allmessages[*nMess].group, user[copyIndex].username);
					strcpy(allmessages[*nMess].subj, BBLU "(GROUP MESSAGE) " RST);
					strcpy(allmessages[*nMess].subj, allmessages[0].subj);
					strcpy(allmessages[*nMess].mail, BBLU "(REPLY) " RST);
					strcat(allmessages[*nMess].mail, stringLine2);
					*nMess+=1;
				}
			}
			else 
				bStop = 1;
		}
		else if (*nMess > 1)
		{
			for(i = 0; i < *nMess; i++)
			{
				if(strcmp(user[*nIndex].username, allmessages[i].receiver) == 0 && strlen(allmessages[i].group) == 0)
				{
					printf(BBLU "ID [%d] " RST, i);
					printf(" Sender: %s\n", allmessages[i].sender);
					printf("Subject: %s\n", allmessages[i].subj);
					printf("Message: %s\n\n", allmessages[i].mail);
				}
				else if(strcmp(user[*nIndex].username, allmessages[i].receiver) != 0 && strlen(allmessages[i].group) != 0)
				{
					if (strcmp(user[*nIndex].username, allmessages[i].group) == 0)	
					{
						printf(BBLU "ID [%d] " RST, i);
						printf(" Sender: %s\n", allmessages[i].sender);
						printf("\nSubject: %s\n", allmessages[i].subj);
						printf("Message: %s\n\n", allmessages[i].mail);
					}
				}
			}
				
			
			printf("\nType the [ID. No.] you want to REPLY\n");
			printf("Or Type [-1] to leave: ");
			scanf("%d", &choose);
			
			if(choose == -1)
				bStop = 0;
			else if (choose >= 0 && choose < i)
			{
				fflush(stdin);
				copyIndex = choose;
				
				if(strlen(allmessages[copyIndex].group) == 0)
				{
					strcpy(allmessages[*nMess].sender, user[*nIndex].username);
					strcpy(allmessages[*nMess].receiver, allmessages[copyIndex].sender);
			
					strcpy(allmessages[*nMess].subj, allmessages[copyIndex].subj);
					
					printf("\n");
					printf("Reply: ");
					fgets(stringLine2, sizeof(stringLine2), stdin);
					stringLine2[strlen(stringLine2) - 1] = '\0';
				
					strcpy(allmessages[*nMess].mail, BBLU "(REPLY) " RST);
					strcat(allmessages[*nMess].mail, stringLine2);
		
					*nMess+=1;
					bStop = 0;
				}
				else if (strlen(allmessages[copyIndex].group) != 0)
				{
					fflush(stdin);
					for(i = 0; i < *nUsers; i++)
					{
						if (strcmp(user[i].username, allmessages[copyIndex].sender) == 0)
						{
							copyUser = i;
						}
					}
					
					printf("Reply: ");
					fgets(stringLine2, sizeof(stringLine2), stdin);
					stringLine2[strlen(stringLine2) - 1] = '\0';
	
					for (j = 0; (max = strlen(user[copyUser].connect.link[j])) != 0; j++)
					{
						strcpy(allmessages[*nMess].sender, user[*nIndex].username);
						
						if(strcmp(user[copyUser].connect.link[j], user[*nIndex].username) != 0)
						{
							strcpy(allmessages[*nMess].group, user[copyUser].connect.link[j]);
							strcpy(allmessages[*nMess].subj, allmessages[copyIndex].subj);
							strcpy(allmessages[*nMess].mail, BBLU "(REPLY) " RST);
							strcat(allmessages[*nMess].mail, stringLine2);
							*nMess+=1;
						}
						
					}
					strcpy(allmessages[*nMess].sender, user[*nIndex].username);
					strcpy(allmessages[*nMess].group, user[copyUser].username);
					strcpy(allmessages[*nMess].subj, allmessages[copyIndex].subj);
					strcat(allmessages[*nMess].mail, BBLU "(REPLY) " RST);
					strcpy(allmessages[*nMess].mail, stringLine2);
					*nMess+=1;
				}
			}
			else 
				bStop = 1;
		}	
		else if (*nMess == 0)
		{
			printf(BHRED "No Messages :( \n" RST);
			printf("\nPress 1 to leave: ");
			scanf("%d", &choose);
			
			bStop = 0;
		}
		
	}while(bStop == 1);
	
}


/* funcsent

	Description - This function displays:
		1) Messages sent by user
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 @param *nMess - contains the total number of messages added into the program.
 @param allmessages - A structure conataining all of the messages.
 
	(void function == does not return anything)
*/

void sent(acc user, int *nUsers, int *nIndex, int *nMess, mess allmessages)
{
	int choose, max;
	int bStop = 1;
	int i, j, k;
		displaySent();
	do{
		j = 0;
		k = 0;
		if (*nMess == 1)
		{
			if(strcmp(user[*nIndex].username, allmessages[0].sender) == 0 && strlen(allmessages[0].group) == 0)
			{
				printf(BBLU "[0] " RST);
				printf("Receiver: %s\n", allmessages[0].receiver);
				printf("Subject: %s\n", allmessages[0].subj);
				printf("Message: %s\n\n", allmessages[0].mail);
			}
			else if(strcmp(user[*nIndex].username, allmessages[0].sender) == 0 && strlen(allmessages[0].group) != 0)
			{
				printf(BBLU "[0] " RST);
				printf("Receivers: ");
				for(k = 0; (max = strlen(user[*nIndex].connect.link[j])) != 0; k++)
					printf("%s\n", allmessages[k].group);
				printf("\nSubject: %s\n", allmessages[0].subj);
				printf("Message: %s\n\n", allmessages[0].mail);
			}
			
			printf("\nPress any number to leave: ");
			scanf("%d", &choose);
			
			bStop = 0;
		}
		else if (*nMess > 1)
		{	
			for(i = 0; i < *nMess; i++)
			{
				if(strcmp(user[*nIndex].username, allmessages[i].sender) == 0 && strlen(allmessages[i].group) == 0)
				{
					if(strlen(allmessages[i].announcement) != 0)
					{	
						printf(BBLU "[%d]" RST, j);
						printf(" Sender: %s\n", allmessages[i].sender);
						printf(" Subject: %s\n", allmessages[i].subj);
						printf(" Announcement: %s\n\n", allmessages[i].announcement);
						printf("\n");
						j+= 1;
					}
					else
					{
					
						printf(BBLU "[%d] " RST, j);
						printf("Receiver: %s\n", allmessages[i].receiver);
						printf("Subject: %s\n", allmessages[i].subj);
						printf("Message: %s\n\n", allmessages[i].mail);
						j+= 1;
					}
				}
				else if(strcmp(user[*nIndex].username, allmessages[i].sender) == 0 && strlen(allmessages[i].group) != 0)
				{
					printf(BBLU "[%d] " RST, j);
					printf("Receivers: ");
					printf("%s\n", allmessages[i].group);
					printf("\nSubject: %s\n", allmessages[i].subj);
					printf("Message: %s\n\n", allmessages[i].mail);
					j += 1;
					k += 1;
				}
			}
				
			
			printf("\nPress 1 to leave: ");
			scanf("%d", &choose);
			
			bStop = 0;
		}	
		else if (*nMess == 0)
		{
			printf(BHRED "No Messages :( \n" RST);
			printf("\nPress 1 to leave: ");
			scanf("%d", &choose);
			
			bStop = 0;
		}
		
		
	}while(bStop == 1);
}

/* funcviewAnnouncement

	Description - This function displays:
		1) Announcement
		
	Function:
	-reply to announcement
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 @param *nMess - contains the total number of messages added into the program.
 @param allmessages - A structure conataining all of the messages.
 
	(void function == does not return anything)
*/

void viewAnnouncement(acc user, int *nIndex, int *nMess, mess allmessages)
{
	int choose, copyIndex;
	int bStop = 0;
	int i, j = 0;
	message stringLine2;
	
	do{
		j = 0;
		system("cls"); 
		fflush(stdin);
		printf("===============================================================\n");
		printf("==========                                           ==========\n"); 
    	printf("==========            Display Announcement           ==========\n"); 
    	printf("===============================================================\n\n");
		
		for(i = 0; i < *nMess; i++)
		{
			if(strlen(allmessages[i].announcement) != 0)
			{
				printf(BBLU"[%d]"RST, j);
				printf("Sender: %s\n", allmessages[i].sender);
				printf(" Subject: %s\n", allmessages[i].subj);
				printf(" Announcement: %s\n", allmessages[i].announcement);
				printf("\n");
				j+= 1;
			}
		}
		printf("Type [No.] to REPLY\n");
		printf("or Type [-1] to leave: ");
		scanf("%d", &choose);
		
		if(choose == -1)
			bStop = 1;
		else if (choose >= 0 && choose < *nMess)
		{
			copyIndex = choose;
			
			do{
			
				system("cls");
				fflush(stdin);
				displayAnnouncement();

				strcpy(allmessages[*nMess].subj, allmessages[copyIndex].subj);
				strcpy(allmessages[*nMess].sender, user[*nIndex].username);
				
				printf("\n");
				printf("Reply: ");
				fgets(stringLine2, sizeof(stringLine2), stdin);
				stringLine2[strlen(stringLine2) - 1] = '\0';
				
				strcpy(allmessages[*nMess].announcement, stringLine2);
				
				*nMess+=1;
				bStop = 1;
				
				
			}while(bStop == 0);
			
		}
		else
			bStop = 0;
		
	}while(bStop == 0);
}

/* funcmodifyPersonalContents

	Description - This function gets user input of:
		1) Modify Name
		2) Modify Description
		3) Exit
		
	Function allows user to choose
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.

	(void function == does not return anything)
*/

void modifyPersonalContents(acc user, int *nUsers, int *nIndex)
{
	int choose;
	int bStop = 0;
	
	do{
		system("cls");
		printf("===============================================================\n");
		printf("==========                                           ==========\n"); 
    	printf("==========          Modify Personal Contents         ==========\n"); 
    	printf("===============================================================\n\n"); 
	    printf("                           MENU\n\n"); 
	    printf("                      [1] Modify Name\n");
	    printf("                      [2] Modify Description\n");
	    printf("                      [3] Exit :(\n");
	    printf("\n                      TYPE CHOICE: ");
	    scanf("%d", &choose);											//User input on where they want to go
	    system("cls");
	    
	    if (choose == 1)
			ModifyName(user, nUsers, nIndex);
		else if (choose == 2)
			ModifyDescription(user, nUsers, nIndex);
		else if (choose == 3)
			bStop = 1;
		else
			bStop = 0;
			
	}while(bStop == 0);
	
}

/* funcModifyPassword

	Description - This function gets user input of:
		1) Current Password
		2) New Password
		
	This is then compared to the acc user Structure.
	Function Modifies user's password.
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.

	(void function == does not return anything)
*/

void ModifyPassword(acc user, int *nUsers, int *nIndex)
{
	str stringLine;
	char choose;
	int bStop = 0;
	int nAttempts = 1;;
	int nValid;
	
	do{
		fflush(stdin);
		system("cls");
		displayModifyPassword();
		// Get Password, place and placing it at char password[MAX_PASS]
		printf("Enter CURRENT password (3 Attempts): ");
		fgets(stringLine,sizeof(stringLine), stdin);
		stringLine[strlen(stringLine)-1] = '\0';
		
		while(strcmp(user[*nIndex].password, stringLine) != 0 && nAttempts <= 3)
		{
			system("cls");
			displayModifyName();
			printf("WRONG PASSWORD!\n");
			
	        printf("Enter your password: ");
			fgets(stringLine,sizeof(stringLine), stdin);
			stringLine[strlen(stringLine)-1] = '\0';
			
			if(strcmp(user[*nIndex].password, stringLine) != 0)
			{
				nValid = 1;
				nAttempts++;
			}
			else
				nValid = 0;
		}
		
		if (nValid == 1)
		{
			bStop = 1;
		}
		else if (nValid == 0)
		{
			printf("Enter new password (MAX = 20): ");
			fgets(stringLine,sizeof(stringLine), stdin);
			stringLine[strlen(stringLine)-1] = '\0';
			strcpy(user[*nUsers].password, stringLine);
			
			while(strlen(user[*nUsers].password) > 20)
			{
				system("cls");
				displayCreateanAccount();
				printf(BHRED "Password SIZE over the limit.\n" RST);
				printf(BHRED "TRY AGAIN!\n\n" RST);
				
				printf("Enter new password (MAX = 20): ");
				fgets(stringLine,sizeof(stringLine), stdin);
				stringLine[strlen(stringLine)-1] = '\0';
				strcpy(user[*nUsers].password, stringLine);
			}
			
			printf("Confirm password: ");
			fgets(stringLine,sizeof(stringLine), stdin);
			stringLine[strlen(stringLine)-1] = '\0';
			
			while(strcmp(user[*nUsers].password, stringLine) != 0)
			{
				system("cls");
				displayCreateanAccount();
				printf(BHRED "Passwords do not match. Please try again.\n" RST);
				
		        printf("Enter password (MAX = 20): ");
				fgets(stringLine,sizeof(stringLine), stdin);
				stringLine[strlen(stringLine)-1] = '\0';
				strcpy(user[*nUsers].password, stringLine);
				
				while(strlen(user[*nUsers].password) > 20)
				{
					system("cls");
					displayCreateanAccount();
					printf(BHRED"Password Size over the limit.\n" RST);
					printf(BHRED "TRY AGAIN!\n\n" RST);
					
					printf("Enter password (MAX = 20): ");
					fgets(stringLine,sizeof(stringLine), stdin);
					stringLine[strlen(stringLine)-1] = '\0';
					strcpy(user[*nUsers].password, stringLine);
				}
			
				printf("Confirm password: ");
				fgets(stringLine,sizeof(stringLine), stdin);
				stringLine[strlen(stringLine)-1] = '\0';
			}
			
			strcpy(user[*nIndex].password, stringLine);
			
			system("cls");
			displayModifyName();
			printf("Your new password is: %s\n", user[*nIndex].password);
			
			printf("Wanna change it again? \n");
			printf("TYPE [Y]es or [N]o: ");
			choose = getchar();
			
			if (choose == 'Y')
				bStop = 0;
			else if (choose == 'y')
				bStop = 0;
			else if (choose == 'N')
				bStop = 1;
			else if (choose == 'n')
				bStop = 1;
		}
	
	}while(bStop == 0);
}

/* funcModifyAnswer

	Description - This function gets user input of:
		1) Answer
		
	Function modifies security answer.
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 
	(void function == does not return anything)
*/

void ModifyAnswer(acc user, int *nUsers, int *nIndex)
{
	str stringLine;
	char choose;
	int bStop = 0;
	//str copy; //A copy of the New Answer
	
	do{
		fflush(stdin);
		system("cls");
		displaySecurityAnswer();
		printf("Security Question: %s\n", user[*nIndex].user_question);
		printf("Current Answer: %s\n\n", user[*nIndex].answer);
		
		printf("Type your new Answer: ");
		fgets(stringLine, sizeof(stringLine), stdin);
		stringLine[strlen(stringLine) - 1] = '\0';
		strcpy(user[*nIndex].answer, stringLine);
		
		printf("Confirm Answer: ");
		fgets(stringLine,sizeof(stringLine), stdin);
		stringLine[strlen(stringLine)-1] = '\0';
	
		while(strcmp(user[*nIndex].answer, stringLine) != 0)
		{
			system("cls");
			displaySecurityAnswer();
			printf(BHRED "Answers do not match. Please try again.\n" RST);
			
	        printf("Type Answer: ");
			fgets(stringLine,sizeof(stringLine), stdin);
			stringLine[strlen(stringLine)-1] = '\0';
			strcpy(user[*nIndex].answer, stringLine);
		
			printf("Confirm answer: ");
			fgets(stringLine,sizeof(stringLine), stdin);
			stringLine[strlen(stringLine)-1] = '\0';
		}
			strcpy(user[*nIndex].answer, stringLine);
		
		system("cls");
	displaySecurityAnswer();
		printf("Your new answer is: %s\n", user[*nIndex].answer);
		
		printf("Wanna change it again? \n");
		printf("TYPE [Y]es or [N]o: ");
		choose = getchar();
		
		if (choose == 'Y')
			bStop = 0;
		else if (choose == 'y')
			bStop = 0;
		else if (choose == 'N')
			bStop = 1;
		else if (choose == 'n')
			bStop = 1;	
	
	}while(bStop == 0);
}

/* funcmodifyAccountSecurity

	Description - This function gets user input of:
		1) Modify Password
		2) Modify Answer
		3) Exit
		
	Function allows user to choose
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 
	(void function == does not return anything)
*/

void modifyAccountSecurity(acc user, int *nUsers, int *nIndex)
{
	
	int choose;
	int bStop = 0;
	
	do{
		system("cls");
		displayModifySecurity();
	    printf("                          MENU\n\n"); 
	    printf("                   [1] Modify Password\n");
	    printf("                   [2] Modify Answer\n");
	    printf("                   [3] Exit :(\n");
	    printf("\n                   TYPE CHOICE: ");
	    scanf("%d", &choose);											//User input on where they want to go
	    system("cls");
	    
	    if (choose == 1)
			ModifyPassword(user, nUsers, nIndex);
		else if (choose == 2)
			ModifyAnswer(user, nUsers, nIndex);
		else if (choose == 3)
			bStop = 1;
	}while(bStop == 0);

}

/* funcaddPC

	Description - This function gets user input of:
		1) Username
		2) List
		3) Exit
		
	Function:
	- displays all users in the program
	- allows user to add personal connection
		- via username
		- via list
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 
	(void function == does not return anything)
*/

void addPC(acc user, int *nUsers, int *nIndex)
{
	int bStop = 0, bStop2;
	int choose;
	char choose1;
	str stringLine;
	int userVal, nValid, nValid2;
	int i, k, j;
	int comp;
	
	fflush(stdin);
	
	do{
		system("cls"); 
		printf("===============================================================\n");
		printf("==========                                           ==========\n"); 
    	printf("==========         Add a Personal Connection         ==========\n"); 
    	printf("===============================================================\n\n");
	    printf("               MENU\n\n"); 
	    printf("   [1] Add via Username\n");
	    printf("   [2] Add via List\n");
	    printf("   [3] Exit :(\n");
	    printf("\nTYPE CHOICE: ");
	    scanf("%d", &choose);											//User input on where they want to go
	    system("cls");
		
	    if (choose == 1)
			{
				do{
				fflush(stdin);
				userVal = 1;
				nValid = 1;
				nValid2 = 0;
				bStop2 = 0;
				k = 0;
				
				system("cls");
				printf("Enter Username (Type [No] if none): ");
				fgets(stringLine,sizeof(stringLine), stdin);
				stringLine[strlen(stringLine)-1] = '\0';

				if (strcmp(user[*nIndex].username, stringLine) == 0)
					userVal = 1;
				else if (strcmp(user[*nIndex].username, stringLine) != 0)
				{
					if(strcmp(stringLine, "No") == 0)
						bStop2 = 1;
					else if(strcmp(stringLine, "NO") == 0)
						bStop2 = 1;
					else if(strcmp(stringLine, "no") == 0)
						bStop2 = 1;
					else if(strcmp(stringLine, "nO") == 0)
						bStop2 = 1;
					else if ((comp = strlen(user[*nIndex].connect.link[k])) == 0)
					{
						for (i = 0; i < *nUsers && nValid == 1; i++)
						{
							if (strcmp(user[i].username, stringLine) == 0)
							{
								nValid = 0;
							}
						}
						
						if (nValid == 1)
							userVal = 1;
						else if (nValid == 0)
						{
							userVal = 0;
							strcpy(user[*nIndex].connect.link[k], stringLine);
							//user[*nIndex].connect.j += 1;
						}
					}
					else if ((comp = strlen(user[*nIndex].connect.link[k])) != 0)
					{
						for (i = 0; i < *nUsers && nValid == 1; i++)
						{
							if (strcmp(user[i].username, stringLine) == 0)
							{
								nValid = 0;
							}
						}
						
						if (nValid == 1)
							userVal = 1;
						else if (nValid == 0)
						{
							for (j = 0; j < MAX_USER && nValid2 == 0; j++)
							{
								if (strcmp(user[*nIndex].connect.link[j], stringLine) == 0)
								{
									nValid2 = 1;
								}
							}
							
							if (nValid2 == 1)
								userVal = 1;
							else if (nValid2 == 0)
							{
								userVal = 0;
								while((comp = strlen(user[*nIndex].connect.link[k])) != 0)
								{
									k++;
								}
								
								strcpy(user[*nIndex].connect.link[k], stringLine);
								//user[*nIndex].connect.j += 1;
							}
						}
					}
				}
				
				if (userVal == 1)
				{
					system("cls");
					printf(BHRED "SAME USERNAME OR WRONG USERNAME INPUT!\n" RST);
					printf("Press any letter to continue: ");
					scanf("%c", &choose1);
					bStop2 = 1;
				}
				else if (userVal == 0)
				{
					system("cls");
					printf(GRN "User has been added! :)\n" RST);
					
					printf("Add another Username? [Y]es or [N]o \n");
					printf("TYPE CHOICE: ");
					choose1 = getchar();
					
					if(choose1 == 'N')
						bStop2 = 1;
					else if (choose1 == 'n')
						bStop2 = 1;
				}
				
			}while(bStop2 == 0);
				
			}
			
			
		else if(choose == 2)
		{
			do{
				fflush(stdin);
				userVal = 1;
				nValid = 1;
				nValid2 = 0;
				bStop2 = 0;
				k = 0;
				
				system("cls");
				for (i = 0; i < *nUsers; i++)
					{
						printf("[%d] %s \n", i, user[i].username);
					}
				printf("Enter Username (Type [No] if none): ");
				fgets(stringLine,sizeof(stringLine), stdin);
				stringLine[strlen(stringLine)-1] = '\0';

				if (strcmp(user[*nIndex].username, stringLine) == 0)
					userVal = 1;
				else if (strcmp(user[*nIndex].username, stringLine) != 0)
				{
					if(strcmp(stringLine, "No") == 0)
						bStop2 = 1;
					else if(strcmp(stringLine, "NO") == 0)
						bStop2 = 1;
					else if(strcmp(stringLine, "no") == 0)
						bStop2 = 1;
					else if(strcmp(stringLine, "nO") == 0)
						bStop2 = 1;
					else if ((comp = strlen(user[*nIndex].connect.link[k])) == 0)
					{
						for (i = 0; i < *nUsers && nValid == 1; i++)
						{
							if (strcmp(user[i].username, stringLine) == 0)
							{
								nValid = 0;
							}
						}
						
						if (nValid == 1)
							userVal = 1;
						else if (nValid == 0)
						{
							userVal = 0;
							strcpy(user[*nIndex].connect.link[k], stringLine);
							//user[*nIndex].connect.j += 1;
						}
					}
					else if ((comp = strlen(user[*nIndex].connect.link[k])) != 0)
					{
						for (i = 0; i < *nUsers && nValid == 1; i++)
						{
							if (strcmp(user[i].username, stringLine) == 0)
							{
								nValid = 0;
							}
						}
						
						if (nValid == 1)
							userVal = 1;
						else if (nValid == 0)
						{
							for (j = 0; j < MAX_USER && nValid2 == 0; j++)
							{
								if (strcmp(user[*nIndex].connect.link[j], stringLine) == 0)
								{
									nValid2 = 1;
								}
							}
							
							if (nValid2 == 1)
								userVal = 1;
							else if (nValid2 == 0)
							{
								userVal = 0;
								while((comp = strlen(user[*nIndex].connect.link[k])) != 0)
								{
									k++;
								}
								
								strcpy(user[*nIndex].connect.link[k], stringLine);
								//user[*nIndex].connect.j += 1;
							}
						}
					}
				}
				
				if (userVal == 1)
				{
					system("cls");
					printf(BHRED "SAME USERNAME OR WRONG USERNAME INPUT!\n" RST);
					printf("Press any letter to continue: ");
					scanf("%c", &choose1);
					bStop2 = 1;
				}
				else if (userVal == 0)
				{
					system("cls");
					printf(GRN "User has been added! :)\n" RST);
					
					printf("Add another Username? [Y]es or [N]o \n");
					printf("TYPE CHOICE: ");
					choose1 = getchar();
					
					if(choose1 == 'N')
						bStop2 = 1;
					else if (choose1 == 'n')
						bStop2 = 1;
				}
				
			}while(bStop2 == 0);
				
		}
		else if (choose == 3)
			bStop = 1;
			
	}while(bStop == 0);
	
	
}

/* funcviewPC

	Description - This function displays:
		1) USer's personal connection
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 
	(void function == does not return anything)
*/

void viewPC(acc user, int *nUsers, int *nIndex)
{
	int i, choice;
	int max;
	
	
	printf("===============================================================\n");
	printf("==========                                           ==========\n"); 
    printf("==========        View a Personal Connection         ==========\n"); 
    printf("===============================================================\n\n");
	for (i = 0; (max = strlen(user[*nIndex].connect.link[i])) != 0; i++)
	{	
		printf("ID [%d] %s \n", i, user[*nIndex].connect.link[i]);
	}
	
	printf("TYPE [1] to go back: ");
	scanf("%d", &choice);
}

/* funcremovePC

	Description - This function gets user input of:
		1) Username
		
	Function:
	- Deletes User's personal connection
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 
	(void function == does not return anything)
*/

void removePC(acc user, int *nUsers, int *nIndex)
{
	int i, j;
	int bStop = 0;
	int choose, copyIndex;
	int max;
	
	do{
		system("cls");
		printf("===============================================================\n");
		printf("==========                                           ==========\n"); 
    	printf("==========            Remove a Connection            ==========\n"); 
   		 printf("===============================================================\n\n");
	    
	    	for (i = 0; (max = strlen(user[*nIndex].connect.link[i])) != 0; i++)
			{	
				printf("ID [%d] %s \n", i, user[*nIndex].connect.link[i]);
			}
			
			printf("\nType [ID No.] to REMOVE Connection\n");
			printf("TYPE [-1] to go back: ");
			scanf("%d", &choose);
			
			if(choose == -1)
				bStop = 1;
			else if (choose >= 0 && choose <= i)
			{
				copyIndex = choose;
				
				for (j = copyIndex; j < MAX_USER - 1; j++)
				{
					strcpy(user[*nIndex].connect.link[j], user[*nIndex].connect.link[j+1]);
				}
				
			}
			else
				bStop = 0;
			
	}while(bStop == 0);
}

/* funcindividualMessage

	Description -
		
	Function:
	- allows user to check who added them as a connection
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 
	(void function == does not return anything)
*/

void viewUC(acc user, int *Users, int *nIndex)
{
	int i, choice, k;
	
	
	printf("===============================================================\n");
	printf("==========                                           ==========\n"); 
    printf("==========            View User Connection           ==========\n"); 
    printf("===============================================================\n\n");
	for (i = 0; i < MAX_USER; i++)
	{
		for (k = 0; k < MAX_USER; k++)
		{
			if (strcmp(user[*nIndex].username, user[i].connect.link[k]) == 0)
				printf("%s \n", user[i].username);
		}
	}
	
	printf("TYPE [1] to go back: ");
	scanf("%d", &choice);
	
}

/* funcmodifyPersonalConnections

	Description - This function gets user input of:
		1) Add PC
		2) View PC
		3) Remove PC
		4) View User connection
		5) Exit
		
	Function allows user to choose
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 
	(void function == does not return anything)
*/

void modifyPersonalConnections(acc user, int *nUsers, int *nIndex)
{
	int choose;
	int bStop = 0;

	do{
		system("cls");
		printf("===============================================================\n");
		printf("==========                                           ==========\n"); 
   		printf("==========        Modify Personal Connections        ==========\n"); 
  	    printf("===============================================================\n\n");
	    printf("                          MENU\n\n"); 
	    printf("               [1] Add a Personal Connection\n");
	    printf("               [2] View personal connections\n");
	    printf("               [3] Remove a personal connection\n");
	    printf("               [4] View user connections\n");
	    printf("               [5] Exit :(\n");
	    printf("\n                     TYPE CHOICE: ");
	    scanf("%d", &choose);											//User input on where they want to go
	    system("cls");
	    
	    if (choose == 1)
			addPC(user, nUsers, nIndex);
		else if (choose == 2)
			viewPC(user, nUsers, nIndex);
		else if (choose == 3)
			removePC(user, nUsers, nIndex);
		else if (choose == 4)
			viewUC(user, nUsers, nIndex);
		else if (choose == 5)
			bStop = 1;
		else
			bStop = 0;
			
	}while(!bStop);
	    
	    
}

/* funcmessageViaBrowse

	Description - This function gets user input of:
		1) Subject
		2) Message
		
	Function:
	- user can send a private message to the chosen user
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 @param *nMess - contains the total number of messages added into the program.
 @param allmessages - A structure conataining all of the messages.
 
	(void function == does not return anything)
*/

void messageViaBrowse(acc user, int *nUsers, int *nIndex, int copyIndex, mess allmessages, int *nMess)
{
	int bStop = 0;
	str stringLine;
	message stringLine2;
	
	system("cls");
	displayBrowseUser();
	
	
	do{
		fflush(stdin);
		
		if (strcmp(user[*nIndex].username, user[copyIndex].username) != 0)
		{
			printf("Sending to: %s\n", user[copyIndex].username);
			strcpy(allmessages[*nMess].sender, user[*nIndex].username);
			strcpy(allmessages[*nMess].receiver, user[copyIndex].username);
			
			printf("\nSubject: ");
			fgets(stringLine, sizeof(stringLine), stdin);
			stringLine[strlen(stringLine) - 1] = '\0';
	
			strcpy(allmessages[*nMess].subj, stringLine);
			
			printf("\n");
			printf("Message: ");
			fgets(stringLine2, sizeof(stringLine2), stdin);
			stringLine2[strlen(stringLine2) - 1] = '\0';
		
			strcpy(allmessages[*nMess].mail, stringLine2);
	
			*nMess+=1;
			bStop = 1;
		}
		else
			bStop = 1;
		
	}while(bStop == 0);
}

/* funcassPCViaBrowse

	Description - 
	
	Function:
	- user adds connection to the chosen user
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 @param copyIndex - A user's ID
 
	(void function == does not return anything)
*/

void addPCViaBrowse(acc user, int *nUsers, int *nIndex, int copyIndex)
{
	int bStop = 0;
	int choose;
	int nValid;
	int i, k;
	int comp;
	
	do{
		system("cls");
		displayBrowseUser();
		nValid = 0;
		k = 0;
		
		for(i = 0; i < MAX_USER && nValid == 0; i++)
		{
			if (strcmp(user[*nIndex].connect.link[i], user[copyIndex].username) == 0)
			{
				nValid = 1;
			}
			else if (strcmp(user[*nIndex].username, user[copyIndex].username) == 0)
			{
				nValid = 1;
			}
		}
		
		if (nValid == 1)
		{
			printf(BHRED "USER ALREADY ADDED or YOU ARE TRYING TO ADD YOURSELF!\n" RST);
			printf("Press any No. to go back: ");
			scanf("%d", &choose);
			bStop = 1;
		}
		else if (nValid == 0)
		{
			while((comp = strlen(user[*nIndex].connect.link[k])) != 0)
			{
				k++;
			}
			
			strcpy(user[*nIndex].connect.link[k], user[copyIndex].username);
			printf(GRN "NEW USER ADDED!\n" RST);
			printf("Press any No. to go back: ");
			scanf("%d", &choose);
			
			bStop = 1;
		}
		
	}while(bStop == 0);
}

/* funcbrowseViaAllUsers

	Description - This function gets user input of:
		1) Subject
		2) Message
		
	Function:
	- display all users in the program
	- if user wants to send a message
	- if user wants to add them as a conection
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 @param *nMess - contains the total number of messages added into the program.
 @param allmessages - A structure conataining all of the messages.
 
	(void function == does not return anything)
*/

void browseViaAllUsers(acc user, int *nUsers, int *nIndex, mess allmessages, int *nMess)
{
	int i, choose, choose2;
	int bStop = 0;
	int copyIndex;
	
	do{
		system("cls");
		displayBrowseUser();
		for(i = 0; i < *nUsers; i++)
		{
			printf("[%d] %s\n", i, user[i].name);
				
			printf("\n");				
		}
		
		printf("\nType No. to check their Information\n");
		printf("or Press [-1] to go back: ");
		scanf("%d", &choose);
		
		if(choose == -1)
			bStop = 1;
		else if (choose < *nUsers && choose >= 0)
		{
			copyIndex = choose; //copyIndex will be used to get information of the chosen name.
			system("cls");
			displayBrowseUser();
			
			printf("Username: %s\n", user[copyIndex].username);
			printf("Real Name: %s\n", user[copyIndex].name);
			printf("Description: %s\n\n", user[copyIndex].description);
			
			printf("Press [1] to Add User \n");
			printf("Press [2] to Send Private Message \n");
			printf("Press any [No.] to go back: ");
			scanf("%d", &choose2);
			
			if(choose2 == 1)
				addPCViaBrowse(user, nUsers, nIndex, copyIndex);
			else if (choose2 == 2)
				messageViaBrowse(user, nUsers, nIndex, copyIndex, allmessages, nMess);
			else
				bStop = 1;
		}
		else
			bStop = 0;
		
	}while(bStop == 0);
}

/* funcbrowseViaByName

	Description - This function gets user input of:
		1) username

	Function:
	- user can search for a user via typing name
	- can add user
	- can message user
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 @param *nMess - contains the total number of messages added into the program.
 @param allmessages - A structure conataining all of the messages.
 
	(void function == does not return anything)
*/

void browseViaByName(acc user, int *nUsers, int *nIndex, mess allmessages, int *nMess)
{
	int bStop = 0;
	int choose, choose2, copyIndex;
	char character, comparechar;
	int i, j;
	
	do{
		fflush(stdin);
		system("cls");
		displayBrowseUser();
		
		printf("Enter the First Letter of Name (Be mindful of Caps): ");
		scanf("%c", &character);
		
		for (i = 0; i < *nUsers; i++)
		{
			j = 0;
			comparechar = user[i].name[j];
			if(comparechar == character)
				printf("[%d] %s \n", i, user[i].name);
			
		}

		printf("\nType No. to check their Information\n");
		printf("or Press [-1] to go back: ");
		scanf("%d", &choose);
		
		if(choose == -1)
			bStop = 1;
		else if (choose < *nUsers && choose >= 0)
		{
			copyIndex = choose; //copyIndex will be used to get information of the chosen name.
			system("cls");
			displayBrowseUser();
			
			printf("Username: %s\n", user[copyIndex].username);
			printf("Real Name: %s\n", user[copyIndex].name);
			printf("Description: %s\n\n", user[copyIndex].description);
			
			printf("Press [1] to Add User \n");
			printf("Press [2] to Send Private Message \n");
			printf("Press any [No.] to go back: ");
			scanf("%d", &choose2);
			
			if(choose2 == 1)
				addPCViaBrowse(user, nUsers, nIndex, copyIndex);
			else if (choose2 == 2)
				messageViaBrowse(user, nUsers, nIndex, copyIndex, allmessages, nMess);
			else
				bStop = 1;
		}
		else
			bStop = 0;
			
	}while(bStop == 0);
}

/* funcbrowseUsers

	Description - This function gets user input of:
		1) All users
		2) Filter by  name
		3) log out
		
	Function:
	- user can choose what they want to do
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 @param *nMess - contains the total number of messages added into the program.
 @param allmessages - A structure conataining all of the messages.
 
	(void function == does not return anything)
*/

void browseUsers(acc user, int *nUsers, int *nIndex, int *nMess, mess allmessages)
{
	int bStop = 0;
	int choose;
	
	do{
		system("cls");
		displayBrowseUser();
		
		printf("                         MENU\n\n"); 
	    printf("                     [1] All Users\n");
	    printf("                     [2] Filter by Name\n");
	    printf("                     [3] Log Out :(\n");
	    printf("\n                    TYPE CHOICE: ");
	    scanf("%d", &choose);											//User input on where they want to go
	    system("cls");
	    
	    if (choose == 1)
			browseViaAllUsers(user, nUsers, nIndex, allmessages, nMess);
		else if (choose == 2)
			browseViaByName(user, nUsers, nIndex, allmessages, nMess);
		else if (choose == 3)
			bStop = 1;
		
	}while(bStop == 0);
}

/* funcuserModule

	Description - This function gets user input:
		1) on what they want to do on the usermodule
		
	Function:
	- compose message
	- inbox
	- sent
	- announcements
	- personal contents
	- personal security
	- personal connections
	- browse users
	- log out
	
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 @param *nMess - contains the total number of messages added into the program.
 @param allmessages - A structure conataining all of the messages.
 
	(void function == does not return anything)
*/

void userModule(acc user, int *nUsers, int *nIndex, int *nMess, mess allmessages)
{
	int check;
	int bStop = 0;
	int choose;
	
	check = logInUser(user, nUsers, nIndex);
	
	if (check == 1)
	{
	
		do{
			system("cls");
			printf("===============================================================\n");
			printf("==========                                           ==========\n"); 
 		    printf("==========                USER MODULE                ==========\n"); 
  		    printf("===============================================================\n\n");
		    printf("                           MENU\n\n"); 
		    printf("                    [1] Compose Message\n");
		    printf("                    [2] Inbox\n");
		    printf("                    [3] Sent\n");
		    printf("                    [4] View Announcements\n");
		    printf("                    [5] Modify Personal Contents\n");
		    printf("                    [6] Modify Account Security\n");
		    printf("                    [7] Modify Personal Connections\n");
		    printf("                    [8] Browse Users\n");
		    printf("                    [9] Log Out :(\n");
		    printf("\n                    TYPE CHOICE: ");
		    scanf("%d", &choose);											//User input on where they want to go
		    system("cls");
		    
		    if (choose == 1)
				composeMessage(user, nUsers, nIndex, nMess, allmessages);
			else if (choose == 2)
				inbox(user, nUsers, nIndex, nMess, allmessages);
			else if (choose == 3)
				sent(user, nUsers, nIndex, nMess, allmessages);
			else if (choose == 4)
				viewAnnouncement(user, nIndex, nMess, allmessages);
			else if (choose == 5)
				modifyPersonalContents(user, nUsers, nIndex);
			else if (choose == 6)
				modifyAccountSecurity(user, nUsers, nIndex);
			else if (choose == 7)
				modifyPersonalConnections(user, nUsers, nIndex);
			else if (choose == 8)
				browseUsers(user, nUsers, nIndex, nMess, allmessages);
			else if (choose == 9)
				bStop = 1;
			else
				bStop = 0;
	    
		}while (!bStop);
	}
}

/* funcviewUser

	Description - 
		
	Function:
	- displays user's information
	

 @param user - A structure containing all of a user's information
 @param *nUsers - contains the total number of users added into the program
 @param *nIndex - this variable is considered the User's ID to check who is logged in.
 
	(void function == does not return anything)
*/

void viewUser(acc user, int *nUsers, int *nIndex)
{
	int i, j;
	int choose;
	int bStop = 1;
	str Temp;
	int num;

	do{
		do{
			for(i = 0; i < *nUsers; i++)
			{
				strcpy(Temp, user[i].password);
				num = strlen(Temp);
				for(j = 0; j < num; j++)
				{
					Temp[j] = Temp[j] + 3;
				}
				if(user[i].Locked == 0)
					printf("Account = Unlocked\n");
				else
					printf("Account = Locked\n");
				printf("[%d] %s\n", i, user[i].username);
				printf("	Name: %s\n", user[i].name);
				printf("	Password: %s\n", Temp);
				printf("	Description: %s\n\n", user[i].description);
				printf("	Personal Connection => \n");
				for (j = 0; strlen(user[i].connect.link[j]) != 0; j++)
					printf("		%s\n", user[i].connect.link[j]);	
					
				printf("\n");				
			}
		
			printf("Wanna go back?\n");
			printf("Type [1]: ");
			scanf("%d", &choose);
		
			if(choose == 1)
				bStop = 0;
			else
				bStop = 1;
			
		}while(bStop == 1);
		
	}while(bStop == 1);
}


/* funcadminModifyName
		
	Function:
	- Admin changes a user's name
	

 @param user - A structure containing all of a user's information
 @param Temp - A user's ID
 
	(void function == does not return anything)
*/

void adminModifyName(acc user, int Temp)
{
	int bStop = 0;
	str stringLine;
	char choose;
	
	do{
		fflush(stdin);
		system("cls");
		displayModifyUser();
		printf("Current Name: %s\n", user[Temp].name);
		printf("Enter new Name: ");
		fgets(stringLine,sizeof(stringLine), stdin);
		stringLine[strlen(stringLine)-1] = '\0';
	
		strcpy(user[Temp].name, stringLine);
		
		system("cls");
		displayModifyUser();
		printf("%s's' new Name is: %s\n", user[Temp].username, user[Temp].name);
		
		printf("Wanna change it again? \n");
		printf("TYPE [Y]es or [N]o: ");
		choose = getchar();
		
		if (choose == 'Y')
			bStop = 0;
		else if (choose == 'y')
			bStop = 0;
		else if (choose == 'N')
			bStop = 1;
		else if (choose == 'n')
			bStop = 1;
			
	}while(bStop == 0);
}

/* funcadminModifyusername
		
	Function:
	- Admin changes a user's username
	

 @param user - A structure containing all of a user's information
 @param Temp - A user's ID
 
	(void function == does not return anything)
*/

void adminModifyUsername(acc user, int Temp)
{
	int bStop = 0;
	str stringLine;
	char choose;
	
	do{
		fflush(stdin);
		system("cls");
		displayModifyUser();
		printf("Current Username: %s\n", user[Temp].username);
		printf("Enter new Username: ");
		fgets(stringLine,sizeof(stringLine), stdin);
		stringLine[strlen(stringLine)-1] = '\0';
	
		strcpy(user[Temp].username, stringLine);
		
		system("cls");
		displayModifyUser();
		printf("%s's' new Name is: %s\n", user[Temp].name, user[Temp].username);
		printf("Wanna change it again? \n");
		printf("TYPE [Y]es or [N]o: ");
		choose = getchar();
		
		if (choose == 'Y')
			bStop = 0;
		else if (choose == 'y')
			bStop = 0;
		else if (choose == 'N')
			bStop = 1;
		else if (choose == 'n')
			bStop = 1;
			
	}while(bStop == 0);
}

/* funcadminModifyDescription
		
	Function:
	- Admin changes a user's description
	

 @param user - A structure containing all of a user's information
 @param Temp - A user's ID
 
	(void function == does not return anything)
*/

void adminModifyDescription(acc user, int Temp)
{
	int bStop = 0;
	message stringLine;
	char choose;
	
	do{
		fflush(stdin);
		system("cls");
		displayModifyUser();
		printf("Current Description: %s\n", user[Temp].description);
		printf("Enter new Description: ");
		fgets(stringLine,sizeof(stringLine), stdin);
		stringLine[strlen(stringLine)-1] = '\0';
	
		strcpy(user[Temp].description, stringLine);
		
		system("cls");
		displayModifyUser();
		printf("%s's' new Description is: %s\n", user[Temp].username, user[Temp].description);
		
		printf("Wanna change it again? \n");
		printf("TYPE [Y]es or [N]o: ");
		choose = getchar();
		
		if (choose == 'Y')
			bStop = 0;
		else if (choose == 'y')
			bStop = 0;
		else if (choose == 'N')
			bStop = 1;
		else if (choose == 'n')
			bStop = 1;
			
	}while(bStop == 0);
}

/* funcmadminAddPC
		
	Function:
	- Admin modifies user's personal connections (add)
	

 @param user - A structure containing all of a user's information
 @param *nUsers - Containing how many users were created in the program.
 @param Temp - A user's ID
 
	(void function == does not return anything)
*/

void adminAddPC(acc user, int *nUsers, int Temp)
{
	int bStop = 0;
	int choose, copyIndex;
	int nValid;
	int i, k;
	int comp;
	
	do{
		fflush(stdin);
		system("cls");
		nValid = 0;
		k = 0;
		for(i = 0; i < *nUsers; i++)
		{
			if(strcmp(user[i].name, user[Temp].name) != 0)
				printf("[%d] %s\n\n", i, user[i].name);
					
		}
		printf("\n");
		printf("\nType No. to add User as Personal Connection\n");
		printf("or Press [-1] to go back: ");
		scanf("%d", &choose);
		
		if(choose == -1)
			bStop = 1;
		else if (choose < *nUsers && choose >= 0 && choose != Temp)
		{
			copyIndex = choose;
			
			for(i = 0; i < MAX_USER && nValid == 0; i++)
			{
				if (strcmp(user[Temp].connect.link[i], user[copyIndex].username) == 0)
					nValid = 1;
				
			}
			
			if (nValid == 1)
			{
				printf(BHRED "USER ALREADY ADDED!\n" RST);
				printf("Press any No. to go back: ");
				scanf("%d", &choose);
				bStop = 1;
			}
			else if (nValid == 0)
			{
				while((comp = strlen(user[Temp].connect.link[k])) != 0)
				{
					k++;
				}
				
				strcpy(user[Temp].connect.link[k], user[copyIndex].username);
				printf(GRN "NEW USER ADDED!\n" RST);
				printf("Press any No. to go back: ");
				scanf("%d", &choose);
				
				bStop = 1;
			}
		}
	}while(bStop == 0);
}

/* funcadminRemovePC
		
	Function:
	- Admin modifies user's personal connections (remove)
	

 @param user - A structure containing all of a user's information
 @param *nUsers - Containing how many users were created in the program.
 @param Temp - A user's ID
 
	(void function == does not return anything)
*/

void adminRemovePC(acc user, int *nUsers, int Temp)
{
	int bStop = 0;
	int choose, copyIndex;
	int i, j;
	int max;
	
	do{
		system("cls");
		displayModifyUser();
		
		for (i = 0; (max = strlen(user[Temp].connect.link[i])) != 0; i++)
		{	
			printf("ID [%d] %s \n", i, user[Temp].connect.link[i]);
		}
		
		printf("\nType [ID No.] to REMOVE Connection\n");
		printf("TYPE [-1] to go back: ");
		scanf("%d", &choose);
		
		if(choose == -1)
			bStop = 1;
		else if (choose >= 0 && choose <= i)
		{
			copyIndex = choose;
			
			for (j = copyIndex; j < MAX_USER - 1; j++)
			{
				strcpy(user[Temp].connect.link[j], user[Temp].connect.link[j+1]);
			}
			
		}
		else
			bStop = 0;

	}while(bStop == 0);
}

/* funcadminModifyPC
		
	Function:
	- Admin modifies user's personal connections (add and remove)
	

 @param user - A structure containing all of a user's information
 @param *nUsers - Containing how many users were created in the program.
 @param Temp - A user's ID
 
	(void function == does not return anything)
*/

void adminModifyPC(acc user, int *nUsers, int Temp)
{
	int bStop = 0;
	int choose;
	
	do{
		
		fflush(stdin);
		system("cls");
		displayModifyUser();
		printf("EDIT MENU\n");
		printf("[1] Add\n");
		printf("[2] Remove\n");
		printf("[3] Go back :(\n");
		printf("TYPE CHOICE[No.]: ");
		scanf("%d", &choose);
		
		if (choose == 1)
			adminAddPC(user, nUsers, Temp);
		else if (choose == 2)
			adminRemovePC(user, nUsers, Temp);
		else if (choose == 3)
			bStop = 1;
		else 
			bStop = 0;	
			
		
	}while(bStop == 0);
}

/* funcmodifyUSer
		
	Function:
	- Display's user information
	- Admin is allowed to modify user
	

 @param user - A structure containing all of a user's information
 @param *nUsers - Containing how many users were created in the program.
 
	(void function == does not return anything)
*/

void modifyUser(acc user, int *nUsers)
{
	int i, j;
	int choose, choose1;
	int bStop = 1;
	str name;
	int Temp;
	int userVal = 1;
	
	system("cls");
	displayModifyUser();
	for(i = 0; i < *nUsers; i++)
	{
		printf("[%d] %s\n", i, user[i].username);
		printf("	Name: %s\n", user[i].name);
		printf("	Description: %s\n\n", user[i].description);
		printf("	Personal Connection => \n");
		for (j = 0; strlen(user[i].connect.link[j]) != 0; j++)
			printf("		%s\n", user[i].connect.link[j]);	
			
		printf("\n");				
	}
	
	do{
		printf("Type [1] to go back or [0] to EDIT: ");
		scanf("%d", &choose);
		
		if(choose == 1)
			bStop = 0;
		else if (choose == 0)
		{
			do{
				fflush(stdin);
				system("cls");
				displayModifyUser();
				for(i = 0; i < *nUsers; i++)
				{
					printf("[%d] %s\n", i, user[i].username);
					printf("	Name: %s\n", user[i].name);
					printf("	Description: %s\n\n", user[i].description);
					printf("	Personal Connection => \n");
					for (j = 0; strlen(user[i].connect.link[j]) != 0; j++)
						printf("		%s\n", user[i].connect.link[j]);	
						
					printf("\n");				
				}
				printf("\nType the name you want to EDIT: ");
				fgets(name, sizeof(name), stdin);
				name[strlen(name) - 1] = '\0';
					for(i = 0; i < *nUsers && userVal == 1; i++)
					{
						if(strcmp(user[i].username, name) == 0)
						{
							userVal = 0;
							Temp = i;
						}
					}
			}while(userVal != 0);
			
			system("cls");
			
			displayModifyUser();
			
			printf("EDIT MENU\n");
			printf("[1] Name\n");
			printf("[2] Username\n");
			printf("[3] Description\n");
			printf("[4] Personal Connections\n");
			printf("Type No. : ");
			scanf("%d", &choose1);
			
			if (choose1 == 1)
				adminModifyName(user, Temp);
			else if (choose1 == 2)
				adminModifyUsername(user, Temp);
			else if (choose1 == 3)
				adminModifyDescription(user, Temp);
			else if (choose1 == 4)
				adminModifyPC(user, nUsers, Temp);
			else
				bStop = 0;
	}
	
		bStop = 0;
		
	}while(bStop == 1);
	
}

/* funcrefreshPassword
		
	Function:
	- Admin refreshes a user's password if the user requested for one
	

 @param user - A structure containing all of a user's information
 @param *nUsers - Containing how many users were created in the program.
 
	(void function == does not return anything)
*/

void refreshPassword(acc user, int *nUsers)
{
	int choose, choose2;
	int bStop = 0;
	int i, approve, num_of_requests;
	
	do{
		num_of_requests = 0;
		system("cls");
		displayRefreshPassword();
		printf("LIST OF USERS: \n");
		
		for(i = 0; i < *nUsers; i++)
		{
			if (user[i].IDRequest == 1)
			{
				printf("[%d] %s\n", i, user[i].username);
				num_of_requests += 1;
			}
		}
		
		printf("Type [No.] to approve User or [-1] to go back: ");
		scanf("%d", &choose);
		
		if (choose < *nUsers && choose >= 0 && num_of_requests > 0)
		{
			approve = choose;
			
			strcpy(user[approve].password, "DLSU122");
			user[approve].IDRequest = 0;
			user[approve].Locked = 0;
			
			system("cls");
			displayRefreshPassword();
			
			printf("User - %s has been ", user[approve].username);
			printf(GRN"APPROVED.\n"RST);
			
			printf("Press any No. to go back: ");
			scanf("%d", &choose2);
			
			bStop = 1;
		}
		else if (choose == -1)
			bStop = 1;
		
		
	}while(bStop == 0);
}

/* funcdeleteUser
		
	Function:
	- Admin can deletes a user permanently
	When admin deletes user, personal connection will be gone
	but the MESSAGES will stay but, the sender/receiver would be considered, "DELETED USER"

 @param user - A structure containing all of a user's information
 @param *nUsers - Containing how many users were created in the program.
 @param *nMess - Containing the no. messages
 @param allmessages - A structure conatining all of a messasge's information.
 
	(void function == does not return anything)
*/

void deleteUser(acc user, int *nUsers, int *nMess, mess allmessages)
{
	int bStop = 0;
	int choose;
	int copyIndex, copyUser;
	int i, j, k;
	int max;
	
	do{
		system("cls");
		displayDeleteUser();
		
		if(*nUsers == 0)
		{
			printf("Nothing to show....\n");
			printf("Type [-1] to go back: ");
			scanf("%d", &choose);
			
			if(choose == -1)
				bStop = 1;
			else
				bStop = 0;
		}
		else if (*nUsers > 0 && *nUsers <= MAX_USER)
		{
			for(i = 0; i < *nUsers; i++)
			{
				printf("ID [%d] %s\n", i, user[i].username);
			}
			
			printf("\n\nType [ID No.] to permanently delete User\n");
			printf("Or Type [-1] to go back: ");
			scanf("%d", &choose);
			
			if(choose == -1)
				bStop = 1;
			else if (choose >= 0 && choose <= i)
			{
				copyUser = choose;
				
				//User Connections
				for(i = 0; i < *nUsers; i++)
				{
					copyIndex = 50; 
					for (j = 0; (max = strlen(user[i].connect.link[j])) != 0; j++)
					{
						if (strcmp(user[copyUser].username, user[i].connect.link[j]) == 0)
							copyIndex = j;
					}
					
					if (copyIndex != 50)
					{
						for(k = copyIndex; k < MAX_USER - 1; k++)
						{
							strcpy(user[i].connect.link[k], user[i].connect.link[k+1]);
						}
					}
				}
				
				for(i = 0; i < *nMess; i++)
				{
					if(strcmp(user[copyUser].username, allmessages[i].sender) == 0)
					{
						strcpy(allmessages[i].sender, "'DELETED USER'");
					}
					
				}
				
		
				for(i = copyUser; i < *nUsers - 1; i++)
				{
					strcpy(user[i].username, user[i+1].username);
					strcpy(user[i].name, user[i+1].name);
					strcpy(user[i].password, user[i+1].password);
					
					strcpy(user[i].description, user[i+1].description);
					
					strcpy(user[i].user_question, user[i+1].user_question);
					strcpy(user[i].answer, user[i+1].answer);
					
					user[i].IDRequest = user[i+1].IDRequest;
					user[i].Locked = user[i+1].Locked;
					
					for(j = 0; j < MAX_USER - 1; j++)
					{
						strcpy(user[i].connect.link[j], user[i+1].connect.link[j]);
					}
					
				}
				
				*nUsers -= 1; 
				
			}
			else
				bStop = 0;
		}
		
	}while(bStop == 0);
}

/* funcviewQuestion
		
	Function:
	- Admin can view security questions

 @param user - A structure containing all of a user's information
 @param *nQuestions - Containing how many security questions were created in the program.
 
	(void function == does not return anything)
*/

void viewQuestion(acc user, int *nQuestions)
{
	int choose;
	int bStop = 0;
	int i; 
	
	do{
		system("cls");
		printf("TQ = %d\n", *nQuestions);
		printf("===============================================================\n");
		printf("==========                                           ==========\n"); 
  	    printf("==========             Security Question             ==========\n"); 
	    printf("===============================================================\n\n"); 
	    
	    for (i = 0; i < *nQuestions; i++)
	    {
	    	printf("[%d] %s\n", i, user[i].question);
		}
		
		printf("\n TYPE 1 to go back:");
		scanf("%d", &choose);
		
		if (choose == 1)
			bStop = 1;
		else
			bStop = 0;
			
	}while(bStop == 0);	
	
}

/* funcaddQuestion
		
	Function:
	- Admin can add security questions

 @param user - A structure containing all of a user's information
 @param *nQuestions - Containing how many security questions were created in the program.
 
	(void function == does not return anything)
*/

void addQuestion(acc user, int *nQuestions)
{
	int choose;
	int bStop = 0;
	message stringLine;
	
	
	do{
		fflush(stdin);
		system("cls");
		printf("TQ = %d\n", *nQuestions);
		printf("===============================================================\n");
		printf("==========                                           ==========\n"); 
    	printf("==========           Add Security Questions          ==========\n"); 
    	printf("===============================================================\n\n");
	    
	    do{
		    printf("Enter Question (MAX = 100 Char): ");
			fgets(stringLine,sizeof(stringLine), stdin);
			stringLine[strlen(stringLine)-1] = '\0';
		}while(strlen(stringLine) > MAX_SECURE);
		
		printf("Question Inputted: %s\n", stringLine);
		printf("TYPE any No. to finalize question or [0] to retry: ");
		scanf("%d", &choose);
		
		if(choose == 1)
		{
			strcpy(user[*nQuestions].question, stringLine);
			(*nQuestions)++; // Add 1 to the total no. of Questions
			bStop = 1;
		}
		else if (choose == 0)
			bStop = 0;
			
	}while(bStop == 0);	

}

/* funcsecurityQuestion
		
	Function:
	- Admin can view and if they want to add security questions

 @param user - A structure containing all of a user's information
 @param *nQuestions - Containing how many security questions were created in the program.
 
	(void function == does not return anything)
*/
void securityQuestion(acc user, int *nQuestions)
{
	int choose;
	int bStop = 0;
	
	do{
		system("cls");
		printf("TQ = %d\n", *nQuestions);
		printf("===============================================================\n");
		printf("==========                                           ==========\n"); 
    	printf("==========             Security Question             ==========\n"); 
    	printf("===============================================================\n\n");
	    printf("               MENU\n\n"); 
	    printf("        [1] VIEW QUESTIONS\n");
	    printf("        [2] ADD QUESTIONS\n");
	    printf("        [3] GET OUT :(\n");
	    printf("\n TYPE CHOICE: ");
	    scanf("%d", &choose);											//User input on where they want to go
	    system("cls");
	    
	    if (choose == 1)
			viewQuestion(user, nQuestions);
		else if (choose == 2)
			addQuestion(user, nQuestions);
		else if (choose == 3)
			bStop = 1;
		else
			bStop = 0;
	    
	}while(bStop == 0);
	
}

/* funcadminUMOD
		
	Function:
	- Admin can choose if they want to
		- view user
		- modify user
		- refresh password
		- delete user
		- security question
		- get out

 @param user - A structure containing all of a user's information
 @param *nQuestions - Containing how many security questions were created in the program.
 @param *nUsers - Conatining the no. of user's created.
 @param *nIndex - a user's ID.
 
	(void function == does not return anything)
*/

void adminUMOD(acc user, int *nUsers, int *nIndex, int *nQuestions, int *nMess, mess allmessages)
{
	int choose;
	int bStop = 0;
	
	do{
		system("cls");
		printf("===============================================================\n");
		printf("==========                                           ==========\n"); 
    	printf("==========             Admin User Module             ==========\n"); 
    	printf("===============================================================\n\n");
	    printf("                           MENU\n\n"); 
	    printf("                     [1] VIEW USERS\n");
	    printf("                     [2] MODIFY USERS\n");
	    printf("                     [3] REFRESH PASSWORD\n");
	    printf("                     [4] DELETE USERS\n");
	    printf("                     [5] SECURITY QUESTIONS\n");
	    printf("                     [6] Get out :(");
	    printf("\n                      TYPE CHOICE: ");
	    scanf("%d", &choose);											//User input on where they want to go
	    system("cls");
	    
	    if (choose == 1)
			viewUser(user, nUsers, nIndex);
		else if (choose == 2)
			modifyUser(user, nUsers);
		else if (choose == 3)
			refreshPassword(user, nUsers);
		else if (choose == 4)
			deleteUser(user, nUsers, nMess, allmessages);
		else if (choose == 5)
			securityQuestion(user, nQuestions);
		else if (choose == 6)
			bStop = 1;
		else
			bStop = 0;
	    
	}while (!bStop);
	
	
}

/* funcadminViewMessage
		
	Function:
	- Admin view every message

 @param user - A structure containing all of a user's information
 @param *nUsers - Containing how many users were created in the program.
 @param *nMess - Containing the no. messages
 @param allmessages - A structure conatining all of a messasge's information.
 
	(void function == does not return anything)
*/

void adminViewMessage(acc user, int *nMess, mess allmessages)
{
	int bStop = 0;
	int choose;
	int i, j, k;
	
	do{
		j = 0;
	    k = 0;
	    
		system("cls");
		displayMessagesModule();
		
		if (*nMess == 0)
		{
			printf(BHRED "Nothing to show.......\n" RST);
			printf("Press any [No.] to go back: ");
			scanf("%d", &choose);
			bStop = 1;
		}
		else if (*nMess > 0)
		{
			for (i = 0; i < *nMess; i++)
			{
				if(strlen(allmessages[i].group) == 0)
				{
					if(strlen(allmessages[i].announcement) == 0)
					{
					
						printf(BBLU "[%d] Sender:" RST, j);
						if(strcmp(allmessages[i].sender, "'DELETED USER'") == 0)
							printf(BHRED" %s\n"RST, allmessages[i].sender);
						else
							printf(" %s\n", allmessages[i].sender);
						printf(GRN"Receiver:" RST);
						printf(" %s\n", allmessages[i].receiver);
						printf("Subject: %s\n", allmessages[i].subj);
						printf("Message: %s\n\n", allmessages[i].mail);
						j+= 1;
					}
					else if(strlen(allmessages[i].announcement) != 0)
					{
						printf(BBLU "[%d] Sender:" RST, j);
						if(strcmp(allmessages[i].sender, "'DELETED USER'") == 0)
							printf(BHRED" %s\n"RST, allmessages[i].sender);
						else
							printf(" %s\n", allmessages[i].sender);
						printf("Subject: %s\n", allmessages[i].subj);
						printf(GRN"Receiver: EVERYONE\n" RST);
						printf("Announcement: %s\n\n", allmessages[i].announcement);
						printf("\n");
						j+= 1;
					}
				}
				else if(strlen(allmessages[i].group) != 0)
				{
					printf(BBLU "[%d] Sender:" RST, j);
					if(strcmp(allmessages[i].sender, "'DELETED USER'") == 0)
						printf(BHRED" %s\n"RST, allmessages[i].sender);
					else
						printf(" %s\n", allmessages[i].sender);
					printf(GRN"Receivers: "RST);
					printf("%s\n", allmessages[i].group);
					printf("\nSubject: %s\n", allmessages[i].subj);
					printf("Message: %s\n\n", allmessages[i].mail);
					j += 1;
					k += 1;
				}
			}
			
			printf("Press any [No.] to go back: ");
			scanf("%d", &choose);
			bStop = 1;
		}
		
	}while(bStop == 0);
	
}

/* funcfilterBySender
		
	Function:
	- Admin view every message via by sender

 @param user - A structure containing all of a user's information
 @param *nUsers - Containing how many users were created in the program.
 @param *nMess - Containing the no. messages
 @param allmessages - A structure conatining all of a messasge's information.
 
	(void function == does not return anything)
*/
void filterBySender(acc user, int *nUsers, int *nMess, mess allmessages)
{
	int bStop = 0;
	int choose, copyIndex;
	int i, j, k;
	int max;
	
	do{
		system("cls");
		displayMessagesModule();
		
		for(i = 0; i < *nUsers; i++)
		{
			printf("[%d] %s\n", i, user[i].username);
			printf("\n");				
		}
		
		printf("Type [No.] to VIEW messages sent\n");
		printf("Or Type [-1] to go back: ");
		scanf("%d", &choose);
		
		if (choose == -1)
			bStop = 1;
		else if (choose >= 0 && choose < *nUsers)
		{
			copyIndex = choose;
			system("cls");
			
			do{
				j = 0;
				k = 0;
				if (*nMess == 1)
				{
					if(strcmp(user[copyIndex].username, allmessages[0].sender) == 0 && strlen(allmessages[0].group) == 0)
					{
						if(strlen(allmessages[0].announcement) == 0)
						{
						
							printf("[0] ");
							//printf(" Sender: %s\n", allmessages[0].sender);
							printf("Receiver: %s\n", allmessages[0].receiver);
							printf("Subject: %s\n", allmessages[0].subj);
							printf("Message: %s\n", allmessages[0].mail);
						}
						else if (strlen(allmessages[0].announcement) != 0)
						{
							printf("[%d] Sender: %s\n", j, allmessages[0].sender);
							printf(" Subject: %s\n", allmessages[0].subj);
							printf(" Announcement: %s\n", allmessages[0].announcement);
							printf("\n");
						}
					}
					else if(strcmp(user[copyIndex].username, allmessages[0].sender) == 0 && strlen(allmessages[0].group) != 0)
					{
						printf("[0] ");
						//printf(" Sender: %s\n", allmessages[0].sender);
						printf("Receivers: ");
						for(k = 0; (max = strlen(user[copyIndex].connect.link[j])) != 0; k++)
							printf("%s\n", allmessages[k].group);
						printf("\nSubject: %s\n", allmessages[0].subj);
						printf("Message: %s\n", allmessages[0].mail);
					}
					
					printf("\nPress any number to leave: ");
					scanf("%d", &choose);
					
					bStop = 0;
				}
				else if (*nMess > 1)
				{	
					for(i = 0; i < *nMess; i++)
					{
						if(strcmp(user[copyIndex].username, allmessages[i].sender) == 0 && strlen(allmessages[i].group) == 0)
						{
							if(strlen(allmessages[i].announcement) == 0)
							{
							
								printf("[%d] ", j);
								//printf(" Sender: %s\n", allmessages[i].sender);
								printf("Receiver: %s\n", allmessages[i].receiver);
								printf("Subject: %s\n", allmessages[i].subj);
								printf("Message: %s\n\n", allmessages[i].mail);
								j+= 1;
							}
							else if (strlen(allmessages[i].announcement) != 0)
							{
								printf("[%d] Sender: %s\n", j, allmessages[i].sender);
								printf(" Subject: %s\n", allmessages[i].subj);
								printf(" Announcement: %s\n", allmessages[i].announcement);
								printf("\n");
								j+= 1;
							}
						}
						else if(strcmp(user[copyIndex].username, allmessages[0].sender) == 0 && strlen(allmessages[i].group) != 0)
						{
							printf("[%d] ", j);
							//printf(" Sender: %s\n", allmessages[0].sender);
							printf("Receivers: ");
							printf("%s\n", allmessages[j].group);
							printf("\nSubject: %s\n", allmessages[i].subj);
							printf("Message: %s\n", allmessages[i].mail);
							j += 1;
						}
					}
						
					
					printf("\nPress 1 to leave: ");
					scanf("%d", &choose);
					
					bStop = 0;
				}	
				else if (*nMess == 0)
				{
					printf("No Messages :( \n");
					printf("\nPress 1 to leave: ");
					scanf("%d", &choose);
					
					bStop = 0;
				}
				
				
			}while(bStop == 1);
			
		}
		else
			bStop = 0;
		
		
		
	}while(bStop == 0);
}

/* funcfilterByRecipient
		
	Function:
	- Admin view every message via recipient

 @param user - A structure containing all of a user's information
@param *nUsers - Containing how many users were created in the program.
 @param *nMess - Containing the no. messages
 @param allmessages - A structure conatining all of a messasge's information.
 
	(void function == does not return anything)
*/

void filterByRecipient(acc user, int *nUsers, int *nMess, mess allmessages)
{
	int bStop = 0;
	int choose, copyIndex;
	int i, j;
	
	do{
		system("cls");
		displayMessagesModule();
		
		for(i = 0; i < *nUsers; i++)
		{
			printf("[%d] %s\n", i, user[i].username);
			printf("\n");				
		}
		
		printf("Type [No.] to VIEW messages sent\n");
		printf("Or Type [-1] to go back: ");
		scanf("%d", &choose);
		
		if (choose == -1)
			bStop = 1;
		else if (choose >= 0 && choose < *nUsers)
		{
			copyIndex = choose;
			system("cls");
			
			
			do{
				j = 0;
				if (*nMess == 1)
				{
					if(strcmp(user[copyIndex].username, allmessages[0].receiver) == 0 && strlen(allmessages[0].group) == 0)
					{
						printf("[0] ");
						printf(" Sender: %s\n", allmessages[0].sender);
						printf("Subject: %s\n", allmessages[0].subj);
						printf("Message: %s\n", allmessages[0].mail);
					}
					else if(strcmp(user[copyIndex].username, allmessages[0].receiver) != 0 && strlen(allmessages[0].group) != 0)
					{
							printf("[0] ");
							printf(" Sender: %s\n", allmessages[0].sender);
							printf("\nSubject: %s\n", allmessages[0].subj);
							printf("Message: %s\n", allmessages[0].mail);
					}
					
					for(i = 0; i < *nMess; i++)
					{
						if(strlen(allmessages[i].announcement) != 0)
						{
							printf("[%d] Sender: %s\n", j, allmessages[i].sender);
							printf(" Subject: %s\n", allmessages[i].subj);
							printf(" Announcement: %s\n", allmessages[i].announcement);
							printf("\n");
							j+= 1;
						}
					}
					
					printf("\nPress any number to leave: ");
					scanf("%d", &choose);
					
					bStop = 0;
				}
				else if (*nMess > 1)
				{	
					for(i = 0; i < *nMess; i++)
					{
						if(strcmp(user[copyIndex].username, allmessages[i].receiver) == 0 && strlen(allmessages[i].group) == 0)
						{
							printf("[%d] ", j);
							printf(" Sender: %s\n", allmessages[i].sender);
							printf("Subject: %s\n", allmessages[i].subj);
							printf("Message: %s\n\n", allmessages[i].mail);
							j+= 1;
						}
						else if(strcmp(user[copyIndex].username, allmessages[i].receiver) != 0 && strlen(allmessages[i].group) != 0)
						{
							if (strcmp(user[copyIndex].username, allmessages[i].group) == 0)	
							{
								printf("[%d] ", j);
								printf(" Sender: %s\n", allmessages[i].sender);
								printf("\nSubject: %s\n", allmessages[i].subj);
								printf("Message: %s\n", allmessages[i].mail);
								j += 1;
							}
						}
					}
						
					for(i = 0; i < *nMess; i++)
					{
						if(strlen(allmessages[i].announcement) != 0)
						{
							printf("[%d] Sender: %s\n", j, allmessages[i].sender);
							printf(" Subject: %s\n", allmessages[i].subj);
							printf(" Announcement: %s\n", allmessages[i].announcement);
							printf("\n");
							j+= 1;
						}
					}
					printf("\nPress 1 to leave: ");
					scanf("%d", &choose);
					
					bStop = 0;
				}	
				else if (*nMess == 0)
				{
					printf("No Messages :( \n");
					printf("\nPress 1 to leave: ");
					scanf("%d", &choose);
					
					bStop = 0;
				}
				
			}while(bStop == 1);
		}
		
	}while(bStop == 0);
	

}

/* funcadminViewByFilter
		
	Function:
	- Admin can view every message via sender or recipient
	- get out

 @param user - A structure containing all of a user's information
 @param *nUsers - Containing how many users were created in the program.
 @param *nMess - Containing the no. messages
 @param allmessages - A structure conatining all of a messasge's information.
 
	(void function == does not return anything)
*/

void adminViewByFilter(acc user, int *nUsers, int *nMess, mess allmessages)
{
	int bStop = 0;
	int choose;
	
	do{
		system("cls");
		displayMessagesModule();
		printf("                          MENU\n\n"); 
	    printf("                   [1] FILTER BY SENDER\n");
	    printf("                   [2] FILTER BY RECIPIENT\n");
	    printf("                   [3] Get out :(");
	    printf("\n                     TYPE CHOICE: ");
	    scanf("%d", &choose);											//User input on where they want to go
	    system("cls");
		
		if(choose == 1)
			filterBySender(user, nUsers, nMess, allmessages);
		else if (choose == 2)
			filterByRecipient(user, nUsers, nMess, allmessages);
		else if (choose == 3)
			bStop = 1;
		else
			bStop = 0;
		
	}while(bStop == 0);
}

/* funcdeleteMessage
		
	Function:
	- Admin can delete a message

 @param user - A structure containing all of a user's information
 @param *nUsers - Containing how many users were created in the program.
 @param *nMess - Containing the no. messages
 @param allmessages - A structure conatining all of a messasge's information.
 
	(void function == does not return anything)
*/

void deleteMessage(acc user, int *nUsers, int *nMess, mess allmessages)
{
	int bStop = 0;
	int i, choose;
	int j, k;
	
	do{
		j = 0;
		k = 0;
		system("cls");
		displayMessagesModule();
		
		if (*nMess == 0)
		{
			printf(BHRED "Nothing to show.......\n" RST);
			printf("Press any [No.] to go back: ");
			scanf("%d", &choose);
			bStop = 1;
		}
		else if (*nMess > 0)
		{
			for (i = 0; i < *nMess; i++)
			{
				if(strlen(allmessages[i].group) == 0)
				{
					if(strlen(allmessages[i].announcement) == 0)	//if it is a individual message
					{
					
						printf("ID [%d] ", j);
						printf("Sender: %s\n", allmessages[i].sender);
						printf("Receiver: %s\n", allmessages[i].receiver);
						printf("Subject: %s\n", allmessages[i].subj);
						printf("Message: %s\n\n", allmessages[i].mail);
						j+= 1;
					}
					else if(strlen(allmessages[i].announcement) != 0)	//if it is an announcement
					{
						printf("ID [%d] Sender: %s\n", j, allmessages[i].sender);
						printf("Subject: %s\n", allmessages[i].subj);
						printf("Receiver: EVERYONE\n");
						printf("Announcement: %s\n", allmessages[i].announcement);
						printf("\n");
						j+= 1;
					}
				}
				else if(strlen(allmessages[i].group) != 0)	//if it is a group message
				{
					printf("ID [%d] ", j);
					printf("Sender: %s\n", allmessages[0].sender);
					printf("Receivers: ");
					printf("%s\n", allmessages[k].group);
					printf("\nSubject: %s\n", allmessages[i].subj);
					printf("Message: %s\n", allmessages[i].mail);
					j += 1;
					k += 1;
				}
			}
			printf("\nType the [ID No.] to DELETE\n");
			printf("Or Type [-1] to go back: ");
			scanf("%d", &choose);
			
			if (choose == -1)
				bStop = 1;
			else if (choose >= 0 && choose < *nMess)
			{
				for(i = choose; i < *nMess - 1; i++)
				{	
					
					if(strlen(allmessages[i].group) == 0)		//If it is an individual message or announcement message
					{
						if(strlen(allmessages[i].announcement) == 0)	//If it is an individual message
						{
							strcpy(allmessages[i].sender, allmessages[i+1].sender);
							strcpy(allmessages[i].receiver, allmessages[i+1].receiver);
							strcpy(allmessages[i].subj, allmessages[i+1].subj);
							strcpy(allmessages[i].mail, allmessages[i+1].mail);
							
							strcpy(allmessages[i].announcement, allmessages[i+1].announcement);
							strcpy(allmessages[i].group, allmessages[i+1].group);
						}
						else if(strlen(allmessages[i].announcement) != 0)	//If it is an announcement message
						{
							strcpy(allmessages[i].sender, allmessages[i+1].sender);
							strcpy(allmessages[i].subj, allmessages[i+1].subj);
							strcpy(allmessages[i].announcement, allmessages[i+1].announcement);
							
							strcpy(allmessages[i].group, allmessages[i+1].group);
							strcpy(allmessages[i].receiver, allmessages[i+1].receiver);
							strcpy(allmessages[i].mail, allmessages[i+1].mail);
						}
					}
					else if(strlen(allmessages[i].group) != 0)	//If it is a group message
					{
							strcpy(allmessages[i].sender, allmessages[i+1].sender);
							strcpy(allmessages[i].group, allmessages[i+1].group);
							strcpy(allmessages[i].subj, allmessages[i+1].subj);
							strcpy(allmessages[i].mail, allmessages[i+1].mail);
							
							strcpy(allmessages[i].announcement, allmessages[i+1].announcement);
							strcpy(allmessages[i].receiver, allmessages[i+1].receiver);
					}
				}
				*nMess -= 1;
			}
			else
				bStop = 0;
		}
		
	}while(bStop == 0);
		
}

/* funcadminViewMessage
		
	Function:
	- Admin can
		- view message
		- view by filter
		- delete message
		- get out

 @param user - A structure containing all of a user's information
 @param *nQuestions - Containing how many security questions were created in the program.
 @param *nMess - Containing the no. messages
 @param allmessages - A structure conatining all of a messasge's information.
 @param *nIndex - A user's ID.
 
 
	(void function == does not return anything)
*/

void adminMESSMOD(acc user, int *nUsers, int *nIndex, int *nMess, mess allmessages)
{
	int bStop = 0;
	int choose;
	
	do{
		system("cls");
		displayMessagesModule();
		printf("                           MENU\n\n"); 
	    printf("                    [1] VIEW MESSAGES\n");
	    printf("                    [2] VIEW BY FILTER\n");
	    printf("                    [3] DELETE MESSAGE\n");
	    printf("                    [4] Get out :(");
	    printf("\n                    TYPE CHOICE: ");
	    scanf("%d", &choose);											//User input on where they want to go
	    system("cls");
		
		if (choose == 1)
			adminViewMessage(user, nMess, allmessages);
		else if (choose == 2)
			adminViewByFilter(user, nUsers, nMess, allmessages);
		else if (choose == 3)
			deleteMessage(user, nUsers, nMess, allmessages);
		else if (choose == 4)
			bStop = 1;
		else
			bStop = 0;
		
	}while(bStop == 0);
}

/* funcpasswordModule
		
	Function:
	- Admin can
		- change admin's passowrd

 @param sAdminPassword - the admin's password
 
	(void function == does not return anything)
*/

void passwordModule(str sAdminPassword)
{
	int bStop = 0;
	str stringLine;
	char choose; 
	
	do{
		fflush(stdin);
		system("cls");
		displayPasswordModule();
		printf("Current Admin Password: %s\n\n", sAdminPassword);
		printf("Type New Admin Password: ");
		
		fgets(stringLine, sizeof(stringLine), stdin);	//Input new Admin Password
		stringLine[strlen(stringLine) - 1] = '\0';
		strcpy(sAdminPassword, stringLine);
		
		printf("Confirm Admin password: ");
		fgets(stringLine,sizeof(stringLine), stdin);
		stringLine[strlen(stringLine)-1] = '\0';
		
		while(strcmp(sAdminPassword, stringLine) != 0)
		{
			system("cls");
			displayPasswordModule();
			printf("Passwords do not match. Please try again.\n");
			
	        printf("Type New Admin Password: ");
			fgets(stringLine,sizeof(stringLine), stdin);
			stringLine[strlen(stringLine)-1] = '\0';
			strcpy(sAdminPassword, stringLine);
		
			printf("Confirm Admin password: ");
			fgets(stringLine,sizeof(stringLine), stdin);
			stringLine[strlen(stringLine)-1] = '\0';
		}
		
		strcpy(sAdminPassword, stringLine);
		
		system("cls");
		displayPasswordModule();
		printf("Admin's new password is: %s\n", sAdminPassword);
		
		printf("Wanna change it again? \n");
		printf("TYPE [Y]es or [N]o: ");
		choose = getchar();
		
		if (choose == 'Y')
			bStop = 0;
		else if (choose == 'y')
			bStop = 0;
		else if (choose == 'N')
			bStop = 1;
		else if (choose == 'n')
			bStop = 1;
		
	}while(bStop == 0);
}

/* funclogInAdmin
		
	Function:
	- Admin needs to log in

 @param sAdminPassword - the admin's password
 
	(void function == does not return anything)
*/

int logInAdmin(str sAdminPassword)
{
	str stringLine;		//input for password
	int passVal = 1;	//check if password is TRUE
	int nValid = 1;	//check if password is true

	do{
		fflush(stdin);
		system("cls");
		printf("===============================================================\n");
		printf("==========                                           ==========\n"); 
	    printf("==========                LOG IN ADMIN               ==========\n"); 
	    printf("==========                                           ==========\n"); 
	    printf("===============================================================\n\n");
		printf("Enter Admin's Password: ");
		fgets(stringLine,sizeof(stringLine), stdin);
		stringLine[strlen(stringLine)-1] = '\0';
		
		if (strcmp(sAdminPassword, stringLine) == 0)
			passVal = 0;
	}while(passVal != 0);
	
	
	if(passVal == 1)
		nValid = 0;
		
	return (nValid);
}

/* funcadminModule
		
	Function:
	- Admin can
		- view Users module
		- view Messages module
		- view password module
		- get out

 @param user - A structure containing all of a user's information
 @param *nQuestions - Containing how many security questions were created in the program.
 @param *nUser - Containing how many users were created in the program.
 @param *nMess - Containing the no. messages
 @param allmessages - A structure containing all of a messasge's information.
 @param *nIndex - A user's ID.
 @param sAdminPassword - the admin's password

 
	(void function == does not return anything)
*/

void adminModule(acc user, int *nUsers, int *nIndex, int *nQuestions, str sAdminPassword, int *nMess, mess allmessages)
{
	int choose;
	int bStop = 0;
	int check;
	
	check = logInAdmin(sAdminPassword);
	
	if (check == 1)
	{
		do{
		system("cls");
		printf("===============================================================\n");
		printf("==========                                           ==========\n"); 
    	printf("==========               Admin Module                ==========\n"); 
    	printf("===============================================================\n\n");
	    printf("                           MENU\n\n"); 
	    printf("                     [1] USERS MODULE\n");
	    printf("                     [2] MESSAGES MODULE\n");
	    printf("                     [3] CHANGE PASSWORD MODULE\n");
	    printf("                     [4] GET OUT :(\n");
	    printf("\n                      TYPE CHOICE: ");
	    scanf("%d", &choose);											//User input on where they want to go
	    system("cls");
	    
	    if (choose == 1)
			adminUMOD(user, nUsers, nIndex, nQuestions, nMess, allmessages);
		else if (choose == 2)
			adminMESSMOD(user, nUsers, nIndex, nMess, allmessages);
		else if (choose == 3)
			passwordModule(sAdminPassword);
		else if (choose == 4)
			bStop = 1;
		else
			bStop = 0;
		    
		}while (!bStop);
	}
	
}

/* funcsaveuserList
		
	Function:
	- Saves everything in text files

 @param user - A structure containing all of a user's information
 @param *nQuestions - Containing how many security questions were created in the program.
 @param *nMess - Containing the no. messages
 @param allmessages - A structure conatining all of a messasge's information.
 @param sAdminPassword - the admin's password
 
 
	(void function == does not return anything)
*/

void saveUserList(acc users, int nUsers, int *nQuestions, str sAdminPassword)
{
	FILE *pFile;
	int i, k = 0;
	
	pFile = fopen("users.txt","wt");
		
	if (pFile != NULL) // File generated successfully!
	{
		
		fprintf (pFile,"%d\n",nUsers);
		
		for (i = 0;i < nUsers;i++)
		{
			fprintf (pFile,"%s\n",users[i].name);
			fprintf (pFile,"%s\n",users[i].username);
			fprintf (pFile,"%s\n",users[i].password);
			fprintf (pFile,"%s\n",users[i].description);
			fprintf (pFile,"%s\n",users[i].user_question);
			fprintf (pFile,"%s\n",users[i].answer);
			fprintf (pFile,"%d\n",users[i].IDRequest);
			fprintf (pFile,"%d\n",users[i].Locked);
		}
		
		fclose (pFile); 
	}
	else
		printf ("Unable to generate users.txt\n");
		
	pFile = fopen("pc_connections.txt", "wt");
	
	if(pFile != NULL)	// File generated successfully!
	{
		fprintf (pFile,"%d\n",nUsers);
		
		for (i = 0; i < nUsers; i++)
		{
		
			for (k = 0; k < MAX_USER; k++)
			{
				fprintf (pFile,"%s\n", users[i].connect.link[k]);
			}
		}
		fclose (pFile);
	}
	else
		printf ("Unable to generate pc_connections.txt\n");
		
	pFile = fopen("scquestions.txt", "wt");
	
	if(pFile != NULL)	// File generated successfully!
	{
		fprintf (pFile,"%d\n", *nQuestions);
		
		for (i = 0; i < *nQuestions; i++)
		{
			fprintf (pFile,"%s\n", users[i].question);
		
		}
		fclose (pFile);
	}
	else
		printf ("Unable to generate sc_questions.txt\n");
		
		
	pFile = fopen("adminpassword.txt", "wt");
	
	if(pFile != NULL)	// File generated successfully!
	{

		fprintf (pFile,"%s\n", sAdminPassword);
		fclose (pFile);
	}
	else
		printf ("Unable to generate adminpassword.txt\n");
}

/* funcloadUserList
		
	Function:
	- Loads everything in text files

 @param user - A structure containing all of a user's information
 @param *nQuestions - Containing how many security questions were created in the program.
 @param *nMess - Containing the no. messages
 @param allmessages - A structure conatining all of a messasge's information.
 
 
	(void function == does not return anything)
*/

void saveMessages(int nMess, mess allmessages)
{
	FILE *pFile;
	int i;
	
	pFile = fopen("message.txt", "wt");	
	
	if(pFile != NULL)	// File generated successfully!
	{
		fprintf (pFile,"%d\n", nMess);

		for (i = 0; i < nMess; i++)
		{
			fprintf (pFile,"%s\n",allmessages[i].sender);
			fprintf (pFile,"%s\n",allmessages[i].receiver);
			fprintf (pFile,"%s\n",allmessages[i].group);
			fprintf (pFile,"%s\n",allmessages[i].subj);
			fprintf (pFile,"%s\n",allmessages[i].announcement);
			fprintf (pFile,"%s\n",allmessages[i].mail);
		}
		
		fclose (pFile);
	}
	else
		printf ("Unable to generate message.txt\n");
}

void loadUserList(acc users, int *nUsers, int *nMess, mess allmessages)
{
	FILE *pFile;
	str strLine; // Temporary line
	message stringLine; //Temporary line
	int i, k;
	
	pFile = fopen("users.txt","rt"); // See above, in saveUserList
	
	if (pFile != NULL) // users.txt exists
	{
		fgets(strLine,sizeof(strLine),pFile);
		
		*nUsers = atoi(strLine); // We obtained strLine for nUsers
		
		for (i = 0;i < *nUsers;i++)
		{
			// 1st line contains the user ID
			fgets(strLine,sizeof(strLine),pFile);
			strLine[strlen(strLine)-1] = '\0';
			strcpy(users[i].name, strLine);
			
			// 2nd line contains the username
			fgets(strLine,sizeof(strLine),pFile);
			strLine[strlen(strLine)-1] = '\0';
			strcpy(users[i].username,strLine);
			
			// 3rd line contains the password
			fgets(strLine,sizeof(strLine),pFile);
			strLine[strlen(strLine)-1] = '\0';
			strcpy(users[i].password, strLine);
			
			// 4th line contains the description
			fgets(stringLine,sizeof(stringLine),pFile);
			stringLine[strlen(stringLine)-1] = '\0';
			strcpy(users[i].description, stringLine);
			
			// 5th line contains the user's random question
			fgets(strLine,sizeof(strLine),pFile);
			strLine[strlen(strLine)-1] = '\0';
			strcpy(users[i].user_question, strLine);
			
			// 6th line contains the security answer
			fgets(stringLine,sizeof(stringLine),pFile);
			stringLine[strlen(stringLine)-1] = '\0';
			strcpy(users[i].answer, stringLine);
			
			// 7th line contains the ID request
			fgets(strLine,sizeof(strLine),pFile);
			users[i].IDRequest = atoi(strLine);
			
			// 8th mline contains whether the account is Locked or not
			fgets(strLine,sizeof(strLine),pFile);
			users[i].Locked = atoi(strLine);
		}
		fclose (pFile); 
	}
	else	// users.txt not found, revert to default
		*nUsers = 0;
		
	pFile = fopen("pc_connections.txt", "rt"); //See above, in saveUserList
	
	if (pFile != NULL) // pc_connections.txt exists
	{
		fgets(strLine,sizeof(strLine),pFile);
		
		*nUsers = atoi(strLine);
		
		for (i = 0; i < *nUsers; i++)
		{
			for (k = 0; k < MAX_USER; k++)
			{
				fgets(strLine,sizeof(strLine),pFile);
				strLine[strlen(strLine)-1] = '\0';
				strcpy(users[i].connect.link[k], strLine);

			}
			//fclose (pFile); 
		}
		fclose (pFile); 
	}
	else	// pc_connections.txt not found, revert to default
		*nUsers = 0;
		
	pFile = fopen("message.txt","rt"); // See above, in saveUserList
	
	if (pFile != NULL) // users.txt exists
	{
		fgets(strLine,sizeof(strLine),pFile);
		
		*nMess = atoi(strLine); // We obtained strLine for nUsers
		
		for (i = 0;i < *nMess;i++)
		{
				// 1st line contains the sender
				fgets(strLine,sizeof(strLine),pFile);
				strLine[strlen(strLine)-1] = '\0';
				strcpy(allmessages[i].sender, strLine);
				
				// 2nd line contains the receiver
				fgets(strLine,sizeof(strLine),pFile);
				strLine[strlen(strLine)-1] = '\0';
				strcpy(allmessages[i].receiver,strLine);
				
				// 3rd line contains the group
				fgets(strLine,sizeof(strLine),pFile);
				strLine[strlen(strLine)-1] = '\0';
				strcpy(allmessages[i].group, strLine);
				
				// 4th line contains the subject
				fgets(strLine,sizeof(strLine),pFile);
				strLine[strlen(strLine)-1] = '\0';
				strcpy(allmessages[i].subj, strLine);
				
				// 5th line contains the announcement
				fgets(stringLine,sizeof(stringLine),pFile);
				stringLine[strlen(stringLine)-1] = '\0';
				strcpy(allmessages[i].announcement, stringLine);
				
				// 6th line contains the mail
				fgets(stringLine,sizeof(stringLine),pFile);
				stringLine[strlen(stringLine)-1] = '\0';
				strcpy(allmessages[i].mail, stringLine);
		}
		fclose (pFile); 
	}
	else	// users.txt not found, revert to default
		*nMess = 0;
}

/* funcloadUserList2
		
	Function:
	- Loads everything in text files

 @param user - A structure containing all of a user's information
 @param *nQuestions - Containing how many security questions were created in the program.
 @param sAdminPassword - the admin's password
 
 
	(void function == does not return anything)
*/

void loadUserList2(acc users, int *nQuestions, str sAdminPassword)
{
	FILE *pFile;
	str strLine;
	int i;
	
	pFile = fopen("scquestions.txt", "rt"); //See above, in saveUserList
	
	if (pFile != NULL) // scquestions.txt exists
	{
		fgets(strLine,sizeof(strLine),pFile);
		*nQuestions = atoi(strLine);
		
		for (i = 0; i < *nQuestions; i++)
		{
				fgets(strLine,sizeof(strLine),pFile);
				strLine[strlen(strLine)-1] = '\0';
				strcpy(users[i].question, strLine);
		}
		fclose (pFile); 
		
	}
	else	// sc_questions.txt not found, revert to default
		*nQuestions = 0;
		
	pFile = fopen("adminpassword.txt", "rt"); //See above, in saveUserList
	
	if (pFile != NULL) // scquestions.txt exists
	{
		fgets(strLine,sizeof(strLine),pFile);
	
		fgets(strLine,sizeof(strLine),pFile);
		strLine[strlen(strLine)-1] = '\0';
		strcpy(sAdminPassword, strLine);
		
		fclose (pFile); 
		
	}
}

int main()
{
	int choose, bStop = 0; //Input and whether the input is valid or not
	acc user; //USER structure
	mess allmessages; //MESSENGER STRUCTURE
	int nUsers = 0, nQuestions = 0, nMess = 0; //no. of users, no..of questions, no. of messages
	int nIndex; //save current user's location on .txt
	str sAdminPassword; //The default password of ADMIN

	loadUserList(user, &nUsers, &nMess, allmessages);						//Getting Information on the txt. file
	loadUserList2(user, &nQuestions, sAdminPassword);	//Getting Information on the txt. file
	
	do{
		system("cls");
		printf("===============================================================\n");
		printf("==========                                           ==========\n"); 
	    printf("==========        GUMMIPHONE MESSENGER SERVICE       ==========\n"); 
	    printf("==========                                           ==========\n"); 
	    printf("===============================================================\n");
	    printf("                           MENU\n\n"); 
	    printf("                       [1] Log-in\n");
	    printf("                       [2] Create new Account\n");
	    printf("                       [3] U Admin?\n");
	    printf("                       [4] Exit :(\n");
	    printf("\n                    TYPE CHOICE: ");
	    scanf("%d", &choose);											//User input on where they want to go
	    system("cls");
	    
	    if (choose == 1)
			userModule(user, &nUsers, &nIndex, &nMess, allmessages);		//User Module
		else if (choose == 2)
			addUser(user, &nUsers, &nQuestions);							//Creating an Account
		else if (choose == 3)
			adminModule(user, &nUsers, &nIndex, &nQuestions, sAdminPassword, &nMess, allmessages); //Administrator Module
		else if (choose == 4)
			bStop = 1;			//Terminating the Program
		else
			bStop = 0;			//Looping the Program
	    
	}while (bStop == 0);
	
	saveUserList(user, nUsers, &nQuestions, sAdminPassword);		//Saving structure's contents
	saveMessages(nMess, allmessages);
	
	return 0;
}
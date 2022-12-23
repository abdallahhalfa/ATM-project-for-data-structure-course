#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
void GetCardNum(char InputCardNum[]) //used to input the card number throughout the code.
// it checks that the card number contains 10 digits and no characters before returning.
{
    bool InvalidNum=false;
    bool SameDigit=true;
    do{
            SameDigit=true;
    do{
    cin.getline(InputCardNum,100);
     if(strlen(InputCardNum)==0){
        cout<<"Card number can't be empty.\n";
        cout<<"Please enter the account number (10 numbers): ";
        InvalidNum=true;
        continue;
     }
     for(int i=0;i<strlen(InputCardNum);i++){
      if(InputCardNum[i]<48||InputCardNum[i]>57){ //comparing ASCII codes
            cout<<"Card number can't contain any characters or spaces.\n";
            cout<<"Please enter the account number (10 numbers): ";
            InvalidNum=true;
            break;}
      else
        InvalidNum=false;
    }
    }while(InvalidNum);
    for(int i=0;i<strlen(InputCardNum)-1;i++){
        if(InputCardNum[i]!=InputCardNum[i+1]){
            SameDigit=false;
            break;
        }
    }
    if(strlen(InputCardNum)>10||strlen(InputCardNum)<10){
        cout<<"Card number must contain 10 digits\n";
        cout<<"Please enter the account number (10 numbers): ";
    }
    else if(SameDigit){
        cout<<"Card number can not be made of the same number only\n";
        cout<<"Please enter the account number (10 numbers): ";
    }
    }while(strlen(InputCardNum)!=10||SameDigit);
    return;
}
//-------------------------------------------------------------------------------------------------------------------------
float GetAmount(char arr_amount[]){ //used to input the amount of money throughout the code.
    // it takes a string containing the amount and only returns it as float after checking that it's written correctly and without any special characters.
    float amount_int=0;
    float sum_amount=0;
    int decimal_place=0;
    bool invalidnum=false;
    bool more_point=false;
    do{
        do{
            decimal_place=0;
            cin.getline(arr_amount,100);
            if(strlen(arr_amount)>15){
                cout<<"amount is too long. "<<"Please re-enter the amount correctly:";
                invalidnum=true;
                continue;
            }else if(strlen(arr_amount)==0){
                cout<<"amount is can't be empty. "<<"Please re-enter the amount correctly:";
                invalidnum=true;
                continue;
            }
            for(int i=0;i<strlen(arr_amount);i++){
            if(arr_amount[i]=='.'){
            decimal_place=i;
            break;
            }}
            for(int i=0;i<strlen(arr_amount);i++){
                if(arr_amount[i]=='.'){
                    continue;}
                else if(arr_amount[i]<48||arr_amount[i]>57){
                    cout<<"Invalid. Please enter the amount as a positive number without special characters or spaces:";
                    invalidnum=true;
                    break;}
                else
                    invalidnum=false;
        }}while(invalidnum);
        for(int i=decimal_place+1;i<strlen(arr_amount);i++){
            if(arr_amount[i]=='.'){
                cout<<"Number cannot contain more than one decimal point \n"<<"Please re-enter the amount correctly:";
                more_point=true;
                break;}
            else
                more_point=false;
    }}while(more_point);
for(int i=0;i<strlen(arr_amount);i++){
    if(arr_amount[i]=='.'){
        for(int j=i+1;j<strlen(arr_amount);j++){
            amount_int=arr_amount[j]-'0';
            sum_amount+= amount_int*pow(10,-(j-i));}
            break;
        }
    amount_int=arr_amount[i]-'0';
    if(decimal_place!=0)
        sum_amount+= amount_int*pow(10,decimal_place-i-1);
    else
        sum_amount+= amount_int*pow(10,strlen(arr_amount)-i-1);}
return sum_amount;}
//-------------------------------------------------------------------------------------------------------------------------
//try again function enables user to chose if he wants to continue or exit to main menu when entering invalid input
bool try_again(){
char *input=new char[3];
while(true){
cout<<"Press 1 to try again and 0 to exit to main menu: ";
cin.getline(input,50);
if(strcmp(input,"1")==0){
    delete []input;
    input=NULL;
    return true;
    }
else if(strcmp(input,"0")==0){
    delete []input;
    input=NULL;
    return false;}
else{
    cout<<"invalid input.\n";}
}}
//-------------------------------------------------------------------------------------------------------------------------
//DECLARATION OF THE CLASS.
class ATM
{
    private:
    char account_name[102];
    char card_number[12];
    double amount;
    public:
    ATM()
        {
        for(int i=0;i<10;i++)
            card_number[i]=0;
        }
    void create_new_acc();
    void Deposit(char arr_amount[]);
    void Withdrawal(char arr_amount[]);
    void Transfer(ATM &a,char arr_amount[]);
    void Print_acc_data();
    bool Compare_cardnum(char InputCardNum[]);
    bool compare_accounts(ATM a);

};
//-------------------------------------------------------------------------------------------------------------------------
ATM acc[100]; //Declaring global objects of type ATM. They're global because they're accessed by the CheckAccountAvailability function.


//CheckAccountAvailability function checks if the cardnumber entered is available
bool CheckAccountAvailability(char InputCardNum[]) //returns TRUE if the card number is available to be used
{
    for(int i=0;i<100;i++)
        if(acc[i].Compare_cardnum(InputCardNum))
        return false;
    return true;
}
//-------------------------------------------------------------------------------------------------------------------------
//Create new account function that get the name and the cardnumber from the user and checks their validity
void ATM::create_new_acc()
{
    char numtemp[12];
    bool InvalidName=false;
    bool consecutive_spaces=false;
    do{
    do{
    consecutive_spaces=false;
    cout<<"Please enter the account name: ";
    cin.getline(account_name,500);
    for(int i=0;i<strlen(account_name);i++){  //checks that the name contains no special characters or numbers.
      if(account_name[i]==32)
            continue;
      if(account_name[i]<65||account_name[i]>122){
            cout<<"Name must not contain special characters or numbers. \n";
            InvalidName=true;
            break;}
      else if(account_name[i]<97&&account_name[i]>90){
            cout<<"Name must not contain special characters or numbers. \n";
            InvalidName=true;
            break;}
      else
        InvalidName=false;
    }
    //makes sure that the name doesn't contain consecutive spaces that could allow names to be made up of spaces only
     for(int i=0;i<strlen(account_name);i++){
        if(account_name[i]==32&&account_name[i+1]==32){
        cout<<"Name must not contain consecutive spaces. \n";
            consecutive_spaces=true;
            InvalidName=true;
            break;
    }}
    if(consecutive_spaces) //if name contains more than one space re-enter the loop to re-enter the name
        continue;
    if(strlen(account_name)>100)   //makes sure that the account name is less than 100 characters long
    {
        cout<<"Account name must contain less than 100 characters.\n";
        break;
    }else if(strlen(account_name)==0){   //makes sure that the account name is not empty
        cout<<"Account name must not be empty.\n";
        break;
        }
    else if(account_name[0]==32){ //makes sure name doesnt begin with space
        cout<<"Account name can't begin with space.\n";
        break;
        }
    }while(InvalidName);
    }while(strlen(account_name)>100||strlen(account_name)==0||account_name[0]==32);
    do
    {
    cout<<"Please enter the account number (10 numbers): ";
    GetCardNum(numtemp);
        if(CheckAccountAvailability(numtemp)==true)
        {
            for(int j=0;j<10;j++)
                card_number[j]=numtemp[j];
            break;
        }
        else{
            cout<<"Card number is already used.\n";
        }
    } while(true);
    amount=0;
    Print_acc_data();
}
//-------------------------------------------------------------------------------------------------------------------------
//Deposit function enables the user to add amount of money to the account
void ATM::Deposit(char arr_amount[])
{
    double dep;
    do{
    cout<<"Please enter the amount to be deposited: ";
    dep=GetAmount(arr_amount);
    if(dep==0)
        cout<<"Amount can't be zero.\n";
    }while(dep<=0);
    amount+=1.01*dep;
    Print_acc_data();
}
//-------------------------------------------------------------------------------------------------------------------------
//Withdrawal function enables the user to withdraw an amount of money if the amount of money in the account is greater than the withdrawn one
void ATM::Withdrawal(char arr_amount[])
{
    double withd;
    Return_to_withdrawral:
    if(amount==0)
    {
        cout<<"There is no money in the account to withdraw.\n";
        return;
    }
    do{
    cout<<"Please enter the amount to be withdrawn: ";
    withd=GetAmount(arr_amount);
    if(withd==0)
        cout<<"Amount can't be zero.\n";
    }while(withd<=0);
    if(amount>=withd*1.03)
    {
        amount-=withd*1.03;
        Print_acc_data();}
    else{
        cout<<"Not enough money for the operation.\n";
        if(try_again())
            goto Return_to_withdrawral;
    }
}
//-------------------------------------------------------------------------------------------------------------------------
//transfer function enable the user to transfer money from one account to another
void ATM::Transfer(ATM &a,char arr_amount[])
{
    Return_to_transfer:
    double trans;
    do{
    cout<<"Please enter the amount to be transfered: ";
    trans=GetAmount(arr_amount);
    if(trans==0)
        cout<<"Amount can't be zero.\n";
    }while(trans<=0);
    if(amount>=trans*(1.015))
    {
        amount-=trans*(1.015);
        a.amount+=trans*(0.985);
        cout<<"sending account:\n";
        Print_acc_data();
        cout<<"receiving account:\n";
        a.Print_acc_data();
    }
    else{
        cout<<"Not enough money for the operation.\n";
        if(try_again())
            goto Return_to_transfer;
    }
}
//-------------------------------------------------------------------------------------------------------------------------
//print function prints all the user's data
void ATM::Print_acc_data()
{
    cout<<"name: "<<account_name;
    cout<<"\nCard number: ";
    for(int i=0;i<10;i++)
        cout<<card_number[i];
    cout<<"\namount: "<<amount<<endl;
}
//-------------------------------------------------------------------------------------------------------------------------
bool ATM::Compare_cardnum(char InputCardNum[]) //compares the input array with the object's card number and returns TRUE if they're similar
{
    bool similar=true;
    for(int i=0;i<10;i++)
    if(card_number[i]!=InputCardNum[i])
    {
        similar=false;
        break;
    }
    return similar;
}

bool ATM::compare_accounts(ATM a) //used to compare accounts externally using the Compare_cardnum function, used for a certain corner case
{
    return Compare_cardnum(a.card_number);
}
//-------------------------------------------------------------------------------------------------------------------------
int main()
{
    int AccountCounter=0;
    char tempcardnum1[12];
    char tempcardnum2[12];
    char operation[3];
    char amount[20];
    do
    {
      cout<<"1----Create new account"<<endl<<"2----Deposit"<<endl<<"3----transfer to another account"<<endl<<"4----withdrawal"<<endl<<"5----exit"<<endl;
        cout<<"Please enter the number of operation: ";

        cin.getline(operation,50);
        if(strcmp(operation,"1")==0)
        {
            if (AccountCounter<100) //makes sure that the number of accounts doesn't exceed 100
            {
                acc[AccountCounter].create_new_acc();
                AccountCounter++;
            }
            else
                cout<<"Maximum number of accounts reached.\n";
        }


        else if(strcmp(operation,"2")==0)
        {
            Return_to_operation2:
            if(AccountCounter==0){
                cout<<"There is no enough accounts to enter the operation. Please create an account first.\n";
                continue;}
            bool found=false;
           cout<<"Please enter the account number (10 numbers): ";
           GetCardNum(tempcardnum1); //input the card number
           for(int i=0;i<100;i++) //loop to find the account from the card number
            if(acc[i].Compare_cardnum(tempcardnum1)==true)
           {
               acc[i].Deposit(amount);
               found=true;
               break;
           }
           if(found==false)
            {cout<<"Account not found\n";
            if(try_again())
                goto Return_to_operation2;
            }
           }

           else if(strcmp(operation,"3")==0)

           {   Return_to_operation3:
                if(AccountCounter<2){
                cout<<"There is no enough accounts to enter the operation. Please create an account first.\n";
                continue;}
               bool found1=false;
               bool found2=false;
               int idx1,idx2;
               cout<<"Please enter the number of the sending account (10 numbers): ";
               GetCardNum(tempcardnum1);
               cout<<"Please enter the number of the receiving account (10 numbers): ";
               GetCardNum(tempcardnum2);

               for(int i=0;i<100;i++) //loop to find sending and receiving accounts
               {
                   if(acc[i].Compare_cardnum(tempcardnum1)==true)
                   {
                       found1=true;
                       idx1=i;
                   }
                    if(acc[i].Compare_cardnum(tempcardnum2)==true)
                    {
                        found2=true;
                        idx2=i;
                    }
                    if(found1==true&&found2==true)
                    {
                        if(acc[idx1].compare_accounts(acc[idx2])==true)
    {
        cout<<"Failed operation. Sending and receiving accounts cannot be the same.\n";
        if(try_again())
            goto Return_to_operation3;
        else
            break;
    }
                    else
                      acc[idx1].Transfer(acc[idx2],amount);
                      break;
                    }

               }

               if(found1==false||found2==false)
                {cout<<"One of the accounts or both were not found\n";
                    if(try_again())
                        goto Return_to_operation3;
                }
           }

           else if(strcmp(operation,"4")==0)
           {Return_to_operation4:
               if(AccountCounter==0){
                cout<<"There is no enough accounts to enter the operation. Please create an account first.\n";
                continue;}
            bool found=false;
           cout<<"Please enter the account number (10 numbers): ";
           GetCardNum(tempcardnum1); //input the card number
           for(int i=0;i<100;i++) //loop to find the account from the card number
            if(acc[i].Compare_cardnum(tempcardnum1)==true)
           {
               acc[i].Withdrawal(amount);
               found=true;
               break;
              }

              if(found==false)
            {cout<<"Account not found\n";
            if(try_again())
                goto Return_to_operation4;
            }
           }

           else if(strcmp(operation,"5")==0)
            break;
           else
            {cout<<"Invalid input \n";
            }

    } while(true);

    return 0;
}

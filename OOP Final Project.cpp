#include<bits/stdc++.h>
using namespace std;
class ATM
{
    int deposit_money=0;
    int withdraw_money=0;
    int amount_of_balance=0;
public:
    void deposit(int amount)
    {
        deposit_money=amount;
        amount_of_balance+=deposit_money;
        cout<<endl;
        cout<<"-------------Deposit Complete----------------"<<endl<<endl;
    }
    void withdraw(int amount2)
    {
        withdraw_money=amount2;
        if(amount_of_balance<withdraw_money)
        {
            cout<<endl;
            cout<<"--------Insufficient Balance---------"<<endl<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"-------------Withdraw complete---------------"<<endl<<endl;
            amount_of_balance-=withdraw_money;
        }
    }
    void show_balance()
    {
        cout<<"Your current balance is: "<<amount_of_balance<<endl<<endl;
    }
};
class user
{
private:
    int user_id;
    int Password;
public:
    int get_id(int id)
    {
        user_id=id;
    }
    int take_id()
    {
        return user_id;
    }
    int get_pass(int pass)
    {
        Password=pass;
    }
    int take_pass()
    {
        return Password;
    }

};
int main()
{
    int option,amount1,amount2,inp_id,inp_pass,flag=0,id,passw,x,count=1,key,number_of_User;
    ATM obj;
    cout<<"Enter User Number: ";
    cin>>number_of_User;
    user arr[number_of_User];
    if(count==1){
        ofstream file("user.txt");
        for(int i=0; i<number_of_User; i++)
        {
            cout<<"ID: ";
            cin>>id;
            arr[i].get_id(id);
            cout<<"Password: ";
            cin>>passw;
            arr[i].get_pass(passw);
            file<<id<<endl;
            file<<passw<<endl;
        }
        file.close();
    }
    count++;
    system("cls");
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"                  Welcome To ATM Machine             "<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<endl<<endl;
    while(1)
    {
        cout<<"Enter Your User Id: ";
        cin>>inp_id;
        cout<<"Enter Your Password: ";
        cin>>inp_pass;
        cout<<endl;

        for(int i=0; i<3; i++)
        {
            if(inp_id==arr[i].take_id())
            {
                if(inp_pass==arr[i].take_pass())
                {
                    flag=1;
                    x=inp_id;
                    break;
                }

            }
        }

        if(flag==0)
        {

            cout<<"-----------Incorrect User Id or Password----------"<<endl<<endl;
            cout<<"---------------Press 0 to continue----------------"<<endl;
            cin>>key;
            if(key==0)
            {
                system("cls");
                continue;
            }
            else{

                cout<<"----------Invalid Number-----------"<<endl;
            }

        }
        else if(flag==1)
        {
            break;
        }
    }
    system("cls");
    while(1)
    {
        cout<<"---------------------------------"<<endl;
        cout<<"          User Id: "<<x<<endl;
        cout<<"---------------------------------"<<endl<<endl;
        cout<<"Menu"<<endl<<"----------------------"<<endl;
        cout<<"1.Cash Deposit"<<endl;
        cout<<"2.Cash Withdraw"<<endl;
        cout<<"3.Check Balance"<<endl;
        cout<<"4.Exit"<<endl<<endl;
        cout<<"Choose your option: ";
        cin>>option;
        if(option == 4)
        {
            break;
        }
        else if(option == 1)
        {
            system("cls");
            cout<<"Enter the amount: ";
            cin>>amount1;
            obj.deposit(amount1);
        }
        else if(option == 2)
        {
            system("cls");
            cout<<"Enter the amount: ";
            cin>>amount2;
            obj.withdraw(amount2);
        }
        else if(option == 3)
        {
            system("cls");
            obj.show_balance();
        }
    }

}




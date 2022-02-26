#include<stdio.h>
#include<windows.h>
#include<time.h>

int main(){
    
    int pin=1234,option,enteredPin,count=0,amount=1;
    float balance = 5000;
    int continueTransaction =1;

    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t\t\t\t         %s",ctime(&now));
    printf("\n\t\t\t\t\t ================*Welcome to SHARMAJI ATM*================");

    while(pin!= enteredPin){
        printf("\nPlease enter your pin:\t");
        scanf("%d",&enteredPin);
        if(enteredPin!= pin){
            Beep(610,600);
            printf("\nInvalid Pin!!!!!!");   
        }
        count++;
        if(count==3 && pin != enteredPin){
            exit(0);
        }
    }

    while(continueTransaction !=0){
        printf("\n\t\t\t\t\t ================*Available Transactions*================");
        printf("\n\n\t1.Withdrawal");
        printf("\n\n\t2.Deposit");
        printf("\n\n\t3.Check Balance");
        printf("\n\n\n\tPlease select the option : ");
        scanf("%d",&option);

        switch(option){
            case 1:
                while(amount % 500 != 0){
                    printf("\n\tEnter the amount : ");
                    scanf("%d",&amount);
                    if(amount != 0)
                    printf("\n\tThe amount should be multiple of 500");
                }

                if(balance< amount){
                    printf("\n\t Sorry Insufficient Balance");
                    amount = 1;
                    break;
                }
                else {
                    balance -= amount;
                    printf("\n\tYou have withdrawn Rs.%d. Your new balance is %.2f",amount,balance);
                    printf("\n\n\t\t\t\t ================*Thank You for banking with SHARMAJI ATM*================\n");
                    amount = 1;
                    break;
                }

            case 2:
                printf("\n\tPlease enter the amount : ");
                scanf("%d",&amount);
                balance += amount;
                
                printf("\n\tYou have deposited Rs.%d. Your new balance is %.2f",amount,balance);
                printf("\n\n\t\t\t\t ================*Thank You for banking with SHARMAJI ATM*================\n");
                amount = 1;
                break;
            
            case 3:
                printf("\n\tYour Balance is Rs.%.2f",balance);
                printf("\n\n\t\t\t\t ================*Thank You for banking with SHARMAJI ATM*================\n");
                break;
            
            default:
                Beep(610,600);
                printf("\n\tInvalid Option!!!!!!");    
        }

        printf("\n\t\tDo you wish to perform another transaction? Press 1[Yes], 0[No] :  ");
        scanf("%d",&continueTransaction);
    }

    return 0;
}
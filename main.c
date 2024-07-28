#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct choice{
    char life_insure;
    char donations;
    char saving_acc;
    char comp;
    char mis_children;
    char mis_food_coup;
    char mis_books;
    char mis_leave_trav;
    char home_loan;
    char standard_deduction;

}choice;

typedef struct deduction{
    float life_insure;
    float donations;
    float saving_acc;

    }deduction;

 typedef struct person{

    char name[20];
    float income;
    float tax_initial;
    float tax_final;
    float total_tax;
    float deduction;
}info;

//defining the functions for company
float income_tax(float *income);
float life_ensure(char *ch,int i);
float donation(char *ch,int i);
int saving_account(char *ch,int i);
int comp_facility(char *ch,int i);
int children_allowance(char *ch,int i);
int food_coupons(char *ch,int i);
int leave_travel(char *ch,int i);
float home_loan(char *ch,int i);
float standard_deduction();

//functions for the family
float income_tax_family(float *income);
float life_ensure_family(char *ch,int i);
float donation_family(char *ch,int i);
int saving_account_family(char *ch,int i);
int comp_facility_family(char *ch,int i);
int children_allowance_family(char *ch,int i);
int food_coupons_family(char *ch,int i);
int leave_travel_family(char *ch,int i);
float home_loan_family(char *ch,int i);
float standard_deduction_family();


void main()
{


    //  starting the program with welcoming the user
    printf("  Hello There !!\n\n");
    printf("  This is a program were we will calculate the net income tax you SAVE and PAY to Government.\n\n");
    printf("---------------------------------------------------------------------------------------------------\n\n");

    printf("  Would You Like To Use The Income Tax Calculator For Family Or Company ? \n\n");
    printf("  Enter 'F' For Family And Enter 'C' for Company : ");
    char ch ; scanf("%c",&ch);
    printf("\n");

    // code for company

    if(ch=='c' || ch=='C'){

            int num_of_employee;
    printf("  Please Enter The Number of Employee : ");
    scanf("%d",&num_of_employee);

    info p[num_of_employee];choice c[num_of_employee];deduction d[num_of_employee];

    printf("  First Give Us Some Information About Your employee/employees \n\n");

    // taking necessary informations from the user

    for(int i = 0 ; i<num_of_employee ; i++){


    printf("  Please Give Us The Name Of Employee %d : ",i+1);fflush(stdin);
     gets(p[i].name);
    printf("  \n  What Is Annual Income of Employee %d: ",i+1);fflush(stdin);
     scanf("%f",&p[i].income);

    //calculating the income tax the user pay without deductions
     p[i].tax_initial = income_tax(&p[i].income);


         //asking user if he wants to apply for standard deduction or he wants to file taxs
         printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");
         printf("  Do you Wish To Proceed With Standard Deduction for Employee %d : ",i+1);fflush(stdin);

          // standard deduction choice
          scanf("%c",&c[i].standard_deduction);


     // asking from the user for his choices of deductions
     //and sending choice to the functions for calculations

     if(c[i].standard_deduction == 'y' || c[i].standard_deduction == 'Y'){

        p[i].deduction = standard_deduction();

        printf("---------------------------------------------------------------------------------------------------\n\n");

        continue ;

     }

     else {

     printf("  Now We Will Like To Ask You About Your Deduction Schemes \n\n");

     printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");

     printf("  Do You Have Any Life Insurance For Employee %d : ",i+1);fflush(stdin);

     scanf("%c",&c[i].life_insure);

     printf("\n\n");

     // taking back the value returned by the function and storing it in a structure for ease of access through entire program


    d[i].life_insure = life_ensure(&c[i].life_insure,i);

    p[i].deduction = d[i].life_insure;

    //choice and calculation for donations
    printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");
    printf("  Are There Any Donations Registered Under Employee %d : ",i+1);fflush(stdin);
    scanf("%c",&c[i].donations);
    printf("\n\n");
    d[i].donations = donation(&c[i].donations,i);

    // adding the values in the deduction of person structure for total calculation
    p[i].deduction = p[i].deduction + d[i].donations;

    // savings account
    printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");
    printf("  Does Employee %d Have An Saving Account : ",i+1);fflush(stdin);
    scanf("%c",&c[i].saving_acc);
    printf("\n\n");
    p[i].income = p[i].income +saving_account(&c[i].saving_acc,i);


    //calculations for company facilities
    printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");
    printf("  Does Your Company Provide Any Services For Employee %d: ",i+1);fflush(stdin);
    scanf("%c",&c[i].comp);
    printf("\n\n");

    // adding the amount after 5000 for gift vouchers to income because that is taxable
    p[i].income = p[i].income + comp_facility(&c[i].comp,i);

    // calculations for miscellaneous things

    // children allowance
    printf("  Now We Are Going to Ask You About Your Few Miscellaneous allowances \n");

    printf("  So that We Can Calculate Your Total Tax To Be Paid To The Government Per Year \n\n");

    printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");

    printf("  Do You Provide Employee %d With Children Allowance : ",i+1);fflush(stdin);

    scanf("%c",&c[i].mis_children);
    p[i].income = p[i].income + children_allowance(&c[i].mis_children,i);

    // food coupouns
    printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");

    printf("  Do You Provide Employee %d With Food Coupons/Money : ",i+1);fflush(stdin);

    scanf("%c",&c[i].mis_food_coup);
    printf("\n\n");

    p[i].income = p[i].income + food_coupons(&c[i].mis_food_coup,i);

    //leave travel allowance

    printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");

    printf("  Does yo provide provide Employee %d With Leave Travel Allowance : ",i+1); fflush(stdin);

    scanf("%c",&c[i].mis_leave_trav);
    printf("\n\n");

    p[i].income = p[i].income + leave_travel(&c[i].mis_leave_trav,i);

    // tax deduction on interest on home loan
    printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");

    printf("  Does Employee %d Have An Home Loan : ",i+1);fflush(stdin);

    scanf("%c",&c[i].home_loan);

    p[i].deduction = p[i].deduction + home_loan(&c[i].home_loan,i);

    printf("---------------------------------------------------------------------------------------------------\n\n");

     }

    }





    // printing all the information , tax and deduction calculated
    printf("---------------------------------------------------------------------------------------------------\n\n");

    for(int i = 0 ; i<num_of_employee;i++){


    //printing name
    printf("The Tax Has Been Calculated On The Information Provided For ");
    puts(p[i].name);
    printf("\n\n");
    //printing Taxable income
    printf("  Your Taxable Income Is : %.3f\n\n",p[i].income);

    //calculating and printing Tax on Taxable income
    printf("  Your Tax On Taxable Income is : ");
    p[i].tax_final = income_tax(&p[i].income);
    printf("%.3f\n\n",p[i].tax_final);

    //to print deductions
    printf("  Total Deductions On Your Tax = %.3f\n\n",p[i].deduction);

    //calculating and printing total tax
    p[i].total_tax = p[i].tax_final - p[i].deduction;
    printf("  Tax To Be Paid By ");
    puts(p[i].name);

    if(p[i].total_tax>0)
    printf(" Is : %.3f\n\n",p[i].total_tax);
    else
        printf(" IS : 0.000\n\n");


    }

     float sum_deduct=0,sum_tax=0;
    for(int i = 0;i<num_of_employee;i++){

        sum_tax=sum_tax + p[i].total_tax;
        sum_deduct = sum_deduct + p[i].deduction;
    }

    printf("  Total Tax To Be Paid By Company : %.2f\n\n",sum_tax);
    printf("  Total Deduction : %.2f\n",sum_deduct);
    printf("---------------------------------------------------------------------------------------------------\n\n");


    }






    // code for family members

    else if(ch=='f' || ch=='F'){

            int num_of_fam;
    printf("  Please Enter The Number of Family Members : ");
    scanf("%d",&num_of_fam);
        printf("\n");

        info p[num_of_fam];choice c[num_of_fam];deduction d[num_of_fam];
        printf("  First Give Us Some Information About Your Family Members \n\n");

    // taking necessary informations from the user

    for(int i = 0 ; i<num_of_fam ; i++){


    printf("  Please Give Us The Name Of Family Member %d : ",i+1);fflush(stdin);
     gets(p[i].name);
    printf("  \n  What Is Annual Income of Family Member %d: ",i+1);fflush(stdin);
     scanf("%f",&p[i].income);

    //calculating the income tax the user pay without deductions
     p[i].tax_initial = income_tax_family(&p[i].income);


         //asking user if he wants to apply for standard deduction or he wants to file taxs
         printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");
         printf("  Do you Wish To Proceed With Standard Deduction for Family Member %d : ",i+1);fflush(stdin);

          // standard deduction choice
          scanf("%c",&c[i].standard_deduction);


     // asking from the user for his choices of deductions
     //and sending choice to the functions for calculations

     if(c[i].standard_deduction == 'y' || c[i].standard_deduction == 'Y'){

        p[i].deduction = standard_deduction();

        printf("---------------------------------------------------------------------------------------------------\n\n");

        continue ;

     }

     else {

     printf("  Now We Will Like To Ask You About Your Deduction Schemes For Family Member %d \n\n",i+1);

     printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");

     printf("  Do You Have Any Life Insurance For Family Member %d : ",i+1);fflush(stdin);

     scanf("%c",&c[i].life_insure);

     printf("\n\n");

     // taking back the value returned by the function and storing it in a structure for ease of access through entire program


    d[i].life_insure = life_ensure_family(&c[i].life_insure,i);

    p[i].deduction = d[i].life_insure;

    //choice and calculation for donations
    printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");
    printf("  Are There Any Donations Registered Under Family Member %d : ",i+1);fflush(stdin);
    scanf("%c",&c[i].donations);
    printf("\n\n");
    d[i].donations = donation_family(&c[i].donations,i);

    // adding the values in the deduction of person structure for total calculation
    p[i].deduction = p[i].deduction + d[i].donations;

    // savings account
    printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");
    printf("  Does Family Member %d Have An Saving Account : ",i+1);fflush(stdin);
    scanf("%c",&c[i].saving_acc);
    printf("\n\n");
    p[i].income = p[i].income +saving_account_family(&c[i].saving_acc,i);


    //calculations for company facilities
    printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");
    printf("  Does Family Member %d Company Provide Any Services : ",i+1);fflush(stdin);
    scanf("%c",&c[i].comp);
    printf("\n\n");

    // adding the amount after 5000 for gift vouchers to income because that is taxable
    p[i].income = p[i].income + comp_facility_family(&c[i].comp,i);

    // calculations for miscellaneous things

    // children allowance
    printf("  Now We Are Going to Ask You About Your Few Miscellaneous allowances Of Family Member %d\n",i+1);

    printf("  So that We Can Calculate Family Member %d Total Tax To Be Paid To The Government Per Year \n\n",i+1);

    printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");

    printf("  Does Family Member %d Company Provide Children Allowance : ",i+1);fflush(stdin);

    scanf("%c",&c[i].mis_children);
    p[i].income = p[i].income + children_allowance_family(&c[i].mis_children,i);

    // food coupouns
    printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");

    printf("  Does Family Member %d Company Provide Food Coupons/Money : ",i+1);fflush(stdin);

    scanf("%c",&c[i].mis_food_coup);
    printf("\n\n");

    p[i].income = p[i].income + food_coupons_family(&c[i].mis_food_coup,i);

    //leave travel allowance

    printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");

    printf("  Does Family Member %d Company Provide Leave Travel Allowance : ",i+1); fflush(stdin);

    scanf("%c",&c[i].mis_leave_trav);
    printf("\n\n");

    p[i].income = p[i].income + leave_travel_family(&c[i].mis_leave_trav,i);

    // tax deduction on interest on home loan
    printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");

    printf("  Does Family Member %d Have An Home Loan : ",i+1);fflush(stdin);

    scanf("%c",&c[i].home_loan);

    p[i].deduction = p[i].deduction + home_loan_family(&c[i].home_loan,i);

    printf("---------------------------------------------------------------------------------------------------\n\n");

     }

    }





    // printing all the information , tax and deduction calculated


    for(int i = 0 ; i<num_of_fam;i++){


    //printing name
    printf("The Tax Has Been Calculated On The Information Provided For ");
    puts(p[i].name);
    printf("\n\n");
    //printing Taxable income
    printf("  Your Taxable Income Is : %.3f\n\n",p[i].income);

    //calculating and printing Tax on Taxable income
    printf("  Your Tax On Taxable Income is : ");
    p[i].tax_final = income_tax_family(&p[i].income);
    printf("%.3f\n\n",p[i].tax_final);

    //to print deductions
    printf("  Total Deductions On Your Tax = %.3f\n\n",p[i].deduction);

    //calculating and printing total tax
    p[i].total_tax = p[i].tax_final - p[i].deduction;
    printf("  Tax To Be Paid By ");
    puts(p[i].name);

    if(p[i].total_tax>0)
    printf(" Is : %.3f\n\n",p[i].total_tax);
    else
        printf(" IS : 0.000\n\n");

    printf("---------------------------------------------------------------------------------------------------\n\n");
    }
    float sum_deduct=0,sum_tax=0;
    for(int i = 0;i<num_of_fam;i++){

        sum_tax=sum_tax + p[i].total_tax;
        sum_deduct = sum_deduct + p[i].deduction;
    }

    printf("  Total Tax To Be Paid By Family : %.2f\n\n",sum_tax);
    printf("  Total Deduction : %.2f\n",sum_deduct);
    printf("---------------------------------------------------------------------------------------------------\n\n");

    }



}

// tax calculation for company


//calculating the tax in the function
float income_tax(float *income){
   float tax ;
 if (*income <= 250000) {
        tax = 0;
    } else if (*income <= 500000) {
        tax = 0.05 * (*income - 250000);
    } else if (*income <= 1000000) {
        tax = 12500 + 0.2 * (*income - 500000);
    } else {
        tax = 112500 + 0.3 * (*income - 1000000);
    }

    return tax ;
}

 //creating a function for life insurance deduction calculation
 float life_ensure(char *ch,int i){
     char check;float deduct;

    switch(*ch){

    case 'n':
    case 'N':   return 0;
        break;
    case 'y':
    case 'Y': //calculating the deduction for the person
        deduct = 25000;

        //asking user for his senior life insurance

        printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");

        printf("  Does the Employee %d Have Any Life Insurance For Any Elder/Senior : ",i+1);fflush(stdin);

        scanf("%c",&check);

        printf("\n\n");

            switch(check){
                case 'n':
                case 'N':
                    break;
                case 'y':
                case 'Y':
                    deduct = deduct + 50000;
            }

    }

    return deduct ;
 }
// calculation for donations deductions
 float donation(char *ch,int i){

        switch(*ch){

            case 'n':
            case 'N':
                return 0;
                break;
            case 'y':
            case 'Y':
                        printf("  Please Enter Amount Of Donation Done By Employee %d : ",i+1);
                        float amt; scanf("%f",&amt);
                        printf("\n\n");
                        printf("  Enter Percentage Deduction Applied/Provided By The Organization : ");fflush(stdin);
                        float per ;
                        do{
                        scanf("%f",&per);
                        printf("\n");
                        if(per < 0 || per > 100)
                            printf("  Wrong Input For Percentage \n\n Please Enter Again : ");

                        }while(per>=0 && per<=100);

                        return (amt*(per/100.0));
        }


 }

 // calculations for saving account
 int saving_account(char *ch,int i){
            int amt;
        switch(*ch){
            case 'n':
            case 'N':
                return 0;
            case 'y':
            case 'Y': printf("  Please Enter The Income Earned From Saving Account Interest By Employee %d : ",i+1);fflush(stdin);
                        scanf("%d",&amt);
                      printf("\n\n");
                      if(amt<=10000)
                        return 0;
                      else
                        return (amt -10000);
        }
 }

 //calculations for company facilities
 int comp_facility(char *ch,int i){
        char cab,health_club,gifts;int amt_gift;
    switch(*ch){
        case 'n':
        case 'N': return 0;
            break;
        case 'Y':
        case 'y':   printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");
                    printf("  Do You Provide Employee %d With Cab Facility : ",i+1);fflush(stdin);
                    scanf("%c",&cab);
                    printf("\n\n");
                    printf("  Do You Provide Employee %d With Health Club Facility  : ",i+1);fflush(stdin);
                    scanf("%c",&health_club);
                    printf("\n\n");
                    printf("  Do You Provide Employee %d With Gifts/Vouchers : ",i+1);fflush(stdin);
                    scanf("%c",&gifts);
                    printf("\n\n");

                    switch(gifts){
                            case 'n':
                            case 'N': return 0;
                                break ;

                            case 'Y':
                            case 'y':
                                printf("  Enter Amount Of Gift/Vouchers Received per year By Employee %d : ",i+1);fflush(stdin);
                                scanf("%d",&amt_gift);
                                printf("\n\n");
                                if(amt_gift>5000){
                                    return (amt_gift-5000);
                                }
                                else return 0;
                    }

    }
 }

 // children allowance
 int children_allowance(char *ch,int i){
     int amt;
        switch(*ch){
            case 'n':
            case 'N':
                return 0;
                break ;
            case 'y':
            case 'Y': printf("  Please Enter The Amount Of Children Allowance Employee %d Receive Per Year : ",i+1);fflush(stdin);
                scanf("%d",&amt);
                printf("\n\n");

                if(amt<=1200)
                    return 0;
                else{

                    return (amt - 1200);
                }
        }
 }

 // food coupons
 int food_coupons(char *ch,int i){
        int amt;

        switch(*ch){
            case 'n':
            case 'N':
                return 0;
            case 'y':
            case 'Y': printf("  Please Enter The Amount Of Food Coupons/money Received Yearly by Employee %d : ",i+1);fflush(stdin);
                        scanf("%d",&amt);
                      printf("\n\n");
                      if(amt<=26400)
                        return 0;
                      else {
                        return (amt - 26400);
                      }

        }
 }

 int leave_travel(char *ch,int i){
     int amt,amt_spent;char check;
    switch(*ch){
        case 'n':
        case 'N':
            return 0;
            break;
        case 'y':
        case 'Y':   //checking whether the travel was domestic or international
                    printf("  Please Enter The Leave Travel Allowance Employee %d Receive Per Year : ",i+1);fflush(stdin);
                    scanf("%d",&amt);
                    printf("\n\n");

                    printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");
                    printf("  Was Employee %d Travel Domestic :",i+1);fflush(stdin);
                    scanf("%c",&check);
                    if(check == 'n'|| check == 'N'){
                        return amt;
                        break;
                    }
                    else{

                   printf("  Please Enter The Amount Spent On Actual Travel Costel by Employee %d : ",i+1);fflush(stdin);
                   scanf("%d",&amt_spent);

                   if((amt-amt_spent)<=0){
                    return 0;
                   }
                   else {
                    return (amt-amt_spent);
                   }
                    }
    }
 }

 // tax deduction on interest on home loan

 float home_loan(char *ch,int i){
    int amt;float rate,paying_amt;

    switch(*ch){
        case 'n':
        case 'N':
            return 0;
            break;

        case 'Y':
        case 'y':

    printf("  Please Enter The Principle Amount Of Employee %d Loan : ",i+1);fflush(stdin);
    scanf("%d",&amt);

    printf("  Please Enter The Yearly Rate Of Employee %d Loan : ",i+1);
    scanf("%f",&rate);

    paying_amt = amt * (rate/100.0);

    if(paying_amt <=50000){
        return paying_amt;
    }
        else
            return 50000;
    }
    }


 //standard deduction
 float standard_deduction(){

        return 50000;

 }



 // tax calculation for family


 //calculating the tax in the function
float income_tax_family(float *income){
   float tax ;
 if (*income <= 250000) {
        tax = 0;
    } else if (*income <= 500000) {
        tax = 0.05 * (*income - 250000);
    } else if (*income <= 1000000) {
        tax = 12500 + 0.2 * (*income - 500000);
    } else {
        tax = 112500 + 0.3 * (*income - 1000000);
    }

    return tax ;
}

 //creating a function for life insurance deduction calculation
 float life_ensure_family(char *ch,int i){
     char check;float deduct;

    switch(*ch){

    case 'n':
    case 'N':   return 0;
        break;
    case 'y':
    case 'Y': //calculating the deduction for the person
        deduct = 25000;

        //asking user for his senior life insurance

        printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");

        printf("  Does Family Member %d Have Any Life Insurance For Any Elder/Senior : ",i+1);fflush(stdin);

        scanf("%c",&check);

        printf("\n\n");

            switch(check){
                case 'n':
                case 'N':
                    break;
                case 'y':
                case 'Y':
                    deduct = deduct + 50000;
            }

    }

    return deduct ;
 }
// calculation for donations deductions
 float donation_family(char *ch,int i){

        switch(*ch){

            case 'n':
            case 'N':
                return 0;
                break;
            case 'y':
            case 'Y':
                        printf("  Please Enter Amount Of Donation Done By Family Member %d : ",i+1);
                        float amt; scanf("%f",&amt);
                        printf("\n\n");
                        printf("  Enter Percentage Deduction Applied/Provided By The Organization : ");fflush(stdin);
                        float per ; scanf("%f",&per);
                        printf("\n");

                        return (amt*(per/100.0));
        }


 }

 // calculations for saving account
 int saving_account_family(char *ch,int i){
            int amt;
        switch(*ch){
            case 'n':
            case 'N':
                return 0;
            case 'y':
            case 'Y': printf("  Please Enter The Income Earned From Saving Account Interest By Family Member %d : ",i+1);fflush(stdin);
                        scanf("%d",&amt);
                      printf("\n\n");
                      if(amt<=10000)
                        return 0;
                      else
                        return (amt -10000);
        }
 }

 //calculations for company facilities
 int comp_facility_family(char *ch,int i){
        char cab,health_club,gifts;int amt_gift;
    switch(*ch){
        case 'n':
        case 'N': return 0;
            break;
        case 'Y':
        case 'y':   printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");
                    printf("  Does Family Member %d Company Provide Cab Facility : ",i+1);fflush(stdin);
                    scanf("%c",&cab);
                    printf("\n\n");
                    printf("  Does Family Member %d Company Provide Health Club Facility  : ",i+1);fflush(stdin);
                    scanf("%c",&health_club);
                    printf("\n\n");
                    printf("  Does Family Member %d Company Provide Gifts/Vouchers : ",i+1);fflush(stdin);
                    scanf("%c",&gifts);
                    printf("\n\n");

                    switch(gifts){
                            case 'n':
                            case 'N': return 0;
                                break ;

                            case 'Y':
                            case 'y':
                                printf("  Enter Amount Of Gift/Vouchers Received per year By Family Member %d : ",i+1);fflush(stdin);
                                scanf("%d",&amt_gift);
                                printf("\n\n");
                                if(amt_gift>5000){
                                    return (amt_gift-5000);
                                }
                                else return 0;
                    }

    }
 }

 // children allowance
 int children_allowance_family(char *ch,int i){
     int amt;
        switch(*ch){
            case 'n':
            case 'N':
                return 0;
                break ;
            case 'y':
            case 'Y': printf("  Please Enter The Amount Of Children Allowance Received Per Year By Family Member %d : ",i+1);fflush(stdin);
                scanf("%d",&amt);
                printf("\n\n");

                if(amt<=1200)
                    return 0;
                else{

                    return (amt - 1200);
                }
        }
 }

 // food coupons
 int food_coupons_family(char *ch,int i){
        int amt;

        switch(*ch){
            case 'n':
            case 'N':
                return 0;
            case 'y':
            case 'Y': printf("  Please Enter The Amount Of Food Coupons/money Received Yearly by Family Member %d : ",i+1);fflush(stdin);
                        scanf("%d",&amt);
                      printf("\n\n");
                      if(amt<=26400)
                        return 0;
                      else {
                        return (amt - 26400);
                      }

        }
 }

 int leave_travel_family(char *ch,int i){
     int amt,amt_spent;char check;
    switch(*ch){
        case 'n':
        case 'N':
            return 0;
            break;
        case 'y':
        case 'Y':   //checking whether the travel was domestic or international
                    printf("  Please Enter The Leave Travel Allowance Family Member %d Receive Per Year : ",i+1);fflush(stdin);
                    scanf("%d",&amt);
                    printf("\n\n");

                    printf("  Type 'Y'/'y' for YES and 'N'/'n' for NO \n\n");
                    printf("  Was Family Member %d Travel Domestic :",i+1);fflush(stdin);
                    scanf("%c",&check);
                    if(check == 'n'|| check == 'N'){
                        return amt;
                        break;
                    }
                    else{

                   printf("  Please Enter The Amount Spent On Actual Travel Costel by Family Member %d : ",i+1);fflush(stdin);
                   scanf("%d",&amt_spent);

                   if((amt-amt_spent)<=0){
                    return 0;
                   }
                   else {
                    return (amt-amt_spent);
                   }
                    }
    }
 }

 // tax deduction on interest on home loan

 float home_loan_family(char *ch,int i){
    int amt;float rate,paying_amt;

    switch(*ch){
            case 'n':
            case 'N':
                return 0;
                break;

            case 'y':
            case 'Y':

    printf("  Please Enter The Principle Amount Of Family Member %d Loan : ",i+1);fflush(stdin);
    scanf("%d",&amt);

    printf("  Please Enter The Yearly Rate Of Family Member %d Loan : ",i+1);
    scanf("%f",&rate);

    paying_amt = amt * (rate/100.0);

    if(paying_amt <=50000){
        return paying_amt;
    }
        else
            return 50000;

    }
    }


 //standard deduction
 float standard_deduction_family(){

        return 50000;

 }





#include "BankAccount.h"

struct BankAccount {
    double balance;
    double last_withdrawl;
    double last_deposit;
};

BankAccount* BankAccount_construct(double balance)
{ /*Making an array for malloc*/
  struct BankAccount *x = malloc(sizeof(struct BankAccount));

   //pointing to objects in struct
   x->balance = balance;
   x->last_withdrawl = 0;
   x->last_deposit = 0;

   return x;
}

void BankAccount_destroy(BankAccount* ba)
{
/*Freeing memory*/

   free(ba);

}

int BankAccount_deposit(BankAccount* ba, double amount)
{
/*
 * Performs a deposit on an account.
 *
 * - Bonus feature: checking for overflow/underflow.
 *   - Does not modify ba->balance on error.
 *
 * Returns: 0 on success, 1 on overflow, -1 on underflow.
 */

//sending pointer values to the struct

   ba->balance = ba->balance + amount;
   ba->last_deposit = amount;


   //Not going for bonus just yet :)
   return 0;

}

int BankAccount_withdraw(BankAccount* ba, double amount)
{
/*
 * Performs a withdrawal on a BankAccount.
 *
 */

   //Doing withdrawl and sending back to struct
   ba->balance = ba->balance - amount;
   ba->last_withdrawl = amount;

   return 0;
}

double BankAccount_get_balance(BankAccount* ba)
{
   return ba->balance;   
}

double BankAccount_get_last_deposit(BankAccount* ba)
{
   return ba->last_deposit;
}

double BankAccount_get_last_withdrawal(BankAccount* ba)
{
   return ba->last_withdrawl;
}

/*
 * Implement the definitions for the
 * functions involving BankAccount from BankAccount.h here,
 *
 * Make sure to produce comments that look like this!
 * (Try to copy the formatting.)
 *
 * For BankAccount_construct() and BankAccount_destroy(),
 * if you do not remember malloc() and free(), review them
 * by creating a toy program.
 */


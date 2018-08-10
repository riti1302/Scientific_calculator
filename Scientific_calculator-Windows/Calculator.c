


/**

* Scientific calculator

*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<math.h>
#include<windows.h>

//Number of operations that can be stored in memory
#define size 100

//Memory index
int i=0;

//Storing each operation
struct store
{
    double num1, num2, result;
    char op[10];
};
struct store mem[size]={0};;



/**   Function Declarations   **/


//For display use
void welcome();
void display_calculator();


//Instructions how to use
void Instructions();
void Abbreviations();


//For memory use
void memory1(double, char op[], double, double);    //for binary operations
void memory2(char op[], double, double);            //for unary operations



//Binary Operations
double addition(double, double);
double substraction(double, double);
double multiplication(double, double);
double division(double, double);
double permutation(int, int);
double combination(int, int);
int modulus(int, int);


//Unary Operations
double inverse(double);
int decimal_to_binary(int);
int decimal_to_octal(int);
int binary_to_decimal(int);
int octal_to_decimal(int);
int factorial(int);



//Clears the screen and calls the main function
void clear();

//Detects error
void error();



/** Main funtion  **/

int main()
{
    system("cls");    //Clears the screen.

    int option;
    char choice[10];
    double number1, number2, result;


   while(1)
   {
      system("cls");
      welcome();

      printf("\n\n\n\t\t\t[1] How to use\t\t[2] Abbreviations\t\t[3] Use calculator\n\n\t\t\t[4] Exit\n\n\t\tChoice:     ");
      scanf("%d", &option);
      system("cls");

      if(option == 1)
      {
         Instructions();
         continue;
      }

      else if(option == 2)
      {
         Abbreviations();
         continue;
      }

      else if(option == 3)
      {
          break;
      }

      else if(option == 4)
      {
          exit(1);
      }

      else
      {
          printf("\n\n\t\t\t\t\tInvalid option");
          continue;
      }
   }
    system("cls");
    system("color 0F");

    display_calculator();
    delay(100);

    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 14);

    printf("\t\tNumber:     ");
    scanf("%lf", &number1);

    while(1)
    {
      SetConsoleTextAttribute(h, 15);

      printf("\t\tOperation:    ");
      fflush(stdin);                 //Clears the buffer
      gets(choice);


      if((strcmp(choice, "+")== 0) || (strcmp(choice, "-")== 0) || (strcmp(choice, "*")== 0) || (strcmp(choice, "/")== 0) || (strcmp(choice, "%")== 0) || (strcmp(choice, "^")== 0) || (strcmp(choice, "P")== 0) || (strcmp(choice, "C")== 0))
      {
          SetConsoleTextAttribute(h, 14);
          printf("\t\tNumber:    ");
          scanf("%lf", &number2);

          if(strcmp(choice, "+")== 0)
               result = addition(number1,number2);

          else if(strcmp(choice, "-")== 0)
               result = substraction(number1,number2);

          else if(strcmp(choice, "*")== 0)
               result = multiplication(number1,number2);

          else if(strcmp(choice, "/")== 0)
               result = division(number1,number2);


          else if(strcmp(choice, "%")== 0)
               result = modulus(number1,number2);

          else if(strcmp(choice, "^")== 0)
               result = pow(number1,number2);

          else if(strcmp(choice, "P")== 0)
               result = permutation(number1,number2);


          else if(strcmp(choice, "C")== 0)
               result = combination(number1,number2);


       SetConsoleTextAttribute(h, 10);
       printf("\t\tResult:   %lf\n\n\n", result);

       memory1(number1, choice , number2, result);
     }


      else if((strcmp(choice, "sqrt")== 0) || (strcmp(choice, "sin")== 0) || (strcmp(choice, "cos")== 0) || (strcmp(choice, "tan")== 0) || (strcmp(choice, "sinh")== 0) || (strcmp(choice, "cosh")== 0) || (strcmp(choice, "tanh")== 0) || (strcmp(choice, "sin-1")== 0) || (strcmp(choice, "cos-1")== 0) || (strcmp(choice, "tan-1")== 0) || (strcmp(choice, "sqrt")== 0) || (strcmp(choice, "!")== 0) || (strcmp(choice, "e")== 0) || (strcmp(choice, "In")== 0) || (strcmp(choice, "log")== 0) || (strcmp(choice, "dtb")== 0) || (strcmp(choice, "dto")== 0) || (strcmp(choice, "otd")== 0) || (strcmp(choice, "btd")== 0) || (strcmp(choice, "abs")== 0) || (strcmp(choice, "inv")== 0))
      {
          if(strcmp(choice, "sqrt")== 0)
               result = sqrt(number1);

          else if(strcmp(choice, "sin")== 0)
               result = sin(number1);

          else if(strcmp(choice, "cos")== 0)
               result = cos(number1);

          else if(strcmp(choice, "tan")== 0)
               result = tan(number1);

          else if(strcmp(choice, "e")== 0)
               result = exp(number1);

          else if(strcmp(choice, "In")== 0)
               result = log(number1);

          else if(strcmp(choice, "log")== 0)
               result = log10(number1);

          else if(strcmp(choice, "abs")== 0)
               result = fabs(number1);

          else if(strcmp(choice, "sinh")== 0)
               result = sinh(number1);

          else if(strcmp(choice, "cosh")== 0)
               result = cosh(number1);

          else if(strcmp(choice, "tanh")== 0)
               result = tanh(number1);

          else if(strcmp(choice, "sin-1")== 0)
               result = asin(number1);

          else if(strcmp(choice, "cos-1")== 0)
               result = acos(number1);

          else if(strcmp(choice, "tan-1")== 0)
               result = atan(number1);

          else if(strcmp(choice, "inv")== 0)
               result = inverse(number1);

          else if(strcmp(choice, "dtb")== 0)
               result = decimal_to_binary(number1);

          else if(strcmp(choice, "dto")== 0)
               result = decimal_to_octal(number1);

          else if(strcmp(choice, "btd")== 0)
               result = binary_to_decimal(number1);

          else if(strcmp(choice, "otd")== 0)
               result = octal_to_decimal(number1);

          else if(strcmp(choice, "!")== 0)
               result = factorial(number1);

       SetConsoleTextAttribute(h, 10);
       printf("\t\tResult:   %lf\n\n\n", result);

       memory2(choice, number1, result);
     }


       else if(strcmp(choice, "clr")== 0)
      {
         clear();
      }


      /**
      * Displays memory
      */

       else if(strcmp(choice, "mem")== 0)
       {
          int k;

          SetConsoleTextAttribute(h, 3);
          printf("\n\n\t\t\tMEMORY\n\n");
          for(k=0; k<i; k++)
          {
              printf("\t\t%lf %s %lf %s %lf\n", mem[i].num1, mem[i].op, mem[i].num2, "=", mem[i].result);
          }
          printf("\n");
       }

       else if(strcmp(choice, "exit")== 0)
       {
          exit(1);
       }

       else
       {
          SetConsoleTextAttribute(h, 12);
          printf("\n\t\t\tInvalid operation\n\n");
          system("Invalid.vbs");
       }

       number1 = result;
     }

      return 0;
   }


   /**   Function Definitions  **/


   void welcome()
   {
    int i, j, choice;
    char box[60][80];

    system("color 31");
    char *W="SCIENTIFIC CALCULATOR";
    printf("\n\n\n\n\n");


    for(i=0; i<10; i++)
    {
        for(j=0; j<90; j++)
        {
           if(i==0 || j==0 || i==9 || j==79 || j==1 || j==78)
            box[i][j]= 219;

            else
             box[i][j]= 32;
        }
    }


    for(j=25; j<47; j++)
    {
        i=5;
        box[i][j]= *W;
        W++;
    }


    for(i=0; i<10; i++)
    {
        printf("\t\t");

        for(j=0; j<80; j++)
            printf("%c", box[i][j]);

        printf("\n");
    }
   }




   void Instructions()
   {
      system("color A0");
      char ch;
      FILE *fp;
      fp = fopen("How_to_use.txt","r");
      ch= fgetc(fp);

      if(fp == NULL)
      {
          printf("\n\t\t\tFile is not present");
          exit(1);
      }

      while(ch != EOF)
      {
          printf("%c", ch);
          ch= fgetc(fp);
      }
      fclose(fp);

    printf("\n\n\n\n");
    system("pause");
   }




   void Abbreviations()
   {
      system("color 9F");
      char ch;
      FILE *fp;
      fp = fopen("abbreviations.txt","r");
      ch= fgetc(fp);

      if(fp == NULL)
      {
          printf("\n\t\t\tFile is not present");
          exit(1);
      }

      while(ch != EOF)
      {
          printf("%c", ch);
          ch= fgetc(fp);
      }
      fclose(fp);
      printf("\n\n\n");
      system("pause");
   }



   void display_calculator()
   {
     HANDLE h;
     h = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h, 415);

      char ch;
      FILE *fp;
      fp = fopen("Display_calculator.txt","r");
      ch= fgetc(fp);

      while(ch != EOF)
      {
          printf("%c", ch);
          ch= fgetc(fp);
      }
      fclose(fp);
   }




   void memory1(double numb1, char oper[], double numb2, double res)
   {
       mem[i].num1= numb1;
       strcpy(mem[i].op, oper);
       mem[i].num2= numb2;
       mem[i].result= res;
       i++;
   }




   void memory2(char oper[], double numb1, double res)
   {
       mem[i].num1= numb1;
       strcpy(mem[i].op, oper);
       mem[i].num2= 0;
       mem[i].result= res;
       i++;
   }




   void clear()
   {
       system("cls");
       main();
   }



     void error()
   {
      system("cls");

      HANDLE h;
      h = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(h, 415);

      char ch;
      FILE *fp;

      fp = fopen("Error.txt","r");
      ch= fgetc(fp);

      while(ch != EOF)
      {
          printf("%c", ch);
          ch= fgetc(fp);
      }
      fclose(fp);
      printf("\n");
      system("Error.vbs");


      SetConsoleTextAttribute(h, 003);
      system("pause");

       main();
   }




   double addition(double num1, double num2)
   {
       return (num1+num2);
   }



   double substraction(double num1, double num2)
   {
       return (num1-num2);
   }



   double multiplication(double num1, double num2)
   {
       return (num1*num2);
   }



   double division(double num1, double num2)
   {
       return (num1/num2);
   }



   int modulus(int num1, int num2)
   {
       return (num1%num2);
   }



   double inverse(double num)
   {
       return (1/num);
   }



   int decimal_to_binary(int num)
   {
       int remainder, binary=0, base=1;

       while(num > 0)
       {
          remainder = num%2;
          binary = binary+ (remainder* base);
          num= num/2;
          base= base * 10;
       }

       return binary;
   }



   int decimal_to_octal(int num)
   {
       int remainder, octal=0, base=1;
       while(num > 0)
       {
          remainder = num%8;
          octal = octal+ (remainder* base);
          num= num/8;
          base= base * 10;
       }

       return octal;
   }




   int binary_to_decimal(int num)
   {
      int remainder, decimal=0, base=0;

      while(num > 0)
      {
        remainder = num%10;
        decimal = decimal+ (remainder* pow(2,base));
        num= num/10;
        base++;
      }

       return decimal;
    }




   int octal_to_decimal(int num)
   {
      int remainder, decimal=0, base=0;

      while(num > 0)
      {
        remainder = num%10;
        decimal = decimal+ (remainder* pow(8,base));
        num= num/10;
        base++;
      }

       return decimal;
    }



   int factorial(int num)
   {
       int i, factorial=1;
       if(num < 0)
            error();

       else
       {
           for(i=num; i>=1; i--)
              factorial *= i;
           return factorial;
       }
   }




   double permutation(int n, int r)
   {
        if((n < 0)  || (r < 0))
            error();

        else
        {
             int numerator, denominator;
             numerator= factorial(n);
             denominator= factorial(n-r);
             return (numerator/denominator);
        }
   }



   double combination(int n, int r)
   {
       if((n < 0)  || (r < 0))
            error();

        else
        {
             int numerator, denominator1, denominator2;

             numerator= factorial(n);
             denominator1= factorial(r);
             denominator2= factorial(n-r);

             return (numerator/(denominator1 * denominator2));
        }
   }




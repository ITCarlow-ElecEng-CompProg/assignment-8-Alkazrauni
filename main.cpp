/**  Salman Al kazrauni
*    Exercise 8
*    c00199530
*    Operational Amplifier Circuits */


#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cmath>

using namespace std;

/**< Function declaration */
char menu(void);

void non_inv_Amp(double Vin, double R1, double R2 , double *ptr_Av, double *ptr_Vout);
void inv_Amp (double Vin, double Rin, double Rf, double *ptr_Av, double *ptr_Vout);

void inv_Amp1(void);
void non_inv_Amp1(void);

/**< main function */
int main()
{
    char input;

    /**< do while loop */
    do
    {
        /**< call the menu function to get the input */
        input = menu();

        /**< switch case function */
        switch (input)
        {
            case 'a':
                  system("cls");
                  inv_Amp1();
            break;

            case 'c':
                    system("cls");
                    non_inv_Amp1();
            break;


            case 'q':
                    system("cls");
                    cout <<"Goodbye..."<< endl;
            break;

            default:    cout << "wrong input.."<<endl;
                        break;

        }
    }
    while (input != 'q');

    return 0;

}

char menu(void)
{
    /**< variable declaration */
    char input;

    cout << "Operational Amplifier Circuits..\n\n"<<
    "Inverting Amplifier     'a'\n"<<
    "Non Inverting Amplifier 'b'\n"<<
    "quit program            'q'\n" << endl ;

    cin >> input;

    return input;
}
/**< inverter Amp function */
void inv_Amp1()
{
    /**< variable declaration */
    double Vcc =0 ,Vee =0, Vin=0 ,Rin=0, Rf=0,Av,Vout;
    double *ptr_Av = &Av;
    double *ptr_Vout = &Vout;

    /**< prompt the user to enter the inputs */
    while (Vcc <= 0)
    {
        cout << "Please Enter a value for Vcc: ";
        cin >> Vcc;
    }

      while (Vee <= 0)
    {
        cout << "Please Enter a value for Vee: ";
        cin >> Vee;
    }


      while (Vin <= 0)
    {
        cout << "Please Enter a value for Vin: ";
        cin >> Vin;
    }

    while (Rin <= 0)
    {
        cout << "Please Enter a value for Rin: ";
        cin >> Rin;
    }
    while (Rf <= 0)
    {
        cout << "Please Enter a value for Rf: ";
        cin >> Rf;
    }
    /**< Returns values calculated in the other functions */
    inv_Amp( Vin, Rin, Rf, ptr_Av,ptr_Vout);

    cout << "\nThe Voltage Gain is :" << *ptr_Av << endl;

    /**< using if loop to display the saturation value */
     if(Vout >= Vee || Vout <= Vcc)
    {
        if(Vin <= 0)
        {
            cout << "\nThe Amplifier is in saturation, (Vout) =\t" << Vcc;
        }
        else
        {
            cout << "\nThe Amplifier is in saturation, (Vout) =\t" << Vee;
        }
    }


    return ;
}

/**< inverting Amp function */
void inv_Amp(double Vin, double Rin, double Rf, double *ptr_Av, double *ptr_Vout)

{
    /**< calculating the gain and the Vout */
   *ptr_Av = -Rf/Rin ;
   *ptr_Vout = *ptr_Av * Vin;

}

/**< non inverting Amp function */
void non_inv_Amp1()
{
    /**< variable declaration */
    double Vcc =0 ,Vee =0,Vin=0, R1=0,R2=0,Av,Vout;
    double *ptr_Av = &Av;
    double *ptr_Vout = &Vout;

    /**< prompt the user to enter the inputs */
    while (Vcc <= 0)
    {
        cout << "Please Enter a value for Vcc: ";
        cin >> Vcc;
    }

      while (Vee <= 0)
    {
        cout << "Please Enter a value for Vee: ";
        cin >> Vee;
    }


      while (Vin <= 0)
    {
        cout << "Please Enter a value for Vin: ";
        cin >> Vin;
    }

    while (R1 <= 0)
    {
        cout << "Please Enter a value for R1: ";
        cin >> R1;
    }
      while (R2 <= 0)
    {
        cout << "Please Enter a value for R2: ";
        cin >> R2;
    }

    /**< call the calculation function for the non inverting Amp */
    non_inv_Amp( Vin, R1, R2,ptr_Av,ptr_Vout);

    /**< display the gain  */
	cout << "\nThe Voltage Gain is: \t" << *ptr_Av << endl;

     /**< using the if Loop to display the saturation value */
    if(Vout >= Vee || Vout <= Vcc)

    {
        if(Vin <= 0)
        {
            cout << "\n\nThe Amplifier is in saturation \n\nVout =\t " << Vcc ;
        }
        else
        {
            cout << "\n\nThe Amplifier is in saturation \n\nVout =\t " << Vee ;
        }
    }

    cout << "\nThe Output Voltage is: \t" << *ptr_Vout << endl;

    return ;
}
/**< non inverting Amp for calculation */
void non_inv_Amp(double Vin, double R1, double R2 , double *ptr_Av, double *ptr_Vout)
{
    /**< calculate the gain and the Vout */
   *ptr_Av = 1 + (R2/R1) ;
   *ptr_Vout = *ptr_Av * Vin ;
}





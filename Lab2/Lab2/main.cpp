//
//  main.cpp
//  Lab2
//
//  Created by Mitchell Burr on 9/12/18.
//  Copyright © 2018 Mitchell Burr. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

bool negcheck (double q){
    if ( q >= 0){
        return 1;
    }
    if ( q < 0){
        cout << "please input only positive values" << endl;
        return 0;
    }
    return 1;
}
//reusable func to check for negative value

int ftoc(double T){
    char f ='F';
    double tc=((T-32)/1.8);
    // expression for farenheit to celsius
    char c = 'C';
    cout << T << f << "=" << tc;
    cout << c;
    // display conversion
    return 0;
}
int ctof(double T){
    char c ='C';
    char f = 'F';
    double tf=((T*1.8)+32);
    // expression for celsius to farenheit
    cout << T << c << "=" << tf;
    cout << f;
    // display conversion
    return 0;
}

int relativeL(){
    double L,v,Lr;
    // length, velocity, and relatively length declarations
    double c = (3*pow(10, 10));
    // speed of light declaration and initialization
    
    cout << "input object's length in cm" << endl;
    cin >> L;
    cout << "input object's velocity in cm" << endl;
    cin >> v;
    cout << endl;
    // input of independent variables
    negcheck(L);
    if (v < 0){
        v = abs(v);
    }
    //catch negative case of V
    
    Lr = L*sqrt(1-(pow(v, 2)/pow(c, 2)));
    // expression for relative length
    cout << "relative length is: " << Lr << "cm" << endl;
    // display relative length
    return 0;
}

int BMR(){
    double BMR;
    double CBs;
    char g;
    double w;
    double h;
    int a;
    // declaration of gender, weight in pounds, height in inches, age in years, and BMR
    cout << "what is your gender, M or F?" << endl;
    cin >> g;
    cout << "What is you weight in pounds?" << endl;
    cin >> w;
    cout << "What is your height in inches?" << endl;
    cin >> h;
    cout << "What is you age in years?" << endl;
    cin >> a;
    // initialize variables from user input
    while(negcheck(w) && negcheck(h) && negcheck(a) ){
        if (g == 'F'|| g == 'f'){
            BMR = 66 + (4.3*w)+(4.7*h)-(4.7*a);
            // female expression for BMR
            cout << "your basal metabolic rate is" << BMR << " calories per day." << endl;
            CBs = BMR/230;
            // Candy Bars based on BMR and 230 calorie bar
            cout << "you can consume " << CBs << " per day." << endl;
            return 0;
        }
        if (g == 'M' || g == 'm'){
            BMR = 66 + (6.3*w)+(12.9*h)-(6.8*a);
            // male expression for BMR
            cout << "your basal metabolic rate is" << BMR << " Calories per day." << endl;
            CBs = BMR/230;
            // candy bars based on BMR and 230 calorie bar
            cout << "you can consume " << CBs << " Chocolate bars per day." << endl;
            return 0;
        }
    }
    return 0;
}
int calculator(){
    int FirstInteger;
    int SecondInteger;
    char Operator;
    // intialization of equation variables
    cout << "please input the equation to be calculated in the formation [FirstInteger][Operator][SecondInteger]." << endl;
    cin >> FirstInteger >> Operator >> SecondInteger;
    //input of variables
    int Solution = 0;
    // initialized to 0 for multiplication
    
    if (Operator == '+'){
        Solution = FirstInteger + SecondInteger;
        cout << FirstInteger << Operator << SecondInteger << "=" << Solution << endl;
        return 0;
    }
    // Addition
    
    if (Operator == '-'){
        Solution = FirstInteger - SecondInteger;
        cout << FirstInteger << Operator << SecondInteger << "=" << Solution << endl;
        return 0;
    }
    // subtraction
    
    if (Operator == '*' && SecondInteger > 0){
        for ( int i = 0; i < SecondInteger; i++){
            Solution = Solution + FirstInteger;
        }
    }
    // Negative multiplication
    
    if (Operator == '*' && SecondInteger < 0){
        for ( int i = 0; i > SecondInteger; i--){
            Solution = Solution - FirstInteger;
        }
    }
    // Positive multiplication
    
    if (Operator == '/'){
        int Quotient = FirstInteger/SecondInteger;
        double Remainder = FirstInteger % SecondInteger;
        double Decimal = Remainder / SecondInteger;
        double DSolution = Quotient + Decimal;
        cout << DSolution;
        return 0;
    }
    // Division
    
    cout << FirstInteger << Operator << SecondInteger << "=" << Solution << endl;
    // Solution output for multiplication for loop
    
    return 0;
}
int payrollcalculator(){
    
    double hours, dependants;
    cout << "Please input your hours worked this week and how many dependents you have." << endl;
    cin >> hours >> dependants;
    // Variable Input
    while(negcheck(hours) && negcheck(dependants)){
        double GrossPay;
        if (hours > 40 ){
            GrossPay = (40 *16.78) + ((hours-40)+(16.78*1.5));
        
        }else{
                GrossPay = hours * 16.78;
            }
        double NetPay = GrossPay;
        cout << "Your gross pay is: " << GrossPay << endl;
        //net and gross pay determination
        
        double SocialSecurity = (0.06 * GrossPay);
        cout << "Social Security withheld = " << SocialSecurity << endl;
        NetPay = NetPay - SocialSecurity;
        // social security withdrawal
        
        double FederalIncomeTax = (0.14 * GrossPay);
        cout << "Federal Income Tax withheld = " << FederalIncomeTax << endl;
        NetPay = NetPay - FederalIncomeTax;
        // Federal Income Tax Withdrawal
        
        double StateIncomeTax = (0.05 * GrossPay);
        cout << "State Income Tax withheld = " << StateIncomeTax << endl;
        NetPay = NetPay - StateIncomeTax;
        // State Income Tax Withdrawal
        
        int UnionDues = 10;
        cout << "Union dues withheld = " << UnionDues << endl;
        NetPay = NetPay - UnionDues;
        // Union Dues Withdrawal
        
        
        int HealthCare;
        if (dependants >= 3){
            HealthCare = 35;
            cout << "Healthcare cost withheld = " << HealthCare << endl;
            NetPay = NetPay - HealthCare;
        }
        // HealthCare Withdrawal
        cout << "Your net pay is: " << NetPay << endl;
        return 0;
    }
    return 0;
}

int main() {
    char w = 'y';
    // while loop flip variable
    while (w == 'y'){
        // while loop to allow choice of program
        char pc;
        //pc is program choice variable
        cout << "Would you like to determine relative length (r), chocolate bars consumable to equal basal metabolic rate (b), convert temperature between farenheit and celsius? (t), utilize the integer calculator (c), or utilize the payroll calculator? (p)" << endl;
        cin >> pc;
        //input program choice
        if (pc == 'r'){
            relativeL();
        }
        if (pc == 'b'){
            BMR();
        }
        if (pc == 't'){
            double T;
            char unit;
            cout << "Is the temperature in Farenheit (f) or Celsius (c)?" << endl;
            cin >> unit;
            cout << "What is the temperature?" << endl;
            cin >> T;
            if (unit == 'f'){
                ftoc(T);
            }
            if (unit == 'c'){
                ctof(T);
            }
        }
        if (pc == 'c'){
            calculator();
        }
        
        if (pc == 'p'){
            payrollcalculator();
        }
        cout << "Would you like to choose another program? (y or n)" << endl;
        cin >> w;
    }
    return 0;
    }

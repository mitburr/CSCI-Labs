//
//  main.cpp
//  Lab4
//
//  Created by Mitchell Burr on 10/9/18.
//  Copyright © 2018 Mitchell Burr. All rights reserved.
//
#include <cmath>
#include <iostream>

using namespace std;

int negcheck(double a){
    if (a<=0)cout << "please input a valid number" << endl; return 0;
}

double babylonianRoot( double root){
    double OldGuess = 1;
    double NewGuess = 10;
    while ((abs(NewGuess - OldGuess)/100) > 0.01){
        OldGuess = NewGuess;
        NewGuess = (OldGuess + (root/OldGuess))/2;
        
    }
    return NewGuess;
    
}

bool IsLeapYear(int year){
    negcheck(year);
    if (year%4==0 && (year%100!=0 || (year%400==0))) return 1;
    return 0;
}

int LastDay(int month, int year){
    negcheck(month);
    negcheck(year);
    if ( month == 2 && IsLeapYear(year)) return 29;
    if ( month == 2 && !IsLeapYear(year)) return 28;
    if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
    if ( month == 4 || month == 6 || month == 9 || month == 11) return 30;
    cout << "Please input a valid month" << endl;
    return 0;
}

void NextDay(int month, int day, int year){
    if(day > LastDay(month, year)) return;
    if(month > 12) return;
    if(day == LastDay(month, year) && month == 12) cout << 1 << " " << 1 << " " <<  year + 1 << endl;
    if(day == LastDay(month, year) && month != 12) cout << month + 1 << " " << day + 1 << " " <<  year << endl;
    if(day !=LastDay(month, year)) cout << month << " " << day + 1 << " " <<  year << endl;
}

double Power(double base, int power){
    double temp = base;
    for(int i = power; i > 1; i--)
        temp = temp * base;
    return temp;
}

double AbsVal(double q){
    if (q < 0) q = q*-1;
    return q;
}

double NewtonRaphson(double radicand, int root){
    double NewGuess = 10;
    double OldGuess = 1;
    while ((AbsVal((NewGuess-OldGuess)/100) > 0.01 )){
        OldGuess = NewGuess;
        NewGuess = (((root-1)*OldGuess + (radicand/(Power(OldGuess, root-1))))/root);
    }
    return NewGuess;
}

int main() {
    char RunVariable = 'y';
    while (RunVariable == 'y'){
        char FunctionChoice;
        cout << "Which function would you like to run? 'b' for Babylonian Square Root, 'l' for Leap Year, 'd' for Last Day, 't' for tomorrow's date, or 'n' for Newton-Raphson method of roots." << endl;
        cin >> FunctionChoice;
        
        if ( FunctionChoice == 'b'){
            double root;
            cout << "What would you like to find the root of?" << endl;
            cin >> root;
            negcheck(root);
            cout << babylonianRoot(root) << endl;
        }
        
        if( FunctionChoice == 'l'){
            int year;
            cout << "What year would you like to test for leap year status?" << endl;
            cin >> year;
            if (IsLeapYear(year)) cout << year << " is a leap year." << endl;
                else cout << year << " is not a leap year." << endl;
        }

        if ( FunctionChoice == 'd'){
            int month;
            int year;
            cout << "Which month and year would you like to determine the last day of?" << endl;
            cin >> month;
            cin >> year;
            cout << "There are " << LastDay(month, year) << " days in that month." << endl;
        }
        
        if ( FunctionChoice == 't'){
            int day;
            int month;
            int year;
            cout << "what is today's date? (mm dd yy)" << endl;
            cin >> month >> day >> year;
            cout << "tomorrow's date is: ";
            NextDay(month, day, year);
        }
        
        if( FunctionChoice == 'n'){
            double radicand;
            int root;
            cout << "What radicand and root would you like to computer? (radicand root)" << endl;
            cin >> radicand >> root;
            negcheck(radicand);
            negcheck(root);
            cout << "the root is: " << NewtonRaphson(radicand, root) << endl;
        }
        
        cout << "Would you like to run another function? (y or n)?" << endl;
        cin >> RunVariable;
    }
    return 0;
}

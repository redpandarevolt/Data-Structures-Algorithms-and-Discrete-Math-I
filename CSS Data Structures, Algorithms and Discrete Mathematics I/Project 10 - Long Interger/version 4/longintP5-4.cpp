//
//  longintP5.h
//  longint
//
//  Created by Marcela on 12/1/18.
//  Copyright © 2018 Marcela. All rights reserved.
//
#include <istream>
#include <iostream>
#include <sstream>
#include <deque>
#include "longintP5.h"

using namespace std;

istream & operator >> (istream &in, LongInt &rhs){
    
    //positive number: check char are between 0 and 9, add to rhs
    //istream operator .get() loops retrieving one character at a time
    char num;
    while(in.get(num)){
        if(num != '-' && num > '0' && num < '9'){
            rhs.negative = false; // if character is not '-' set to false
            rhs.digits.addBack(num);
            //add the character to the LongInt
            //rhs.digits.addBack(num - '0');
        }
    
    //negative number: check char between 0 and 9, add to rhs
        if(num == '-' && (num > '0' && num < '9')){
            cout <<" going in 2";
            rhs.negative = true; // if character IS '-' set to false
            rhs.digits.addBack(num);
            //add the character to the LongInt
            //rhs.digits.addBack(num - '0');
        }
    }
    return in;
}
ostream & operator<< (ostream &out, const LongInt &rhs){
    
    Deque<char> tempDigits = rhs.digits;
    if(tempDigits.size() == 0){ // case: rhs is empty
        out << "0";
        return out;
    }
    if(rhs.negative == true)   //case: negative number
        out << "-";
    
    int size = tempDigits.size();
    int i = 0;
    
    for (i = 0; i < size; i++ ){ //otherwise out the rhs string
        char temp2 = tempDigits.removeFront();
        out << temp2;
    }
    return out;
}

// Constructors
LongInt::LongInt(const string str ) {
    negative = false;
    
    //negative number: str[0] becomes '-'
    digits.clear();
    
    for(int i = 0; i < str.size(); i++){
        if(str[0] == '-'){ //fix to only eval once
            //digits.addBack('-');
            negative = true;
        }
        //if(negative == false){
        if (str[i] >= '0' && str[i] <= '9'){
            digits.addBack(str[i]);
        }
        //}
    }
}

LongInt::LongInt( )  {
    digits.clear();
    negative = false;
}
    
LongInt::LongInt(const LongInt &rhs ){
    LongInt right(rhs);
    Deque<char> tempDigits = right.digits;
    for( int i = 0; i < tempDigits.size(); i++){
        char x = tempDigits.removeFront();
        digits.addFront(x);
    }
    digits.clear();
    negative = rhs.negative;
    
    //remove0s();
}
    

// Destructor removes all numbers and destroys the object
LongInt::~LongInt( ) {
    digits.clear();
}

//remove all the zero's from the LontInt Object
void LongInt::remove0s(){
    /*while(digits.getFront() == '0'){
        digits.removeFront();
    }
    if ( digits.isEmpty()){
        digits.addBack('0');
        negative = false;
    }
    return;*/
}

// Arithmetic binary operators

// Work Flow: LongInt >> check +/- flag and size >> put in DQ >> math >> answer
LongInt LongInt::operator+(const LongInt& rhs) const {
    
    LongInt lhs = *this; //access the LongInt for x
    
    LongInt left(lhs);  //make a copy of the lhs object
    LongInt right(rhs); //make a copy of the rhs object
    LongInt answer;
    
    //Evaluate each case of LongInt
    //Check +/- flag on each size to determine call
    
    //positive lhs + negative rhs means do nothing to math calculations
    //positive lhs +  negative rhs means lhs - rhs
    if(left.negative == false && right.negative == true){
        
        right.negative = false;
        answer = left - right;
        
        if(right.digits.size() > left.digits.size()){
            answer.negative = true;
        }
        //answer = left - right;
        return answer;
    }
    
    //negative lhs + positive rhs means ans = rhs - lhs.
    else if(left.negative == true && right.negative == false){
        LongInt tempSwap;
        
        left.negative = false;
        tempSwap = left;
        left = right;
        right = tempSwap;
        
        
        answer = left - right;
        //answer.negative = true;
        if(left.digits.size() < right.digits.size()){
            answer.negative = true;
        }
        return answer;
    }
    
    //negative lhs + negative rhs means ans = -(lhs + rhs)
    else if(left.negative == true && right.negative == true){
        left.negative = false;
        right.negative  =false;
        answer = left + right;
        answer.negative = true;
        return answer;
    }
    
    //move strings into deque in order to access digits
    Deque<char> dq1 = left.digits;
    Deque<char> dq2 = right.digits;
    //Deque<char> addResult;
    
    int x = 0, y = 0;
    //check size
    int max_size = max(dq1.size(), dq2.size());
    int i = 0;
    
    int carry = 0;
    int sum = 0;
    int insertNum = 0;
    
    
    for( i = 0; i < max_size; i++){
        
        //get x and y value for DQ's.
        if(dq1.isEmpty())//if the deque is empty insert zero
            x = 0;
        else
            x = dq1.removeBack() - '0'; // -'0' to get integer
        
        if (dq2.isEmpty())
            y = 0;
        else
            y = dq2.removeBack() - '0';
        
        sum = x + y + carry;
        if(sum < 10){
            insertNum = sum;
            carry = 0;
        }
        else{
            insertNum = sum % 10;
            carry = sum / 10;
        }
        
        answer.digits.addFront(insertNum + '0'); //+'0' to get char
        /// check this is going into a LongInt String
    }
    return answer;
}


// Work Flow: LongInt >> check +/- flag >> put in DQ >> math >> answer >> LongInt
LongInt LongInt::operator-(const LongInt &rhs) const {
    
    LongInt lhs = *this; //access the LongInt for x
    
    LongInt left(lhs);  //make a copy of the lhs object
    LongInt right(rhs); //make a copy of the rhs object
    LongInt answer;
    //work flow >> smaller size to right >> check sign >> do math >> 
    
    //Evaluate each case of LongInt
    //Check +/- flag on each size to determine call
    
    //(+ lhs) - (+ rhs) means ans = lhs - rhs.
    //change the sign of the answer
    /*if(left.negative == false && right.negative == false){
        //check the size and move the larger to the left
        if (right.digits.size() > left.digits.size()){
            LongInt tempSwap;
            
            tempSwap = left;
            left = right;
            right = tempSwap ;
            answer = left - right;
            answer.negative = true;
        }
        
        if(left.digits.size() > right.digits.size()){
            answer = left - right;
            answer.negative = false;
        }
    }*/
    //(+ lhs) - (- rhs) means ans = lhs + rhs. >>>>>>>>>Done
    if(left.negative == false && right.negative == true) {
        
        right.negative = false;
        
        answer = left + right;
        answer.negative = false;
        return answer;
    }
    
    //(-lhs) - (+rhs) means ans = -(lhs + rhs) >>>>>Done
    else if(left.negative == true && right.negative == false){
        left.negative = false;
        answer = left + right;
        answer.negative = true;
        //answer.digits.addFront('-');
        return answer;
    }
    
    //(- lhs) - (- rhs) means ans = rhs - lhs.
    //check the size and move smaller right
    //change the size of the answer.
    else if(left.negative == true && right.negative == true){
        if(right.digits.size() > left.digits.size()){
            answer = right - left;
            answer.negative = false;
            return answer;
        }
        if(left.digits.size() > right.digits.size()){
            answer = left - right;
            answer.negative = true;
            return answer;
        }
        else
             answer = right - left;
        return answer;
    }
    
    //move strings into deque in order to access digits
    Deque<char> dq1 = left.digits;
    Deque<char> dq2 = right.digits;
    
    int x = 0, y = 0;
    
    //check size
    int max_size = max(dq1.size(), dq2.size());
    
    int i = 0;
    int borrow = 0;
    int sum = 0;
    int insertNumber = 0;
    
    for( i = 0; i < max_size; i++){
        if(dq1.isEmpty())
            x = 0;
        else
            x = dq1.removeBack() - '0';
        
        if (dq2.isEmpty())
            y = 0;
        else
            y = dq2.removeBack() - '0';
        
        //check sum
        sum = x - y - borrow;
        borrow = 0;
        
        if(sum >= 0){
            insertNumber = sum;
            borrow = 0;
        }
        else{
            insertNumber = x + 10 - y - borrow;
            borrow = 1;
        }
        answer.digits.addFront(insertNumber + '0');
    }
    return answer;
}

// assignment operators
const LongInt& LongInt::operator=( const LongInt &rhs ){
    
    negative = rhs.negative;
    digits = rhs.digits;
    return *this;
    
}

// Logical binary operators
bool LongInt::operator==( const LongInt & rhs ) const{ //needs help
    if(digits.size() != rhs.digits.size()){
        return false;
    }
    
    LongInt left;
    LongInt right;
    left = *this;
    right = rhs;
    
    for (int i = 0; i <= max(left.digits.size(), right.digits.size()); i++){
        if(!right.digits.isEmpty() && ! left.digits.isEmpty()){
            if(right.digits.removeFront() != left.digits.removeFront()){
                return false;
            }
        }
    }
    return true;
}
bool LongInt::operator!=( const LongInt & rhs ) const{ //ok
    return !(*this == rhs);
}

bool LongInt::operator>( const LongInt & rhs ) const{
    if(digits.size() > rhs.digits.size()){
        return true;
    }
    if(digits.size() < rhs.digits.size()){
        return false;
    }
    
    LongInt left;
    LongInt right;
    LongInt answer;
    left = *this;
    right = rhs;
    answer = left - right;
    if(answer.negative == true){
        return false;
    }
    if(answer.negative == false){
        return true;
    }
    return 0;
}

bool LongInt::operator>=( const LongInt & rhs ) const{ //OK
    return (operator > (rhs) || operator == (rhs));
}

bool LongInt::operator<( const LongInt & rhs ) const { //needs work
    return !(operator > (rhs));
}
    
bool LongInt::operator<=( const LongInt & rhs ) const{ //OK
    return !(operator < (rhs) || operator ==(rhs));
}

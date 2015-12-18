#include <string.h>
#include <stdio.h>


#include <string>
#include <iostream>
#include <sstream>
using namespace std; 

class Solution {
public:
    string parse_one_digit(int i){
        if(i == 0 ) return "zero";
        if(i == 1 ) return "one";
        if(i == 2 ) return "two"; 
        if(i == 3 ) return "three"; 
        if(i == 4 ) return "four" ;
        if(i == 5 ) return "five"; 
        if(i == 6 ) return "six"; 
        if(i == 7 ) return "seven"; 
        if(i == 8 ) return "eight";
        if(i == 9 ) return "nine";  

    }

    string func(int num){
        stringstream ss; 
        if(100<= num && num <= 999 ){
            ss << parse_one_digit(num/100)  << "hunder"; 
        }
        num = num %100;
        if(10<= num && num <= 19 ){
            if(num == 10) ss << "ten";
            else if(num == 11) ss << "eleven";
            else if(num == 12) ss << "twelve";
            else if(num == 13) ss << "thirteen";
            else if(num == 14) ss << "fourteen";
            else if(num == 15) ss << "fifteen";
            else if(num == 16) ss << "sixteen";
            else if(num == 17) ss << "seventeen";
            else if(num == 18) ss << "eighteen";
            else if(num == 19) ss << "nineteen";
        }else if(20<= num && num <= 99){
            if(num/10 == 2) ss<< "twenty" ;
            else if(num/10 == 3) ss<< "thirty" ;
            else if(num/10 == 4) ss<< "forty" ;
            else if(num/10 == 5) ss<< "fifty" ;
            else if(num/10 == 6) ss<< "sixty" ;
            else if(num/10 == 7) ss<< "seventy" ;
            else if(num/10 == 8) ss<< "eighty" ;
            else if(num/10 == 9) ss<< "ninety" ;
           
           if(num % 10) 
                ss<<parse_one_digit(num %10);

        }else{
            if(num % 10)
                ss<<parse_one_digit(num);            
        }

        return ss.str();
    }

    int get_million_part(int number){
        int reg = number /1000000;

        return reg% 1000; 
    }
    int get_thounsand_part(int number){
        int reg = number / 1000;

        return reg % 1000;
    }

    string numberToWords(int num) {
        if(num ==0) return "zero";
        if( 0 < num && num <= 999 ){
            return func(num);

        }else if(1000 <= num &&  num <= 999999){
            //thousand
            string stra = func( num /1000);
            string strb = func(num%1000);
            return stra + " thousand " + strb;

        }else if(1000000 <= num &&  num <= 999999999){
            
            string stra = func( num /1000000)  + " million";
            int thousan_part = num % 1000000 - (num /1000) * 1000; 
            if(thousan_part != 0){
                stra += func(thousan_part / 1000) + " thousand "; 
            }
            int remained = num % 1000;
            if(remained != 0)
                stra += func(thousan_part % 1000);
            return stra; 

        }else {
            //billion
            string stra = func( num /1000000000)  + " billion ";
            int million_part = get_million_part(num); 
            if(million_part != 0){
                stra += func(million_part ) + " million "; 
            }
            int thousand_part = get_thounsand_part(num);
            if(thousand_part != 0){
                stra += func(million_part ) + " thousand ";                
            }
            int hunder_part = num % 1000;
            if(hunder_part != 0)
                stra += func(million_part );

            return stra; 
        }
            
    }
};



int main(int argc, char const *argv[])
{
    /* code */
    Solution s; 
    cout<< s.get_thousand_part(950199999) << endl;
    return 0;
}

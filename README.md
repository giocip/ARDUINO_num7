# C++ ARITHMETIC-LOGIC DECIMAL CLASS LIBRARY WITH ARBITRARY PRECISION CAPABILITY
## _DESCRIPTION AND DOC_

- _**`num7.h`**_ is a C++ high-level (python3 style), lightweight, floating-point computing header file for PRECISION DECIMAL ARITHMETIC.

Easy to use like school math and WITHOUT IEEE754 ISSUES or +0 AND -0 FAILURES, it can be deployed  
for educational school, web e-commerce developing, accounting apps and general math programs included financial ones.  


---

## Installation C++ num7.h header file

### Create a folder on your computer and

- With your favourite editor create num7.h file and copy it along with your c++ project.cpp file in that same folder


- Ok!

---

## HOW TO USE (integer numeric strings (ex. '2.0') MUST BE SUFFIXED WITH .0): 
--- CALCULATOR MODE ---   

	#include "num7.h" 
	using namespace num7; 

	int main() { 
		try { 
			
			/* ADDITION           */ cout << add("2.5", "3.6")      << endl; //Num("6.1")                  
			/* SUBTRACTION        */ cout << sub("2.5", "3.6")      << endl; //Num("-1.1")                 
			/* MULTIPLICATION     */ cout << mul("2.5", "3.6")      << endl; //Num("9.0")                  
			/* DIVISION           */ cout << div("2.5", "3.6")      << endl; //Num("0.6944444444444444444") 
			/* DIVISION REMAINDER */ cout << divmod("11.0", "8.0")  << endl; //Num("3.0")                  
			/* POWER              */ cout << pow("3.14", "8.0")     << endl; //Num("9450.1169810786918656")
			/* SQUARE ROOT        */ cout << sqrt("2.0")            << endl; //Num("1.414213562")          
			/* ROUND 2 DIGITS     */ cout << round(sqrt("2.0"))     << endl; //Num("1.41")    
			/* ROUND 4 DIGITS     */ cout << round("3.141592654", 4)<< endl; //Num("3.1416")      
			/* ABS                */ cout << abs("-5.25")           << endl; //Num("5.25")      
					 cout << "----------------------" << endl; 
			/* M+ */ Num M("0.0"); M.inc("3.0"); M.inc("3.3"); M.inc("3.7"); cout << M << endl; //Num("10.0") 
			/* M- */               M.dec("5.0"); M.dec("3.3"); M.dec("1.5"); cout << M << endl; //Num("0.2") 
			/* MC */ M.clear(); cout << M << endl; //Num("0.0") 
					 cout << "----------------------" << endl; 
					 Num cart[] = { "19.32", "18.37", "15.13" }; int elements = 3; 
			/* SUM   */ cout << sum(cart, elements).format() << endl;          //Num("52.82") 
			/* MEAN  */ cout << mean(cart, elements).round().format() << endl; //Num("17.61") 
			/* MIN   */ cout << min (cart, elements) << endl;                  //Num("15.13") 
			/* MAX   */ cout << max (cart, elements) << endl;                  //Num("19.32") 
			/*MIN MAX*/ Num* result = minmax(cart, elements); 
						cout << result[0] << endl; //Num("15.13") 
						cout << result[1] << endl; //Num("19.32") 
			/* REPL  */ Num a("-3_000_000.0"); cout << format(a) << endl; //"-3,000,000.00" 
						cout << "----------------------" << endl; 
		}
		catch (exception& e) { 
			cout << ": EXCEPTION CAUGHT: " << e.what() << endl; 
		} 
		return 0; 
	} 

## CODING:  

(=) assignment:  

	Num a("3.0"), b("5.0"), c("0.0"); //DECLARATION AND INITIALIZATION
	cout << "a = " << a << "  b = " << b << "  c = " << c << endl; //a = 3.0 b = 5.0 c = 0.0  

(+) adding:  

	Num R = a + b + c; //DECLARATION AND INITIALIZATION
	cout << "R = " << R << endl; //R = 8.0  
	a = "0.1"; b = "0.2"; c = "0.0"; //INITIALIZATION
	R = a + b + c; 
	cout << "R = " << R << endl; //R = 0.3  

(-) subtracting:  

	a = "0.1"; b = "0.2"; c = "0.3"; //INITIALIZATION  
	R = a + b - c; //INITIALIZATION 
	cout << "R = " << R << endl; //R = 0.0 
	a = "-3.99"; b = "-5.20"; c = "+3.01"; //INITIALIZATION 
	R = a - b - c; 
	cout << "R = " << R << endl; //R = -1.8 

(*) multiplying:  

	a = "-3.99"; b = "-5.20"; c = "+3.01"; //INITIALIZATION
	R = a * b * c; //INITIALIZATION 
	cout << "R = " << R << endl; //R = 62.45148

(/) dividing:  

	a = "3.0"; b = "5.7"; 		    //INITIALIZATION
	R = a / b; 			    //INITIALIZATION
	cout << "R = " << R << endl; 	    //R = 0.5263157894736842105
	cout << div(a, b).round() << endl;  //R = 0.52

(% operator, divmod function) int division and floating-point remainder:  

	a = 2564; b = 17;
	Num quotient  = a / b; 					  //DECLARATION AND INITIALIZATION
	Num remainder = a % b; 					 //DECLARATION AND INITIALIZATION
	cout << "Quotient = "  << quotient.get_I() << endl;     //Quotient = 150.0
	cout << "Remainder = " << remainder << endl;           //INTEGER Remainder = 14.0
	a = "3.141592654"; b = 2;
	cout << "Quotient = "  << div(a, b).get_I() << endl; //Quotient = 1.0
	cout << "Remainder = " << divmod(a, b) << endl;     //FLOATING-POINT Remainder = 1.141592654

(sqrt) square root function:  

	a = Num("123_456_789.1234567891");   //INITIALIZATION
	Num root = a.sqrt(); 	            //DECLARATION AND INITIALIZATION 
	cout << "root = " << root << endl; //root = 11111.11106

(^) power operator and pow function:  

	a = "3.14"; b = 2;
	Num power = a.pow(9); 				    //DECLARATION AND INITIALIZATION
	cout << "power = " << power << endl; 		   //power = 29673.367320587092457984
	power = b ^ 32; 				  //INITIALIZATION
	cout << "power = " << power << endl; 		 //power = 4294967296.0
	cout << "power = " << pow(b + 3, 3) << endl;//power = 125.0

logic (<, <=, >, >=, !=, ==) and relational operators (and, or, not).  

(is, is not):  

	a = "3.0", b = "5.0", c = "1.53";  //INITIALIZATION
	cout << a.is_positive() << endl;  //1=true
	cout << !a.is_zero()    << endl; //1=true
	cout << c.is_negative() << endl;//0=false

(< <= > >= != ==)  

	a = "0.0", b = "0.1", c = "-0.2"; 				        //INITIALIZATION
	cout << (a < b) << (a < c) << (b < c)    << endl;      //100 (True  False False) 
	cout << (a <= a) << (a <= c) << (b <= c) << endl;     //100 (True  False False) 
	cout << (a > b) << (a > c) << (b > c)    << endl;    //011 (False True  True) 
	cout << (a >= a) << (a >= c) << (b >= c) << endl;   //111 (True  True  True)
	cout << (c == -2 * b) << (a == c + 2 * b) << (a != a + b + c) << endl; //111 (True  True  True)
	cout << (a && b) << (a || b) << (!a) << endl; 	  //011 (False  True True) 

(+ - unary operators)
  
	a = "-10.0", b = "+10.1"; 							//INITIALIZATION 
	cout << "a = " << a.format() << endl;              //a = -10.00
	cout << "b = " << b.format(2, ',', true) << endl; //b = +10.10

On a given Num variable the following arithmetic methods are available:

    #variable arithmetics  
	Num a = "10.25"; 			   //DECLARATION AND INITIALIZATION
	cout << a << endl; 			  //10.25
	cout << a.inc() << endl; 		 //11.25
	cout << a.dec(2) << endl;		//9.25
	cout << a.dec("4.25") << endl;	       //5.0
	cout << (a = a.mul("5.01")) << endl;  //25.05
	cout << a.mulX10().format() << endl;  //250.50
	cout << a.mulX100().format() << endl; //25,050.00
	cout << a.mulX1000().format() << endl;//25,050,000.00
	cout << a.divX10().format() << endl;  //2,505,000.00
	cout << a.divX100().format() << endl; //25,050.00
	cout << a.divX1000().format() << endl;//25.05
	cout << a.clear() << endl;		 	  //0.0
	cout << "----------------------" << endl;
	
	Num price("59.99"), rate = "22.00";//DECLARATION AND INITIALIZATION
	cout << price << endl;            //59.99
	Num price_industrial = price.spinoff(rate).round(); //DECLARATION AND INITIALIZATION
	cout << price_industrial << endl;                  //49.17
	price = price_industrial.incpct(rate).round();    //INITIALIZATION
	cout << price << endl; //59.99 final price
	cout << price.decpct("17.49").round().format() << endl; //49.50 discounted price

EVEN ODD numbering methods:

	Num a(6), b(3), c = "3.14"; //DECLARATION AND INITIALIZATION
	cout << a << " INTEGER => " << a.is_integer() << "  EVEN => " << a.is_even() << endl; //6.0 INTEGER => 1(true)  EVEN => 1(true)
	cout << b << " INTEGER => " << b.is_integer() << "  ODD  => " << b.is_odd() << endl;  //3.0 INTEGER => 1(true)  ODD  => 1(true)
	cout << c << " FLOAT  => "  << c.is_floating() << endl;  //3.14 FLOAT  => 1(true)
	cout << "----------------------" << endl;

# Advanced logic programming snippet

	double A = -0.3; //double question //DECLARATION AND INITIALIZATION
	A += 0.1; A += 0.1; A += 0.1;
	if (A == 0.0) cout << "double, SUCCESS";
	else cout << "double, FAILURE because " << A << " is not equal " << 0.0 << endl; //double issue
	cout << "----------------------" << endl;
	
	Num a = "-0.3"; //Num question //DECLARATION AND INITIALIZATION
	a += "0.1"; a += "0.1"; a += "0.1";
	if (a == "0.0") cout << "Num, SUCCESS" << endl; //Num solved
	else cout << "Num, FAILURE because " << a << " is not equal " << "0.0" << endl;
	cout << "----------------------" << endl;

LOOP EXAMPLE >>>  

	for (Num i("-1.0"); i != 0; i += "0.1") //-1.0 -0.9 -0.8 -0.7 -0.6 -0.5 -0.4 -0.3 -0.2 -0.1
		cout << i << " ";
	cout << "\n----------------------" << endl;
	
	Num i(0); //DECLARATION AND INITIALIZATION
	while (i < "1.0") {
		i.inc("0.1"); //i += Num("0.1")
		if (i <= "0.5") continue;
		cout << i << " "; //0.6 0.7 0.8 0.9 1.0
	}
	
	cout << endl;
	while (i) {
		i.dec("0.1"); //i -= Num("0.1")
		if (i >= "0.5") continue;
		cout << i << " "; //0.4 0.3 0.2 0.1 0.0
	}
	cout << endl;
	cout << "----------------------" << endl;

ROUNDING AND ACCOUNTING >>>  

	Num p("11.19"), discountRate("7.00"); //DECLARATION AND INITIALIZATION - PRICE -Toslink cable for soundbar  
	cout << "price=" << p;
	Num d = round(p.pct(discountRate));       //DISCOUNT
	Num pd = round(p - d);                   //PRICE DISCOUNTED 7%  
	Num temp = pd;
	Num p_noTAX = round(temp.spinoff(22)); //ITEM COST WITHOUT TAX 22%  
	Num TAX = round(pd - p_noTAX);        //TAX 22% 
	cout << " PAYED=" << pd << " discount=" << d << " COST=" << p_noTAX << " TAX=" << TAX << endl ;
	//price=11.19 PAYED=10.41 discount=0.78 COST=8.53 TAX=1.88
	
OUTPUT LOCALIZATION, FORMATTING AND SQUARENESS >>>

	Num amount = "1_000_000.99"; //DECLARATION AND INITIALIZATION
	cout << "US localization => " << amount.format(2, ',', '+') << endl; //US localization => +1,000,000.99
	cout << "EU localization => " << amount.format(2, '.', '+') << endl; //EU localization => +1.000.000,99
	cout << "----------------------" << endl;
    
# saving calculator 
	
	#include "num7.h"
	#include <iomanip>
	using namespace num7;

		void asset() {
			Num DEPOSIT = "10_000.00", ANNUAL_CONTRIBUTION = "1_000.00", RATE = "7.25", YEARS = 10, ANNUALS[10][4],
				SQUARENESS_1, SQUARENESS_2, SQUARENESS_3;
			for (int i = 0; i < YEARS; i++) {
				ANNUALS[i][0] = i + 1;   //year
				ANNUALS[i][1] = DEPOSIT; //deposit
				ANNUALS[i][2] = (DEPOSIT * RATE).divX100().round();
				ANNUALS[i][3] = ANNUALS[i][1] + ANNUALS[i][2] + ANNUAL_CONTRIBUTION; DEPOSIT = ANNUALS[i][3];

			}
			int width = 12;
			for (int i = 0; i < YEARS; i++) {
				cout << right << setw(5) << ANNUALS[i][0].to_integer();
				cout << setw(width) << ANNUALS[i][1].format(2, '.');
				cout << setw(12) << ANNUALS[i][2].format(2, '.');
				cout << setw(width) << ANNUALS[i][3].format(2, '.') << endl;
			}
			for (int i = 0; i < YEARS; i++) {
				SQUARENESS_1 += ANNUALS[i][1];
				SQUARENESS_2 += ANNUALS[i][2];
				SQUARENESS_3 += ANNUALS[i][3];
			}
			cout << "-------------------------\n";
			cout << right << setw(5) << "";
			cout << setw(width) << SQUARENESS_1.format(2, '.');
			cout << setw(12) << SQUARENESS_2.format(2, '.');
			cout << setw(width) << SQUARENESS_3.format(2, '.');
			Num SQUARENESS = (SQUARENESS_1 + SQUARENESS_2 == SQUARENESS_3 - ANNUAL_CONTRIBUTION * YEARS);

			cout << " => SQUARENESS=" << (SQUARENESS ? "SUCCESS" : "FAILURE") << endl;
		}

	int main() {
		try {
			asset(); //FUNCTION CALL
		}
		catch (exception& e) {
			cout << ": EXCEPTION CAUGHT: " << e.what() << endl;
		}
		return 0;
	} /* Video output:

     1   10.000,00      725,00   11.725,00
     2   11.725,00      850,06   13.575,06
     3   13.575,06      984,19   15.559,25
     4   15.559,25    1.128,05   17.687,30
     5   17.687,30    1.282,33   19.969,63
     6   19.969,63    1.447,80   22.417,43
     7   22.417,43    1.625,26   25.042,69
     8   25.042,69    1.815,60   27.858,29
     9   27.858,29    2.019,73   30.878,02
    10   30.878,02    2.238,66   34.116,68
   ------------------------------------------------------------ 
       194.712,67   14.116,68  218.829,35 => SQUARENESS=SUCCESS	*/ 
	   
ROUNDING TYPES >>>  

        Num r = "2.82", //DECLARATION AND INITIALIZATION
            area = r * r * r.pi,
            temp = area, temp2 = area;
        cout << area << endl;                      //24.9832014216696
        cout << "---- Num floor    rounding ----\n";
        cout << area.round_floor(1) << endl;     //24.9
        cout << "---- Num ceil     rounding ----\n";
        cout << temp.round_ceil(1) << endl;    //25.0
        cout << "---- Num standard rounding ----\n";
        cout << temp2.round(2) << endl;      //24.98

UNSIGNED ARBITRARY PRECISION ARITHMETIC:

	#include "num7.h"
	using namespace num7;

	int main() {
		try {
			/* STRING ADDITION */
			cout << "STRING ADDITION" << endl;
			const char* a = "18446744073709551615.05";
			const char* b = "79557855184810661726.96";
			char* sum = addfs(a, b);
			cout << a << endl;
			cout << b << endl;
			cout << "-----------------------\n";
			cout << sum << endl << endl; free(sum);
			
			/* STRING SUBTRACTION */
			cout << "STRING SUBTRACTION" << endl;
			char* diff = subfs(a, b);
			cout << a << endl;
			cout << b << endl;
			cout << "-----------------------\n";
			cout << diff << endl << endl; free(diff);
			
			/* STRING MULTIPLICATION */
			cout << "STRING MULTIPLICATION" << endl;
			char* mul = mulfs(a, b);
			cout << a << endl;
			cout << b << endl;
			cout << "-----------------------\n";
			cout << mul << endl << endl; free(mul);
			
			/* STRING DIVISION */
			cout << "STRING DIVISION" << endl;
			char* div = divfs(a, b, 80); //80 DECIMAL DIGITS
			cout << a << endl;
			cout << b << endl;
			cout << "-----------------------\n";
			cout << div << endl;
			char* trunc = trunks(div, 5); //TRUNCATION TO 5 DECIMAL DIGITS
			free(div);
			Num result(trunc); free(trunc);
			result.round(4); //ROUNDING TO 4 DECIMAL DIGITS
			cout << result << endl << endl; 

			/* STRING POWER */
			cout << "STRING POWER" << endl;
			i64 e = -3;
			char* power = pwrfs(a, e);
			cout << a << endl;
			cout << e << endl;
			cout << "-----------------------\n";
			cout << power << endl << endl;
			free(power);

		}
		catch (exception& e) {
			cout << ": EXCEPTION CAUGHT: " << e.what() << endl;
		}
		return 0;

	/*Video output:
 
	STRING ADDITION
	18446744073709551615.05
	79557855184810661726.96
	-----------------------
	98004599258520213342.01

	STRING SUBTRACTION
	18446744073709551615.05
	79557855184810661726.96
	-----------------------
       -61111111111101110111.91

	STRING MULTIPLICATION
	18446744073709551615.05
	79557855184810661726.96
	-----------------------
	1467583393647448798475303745564903690126.748

	STRING DIVISION
	18446744073709551615.05
	79557855184810661726.96
	-----------------------
	0.23186577907182494491523079273408950343976398748007645969389844428201825836420705
	0.2319

	STRING POWER
	18446744073709551615.05
	-3
	-----------------------
	0.000000000000000000000000000000000000000000000000000000000159309191113245227727501120158790347743991499315254642414053871413919539657255886403583887813067464357086554400745997412712 */

FLOAT TO NUM CONVERSION LIST >>>

	#include "num7.h"
	using namespace num7;

	int main() {
		try {
			double listing[] = { 5.14, -2.1, 5.0, -2543.99355, -0.02 };
			Num L[5];
			int elements = sizeof(listing) / sizeof(listing[0]);
			cout << "elements=" << elements << endl;
			cout << "----------------------" << endl;
			
			for (int i = 0; i < elements; i++) {
				L[i].from_double(listing[i]).round(5);
			}
			for(Num l : L)
				cout << l << endl;
			
			cout << "----------------------" << endl;
			cout << endl;
		}
		catch (exception& e) {
			cout << ": EXCEPTION CAUGHT: " << e.what() << endl;
		}
		return 0;
	} //OUTPUT:
	/*
	elements=5
	----------------------
	5.14
	-2.1
	5.0
	-2543.99355
	-0.02
	---------------------- */

### FAQ 

Q. I usually try to add 0.1 to 0.2 in C++ with this code:  

	double a = 0.1, b = 0.2;
	cout << (a + b == 0.3) << endl;   //0 => false
and the result is:  

	0 (false)  
	
How instead can it gets exactly 0.3?  
A. Using Num class:  

	Num A = "0.1", B = "0.2";
	cout << (A + B == "0.3") << endl; //1 => true
the result is:

	1 (true)
	
Q. I'll get a warning when i usually type:  
	
	Num n(0.1);    
 
   (6,9): warning C4244: 'argument': conversion from 'double' to 'int', possible loss of data
	
What is wrong?  
A. You must use double quotes or from_double() in-line function:

	Num n("0.1"); 		 //double quotes
	
	Num n2;
	n2.from_double(0.1); //in-line function

Q. I have two double variables in my code:  

	double a = 123456.123, b = -123456789.123456;
	
How can i convert them in Num type with exact decimal digits?  
A. With from_double() and round() in-line functions:

	double a = 123456.123, b = -123456789.123456;
	Num A, B;
	const int MAX_DECIMAL_PRECISION = 6;
	A.from_double(a).round(MAX_DECIMAL_PRECISION); 
	B.from_double(b).round(MAX_DECIMAL_PRECISION); 
	cout << A << endl; // 123456.123
	cout << B << endl; //-123456789.123456

Q. I must enter many integer variables in my code:  

	Num a = "123.0" , b = "456.0", c = "789.0";
	
Can i input them without quotes and suffix .0?  
A. Yes, this way:

	Num a(123), b(456), c(789);  

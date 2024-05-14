# C++ ARITHMETIC-LOGIC DECIMAL CLASS LIBRARY WITH ARBITRARY PRECISION CAPABILITY FOR 32-BIT ARDUINO ARCHITECTURE (UNDER CONSTRUCTION)
## _DESCRIPTION AND DOC_

- _**`num7.h`**_ is a C++ high-level (python3 style), lightweight, floating-point computing header file for ARBITRARY PRECISION DECIMAL ARITHMETIC.

Easy to use like school math and WITHOUT IEEE754 ISSUES AND NUMBER COMPARING FAILURES, it can be deployed  
for educational school, web e-commerce developing, accounting apps and general math programs included financial ones.  


---

## Installation C++ num7.h header file

### Create an Arduino project on your computer and

- With your favourite editor create num7.h file and copy it along with your c++ project.ino file in that same folder


- Ok!

---

## HOW TO USE (integer numeric strings (ex. "2.0") MUST BE SUFFIXED WITH .0): 
--- CALCULATOR MODE ---   

	#include "num7.h" 
	using namespace num7; 

	void setup() { 
		Serial.begin(9600); //open the serial port at 9600 bps
  		delay(1000);       //waits for 1000 millisecond (1 second)

		/* ADDITION           */ add("2.5", "3.6").print("\n"); 	    //6.1                 
		/* SUBTRACTION        */ sub("2.5", "3.6").print("\n"); 	   //-1.1               
		/* MULTIPLICATION     */ mul("2.5", "3.6").print("\n"); 	  //9.0                 
		/* DIVISION           */ div("2.5", "3.6").print("\n"); 	 //0.6944444444444444444
		/* DIVISION REMAINDER */ mod("11.0", "8.0").print("\n");	//3.0                 
		/* POWER              */ pow("3.14", "8.0").print("\n");       //9450.1169810786918656
		/* SQUARE ROOT        */ sqr("2.0").print("\n"); 	      //1.414213562         
		/* ROUND 2 DIGITS     */ round(sqr("2.0")).print("\n");      //1.41  
		/* ROUND 4 DIGITS     */ round("3.141592654", 4).print("\n"); 	    //3.1416
		/* ROUND BANKING      */ round_bank("3.141592654", 7).print("\n"); //3.1415926
		/* ABS                */ Abs("-5.25").print("\n"); 		  //5.25      
		print("----------------------\n"); //---------------------- 
		NUM cart[3] ; cart[0] = "19.32"; cart[1] = "18.37"; cart[2] = "-15.13" ; int elements = 3;
		/* SUM   */ sum(cart, elements).print("\n");           //22.56 
		/* MEAN  */ mean(cart, elements).round().print("\n"); //7.52 
		/* MIN   */ min(cart, elements).print("\n");         //-15.13 
		/* MAX   */ max(cart, elements).print("\n");        //19.32 
		/*MIN MAX*/ NUM* result = minmax(cart, elements);
		result[0].print("\n"); 	//-15.13 
		result[1].print("\n"); //19.32
		/* REPL  */ NUM a("-3_000_000.0"); char* p = format(a); print(p); print("\n"); free(p); //-3,000,000.00 
		print("----------------------\n");  //---------------------- 

	} 

## CODING:  

(=) assignment:  

	NUM a("3.0"), b("5.0"), c("0.0"); //DECLARATION AND INITIALIZATION
	print("a = "); print(a, "  b = "); print(b, "  c = "); print(c, "\n");//a = 3.0 b = 5.0 c = 0.0  

(+) adding:  

	NUM R = a + b + c;                 //DECLARATION AND INITIALIZATION
	print("R = "); print(R, "\n");    //R = 8.0  
	a = "0.1"; b = "0.2"; c = "0.0"; //INITIALIZATION
	R = a + b + c;
	print("R = "); print(R, "\n"); //R = 0.3  

(-) subtracting:  

	a = "0.1"; b = "0.2"; c = "0.3";          //INITIALIZATION  
	R = a + b - c;                           //INITIALIZATION 
	print("R = "); print(R, "\n"); //R = 0.0 
	a = "-3.99"; b = "-5.20"; c = "+3.01"; //INITIALIZATION 
	R = a - b - c; 			      //INITIALIZATION 
	print("R = "); print(R, "\n");       //R = -1.8 

(*) multiplying:  

	a = "-3.99"; b = "-5.20"; c = "+3.01"; //INITIALIZATION
	R = a * b * c;                        //INITIALIZATION 
	print("R = "); print(R, "\n");       //R = 62.45148

(/) dividing:  

	a = "3.0"; b = "5.7"; 		  //INITIALIZATION
	R = a / b; 			//INITIALIZATION
	print("R = "); print(R, "\n"); //R = 0.52631578947368421052631578947368
	print("R = "); print(div(a, b).round()); //R = 0.53

(% operator, divmod function) int division and floating-point remainder:  

	a = 2564; b = 17; 		 //INITIALIZATION 
	NUM quotient((a / b).trunk(0)); //DECLARATION AND INITIALIZATION 
	NUM remainder(a % b); 	       //DECLARATION AND INITIALIZATION 
	print("quotient = ");  quotient.print("\n");  	       //quotient = 150.0 
	print("INTEGER remainder = "); remainder.print("\n"); //remainder = 14.0 
	a = "3.141592654"; b = 2;  			     //INITIALIZATION
	quotient = (a / b).trunk(0); remainder = a % b; 
	print("quotient = ");  quotient.print("\n"); 		     //Quotient = 1.0 
	print("FLOATING-POINT Remainder = "); remainder.print("\n");//FLOATING-POINT Remainder = 1.141592654 

(sqrt) square root function:  

	NUM a("123_456_789.1234567891");     //DECLARATION AND INITIALIZATION 
	NUM root = a.sqrt(); 	            //DECLARATION AND INITIALIZATION 
	print("root = ", a, "\n");	   //root = 11111.111066

(^) power operator and pow function:  

	NUM a("3.14"), b(2);				     //DECLARATION AND INITIALIZATION 
	NUM power = a.pow(9); 				    //DECLARATION AND INITIALIZATION 
	print("power = ", power, "\n"); 		   //power = 29673.367320587092457984 
	power = b ^ 32; 				  //INITIALIZATION 
	print("power = ", power, "\n"); 		 //power = 4294967296.0 
	print("power = ", pow(a, b), "\n");		//power = 9.8596 

logic (<, <=, >, >=, !=, ==) and relational operators (and, or, not).  

(is ...):  

	NUM a("3.0"), b("5.0"), c("1.53");  //DECLARATION AND INITIALIZATION 
	print(a.is_positive(), "\n");      //1=true 
	print(!a.is_zero(), "\n");        //1=true 
	print(c.is_negative(), "\n");    //0=false 

(< <= > >= != ==): 

	NUM a("0.0"), b("0.1"), c("-0.2"); //DECLARATION AND INITIALIZATION 
	print(a < b, " "); print(a < c, " "); print(b < c, "\n");       //1 0 0 (True  False False) 
	print(a <= b, " "); print(a <= c, " "); print(b <= c, "\n");   //1 0 0 (True  False False) 
	print(a > b, " "); print(a > c, " "); print(b > c, "\n");     //0 1 1 (False True  True)
	print(a >= a, " "); print(a >= c, " "); print(b >= c, "\n");			   //1 1 1 (True  True  True)
	print(c == -2 * b, " "); print(a == c + 2 * b, " "); print(a != a + b + c, "\n"); //1 1 1 (True  True  True)
	print(a && b, " "); print(a || b, " "); print(!a, "\n");			 //011 (False  True True) 

(+ - unary operators):
  
	NUM a, b; //DECLARATION 
	a = "-10.0", b = "+10.1"; //INITIALIZATION  
	char* p = a.format(); 
	print("a = ", p); free(p);              
	p = b.format(2, ',', true); //a = -10.00  b = +10.10 
	print("  b = ", p, "\n");  free(p); 

On a given NUM variable the following arithmetic methods are available.

variable arithmetic:

	NUM a = "10.25"; 		      //DECLARATION AND INITIALIZATION
	print(a, "\n"); 		     //10.25
	print(a.inc(1), "\n"); 		    //11.25
	print(a.dec(2), "\n");		   //9.25
	print(a.dec("4.25"), "\n");	  //5.0
	print(a, "\n");			 //5.0
	print(a = a.mul("5.01"), "\n"); //25.05
	print(a, "\n");		       //25.05
	print(a.clear(), "\n");	      //0.0
	print("----------------------"); //----------------------
	
	NUM price("59.99"), rate = "22.00";                   //DECLARATION AND INITIALIZATION
	print(price, "\n");                                  //59.99
	NUM price_industrial = price.spinoff(rate).round(); //DECLARATION AND INITIALIZATION
	print(price_industrial, "\n");                     //49.17
	price = price_industrial.spinon(rate).round();    //INITIALIZATION
	print(price, "\n");                              //59.99 final price
	char* p = (price - price.pct("17.49").round()) .format();
	print(p, "\n"); free(p); 		       //49.50 discounted price

EVEN ODD numbering methods:

	NUM a(6), b(3), c("3.14"); //DECLARATION AND INITIALIZATION
	print(a, " INTEGER => "); print(a.is_integer(), "  EVEN => "); print(a.is_even(), "\n"); //6.0 INTEGER => 1(true)  EVEN => 1(true)
	print(b, " INTEGER => "); print(a.is_integer(), "  ODD => "); print(b.is_odd(), "\n");  //3.0 INTEGER => 1(true)  ODD  => 1(true)
	print(c, " FLOAT => "); print(c.is_floating(), "\n");				       //3.14 FLOAT  => 1(true)

# Advanced logic programming snippets:

	double A = -0.3; //double question //DECLARATION AND INITIALIZATION 
	A += 0.1; A += 0.1; A += 0.1; 
	if (A == 0.0) print("double, SUCCESS"); 
	else print("double, FAILURE because ", String(A).c_str(), " is not equal 0.0\n"); //double issue 
	print("----------------------\n"); 
	
	NUM a("-0.3"); //NUM question //DECLARATION AND INITIALIZATION 
	a += "0.1"; a += "0.1"; a += "0.1"; 
	if (a == "0.0") print("NUM, SUCCESS", "\n"); //NUM solved 
	else print("NUM, FAILURE because ", a, " is not equal 0.0\n"); 
	print("----------------------\n"); 
	
	/* VIDEO OUTPUT: 
		double, FAILURE because 0.00 is not equal 0.0 
		---------------------- 
		NUM, SUCCESS 
		---------------------- */ 

LOOP EXAMPLE:

	for (NUM i("-1.0"); i != 0; i += "0.1") //-1.0 -0.9 -0.8 -0.7 -0.6 -0.5 -0.4 -0.3 -0.2 -0.1 
		print(i, " "); 
	print("\n----------------------\n"); 
	
	NUM i(0); //DECLARATION AND INITIALIZATION 
	while (i < "1.0") { 
		i.inc("0.1"); //i += NUM("0.1") 
		if (i <= "0.5") continue; 
		print(i, " "); //0.6 0.7 0.8 0.9 1.0 
	} 
	print("\n----------------------\n"); 

	while (i) { 
		i.dec("0.1"); //i -= NUM("0.1") 
		if (i >= "0.5") continue; 
		print(i, " "); //0.4 0.3 0.2 0.1 0.0 
	} 
	print("\n----------------------\n"); 

ROUNDING AND ACCOUNTING:

	NUM p("11.19"), discountRate("7.00"); //DECLARATION AND INITIALIZATION - PRICE -Toslink cable for soundbar  
	print("price=", p); 
	NUM d = round(p.pct(discountRate));       //DISCOUNT 
	NUM pd = round(p - d);                   //PRICE DISCOUNTED 7%  
	NUM temp = pd; 
	NUM p_noTAX = round(temp.spinoff(22)); //ITEM COST WITHOUT TAX 22%  
	NUM TAX = round(pd - p_noTAX);        //TAX 22% 
	print(" PAYED=", pd, " discount="); print(d, " COST="); print(p_noTAX, " TAX="); print(TAX, "\n"); 
	//price=11.19 PAYED=10.41 discount=0.78 COST=8.53 TAX=1.88 
	
OUTPUT LOCALIZATION, FORMATTING AND SQUARENESS:

	NUM amount ("1_000_000.9"); //DECLARATION AND INITIALIZATION
	int SIGN = true;
	int decs = 2;
	char* p = amount.format(decs, ',', SIGN);
	print("US localization => ", p, "\n"); free(p); //US localization => +1,000,000.90
	p = amount.format(decs, ',', SIGN);
	print("EU localization => ", p, "\n"); free(p); //EU localization => +1.000.000,90
    
# Saving calculator: 
	
	#include "num7.h"
	using namespace num7;

	void asset() {
		NUM DEPOSIT ("10_000.00") , ANNUAL_CONTRIBUTION("1_000.00")  , RATE("7.25") , YEARS(10)  , ANNUALS[10][4], 
			SQUARENESS_1, SQUARENESS_2, SQUARENESS_3; 
		for (int i = 0; i < YEARS; i++) { 
			ANNUALS[i][0] = i + 1;   //year 
			ANNUALS[i][1] = DEPOSIT; //deposit 
			ANNUALS[i][2] = ((DEPOSIT * RATE) / 100).round(); 
			ANNUALS[i][3] = ANNUALS[i][1] + ANNUALS[i][2] + ANNUAL_CONTRIBUTION; DEPOSIT = ANNUALS[i][3]; 
		} 
		int width = 12; 
		for (int i = 0; i < YEARS; i++) { 
			print(ANNUALS[i][0].to_i32(), "\t"); 
			char* p = ANNUALS[i][1].format(2, '.'); 
			print(p, "\t"); free(p); 
			char* p2 = ANNUALS[i][2].format(2, '.'); 
			if (strlen(p2) < 8) print("  "); 
			print(p2, "\t"); free(p2); 
			char* p3 = ANNUALS[i][3].format(2, '.'); 
			print(p3, "\n"); free(p3); 
		} 
		for (int i = 0; i < YEARS; i++) { 
			SQUARENESS_1 += ANNUALS[i][1]; 
			SQUARENESS_2 += ANNUALS[i][2]; 
			SQUARENESS_3 += ANNUALS[i][3]; 
		}
		print("--------------------------------------------------\n"); 
		print("       "); 
		char* p = SQUARENESS_1.format(2, '.'); 
		print(p, "      "); free(p); 
		char* p2 = SQUARENESS_2.format(2, '.'); 
		print(p2, "       "); free(p2); 
		char* p3 = SQUARENESS_3.format(2, '.'); 
		print(p3, " "); free(p3); 
		NUM SQUARENESS ((SQUARENESS_1 + SQUARENESS_2 == SQUARENESS_3 - ANNUAL_CONTRIBUTION * YEARS)); 
		print(" => SQUARENESS=", (SQUARENESS ? "SUCCESS" : "FAILURE"), "\n"); 
	} 
	
	void setup() { 
		Serial.begin(9600); //open the serial port at 9600 bps
  		delay(1000);       //waits for 1000 millisecond (1 second)

		asset(); //FUNCTION CALL 
	} 
	
	/* Video output: 

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

	   
ROUNDING TYPES:

	NUM r("2.82"), //DECLARATION AND INITIALIZATION 
		area(r * r * pi()), 
		temp(area), temp2(area); 
	print(area, "\n");                      //24.9832014216696 
	print("---- NUM floor    rounding ----\n"); 
	print(area.round_floor(1), "\n");     //24.9 
	print("---- NUM ceil     rounding ----\n"); 
	print(temp.round_ceil(1), "\n");    //25.0 
	print("---- NUM standard rounding ----\n"); 
	print(temp2.round(2), "\n");      //24.98 

UNSIGNED ARBITRARY PRECISION ARITHMETIC:

	NUM a("18446744073709551615.05"), b("79557855184810661726.96"); //DECLARATION AND INITIALIZATION 
	a.print(" "); b.print(" operands\n");
	add(a, b).print(" sum\n");     //98004599258520213342.01 sum
	sub(a, b).print(" dif\n");    //-61111111111101110111.91 dif
	mul(a, b).print(" pro\n");   //1467583393647448798475303745564903690126.748 pro
	div(a, b).print(" quo\n");  //0.2318657790718249449152307927340895034397 quo
	mod(a, b).print(" rem\n"); //18446744073709551615.05 rem
	print("-----------------------------------------\n");
	a = 3; b = 100; //INITIALIZATION 
	a.print(" "); b.print(" operands\n");
	pow(a, b).print(" exp\n"); //515377520732011331036461129765621272702107522001.0 exp

double TO NUM CONVERSION ARRAY:

	double listing[] = { 5.14, -2.1, 5.0, -2543.99355, -0.02 }; 
	NUM L[5]; 
	int elements = sizeof(listing) / sizeof(listing[0]); 
	print("elements="); print(elements, "\n"); 
	print("----------------------\n"); 

	for (int i = 0; i < elements; i++)  
		L[i] = L[i].from_double(listing[i]).round(5); //RECTIFIED BINARY APPROXIMATION! 
	for (NUM l : L) print(l, "\n"); 
	print("----------------------\n\n"); 

### FAQ 

Q. I usually try to add 0.1 to 0.2 in C++ with this code:  

	double a = 0.1, b = 0.2;
	Serial.println(a + b == 0.3);   //0 => false
and the result is:  

	0 (false)  
	
How instead can it gets exactly 0.3?  
A. Using NUM class:  

	NUM A("0.1"), B("0.2");
	print(A + B == "0.3", "\n"); //1 => true
the result is:

	1 (true)
	
Q. I have two double variables in my code:  

	double a = 123456.123, b = -123456789.123456;
	
How can i convert them in NUM type with exact decimal digits?  
A. With from_double() and round() in-line functions:

	double a = 123456.123, b = -123456789.123456; 
	NUM A, B; 
	const int MAX_DECIMAL_PRECISION = 6; 
	A = A.from_double(a).round(MAX_DECIMAL_PRECISION);  
	B = B.from_double(b).round(MAX_DECIMAL_PRECISION);  
	A.print("\n"); // 123456.123 
	B.print("\n"); //-123456789.123456 

Q. I must enter many integer variables in my code:  

	NUM a("123.0") , b("456.0"), c("789.0"); 
	
Can i input them without double quotes and suffix .0?  
A. Yes, this the way:

	NUM a(123), b(456), c(789);  

#include <num7.h> 
using namespace num7; 

void setup() { 
	Serial.begin(9600); //open the serial port at 9600 bps
	delay(2500);       //waits for 2500 milliseconds (2.5 seconds)

	/* ADDITION           */ add("2.5", "3.6").print(" = 2.5 + 3.6 (ADDITION)\n"); 	           //6.1                 
	/* SUBTRACTION        */ sub("2.5", "3.6").print(" = 2.5 - 3.6 (SUBTRACTION)\n"); 	  //-1.1               
	/* MULTIPLICATION     */ mul("2.5", "3.6").print(" = 2.5 * 3.6 (MULTIPLICATION)\n"); 	 //9.0                 
	/* DIVISION           */ div("2.5", "3.6").print(" = 2.5 / 3.6 (DIVISION)\n"); 	        //0.6944444444444444444
	/* DIVISION REMAINDER */ mod("11.0", "8.0").print(" = 11 % 8 (DIVISION REMAINDER)\n"); //3.0                 
	/* INV                */ inv("3.0").print(" = 1 / 3 (INV)\n");  //0.33333333333333333333333333333333                
	/* x2                 */ x2("3.0").print(" = 3 ^ 2 (x2)\n");   //9.0
	/* x3                 */ x3("3.0").print(" = 3 ^ 3 (x3)\n");  //27.0
	/* POWER              */ xy("3.14", "8.0").print(" = 3.14 ^ 8 (POWER)\n");  //9450.1169810786918656
	/* POWER OF TEN       */ _10y(6).print(" = 10^6 (TEN POWER)\n");           //1000000.0
	/* POWER OF TWO       */ _2y(5).print(" = 2^5 (TWO POWER)\n");            //32.0
	/* POWER OF e         */ _ey(5).round(29).print(" = e^5 (e POWER)\n");   //148.41315910257660342111558004056
	/* FACTORIAL          */ NUM P(fact(5)); P.print(" = 5! (FACTORIAL)\n"); //120
	/* BINARY             */ NUM n1("257.0"); char* ram1 = n1.to_bin(1); print(ram1, " = 257 (BINARY)     \n"); free(ram1); //100000001 = 257 (BINARY)
	/* HEXADECIMAL        */ NUM n2("257.0"); char* ram2 = n2.to_bin(0); print(ram2, " = 257 (HEXADECIMAL)\n"); free(ram2);//101 = 257 (HEXADECIMAL)
	/* SQUARE ROOT        */ sqr("2.0").print(" (SQUARE ROOT OF 2)\n"); 	   				//1.414213562         
	/* ROUND 2 DIGITS     */ round(sqr("2.0")).print(" = SQUARE ROOT OF 2 (ROUND 2 DIGITS)\n");            //1.41  
	/* ROUND 4 DIGITS     */ round(pi(), 4).print(" =~ 3.141592654 (ROUND 4 DIGITS)\n"); 	              //3.1416
	/* ROUND BANKING      */ round_bank(pi(), 7).print(" =~ 3.141592654 (ROUND BANKING 7 DIGITS)\n");    //3.1415926
	/* ABS                */ Abs("-5.25").print(" (ABSOLUTE VALUE OF -5.25)\n"); 		            //5.25 
	/* EXP                */ NUM n3("314.0e-2"); n3.print(" = 314.0e-2 (EXP)\n");                      //3.14 = 314.0e-2 (EXP)
	/* SCIENTIFIC         */ NUM n4("314.0e-2"); into_exp(n4).print(" = 3.14e0 (SCI)\n");              //3.14 = 3.14e0 (SCI)
	/* pi                 */ pi().print(" (pi)\n"); 						  //3.1415926535897932384626433832795
	/* e                  */ e().print(" (e)\n");  							 //2.7182818284590452353602874713527
	/* 10 TIME VALUE      */ _10x("5.25").print(" (10 TIME VALUE OF 5.25)\n");                      //52.5
	/* 100 TIME VALUE     */ _100x("5.25").print(" (100 TIME VALUE OF 5.25)\n");                   //525.0
	/* 1000 TIME VALUE    */ _1000x("5.25").print(" (1000 TIME VALUE OF 5.25)\n");                //5250.0
	/* DIVIDE FOR 10      */ _10div("5.25").print(" (DIVISION FOR TEN OF 5.25)\n");              //0.525
	/* DIVIDE FOR 100     */ _100div("5.25").print(" (DIVISION FOR HUNDRED OF 5.25)\n");        //0.0525
	/* DIVIDE FOR 1000    */ _1000div("5.25").print(" (DIVISION FOR THOUSAND OF 5.25)\n");     //0.00525
	/* PERCENTAGE         */ pct("3.725", "150.00").round(2).print(" = 3.725% OF 150 (PERCENTAGE)\n");        //3.73
	/* PERTHOUSAND        */ pth("2.00", "20_000.00").round(2).print(" = 2PTH OF 20000 (PERTHOUSAND)\n");    //40.0
	/* SPIN-OFF           */ spinoff("22.00", "1_299.00").round(2).print(" = (-22%) 1299 (SPIN-OFF)\n"); 	//1064.75
	/* SPIN-ON            */ spinon("22.00", "1_064.75").round(2).print(" = +22% OF 1064.75 (SPIN-ON)\n"); //1299.0
	print("----------------------\n"); 								      //---------------------- 
	int elements = 5; NUM cart[elements] ; 				  			  	     //19.31999 19.32 18.37 -15.13 -15.12 => ELEMENTS
	cart[0] = "19.31999"; cart[1] = "19.32" ; cart[2] = "18.37"; cart[3] = "-15.13" ; cart[4] = "-15.12" ; //
	for (elements = 0 ; elements < 5; elements++) print(cart[elements], " "); print("=> ELEMENTS\n");     //
	/* SUM   */ sum(cart, elements).print(" => SUM\n");            //26.75999 
	/* MEAN  */ mean(cart, elements).round().print(" => MEAN\n"); //5.35
	/* MIN   */ min(cart, elements).print(" => MIN\n");          //-15.13 
	/* MAX   */ max(cart, elements).print(" => MAX\n");         //19.32 
	/*MIN MAX*/ NUM* result = minmax(cart, elements);          //
	result[0].print(" => MIN, "); 	                          //-15.13 => MIN and 
	result[1].print(" => MAX\n");                            //19.32 => MAX 
	/* FORMAT  */ NUM a("-3_000_000.0"); char* ram4 = format(a); print(ram4); print(" => FORMATTING\n"); free(ram4); //-3,000,000.00 => FORMATTING
	print("----------------------\n");  //---------------------- 
} 

void loop() { }   


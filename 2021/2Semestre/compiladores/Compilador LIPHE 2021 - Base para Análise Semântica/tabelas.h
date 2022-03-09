#include "includes.h"

// i = n�o terminal ; j = terminais
int TabParsing[38][58]={{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,2,2,2,2,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,5,0,0,0,0,0,0,6,5,0,0,0,0,0},
						{0,3,7,7,7,7,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,8,9,9,9,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,10,10,10,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,12,13,13,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,14,14,0,0,0,0,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,16,18,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,19,21,0,0,0,0,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,23,0,0,22,0,0,0,0,0,0,0,22,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,24,0,0,0,0,0},
						{0,0,0,0,0,26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,27,0,0,0,0,27,27,0,27,27,27,27,27,27,27,27,0,0,0,27,0,27,0,27,0,27,27,0,0,27,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,27,0,0,0,0,27},
						{0,0,0,0,0,0,29,0,0,0,0,0,0,0,29,29,0,29,29,29,0,0,0,0,0,0,0,0,0,0,0,29,29,0,0,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,28,0,0,0,0,29},
						{0,0,0,0,0,0,31,0,0,0,0,31,31,0,31,31,31,31,31,31,31,31,0,0,0,30,0,31,0,31,0,31,31,0,0,31,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,31,0,0,0,0,31},
						{0,0,0,0,0,0,35,0,0,0,0,0,0,0,35,35,0,35,35,35,0,0,0,0,0,0,0,0,0,0,0,35,35,0,0,35,0,0,0,0,34,0,33,32,0,0,0,0,0,0,0,35,0,0,0,0,35},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,37,0,0,0,0,0,0,0,0,36,0,0,0,0,0,0},
						{0,0,0,0,0,0,38,0,0,0,0,39,40,0,38,38,41,38,38,38,42,43,0,0,0,0,0,44,0,45,0,38,38,0,0,38,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,38,0,0,0,0,38},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,47,46,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,48,49,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,50,51,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,53,53,53,0,0,0,0,0,0,0,0,0,53,53,0,0,53,0,0,0,0,0,0,0,0,0,0,0,0,0,52,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,54,0,0,0,0,0,0,0,0,55,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,56,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,59,59,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,60},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,62,61,61,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,57,0,58,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,65,65,65,0,0,0,0,0,0,0,0,0,65,65,0,0,65,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,66,0,0,0,0,0,0,66,66,66,0,66,66,66,0,0,0,0,0,0,0,0,66,0,66,66,66,66,66,66,0,0,0,0,0,66,0,0,67,69,70,68,71,72,66,66,0,0,0,0,66},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,75,75,75,0,0,0,0,0,0,0,0,0,73,74,0,0,75,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,79,0,0,0,0,0,0,79,79,79,0,79,79,79,0,0,78,0,0,0,0,0,79,0,79,79,79,79,79,79,76,77,0,0,0,79,0,0,79,79,79,79,79,79,79,79,0,0,0,0,79},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,80,80,80,0,0,0,0,0,0,0,0,0,0,0,0,0,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,81,0,0,0,0,0,0,81,81,81,0,81,81,81,0,0,81,84,0,0,0,0,81,0,81,81,81,81,81,81,81,81,82,83,0,81,0,0,81,81,81,81,81,81,81,81,0,0,0,0,81},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,87,88,85,0,0,0,0,0,0,0,0,0,0,0,0,0,86,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,89,0,0,0,0,0,0,89,89,89,0,89,89,89,0,0,89,89,0,0,0,0,89,0,89,89,89,89,89,89,89,89,89,89,90,89,0,0,89,89,89,89,89,89,89,89,0,0,0,0,89}};


int Producoes[312] = {  /*01*/ 101,54,61,52,100,26,1,
						/*02*/ 73,70,102,67,65,64,
						/*03*/ 52,62,103,2,
						/*04*/ 63,104,26,
						/*05*/ 58,
						/*06*/ 63,104,26,51,
						/*07*/ 58,
						/*08*/ 66,52,106,27,45,105,26,3,
						/*09*/ 58,
						/*10*/ 58,
						/*11*/ 66,52,106,27,45,105,26,
						/*12*/ 68,52,69,44,62,107,4,
						/*13*/ 58,
						/*14*/ 58,
						/*15*/ 68,52,69,44,62,
						/*16*/ 108,8,
						/*17*/ 109,10,
						/*18*/ 111,42,62,41,110,9,
						/*19*/ 70,115,52,61,114,52,71,112,26,5,
						/*20*/ 70,52,61,52,69,44,71,26,11,
						/*21*/ 58,
						/*22*/ 58,
						/*23*/ 42,72,69,44,62,116,41,
						/*24*/ 72,69,44,62,116,52,
						/*25*/ 58,
						/*26*/ 113,26,7,74,6,
						/*27*/ 75,76,
						/*28*/ 75,76,52,
						/*29*/ 58,
						/*30*/ 77,117,26,
						/*31*/ 79,
						/*32*/ 76,118,44,
						/*33*/ 120,90,119,43,
						/*34*/ 122,42,78,123,90,121,41,
						/*35*/ 122,121,
						/*36*/ 78,123,90,51,
						/*37*/ 58,
						/*38*/ 58,
						/*39*/ 124,26,12,
						/*40*/ 16,126,80,74,14,125,90,13,
						/*41*/ 129,18,74,81,74,128,17,
						/*42*/ 42,62,41,138,21,
						/*43*/ 42,84,83,41,22,
						/*44*/ 36,137,74,35,136,82,134,90,29,133,90,43,132,26,28,
						/*45*/ 33,162,88,85,31,90,141,30,
						/*46*/ 58,
						/*47*/ 74,15,127,
						/*48*/ 52,130,90,19,
						/*49*/ 52,131,90,20,
						/*50*/ 135,90,34,
						/*51*/ 58,
						/*52*/ 139,55,
						/*53*/ 140,90,
						/*54*/ 58,
						/*55*/ 84,83,51,
						/*56*/ 86,74,53,143,89,27,
						/*57*/ 89,27,142,51,
						/*58*/ 58,
						/*59*/ 58,
						/*60*/ 87,57,
						/*61*/ 58,
						/*62*/ 85,31,160,
						/*63*/ 74,53,32,161,
						/*64*/ 58,
						/*65*/ 91,92,
						/*66*/ 58,
						/*67*/ 144,92,45,
						/*68*/ 145,92,48,
						/*69*/ 146,92,46,
						/*70*/ 147,92,47,
						/*71*/ 148,92,49,
						/*72*/ 149,92,50,
						/*73*/ 93,94,37,
						/*74*/ 93,150,94,38,
						/*75*/ 93,94,
						/*76*/ 93,151,94,37,
						/*77*/ 93,152,94,38,
						/*78*/ 93,153,94,23,
						/*79*/ 58,
						/*80*/ 95,96,
						/*81*/ 58,
						/*82*/ 95,154,96,39,
						/*83*/ 95,155,96,40,
						/*84*/ 95,156,96,24,
						/*85*/ 157,27,
						/*86*/ 42,90,41,
						/*87*/ 158,96,25,
						/*88*/ 97,159,26,
						/*89*/ 58,
						/*90*/ 42,78,90,41};
						
int IndiceProd [92] = {1,8,14,18,21,22,26,27,35,36,37,44,51,52,53,58,60,62,68,78,87,88,89,96,
					      102,103,108,110,113,114,117,118,121,125,132,134,138,139,140,143,151,
					      158,163,168,183,191,192,195,199,203,206,207,209,211,212,215,221,225,
					      226,227,229,230,233,237,238,240,241,244,247,250,253,256,259,262,266,
					      268,272,276,280,281,283,284,288,292,296,298,301,304,307,308,312};
					      
string NomesTerminais[58] = {"PROGRAM","LABEL","CONST","VAR","PROCEDURE","BEGIN","END","INTEGER",
								"ENUM","BOOLEAN","FUNCTION","GOTO","IF","THEN","ELSE","ENDIF","REPEAT",
								"AGAIN","WHILE","UNTIL","READ","WRITE","OR","AND","NOT","IDENTIFICADOR",
								"INTEIRO","FOR","TO","SELECT","WHEN","OTHERS","ENDSELECT","BY","DO",
								"ENDFOR","+","-","*","/","(",")",":=",":","=",">",">=","<","<=","<>",
								",",";","=>",".","LITERAL","$","|"};

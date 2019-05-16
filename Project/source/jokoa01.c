/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		//nds-rako garatuta dagoen liburutegia
#include <stdio.h>		//c-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		//c-ko liburutegi estandarra memoria erreserbak eta zenbaki konbertsioak egiteko
#include <unistd.h>		//Sistema eragileen arteko konpatibilitatea ziurtatzeko liburutegia

//Geuk garatutako fitxategiak
	
#include "definizioak.h"
#include "periferikoak.h"
#include "zerbitzuErrutinak.h"
#include "fondoak.h"

int denb;
int status = 0; //0 jokalariak, 1 zailtasuna, 2 jokoa, 3 mark, 4 cheats
int tekla=0;
int jkop = 1; //jokalari kopurua
int zailt = 1; //1 erraza, 2 normala, 3 zaila	

int jokalariak () {	

		erakutsijokalariak();
		
		iprintf("\x1b[5;5HAukeratu jakalari kopurua");	//Fix Height
		delay(50);
		touchRead(&PANT_DAT);
        iprintf("\x1b[7;5Hx = %d",PANT_DAT.px);
        iprintf("\x1b[8;5Hy = %d",PANT_DAT.py);
		//1 jokalari
		if((PANT_DAT.px >= 18 && PANT_DAT.px <= 110) && (PANT_DAT.py >= 108 && PANT_DAT.py <= 129)){
			jokoa01(1); // Zailtasun egoera
			return jkop=1;
		}

		//2 jokalari
		if((PANT_DAT.px >= 143 && PANT_DAT.px <= 235) && (PANT_DAT.py >= 108 && PANT_DAT.py <= 129)){
			jokoa01(1); // Zailtasun egoera
			return jkop=2;
		}
			
		//3 jokalari
		if((PANT_DAT.px >= 18 && PANT_DAT.px <= 110) && (PANT_DAT.py >= 150 && PANT_DAT.py <= 190)){
			jokoa01(1); // Zailtasun egoera
			return jkop=3;
		}
			
		//4 jokalari
		if((PANT_DAT.px >= 143 && PANT_DAT.px <= 235) && (PANT_DAT.py >= 150 && PANT_DAT.py <= 190)){
			jokoa01(1); // Zailtasun egoera
			return jkop=4;
		}
	
}


int zailtasuna () {
		delay(80);
		erakutsizailtasuna();
		PANT_DAT.px = 0;
		PANT_DAT.py = 0;

		iprintf("\x1b[23;5HAukeratu zailtasuna"); //Fix Height
		
		while (PANT_DAT.px == 0 && PANT_DAT.py == 0){
			touchRead(&PANT_DAT);
		}
			
			
		//Erraza
		if((PANT_DAT.px >= 47 && PANT_DAT.px <= 209) && (PANT_DAT.py >= 90 && PANT_DAT.py <= 111)){
			jokoa01(2); // Jokoa egoera			
			return 1;			
		}

		//Normala
		if((PANT_DAT.px >= 47 && PANT_DAT.px <= 209) && (PANT_DAT.py >= 124 && PANT_DAT.py <= 145)){
			jokoa01(2); // Jokoa egoera
			return 2;		
		}
			
		//Zaila
		if((PANT_DAT.px >= 47 && PANT_DAT.px <= 209) && (PANT_DAT.py >= 158 && PANT_DAT.py <= 179)){
			jokoa01(2); // Jokoa egoera			
			return 3;
			
		}
	}

void jokoa1players () {
		int pushA = 1;
	
		//J1
		int j1 = 0; //finished(1) or not(0)
		int j1x = 5; //x pos of j1
		static int j1y = 40; //y pos of j1

		//J2
		int j2 = 0; //finished(1) or not(0)
		int j2x = 5; //x pos of j2
		static int j2y = 68; //y pos of j2

		//J3
		int j3 = 0; //finished(1) or not(0)
		int j3x = 5; //x pos of j3
		static int j3y = 96; //y pos of j3

		//J4
		int j4 = 0; //finished(1) or not(0)
		int j4x = 5; //x pos of j4
		static int j4y = 124; //y pos of j4

		erakutsijokoa();

		//load sprites
		Erakutsisonic(1,j1x,j1y);
		Erakutsisonic(2,j2x,j2y);
		Erakutsisonic(3,j3x,j3y);
		Erakutsisonic(4,j4x,j4y);

		while (j1 == 0 || j2 == 0 || j3 == 0 || j4 == 0) {
			
			if(SakatutakoTekla() == A){
                		if(TeklaDetektatu() == pushA){
                    			if (pushA == 1){
                        			Ezabatusonic(1,j1x,40);
                        			Erakutsisonic(1,j1x+1,40);
                        			j1x = j1x+5;
                       	 			pushA = 0;
                        			if (j1x >= 220)					
                        			{
                            				iprintf("\x1b[10;5HPOS: %d",j1x);
                            				Ezabatusonic(1,j1x,40);
                            				j1 = 1;
                            	
                        			}
                    			}
                    			else
                    			{
                       				pushA = 1;
                    			}
                    	
          		      	}	
			}			
			//IA
		}
		
		jokoa01(3); // Mark egoera
	
	}

void jokoa2players () {
		int pushA = 1;
		int pushB = 1;
		
		//J1
		int j1 = 0; //finished(1) or not(0)
		int j1x = 5; //x pos of j1
		static int j1y = 40; //y pos of j1

		//J2
		int j2 = 0; //finished(1) or not(0)
		int j2x = 5; //x pos of j2
		static int j2y = 68; //y pos of j2

		//J3
		int j3 = 0; //finished(1) or not(0)
		int j3x = 5; //x pos of j3
		static int j3y = 96; //y pos of j3

		//J4
		int j4 = 0; //finished(1) or not(0)
		int j4x = 5; //x pos of j4
		static int j4y = 124; //y pos of j4

		erakutsijokoa();

		//load sprites
		Erakutsisonic(1,j1x,j1y);
		Erakutsisonic(2,j2x,j2y);
		Erakutsisonic(3,j3x,j3y);
		Erakutsisonic(4,j4x,j4y);

		while (j1 == 0 || j2 == 0 || j3 == 0 || j4 == 0) {
			
			if(SakatutakoTekla() == A){
                		if(TeklaDetektatu() == pushA){
                    			if (pushA == 1){
                        			Ezabatusonic(1,j1x,40);
                        			Erakutsisonic(1,j1x+1,40);
                        			j1x = j1x+5;
                       	 			pushA = 0;
                        			if (j1x >= 220)					
                        			{
                            				iprintf("\x1b[10;5HPOS: %d",j1x);
                            				Ezabatusonic(1,j1x,40);
                            				j1 = 1;
                            	
                        			}
                    			}
                    			else
                    			{
                       				pushA = 1;
                    			}
                    	
          		      	}	
			}

			if(SakatutakoTekla() == B){
	         		if(TeklaDetektatu() == pushB){
	                    		if (pushB == 1){
	                        			EzabatuErronboHandia(2,j2x,j2y);
	                        			Erakutsisonic(2,j2x+1,j2y);
	                        			j2x = j2x+5;
	                        			pushB = 0;
	                        			if (j2x >= 220)					
	                       				{
	                           				Ezabatusonic(2,j2x,j2y);
	                           				j2 = 1;
	                            
	                        			}
	                    		}
	                    		else
	                    		{
	                        		pushB = 1;
	                    		}
	                       	}	    		
			}
			//IA
		}
		
		jokoa01(3);; // Mark egoera

	}



void jokoa3players () {
		int pushA = 1;
		int pushB = 1;
		int pushGORA = 1;

		//J1
		int j1 = 0; //finished(1) or not(0)
		int j1x = 5; //x pos of j1
		static int j1y = 40; //y pos of j1

		//J2
		int j2 = 0; //finished(1) or not(0)
		int j2x = 5; //x pos of j2
		static int j2y = 68; //y pos of j2

		//J3
		int j3 = 0; //finished(1) or not(0)
		int j3x = 5; //x pos of j3
		static int j3y = 96; //y pos of j3

		//J4
		int j4 = 0; //finished(1) or not(0)
		int j4x = 5; //x pos of j4
		static int j4y = 124; //y pos of j4

		erakutsijokoa();

		//load sprites
		Erakutsisonic(1,j1x,j1y);
		Erakutsisonic(2,j2x,j2y);
		Erakutsisonic(3,j3x,j3y);
		Erakutsisonic(4,j4x,j4y);

		while (j1 == 0 || j2 == 0 || j3 == 0 || j4 == 0) {
			
			if(SakatutakoTekla() == A){
                		if(TeklaDetektatu() == pushA){
                    			if (pushA == 1){
                        			Ezabatusonic(1,j1x,40);
                        			Erakutsisonic(1,j1x+1,40);
                        			j1x = j1x+5;
                       	 			pushA = 0;
                        			if (j1x >= 220)					
                        			{
                            				iprintf("\x1b[10;5HPOS: %d",j1x);
                            				Ezabatusonic(1,j1x,40);
                            				j1 = 1;
                            	
                        			}
                    			}
                    			else
                    			{
                       				pushA = 1;
                    			}
                    	
          		      	}	
			}

			if(SakatutakoTekla() == B){
	         		if(TeklaDetektatu() == pushB){
	                    		if (pushB == 1){
	                        			EzabatuErronboHandia(2,j2x,j2y);
	                        			Erakutsisonic(2,j2x+1,j2y);
	                        			j2x = j2x+5;
	                        			pushB = 0;
	                        			if (j2x >= 220)					
	                       				{
	                           				Ezabatusonic(2,j2x,j2y);
	                           				j2 = 1;
	                            
	                        			}
	                    		}
	                    		else
	                    		{
	                        		pushB = 1;
	                    		}
	                       	}	    		
			}

			if(SakatutakoTekla() == GORA){
	         		if(TeklaDetektatu() == pushGORA){
	                    		if (pushGORA == 1){
	                        		Ezabatusonic(3,j3x,j3y);
	                        		Erakutsisonic(3,j3x+1,j3y);
	                        		j3x = j3x+5;
	                        		pushGORA = 0;
	                        		if (j3x >= 220)					
	                        		{
	                            			Ezabatusonic(3,j3x,j3y);
	                            			j3 = 1;	                            
	                        		}
	                    		}
	                    		else
	                    		{
	                        		pushGORA = 1;
	                    		}
	                    
	                	}    		
			}
			//IA
			
		}
		
		jokoa01(3); // Mark egoera	
			
	}
void jokoa4players () {
		int pushA = 1;
		int pushB = 1;
		int pushGORA = 1;
		int pushBEHERA =1;
		
		//J1
		int j1 = 0; //finished(1) or not(0)
		int j1x = 5; //x pos of j1
		static int j1y = 40; //y pos of j1

		//J2
		int j2 = 0; //finished(1) or not(0)
		int j2x = 5; //x pos of j2
		static int j2y = 68; //y pos of j2

		//J3
		int j3 = 0; //finished(1) or not(0)
		int j3x = 5; //x pos of j3
		static int j3y = 96; //y pos of j3

		//J4
		int j4 = 0; //finished(1) or not(0)
		int j4x = 5; //x pos of j4
		static int j4y = 124; //y pos of j4

		erakutsijokoa();

		//load sprites
		Erakutsisonic(1,j1x,j1y);
		Erakutsisonic(2,j2x,j2y);
		Erakutsisonic(3,j3x,j3y);
		Erakutsisonic(4,j4x,j4y);

		while (j1 == 0 || j2 == 0 || j3 == 0 || j4 == 0) {
			
			if(SakatutakoTekla() == A){
                		if(TeklaDetektatu() == pushA){
                    			if (pushA == 1){
                        			Ezabatusonic(1,j1x,40);
                        			Erakutsisonic(1,j1x+1,40);
                        			j1x = j1x+5;
                       	 			pushA = 0;
                        			if (j1x >= 220)					
                        			{
                            				iprintf("\x1b[10;5HPOS: %d",j1x);
                            				Ezabatusonic(1,j1x,40);
                            				j1 = 1;
                            	
                        			}
                    			}
                    			else
                    			{
                       				pushA = 1;
                    			}
                    	
          		      	}	
			}

			if(SakatutakoTekla() == B){
	         		if(TeklaDetektatu() == pushB){
	                    		if (pushB == 1){
	                        			EzabatuErronboHandia(2,j2x,j2y);
	                        			Erakutsisonic(2,j2x+1,j2y);
	                        			j2x = j2x+5;
	                        			pushB = 0;
	                        			if (j2x >= 220)					
	                       				{
	                           				Ezabatusonic(2,j2x,j2y);
	                           				j2 = 1;
	                            
	                        			}
	                    		}
	                    		else
	                    		{
	                        		pushB = 1;
	                    		}
	                       	}	    		
			}

			if(SakatutakoTekla() == GORA){
	         		if(TeklaDetektatu() == pushGORA){
	                    		if (pushGORA == 1){
	                        		Ezabatusonic(3,j3x,j3y);
	                        		Erakutsisonic(3,j3x+1,j3y);
	                        		j3x = j3x+5;
	                        		pushGORA = 0;
	                        		if (j3x >= 220)					
	                        		{
	                            			Ezabatusonic(3,j3x,j3y);
	                            			j3 = 1;	                            
	                        		}
	                    		}
	                    		else
	                    		{
	                        		pushGORA = 1;
	                    		}
	                    
	                	}    		
			}

			if(SakatutakoTekla() == BEHERA){
	         		if(TeklaDetektatu() == pushBEHERA){
	                    		if (pushBEHERA == 1){
	                        		Ezabatusonic(4,j4x,j4y);
	                        		Erakutsisonic(4,j4x+1,j4y);
	                        		j4x = j4x+5;
	                        		pushBEHERA = 0;
	                        		if (j4x >= 220)					
	                        		{
	                            			Ezabatusonic(4,j4x,80);
	                            			j4 = 1;
	                                       	}
	                    		}
	                    		else
	                    		{
	                      		  	pushBEHERA = 1;
	                    		}
	                    
	                	}
	    		}
			
		}
		
		jokoa01(3); // Mark egoera
		
	}


	

	void mark () {
		//erakutsizailtasuna();
		iprintf("\x1b[5;7HRUNNER"); //Fix Height
		int sec = 21;
		int dec = 13;
		iprintf("\x1b[10;7HJ1 -> %d s %d ms",sec,dec);
		iprintf("\x1b[12;7HJ2 -> %d s %d ms",sec,dec);
		iprintf("\x1b[14;7HJ3 -> %d s %d ms",sec,dec);
		iprintf("\x1b[16;7HJ4 -> %d s %d ms",sec,dec);
		iprintf("\x1b[20;2HSakatu tekla bat jarraitzeko");
		while (TeklaDetektatu() == 0){
			//Wait for key press
		}
		jokoa01(0); // Jokalari egoera
	
	}

	void delay (int x){ //delay = x ms
			int time = 0;

			while (x > time){
				time++;
			}
	}

void jokoa01(int status)
{	

	//config
	TekEtenBaimendu();
	ErlojuaMartxanJarri();
    etenZerbErrutEzarri();
	DenbEtenBaimendu();
	tenpZerbErrutEzarri();	
	konfiguratuTeklatua(0x400C);
	konfiguratuTenporizadorea(65208,0x00C3);


	while(1){
	    //iprintf("\x1b[16;7HStatus = %d",status);
		//Egoeren aldaketa
		switch (status){

			case 0:				
				jkop = jokalariak();
				break;
			case 1:
				zailt = zailtasuna();
				if (zailt != -1){
					jokoa01(1);
				}				
				break;
			case 2:
				if (jkop = 1)
					jokoa1players();
				if (jkop = 2)
					jokoa2players();
				if (jkop = 4)
					jokoa3players();
				if (jkop = 4)
					jokoa4players();
				break;
			case 3:
				mark();
				break;
			case 9: //tests
				break;		
		}
	 }

	
}

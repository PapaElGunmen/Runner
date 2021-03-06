/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		//nds-rako garatuta dagoen liburutegia
#include <stdio.h>		//c-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		//c-ko liburutegi estandarra memoria erreserbak eta zenbaki konbertsioak egiteko
#include <unistd.h>		//Sistema eragileen arteko konpatibilitatea ziurtatzeko liburutegia

/* Fondo desberdinak erakutsi nahi izango baditugu, hemen fondo bakoitzaren burukoa (.h fitxategia) gehitu behar da. Buruko horiek
automatikoki sortzen dira, konpilatzerako garaian, baina horretarako gogoratu behar da */

#include "fondoak.h"
#include "grafikoak.h"
#include "Atea.h"
#include "AteaIrekita.h"
#include "jokalariak.h"
#include "zailtasuna.h"
#include "jokoa.h"
#include "pause.h"
#include "score.h"

/* irudiak memorian kopiatzeko DMA kanala aukeratu (3.a) */
static const int DMA_CHANNEL = 3;

/* Pantailaratu nahi den grafiko bakoitzerako horrelako prozedura bat idatzi behar da */

void erakutsiAtea() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
                     AteaBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     AteaBitmapLen); /* Luzera (bytetan) automatikoki sortzen den aldagaia */
}

void erakutsiscore() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
                     scoreBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     scoreBitmapLen); /* Luzera (bytetan) automatikoki sortzen den aldagaia */
}

void erakutsiAteaIrekita() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     AteaIrekitaBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     AteaIrekitaBitmapLen); /* Luzera (bytetan) automatikoki sortzen den aldagaia */
}

void erakutsijokalariak() {
        
    dmaCopyHalfWords(DMA_CHANNEL,
                     jokalariakBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     jokalariakBitmapLen); /* Luzera (bytetan) automatikoki sortzen den aldagaia */
}

void erakutsijokoa() {
        
    dmaCopyHalfWords(DMA_CHANNEL,
                     jokoaBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     jokoaBitmapLen); /* Luzera (bytetan) automatikoki sortzen den aldagaia */
}

void erakutsipause() {
        
    dmaCopyHalfWords(DMA_CHANNEL,
                     pauseBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     pauseBitmapLen); /* Luzera (bytetan) automatikoki sortzen den aldagaia */
}

void erakutsizailtasuna() {
        
    dmaCopyHalfWords(DMA_CHANNEL,
                     zailtasunaBitmap, /* Automatikoki sortzen den aldagaia */
                     (uint16 *)BG_BMP_RAM(0), /* Fondo nagusiaren helbidea */
                     zailtasunaBitmapLen); /* Luzera (bytetan) automatikoki sortzen den aldagaia */
}

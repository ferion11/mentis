/* Created by Anjuta version 1.2.4a */
/*	This file will not be overwritten */


#include "mentis.h"
#include "string.h"
#include "stdlib.h"
#include "util.h"

void splash();
//#define DEBUG 1

int main (int argc, char *argv[])
{
	xosd *osd;
	int X;
	int Y;

	//Setting random seed
	srand(time(NULL));	
	
	//Initializing words
	init();
	setlocale(LC_ALL, "pt_BR");

	splash();
	while(1){
			
		// Fix values to 250, -250 or Zero.
		X = 250 * (rand()%3 - 1);
		Y = 250 * (rand()%3 - 1);
	
		#ifdef DEBUG
			printf("X: %d Y: %d\n",X,Y);
			//fflush(stdout);
		#endif
		
		osd = xosd_create (2);
		if (osd == NULL)
		{
			perror ("Could not create \"osd\"");
			exit (1);
		}
		
		xosd_set_font (osd, "-adobe-helvetica-bold-r-normal-*-*-100-*-*-p-*-*"); 
		//xosd_set_shadow_offset (osd, 2);
		xosd_set_colour (osd, "#FF0000");
		//xosd_set_outline_offset(osd, 1);
		xosd_set_outline_colour(osd, "black");
		
		xosd_set_pos (osd, XOSD_middle);
		xosd_set_vertical_offset (osd, Y);
		
		xosd_set_align (osd, XOSD_center);
		xosd_set_horizontal_offset (osd, X);
	 
		//Showing random phase
		
		xosd_display (osd, 0, XOSD_string, get_word());
		
		timer(.1);
		xosd_hide (osd);	
		xosd_destroy (osd);
		sleep(1);
		
	}
	exit (0);
}

void splash(){
	xosd *osd;
	osd = xosd_create (2);
	if (osd == NULL)
	{
		perror ("Could not create \"osd\"");
		exit (1);
	}
	
	xosd_set_font (osd, "-adobe-helvetica-bold-r-normal-*-*-220-*-*-p-*-*"); 
	xosd_set_shadow_offset (osd, 2);
	xosd_set_colour (osd, "#FF0000");
	xosd_set_outline_offset(osd, 2);
	xosd_set_outline_colour(osd, "black");
	
	xosd_set_pos (osd, XOSD_top);
	xosd_set_vertical_offset (osd, 20);
	
	xosd_set_align (osd, XOSD_left);
	xosd_set_horizontal_offset (osd, 20);
	
	xosd_display (osd, 0, XOSD_string, "Initializing Mentis");
	xosd_display (osd, 1, XOSD_string, "Please, shutdown Mentis if your suffer of epilepsy");
	sleep(1);
	xosd_hide (osd);	
	xosd_destroy (osd);

}

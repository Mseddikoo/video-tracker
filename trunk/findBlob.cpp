/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
#include "videotracker.h"

void findBlob(char * aviName,int id ){
	struct coordinate coord;
	IplImage* background = getBackground(aviName);
	
	int height = background->height;
	int width = background->width;
	int channels = background->nChannels;


	CvCapture* capture = cvCaptureFromAVI(aviName);
  
	if( !capture ) {
   		fprintf( stderr, "ERROR: capture is NULL \n" );
   		exit(0);
  	}

	IplImage* tmp_frame = cvQueryFrame(capture); //current image in the cycles
 
 
	if(!tmp_frame) {
         fprintf( stderr, "ERROR: Bad video\n" );
         exit(0);
        }

	for( int fr = 1;tmp_frame; tmp_frame = cvQueryFrame(capture), fr++ ){

                
		coord = extractBlob(tmp_frame, background,id);
		if (coord.flag == false ) {printf("No Blobs to extract");} else printf("Flag true!\n");
	printf("MaxX: %d, MaxY: %d, MinX: %d, MinY: %d\n-----------\n", coord.Maxx,coord.Maxy,coord.Minx,coord.Miny);
	}




};

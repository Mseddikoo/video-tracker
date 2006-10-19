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

#define rowA 2
#define colA 1

int main (int argc, char ** argv){

	CvMat* indexMat[7];

    int MP = 2; /* number of measurement vector dimensions */
    int DP = 1; /* number of state vector dimensions */
    int CP = 0; /* number of control vector dimensions */
	
	int id=0;
        
	findBlob(argv[1],id);
	
	CvKalman* kalman = cvCreateKalman(DP,MP,CP);

	init(kalman, indexMat);
	
	//execute(kalman, argv[1]);

	return 0;
}
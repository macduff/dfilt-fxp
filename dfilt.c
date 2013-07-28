#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "dfilt_fxp.h"

/* Initialize a test signal, it is a step function mixed with
 * some gaussian noise */
const uint16_t input[] = {0,11,0,0,0,11,14,9,0,0,0,24,0,37,18,0,0,0,0,20,
0,0,13,0,0,10,0,0,0,15,17,11,26,0,0,8,2,0,0,0,
0,28,21,7,2,0,0,0,0,16,470,492,534,506,493,502,495,533,520,492,
475,494,482,501,496,500,510,507,523,523,503,500,463,495,511,481,485,539,525,502,
487,493,487,490,520,501,470,503,509,505,516,510,493,485,507,509,515,515,470,486,
472,498,514,510,522,500,534,487,481,494,509,532,503,508,515,492,458,503,493,518,
488,492,498,499,527,505,498,476,483,496,511,505,521,513,513,500,510,481,509,511,
475,488,479,496,471,487,514,495,514,489,502,507,493,513,482,496,489,490,514,491,
534,528,501,502,495,494,478,498,514,499,500,484,489,486,512,498,532,507,465,519,
489,474,546,507,469,502,531,475,491,503,514,490,510,493,464,504,475,473,509,492,
};

/* Use the calculated cutoff constant, and its scaled counterpart */
#define ALPHA       0.23906 
#define FXP_ALPHA   (ALPHA*(uint16_t)(1<<15))
int main(int argc, char * argv[])
{
  const uint16_t alpha = FXP_ALPHA;
  
  int ii;
  FILE * fid;
  uint16_t output[sizeof(input)/sizeof(uint16_t)] = {0};
  /* open a file for writing only, always makes a new file,
	 * this data will be written to an m file for easy import
	 * into octave for plotting, initialize the first value
	 * at zero, even though this value is not known */
  fid = fopen("out.m","w");
  fprintf(fid,"y = [ 0, ");
	/* process each input value in the test vector
	 * start at 1 so that there is a previous value for
	 * the first ouput */
  for(ii=1;ii<sizeof(input)/sizeof(uint16_t);ii++)
  {
	  /* filter the signal */
    output[ii] = dfilt_single_pole_u16(input[ii],output[ii-1],alpha);

    /* write the results to a file, add a newline every
		 * 20 elements */
    fprintf(fid,"%d,",output[ii]);
    if( (ii % 20) == 0 )
    {
      fprintf(fid,"...\n");
    }
  }
	/* finish the output vector syntax and close the file */
  fprintf(fid,"];\n");
  fclose(fid);
  return 0;
}


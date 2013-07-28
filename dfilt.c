#include <stdlib.h>
#include <stdio.h>

typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

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

#define ALPHA       0.23906 /*0.75855 /*0.38587*/
#define FXP_ALPHA   (ALPHA*(uint16_t)(1<<15))
int main(int argc, char * argv[])
{
  const uint16_t alpha = FXP_ALPHA;
  
  int ii;
  FILE * fid;
  uint16_t output[sizeof(input)/sizeof(uint16_t)] = {0};
  uint32_t a1 = ((1<<15)-alpha);
  uint32_t b0 = alpha;
  printf("alpha = %d : %f\n",alpha,((double)alpha)/((double)(1<<15)));
  printf("a1 = %d : %f\n",a1,((double)a1)/((double)(1<<15)));
  printf("b0 = %d : %f\n",b0,((double)b0)/((double)(1<<15)));
  
  fid = fopen("out.m","w");
  fprintf(fid,"y = [ 0, ");
  for(ii=1;ii<sizeof(input)/sizeof(uint16_t);ii++)
  {
    uint32_t y1 = (a1*output[ii-1]) >> 15;
    uint32_t u1 = (b0*input[ii]) >> 15;
    
    output[ii] = y1 + u1;
    fprintf(fid,"%d,",output[ii]);
    if( (ii % 20) == 0 )
    {
      fprintf(fid,"...\n");
    }
  }
  fprintf(fid,"];\n");
  fclose(fid);
  return 0;
}


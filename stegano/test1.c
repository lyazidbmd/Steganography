#include <stdio.h>
#include "bitstream.h"


// Creates and destroys an empty bitstream.
int main(){
    Bitstream *b=CreateEmptyBitstream();
    FreeBitstream(b);
    printf("Done.\n");
}
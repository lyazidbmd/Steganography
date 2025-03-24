#include <stdio.h>
#include <string.h>
#include "bitstream.h"

// Creates an empty bitstream, and writes 5 chars 'a' followed by '\0'
int main(){
    Bitstream *b=CreateEmptyBitstream();
    for(int i=0; i<5; i++){
        WriteBit(b, 0);
        WriteBit(b, 1);
        WriteBit(b, 1);
        WriteBit(b, 0);
        WriteBit(b, 0);
        WriteBit(b, 0);
        WriteBit(b, 0);
        WriteBit(b, 1);
    }
    for(int i=0; i<8; i++){
        WriteBit(b, 0);
    }
    if(strcmp("aaaaa", b->data)==0){
        printf("Test passed\n");
    }else{
        printf("Test failed\n");
    }

}
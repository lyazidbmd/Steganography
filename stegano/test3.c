#include <stdio.h>
#include "bitstream.h"
#include <string.h>

//reads the content of an empty bitstream

int main(){
    Bitstream *b = CreateEmptyBitstream();
 
 for (int i = 0; i < 5; i++) {
        WriteBit(b, 1);  // 1
        WriteBit(b, 1);  // 1
        WriteBit(b, 1);  // 1
        WriteBit(b, 0);  // 0
        WriteBit(b, 0);  // 0
    }

    ResetPosition(b);
    printf("Bits lus : ");
    for (int i = 0; i < 25; i++) { 
        printf("%d ", ReadBit(b));
    }

    FreeBitstream(b);

    return 0;
}

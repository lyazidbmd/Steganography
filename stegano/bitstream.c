#include "bitstream.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define INITIAL_CAPACITY 4


Bitstream *CreateEmptyBitstream() {
    Bitstream *bs = (Bitstream *)malloc(sizeof(Bitstream));
    bs->capacity = INITIAL_CAPACITY*8;  
    bs->size = 0;
    bs->position = 0;
    bs->data = (char *)malloc(bs->capacity/8);
    //memset(bs->data, 0, bs->capacity);  // Initialisation à zéro
    return bs;
}


Bitstream *CreateBitstreamOnData(char *data, unsigned int size) {
    Bitstream *bs = (Bitstream *)malloc(sizeof(Bitstream));
    bs->capacity = size;
    bs->size = size;
    bs->position = 0;
    bs->data = (char *)malloc(bs->capacity);
    memcpy(bs->data, data, size);
    return bs;
}


void ResetPosition(Bitstream *b) {
    b->position = 0;
}


void WriteBit(Bitstream *b, char o) {
    
if (b->position >= b->capacity) {
        b->capacity *= 2;
        b->data = (char*)realloc(b->data, b->capacity / 8);
    }
    unsigned int byteIndex = b->position / 8;
    unsigned int bitIndex = b->position % 8;

if (o) {
        b->data[byteIndex] |= (1 << (7 - bitIndex));  
    } else {
        b->data[byteIndex] &= ~(1 << (7 - bitIndex)); 
    }
    b->position += 1;

    // Mettre à jour la taille (en octets) uniquement lorsque nous avons écrit un octet complet
    if (b->position % 8 == 0) {
        b->size = (b->position / 8); // Taille en octets
}
}

char ReadBit(Bitstream *b) {
    if (b->position >= b->size*8) {
        
        return -1; 
    }
    unsigned int byteIndex = b->position / 8;
    unsigned int bitIndex = b->position % 8;

    char bit = (b->data[byteIndex] >> (7 - bitIndex)) & 1;

    b->position += 1;

    return bit;
}



void FreeBitstream(Bitstream *b) {
    free(b->data);
    free(b);
  }

#ifndef __BITSTREAM_H__
#define __BITSTREAM_H__

typedef struct
{
    unsigned int size; 
    unsigned int capacity;
    unsigned int position; 
    char *data;            
} Bitstream;

Bitstream *CreateEmptyBitstream(); // Fonction pour créer un bitstream vide (mode écriture)
Bitstream *CreateBitstreamOnData(char *data, unsigned int size); // Fonction pour créer un bitstream à partir de données existantes (mode lecture)
void ResetPosition(Bitstream *b); // Fonction pour réinitialiser la position du bitstream
void WriteBit(Bitstream *b, char o); // Fonction pour écrire un bit dans le bitstream
char ReadBit(Bitstream *b); // Fonction pour lire un bit depuis le bitstream
void FreeBitstream(); // Fonction pour libérer un bitstream
#endif //__BITSTREAM_H__

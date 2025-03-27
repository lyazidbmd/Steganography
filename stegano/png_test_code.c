#include <stdio.h>
#include <stdlib.h>
#include "bitstream.h"
#include "message.h"
#include "pngwrap.h"
#include "md5_utils.h"

int main() 
{
    // Charger le message à cacher
    char *message = CreateMessageFromFile("../CMakeLists.txt");
    if (!message) {
        fprintf(stderr, "Erreur : Impossible de créer le message\n");
        return EXIT_FAILURE;
    }

    // Charger l'image en niveaux de gris
    bwimage_t *lenaimg = E3ACreateImage();
    error_e err = E3ALoadImage("../lena.png", lenaimg);
    if (err != E3A_OK) {
        fprintf(stderr, "Erreur : Impossible de charger l'image\n");
        free(message);
        return EXIT_FAILURE;
    }

    // Calcul de la capacité de l'image
    unsigned int img_capacity = lenaimg->width * lenaimg->height;
    unsigned int msg_size = GetMessageSize(message);

    // Vérification si le message tient dans l'image
    if (msg_size * 8 > img_capacity) { // Besoin de msg_size * 8 bits pour encoder
        fprintf(stderr, "Erreur : Message trop grand pour être caché dans l'image\n");
        free(message);
        E3AFreeImage(lenaimg);
        return EXIT_FAILURE;
    }

    // Création du bitstream pour encoder les bits du message
    Bitstream *bs = CreateBitstreamOnData(message, msg_size);
    if (!bs) {
        fprintf(stderr, "Erreur : Impossible de créer le bitstream\n");
        free(message);
        E3AFreeImage(lenaimg);
        return EXIT_FAILURE;
    }

    char bit=0;
    for(int i=0; i<lenaimg->width; i++){
        for(int j=0; j<lenaimg->height; j++){
            bit=ReadBit(bs);
            if(bit==-1) break;
            lenaimg->data[i][j] = (lenaimg->data[i][j] & 0xFE) | bit;
        }
        if(bit==-1) break;
    }

    // Sauvegarde de l'image modifiée
    err = E3ADumpImage("../lena_avec_codage.png", lenaimg);
    if (err != E3A_OK) {
        fprintf(stderr, "Erreur : Impossible de sauvegarder l'image modifiée\n");
        free(message);
        FreeBitstream(bs);
        E3AFreeImage(lenaimg);
        return EXIT_FAILURE;
    }

    printf("Encodage terminé avec succès. Image sauvegardée sous lena_avec_codage.png\n");

    // Libération de la mémoire
    free(message);
    FreeBitstream(bs);
    E3AFreeImage(lenaimg);

    return EXIT_SUCCESS;
}
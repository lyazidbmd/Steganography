#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitstream.h"
#include "message.h"
#include "pngwrap.h"
#include "md5_utils.h"

int main() 
{
    // Charger l'image encodée
    bwimage_t *img = E3ACreateImage();
    error_e err = E3ALoadImage("../lena_avec_codage.png", img);
    if (err != E3A_OK) {
        fprintf(stderr, "Erreur : Impossible de charger l'image encodée\n");
        return EXIT_FAILURE;
    }

    // Créer un bitstream pour stocker les bits extraits
    Bitstream *extracted_bs = CreateEmptyBitstream();
    if (!extracted_bs) {
        fprintf(stderr, "Erreur : Impossible de créer le bitstream\n");
        E3AFreeImage(img);
        return EXIT_FAILURE;
    }

    // Extraire les bits LSB de chaque pixel
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            // Accès sécurisé au pixel (adapté à votre structure 2D)
            unsigned char pixel = img->data[y][x];
            unsigned char lsb = pixel & 0x01;
            WriteBit(extracted_bs, lsb);
        }
    }

    // Convertir les bits en message
    unsigned char *extracted_data = (unsigned char *)extracted_bs->data;
    unsigned int extracted_size = GetMessageSize(extracted_data);

    // Vérifier la taille
    if (extracted_size == 0 || extracted_size > (img->width * img->height / 8)) {
        fprintf(stderr, "Erreur : Taille du message invalide\n");
        FreeBitstream(extracted_bs);
        E3AFreeImage(img);
        return EXIT_FAILURE;
    }


    // Sauvegarder le message extrait
    const char *filename = GetMessageFileName(extracted_data);
    FILE *out = fopen(filename, "wb");
    if (!out) {
        fprintf(stderr, "Erreur : Impossible de créer %s\n", filename);
        FreeBitstream(extracted_bs);
        E3AFreeImage(img);
        return EXIT_FAILURE;
    }

    fwrite(extracted_data + START_DATA, 1, extracted_size, out);
    fclose(out);

    printf("Message extrait avec succès dans %s\n", filename);

    // Nettoyage
    FreeBitstream(extracted_bs);
    E3AFreeImage(img);

    return EXIT_SUCCESS;
}
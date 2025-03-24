#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitstream.h"
#include "message.h"
#include "pngwrap.h"
#include "md5_utils.h"


int main() 
{
    // Charger l'image modifiée contenant le message
    bwimage_t *encoded_img = E3ACreateImage();
    error_e err = E3ALoadImage("../lena_avec_codage.png", encoded_img);
    if (err != E3A_OK) {
        fprintf(stderr, "Erreur : Impossible de charger l'image encodée\n");
        return EXIT_FAILURE;
    }

    // Déterminer la capacité de l'image
    unsigned int img_capacity = encoded_img->width * encoded_img->height;

    Bitstream *b=CreateEmptyBitstream();
    for(int i=0; i<encoded_img->height; i++){
        for(int j=0; j<encoded_img->width; j++){
            WriteBit(b, encoded_img->data[i][j] & 1);
        }
    }

    unsigned int data_size=GetMessageSize(b->data);

    printf("Found data size: %d\n", data_size);
    
    // // Extraction de la taille du message stockée au début
    // unsigned int msg_size = 0;
    // for (int i = 0; i < 32; i++) { // Stocké sur 32 bits (4 octets)
    //     msg_size |= (*encoded_img->data[i] & 1) << i;
    // }

    // if (msg_size * 8 > img_capacity) {
    //     fprintf(stderr, "Erreur : Message corrompu ou trop grand\n");
    //     E3AFreeImage(encoded_img);
    //     return EXIT_FAILURE;
    // }

    // // Allocation du message
    // char *extracted_message = (char *)malloc(msg_size + 1);
    // if (!extracted_message) {
    //     fprintf(stderr, "Erreur : Impossible d'allouer la mémoire pour le message\n");
    //     E3AFreeImage(encoded_img);
    //     return EXIT_FAILURE;
    // }

    // // Extraire les bits du message
    // Bitstream *bs = CreateBitstreamOnData(extracted_message, msg_size);
    // if (!bs) {
    //     fprintf(stderr, "Erreur : Impossible de créer le bitstream\n");
    //     free(extracted_message);
    //     E3AFreeImage(encoded_img);
    //     return EXIT_FAILURE;
    // }

    // int bit_index = 32; // Début du message après la taille
    // for (unsigned int i = 0; i < msg_size; i++) {
    //     unsigned char byte = 0;
    //     for (int bit = 0; bit < 8; bit++) {
    //         byte |= (*encoded_img->data[bit_index++] & 1) << bit;
    //     }
    //     extracted_message[i] = byte;
    // }
    // extracted_message[msg_size] = '\0';

    // // Vérification du hash MD5
    // unsigned char md5_computed[MD5_DIGEST_LENGTH];
    // calculate_md5((unsigned char*)extracted_message, msg_size - MD5_DIGEST_LENGTH, md5_computed);


    // if (memcmp(md5_computed, extracted_message + msg_size - MD5_DIGEST_LENGTH, MD5_DIGEST_LENGTH) != 0) 
    // {
    // fprintf(stderr, "Erreur : Hachage MD5 ne correspond pas, message corrompu\n");
    // free(extracted_message);
    // FreeBitstream(bs);
    E3AFreeImage(encoded_img);
    
    


    // Sauvegarde du message décodé
    // FILE *msg_file = fopen("decoded_message.txt", "w");
    // if (!msg_file) {
    //     fprintf(stderr, "Erreur : Impossible d'écrire le message\n");
    //     free(extracted_message);
    //     FreeBitstream(bs);
    //     E3AFreeImage(encoded_img);
    //     return EXIT_FAILURE;
    // }
    // fprintf(msg_file, "%s", extracted_message);
    // fclose(msg_file);
    // printf("Message décodé avec succès et enregistré sous 'decoded_message.txt'\n");

    // // Reconstruction de l'image originale
    // for (unsigned int i = 32; i < img_capacity; i++) {
    //     *encoded_img->data[i] &= ~1;  // Réinitialiser le bit LSB à 0
    // }
    
    // err = E3ADumpImage("../lena_reconstruite.png", encoded_img);
    // if (err != E3A_OK) {
    //     fprintf(stderr, "Erreur : Impossible de sauvegarder l'image reconstruite\n");
    //     free(extracted_message);
    //     FreeBitstream(bs);
    //     E3AFreeImage(encoded_img);
    //     return EXIT_FAILURE;
    // }

    // printf("Image reconstruite avec succès sous 'lena_reconstruite.png'\n// Extraction de la taille du message stockée au début
    // unsigned int msg_size = 0;
    // for (int i = 0; i < 32; i++) { // Stocké sur 32 bits (4 octets)
    //     msg_size |= (*encoded_img->data[i] & 1) << i;
    // }

    // if (msg_size * 8 > img_capacity) {
    //     fprintf(stderr, "Erreur : Message corrompu ou trop grand\n");
    //     E3AFreeImage(encoded_img);
    //     return EXIT_FAILURE;
    // }

    // // Allocation du message
    // char *extracted_message = (char *)malloc(msg_size + 1);
    // if (!extracted_message) {
    //     fprintf(stderr, "Erreur : Impossible d'allouer la mémoire pour le message\n");
    //     E3AFreeImage(encoded_img);
    //     return EXIT_FAILURE;
    // }
return EXIT_FAILURE;
    // // Extraire les bits du message
    // Bitstream *bs = CreateBitstreamOnData(extracted_message, msg_size);
    // if (!bs) {
    //     fprintf(stderr, "Erreur : Impossible de créer le bitstream\n");
    //     free(extracted_message);
    //     E3AFreeImage(encoded_img);
    //     return EXIT_FAILURE;
    // }

    // int bit_index = 32; // Début du message après la taille
    // for (unsigned int i = 0; i < msg_size; i++) {
    //     unsigned char byte = 0;
    //     for (int bit = 0; bit < 8; bit++) {
    //         byte |= (*encoded_img->data[bit_index++] & 1) << bit;
    //     }
    //     extracted_message[i] = byte;
    // }
    // extracted_message[msg_size] = '\0';

    // // Vérification du hash MD5
    // unsigned char md5_computed[MD5_DIGEST_LENGTH];
    // calculate_md5((unsigned char*)extracted_message, msg_size - MD5_DIGEST_LENGTH, md5_computed);


    // if (memcmp(md5_computed, extracted_message + msg_size - MD5_DIGEST_LENGTH, MD5_DIGEST_LENGTH) != 0) 
    // {
    // fprintf(stderr, "Erreur : Hachage MD5 ne correspond pas, message corrompu\n");
    // free(extracted_message);
    // FreeBitstream(bs);");

    // Libération de la mémoire
    //free(extracted_message);
    //FreeBitstream(bs);
    // E3AFreeImage(encoded_img);

    return EXIT_SUCCESS;
}

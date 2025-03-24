#include <openssl/evp.h>
#include <openssl/err.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "md5_utils.h" // Assurez-vous que ce fichier existe bien

void calculate_md5(unsigned char* buf, unsigned int buf_size, unsigned char* md5_out) 
{
    EVP_MD_CTX *mdctx;
    unsigned int md5_digest_len = MD5_DIGEST_LENGTH; // Toujours 16 octets (128 bits)

    // Initialisation du contexte
    mdctx = EVP_MD_CTX_new();
    if (!mdctx) {
        fprintf(stderr, "Erreur : Impossible de créer le contexte EVP_MD_CTX\n");
        return;
    }

    if (EVP_DigestInit_ex(mdctx, EVP_md5(), NULL) != 1) {
        fprintf(stderr, "Erreur : EVP_DigestInit_ex a échoué\n");
        EVP_MD_CTX_free(mdctx);
        return;
    }

    // Ajout des données au hachage
    if (EVP_DigestUpdate(mdctx, buf, buf_size) != 1) {
        fprintf(stderr, "Erreur : EVP_DigestUpdate a échoué\n");
        EVP_MD_CTX_free(mdctx);
        return;
    }

    // Finalisation du hachage et stockage du résultat dans md5_out
    if (EVP_DigestFinal_ex(mdctx, md5_out, &md5_digest_len) != 1) {
        fprintf(stderr, "Erreur : EVP_DigestFinal_ex a échoué\n");
        EVP_MD_CTX_free(mdctx);
        return;
    }

    // Nettoyage du contexte
    EVP_MD_CTX_free(mdctx);
}

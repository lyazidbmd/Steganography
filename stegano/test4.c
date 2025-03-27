#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MD5.h"
#include "message.h"

int main() {
    const char *filename = "../CMakeLists.txt";
    char *message = CreateMessageFromFile(filename);
    if (!message) {
        fprintf(stderr, "Erreur: impossible de créer le message.\n");
        return 1;
    }

   
    unsigned int size = GetMessageSize(message);
    printf("Taille du fichier: %u\n", size);

 
    const char *fname = GetMessageFileName(message);
    printf("Nom du fichier: %s\n", fname);


    calculate_md5((unsigned char*)(message + START_DATA), size);

    // Libération finale
    free(message);
    return 0;
}


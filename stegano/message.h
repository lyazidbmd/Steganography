#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#define START_SIZE 0
#define START_MD5 4
#define START_FILENAME 20
#define START_DATA 276


char *CreateMessageFromFile(const char *filename); //cree un code source (message) depuis le fichier
unsigned int GetMessageSize(const char *message); //fonction pour avoir la taille du message
const char *GetMessageFileName(const char *message); //pour avoir le nom du message
int CheckMD5(const char *message); // Returns 0 if MD5 is OK


#endif //__MESSAGE_H__

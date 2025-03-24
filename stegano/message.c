#include "message.h"
#include "md5_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h> 

#define BUFFER_SIZE 4096

char *CreateMessageFromFile(const char *filename)
{
    unsigned int n=0;
    char buf[BUFFER_SIZE];
    char *data=malloc(START_DATA); 
    FILE *in=fopen(filename, "rb");
    if(!in) return 0;
    for(;;){
        unsigned int nread=fread(buf, 1, BUFFER_SIZE, in);
        unsigned int n2=n+nread; 
        data=realloc(data, n2+START_DATA);
        memcpy(data+START_DATA+n, buf, nread);
        n=n2;
        if(nread != BUFFER_SIZE) break;
    }
    for(int i=0; i<sizeof(int); i++){
        data[START_SIZE+i]=(n>>8*i)&0xFF;
    }
    char *basec=strdup(filename);
    if(!basec) {
        free(data);
        return 0;
    }
    char *bname=basename(basec);
    if(strlen(bname) >= 255) {
        free(basec);
        free(data);
        return 0;
    }
    strcpy(data+START_FILENAME, bname);
    free(basec);

    {
       
        calculate_md5((unsigned char*)(data + START_DATA), n, (unsigned char*)(data + START_MD5));
    }

    return data;
}

unsigned int GetMessageSize(const char *message)
{
    unsigned int rv=0;
    for(int i=0; i<sizeof(int); i++){
        rv |= (unsigned int)(unsigned char)message[START_SIZE+i]<<8*i;
    }
    return rv;
}

const char *GetMessageFileName(const char *message)
{
    return message+START_FILENAME;
}





#ifndef MD5_UTILS_H
#define MD5_UTILS_H

#include <openssl/evp.h>
#include <string.h>

#define MD5_DIGEST_LENGTH 16  // 16 octets (128 bits)

void calculate_md5(unsigned char* buf, unsigned int buf_size, unsigned char* md5_out);

#endif // MD5_UTILS_H

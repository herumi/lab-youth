#include<stdio.h>
#include "chacha.h"

int main() {
    // Test Vector
    // https://tools.ietf.org/html/rfc7539#section-2.4.2
    unsigned char plaintext[] = {
        0x4c, 0x61, 0x64, 0x69, 0x65, 0x73, 0x20, 0x61,
        0x6e, 0x64, 0x20, 0x47, 0x65, 0x6e, 0x74, 0x6c,
        0x65, 0x6d, 0x65, 0x6e, 0x20, 0x6f, 0x66, 0x20,
        0x74, 0x68, 0x65, 0x20, 0x63, 0x6c, 0x61, 0x73,
        0x73, 0x20, 0x6f, 0x66, 0x20, 0x27, 0x39, 0x39,
        0x3a, 0x20, 0x49, 0x66, 0x20, 0x49, 0x20, 0x63,
        0x6f, 0x75, 0x6c, 0x64, 0x20, 0x6f, 0x66, 0x66,
        0x65, 0x72, 0x20, 0x79, 0x6f, 0x75, 0x20, 0x6f,
        0x6e, 0x6c, 0x79, 0x20, 0x6f, 0x6e, 0x65, 0x20,
        0x74, 0x69, 0x70, 0x20, 0x66, 0x6f, 0x72, 0x20,
        0x74, 0x68, 0x65, 0x20, 0x66, 0x75, 0x74, 0x75,
        0x72, 0x65, 0x2c, 0x20, 0x73, 0x75, 0x6e, 0x73,
        0x63, 0x72, 0x65, 0x65, 0x6e, 0x20, 0x77, 0x6f,
        0x75, 0x6c, 0x64, 0x20, 0x62, 0x65, 0x20, 0x69,
        0x74, 0x2e,
    };
    unsigned long long msg_length = sizeof(plaintext);
    unsigned char ciphertext[msg_length];

    unsigned char key[] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
        0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
    };
    unsigned char nonce[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a,
        0x00, 0x00, 0x00, 0x00,
    };
    chacha20_encrypt(key, 1, nonce, plaintext, ciphertext, msg_length);


    // Print Plaintext
    puts("[+] Plaintext:");
    for(int j = 0; j < msg_length; j++) {
        if(j % 16 == 0) {
            printf("%03d: ", j);
        }
        printf("%02x " , plaintext[j]);
        if((j + 1) % 16 == 0) puts("");
    }
    puts("\n");

    // Print Ciphertext
    puts("[+] Ciphertext:");
    for(int j = 0; j < msg_length; j++) {
        if(j % 16 == 0) {
            printf("%03d: ", j);
        }
        printf("%02x " , ciphertext[j]);
        if((j + 1) % 16 == 0) puts("");
    }
    puts("");

}
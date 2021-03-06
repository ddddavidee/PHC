#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "catfish.h"

int main() {
    int i;
    const uint8_t salt[16] = {
        0x3e, 0xaf, 0xf7, 0xa0, 0x68, 0x0e, 0x7e, 0xdc, 0x72, 0xfc, 0xcc, 0x8d, 0x1f, 0xc0, 0xed, 0x16,
    };
    const uint8_t password[128] = {
        0x2b, 0xa5, 0xfa, 0xea, 0xf1, 0x4f, 0xbd, 0xbe, 0x43, 0x6a, 0xf6, 0x46, 0x5c, 0x8e, 0xdb, 0x25, 0x24, 0xc6, 0x17, 0xa3, 0x7a, 0xd6, 0xb0, 0x0c, 0x0c, 0x16, 0x76, 0x9f, 0xf4, 0x70, 0x91, 0x1c, 0xfa, 0x6a, 0x99, 0x65, 0xc0, 0xe3, 0x7b, 0x6f, 0x44, 0x6d, 0x4e, 0x8f, 0x0e, 0xc0, 0x3a, 0xdb, 0xbd, 0x12, 0x1a, 0xc6, 0xca, 0x10, 0xb6, 0xb1, 0x4e, 0x5b, 0x7e, 0x5e, 0x97, 0xcb, 0x55, 0xb5, 0xf9, 0x5b, 0xa3, 0x65, 0xd6, 0xa0, 0xfd, 0xd7, 0xb6, 0x40, 0xfe, 0xa1, 0x85, 0x1b, 0x7f, 0x4d, 0xbc, 0x2b, 0x81, 0xd1, 0x5e, 0xd6, 0xeb, 0x0e, 0xfb, 0x5d, 0xb0, 0x0a, 0xf8, 0xb4, 0xa2, 0xb3, 0x8d, 0x67, 0xf5, 0x14, 0xa9, 0x8c, 0xeb, 0x4e, 0x1c, 0xa9, 0xc2, 0x9c, 0xd8, 0xb0, 0xc1, 0xc6, 0x85, 0xde, 0xf8, 0x8d, 0xcb, 0xa4, 0x07, 0x0b, 0xf0, 0x26, 0xb2, 0x89, 0xef, 0x00, 0x7c, 0x13,
    };
    uint8_t tag[32] = {0};
    int error_code;

    printf("salt in hex: ");
    for (i = 0; i < 16; i++) {
        printf("%02x", salt[i]);
    }
    printf("\n");

    printf("password in hex: ");
    for (i = 0; i < sizeof(password) / sizeof(uint8_t); i++) {
        printf("%02x", password[i]);
    }
    printf("\n");

    error_code = catfish(
            tag, 32,
            password, sizeof(password) / sizeof(uint8_t),
            salt, 16,
            2, 1024 // tcost, mcost
    );

    if (0 == error_code) {
        printf("digest in hex: ");
        for (i = 0; i < 32; i++) {
            printf("%02x", tag[i]);
        }
        printf("\n");

    } else {
        printf("Error code: %d\n", error_code);
    }

    return 0;
}

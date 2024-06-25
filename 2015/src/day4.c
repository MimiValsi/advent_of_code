#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include "../misc/misc.h"

#define DIGITS(v) (sizeof(v) * CHAR_BIT * 28 / 93 + 1)


int mining(char *input);
_Bool fetch_zeros(int zeros, char* str_to_compare);

int main(void)
{
        char input[40] = "ckczppom";
        mining(input);
        return 0;
}

int
mining(char *input)
{
        EVP_MD_CTX *mdctx;
        const EVP_MD *md;
        unsigned char md_value[EVP_MAX_MD_SIZE];
        unsigned int md_len;

        md = EVP_get_digestbyname("MD5");
        if (md == NULL) {
                printf("Unkown message digest\n");
                exit(1);
        }

        for (u32 i = 0;; i++) {
                FILE *f = fopen("./output.txt", "w+");
                mdctx = EVP_MD_CTX_new();
                if (!EVP_DigestInit_ex2(mdctx, md, NULL)) {
                    printf("Message digest initialization failed.\n");
                    EVP_MD_CTX_free(mdctx);
                    exit(1);
                }
                if (!EVP_DigestUpdate(mdctx, input, strlen(input))) {
                    printf("Message digest update failed.\n");
                    EVP_MD_CTX_free(mdctx);
                    exit(1);
                }

                if (!EVP_DigestFinal_ex(mdctx, md_value, &md_len)) {
                    printf("Message digest finalization failed.\n");
                    EVP_MD_CTX_free(mdctx);
                    exit(1);
                }

                for (u32 j = 0; j < md_len; j++) {
                        fprintf(f, "%02x", md_value[j]);
                }

                rewind(f);
                // if (fetch_zeros(5, "00000")) {
                //         printf("i = %ld\n", i-1);
                //         break;
                // }

                if (fetch_zeros(6, "000000")) {
                        printf("i = %ld\n", i-1);
                        break;
                }

                char buf[DIGITS(i) + 1];
                sprintf(buf, "%lu", i);
                strcpy(&input[8], buf);

                if (!EVP_DigestInit_ex2(mdctx, md, NULL)) {
                    printf("Message digest initialization failed.\n");
                    EVP_MD_CTX_free(mdctx);
                    exit(1);
                }

                EVP_MD_CTX_free(mdctx);
                fclose(f);
        }
        return 0;

}

_Bool
fetch_zeros(int zeros, char* str_to_compare)
{
        FILE *f = fopen("./output.txt", "r");
        char mystr[zeros+1];
        fgets(mystr, zeros+1, f);

        if (strcmp(mystr, str_to_compare) == 0) {
                return true;
        }
        fclose(f);
        return false;
}

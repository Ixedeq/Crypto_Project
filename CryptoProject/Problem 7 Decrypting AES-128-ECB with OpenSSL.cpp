#include <iostream>
#include <string>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <cstring>

// Decode Base64 encoded string
std::string decode_base64(const std::string &enc) {
    BIO *bio, *b64;
    int decode_length = (enc.length() / 4) * 3;
    char *decode_str = new char[decode_length];

    bio = BIO_new_mem_buf(enc.c_str(), -1);
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_push(b64, bio);

    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
    decode_length = BIO_read(bio, decode_str, enc.length());
    BIO_free_all(bio);

    std::string result(decode_str, decode_length);
    delete[] decode_str;
    return result;
}

// Decrypt AES-128-ECB encrypted string
std::string decrypt_aes_ecb(const std::string &enc, const std::string &key) {
    AES_KEY decrypt_key;
    std::string dec(enc.size(), '\0');

    AES_set_decrypt_key((const unsigned char*)key.c_str(), 128, &decrypt_key);
    for (size_t i = 0; i < enc.size(); i += AES_BLOCK_SIZE) {
        AES_ecb_encrypt((const unsigned char*)enc.data() + i, 
                        (unsigned char*)dec.data() + i, 
                        &decrypt_key, AES_DECRYPT);
    }

    return dec;
}

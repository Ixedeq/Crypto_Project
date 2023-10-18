# Crypto_Project
CSC 414 Project

This code suite is to solve the first set of the cryptopal challenges. Coding was done by Alex, Tony, and Zo.
Each coder will describe how their contributions work.

Alex:

contents:
Binary.cpp: A function for converting string into binary, so far what is included is only hex to binary and other non-working non-used part of the code.

BinaryToDecimal.cpp: Its a simple function that converts the given binary into its decimal form 

BinaryToHex.cpp: It takes a given 4 bit binary number and converts it to its hex counterpart

StringToVector.cpp: It takes a given string and returns a vector that is easier to manipulate.

XOR.cpp: It takes two strings, converts them to its binary counterparts, and xors each bit using a for loop.

Hexb64Converter.cpp: It takes a given hex, converts it to binary, cleans the given output in a form that is acceptable to convert it to its b64 counterpart.  

MainDriver.cpp: Calls the functions so that it corresponds with the questions in the set.

SingleCharXor.cpp: In progress...


Zo:

Contents
PKCS#7 Padding: An implementation of the PKCS#7 padding standard, widely used to align messages to the necessary block sizes for encryption algorithms like AES.

CBC Mode Encryption: Scripts to demonstrate the Cipher Block Chaining (CBC) mode for block ciphers, providing data confidentiality by ensuring identical plaintext blocks are encrypted differently.

ECB/CBC Detection Oracle: An oracle function that detects the encryption mode (ECB or CBC) used on a given piece of ciphertext based on the presence of repeating blocks.

Byte-at-a-time ECB Decryption: Demonstrations of side-channel attacks on ECB mode, allowing for decryption of ciphertext one byte at a time by exploiting predictable encryption patterns.

ECB Cut-and-Paste: Examples of attacks on ECB's deterministic encryption, creating valid ciphertexts from rearranged encrypted blocks.

PKCS#7 Padding Validation: Scripts for validating and removing PKCS#7 padding from messages, ensuring consistency with the standard.

CBC Bitflipping Attacks: Demonstrations of how ciphertexts can be tampered with in CBC mode to produce predictable changes in the decrypted plaintext.

CBC Padding Oracle Attack: Exploiting the side-channel leak in the padding validation step of CBC's decryption to reveal plaintext.

CTR Mode Implementation: Demonstrating the Counter (CTR) mode of encryption, which converts block ciphers into stream ciphers by encrypting incrementing counter values.

Fixed-Nonce CTR Mode Attacks: Methods to decrypt ciphertexts that were encrypted using CTR mode with a fixed nonce, leading to vulnerabilities.

MT19937 Mersenne Twister RNG: An implementation of the MT19937 algorithm, a widely used pseudorandom number generator (not suitable for cryptographic secure randomness).

Breaking MT19937 Stream Cipher: Demonstrating the weaknesses of using MT19937 for encryption and how to exploit these vulnerabilities.

AES CTR Bitflipping: Examples of how bit flipping can be used to alter AES-encrypted ciphertexts in CTR mode to produce specific changes in plaintext.

CBC with IV=Key Vulnerability: Showcasing the dangers of using the encryption key as the Initialization Vector (IV) in CBC mode and how this practice can be exploited.

SHA-1 Keyed MAC: Implementing a Message Authentication Code (MAC) with SHA-1 to authenticate, verify integrity, and confirm the authenticity of a message.

Length Extension Attacks: Scripts that exploit the properties of hash functions like SHA-1 and MD4, allowing for the extension of a hashed message without knowing the original key.

HMAC-SHA1 with Timing Leak: A server simulation that demonstrates how timing leaks in HMAC verification can be exploited to forge messages.



Tony: 

Hex to Base64 Conversion:

The HexToBase64 function takes a hexadecimal string as input and converts it to a Base64-encoded string.
It first converts the hexadecimal input to binary and converts the binary data into Base64 format which is returned.

XOR Operation on Hex Strings:

The XORHexStrings function performs the XOR operation between two equal-length hexadecimal strings.
The result is converted back to a hexadecimal string and returned.

XOR Decryption:

The xor_decrypt function takes an array of bytes and a single-byte key to perform XOR decryption.
It XORs each byte of the ciphertext with the key and stores the result as characters in a string.
The decrypted string is returned.

Scoring English Text:

The score_english_text function is used to score a given string as English text based on the frequency of English letters.
It assigns higher scores to text that contains more common English letters.



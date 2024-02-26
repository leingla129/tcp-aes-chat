/*
 * Advanced Encryption Standard
 * @author Dani Huertas
 * @email huertas.dani@gmail.com
 *
 * Based on the document FIPS PUB 197
 */
#ifndef AES_H
#define AES_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <bitset>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cstdint>
#include "gmult.h"
using namespace std;
#define gmult(a,b) gmult_aes[256*a + b]



	extern uint8_t* key;

	uint8_t* aes_init(size_t key_size);

	uint8_t* aes_key_expansion(uint8_t* key, uint8_t* w);

	void aes_inv_cipher(uint8_t* in, uint8_t* out, uint8_t* w);

	void aes_cipher(uint8_t* in, uint8_t* out, uint8_t* w);

	//added

	std::vector<uint8_t> stringToUint8Array(std::string& plain);

	std::string Uint8ArrayToString(const std::vector<uint8_t>& out);

	std::vector<uint8_t> mergeArray(std::vector<std::vector<uint8_t>> decry_arrays);

	std::vector<std::vector<uint8_t>> divArray(std::vector<uint8_t> inputArray);


	std::string aes_encode(std::string reply);

	std::string aes_decode(std::string cipher);

	std::string setKey();

	uint8_t* expandKey(std::string key);


#endif
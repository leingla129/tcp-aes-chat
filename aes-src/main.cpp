/*
 * Advanced Encryption Standard
 * @author Dani Huertas
 * @email huertas.dani@gmail.com
 *
 * Based on the document FIPS PUB 197
 */


#include "aes.h"



int main() {
	
	//用户设置密钥
	string str_key =setKey();
	//Expand key
	key = expandKey(str_key);
	while (1) {
		// 获取用户输入
		std::string reply;
		std::cout << "Enter a message to encrypt: ";
		std::getline(std::cin, reply);
		if (reply == "-e") {
			break;
		}
		//aes-encode
		std::string cypher = aes_encode(reply);


		//aes-decode
		std::string decodeString = aes_decode(cypher);

		std::cout << "解密结果："<< decodeString << endl;

	}
		free(key);
	
	return 0;
	
}
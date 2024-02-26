#include "config.h"

void printEncryptedAESKey(unsigned int* encryptedKey, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << "Element " << i << ": " << encryptedKey[i] << std::endl;
    }
}

int main() {
    // 第一步，server生成 RSA 公钥私钥对
    Rsa rsa;
    rsa.RsaGetParam();
    Public_key p_key = rsa.get_public_key();
    Secret_key s_key = rsa.get_secret_key();

    cout << "公钥<n：" << p_key.n << ",e：" << p_key.e << ">" << endl;
    cout << "私钥<n：" << s_key.n << ",d：" << s_key.d << ">" << endl;

    //第二步，client生成aes密钥key，并用rsa公钥加密key
    string str_key = setKey();
    

    std::cout << "str_key:" << str_key << std::endl;
    unsigned int* encrpt_aes_key = new unsigned int[str_key.length()];
    //const char* aes_key = str_key.c_str();
    for (size_t i = 0; i < str_key.length(); i++)
    {
        char a = str_key[i];
        int b = atoi(&a);
        encrpt_aes_key[i] = Rsa::Encry(b, p_key);
    }
    size_t keySize = str_key.length();
    printEncryptedAESKey(encrpt_aes_key,keySize);

    //第三步，server解密encrypted key
    string key_0 = "";
    for (size_t i = 0; i <keySize; i++)
    {
        std::stringstream ss;
        ss << Rsa::Decry(encrpt_aes_key[i], s_key);
        key_0 += ss.str();
    }
    cout << " key_0: " << key_0 << endl;
    return 0;
}
//g++ test.cpp aes-src/aes.cpp aes-src/gmult.cpp rsa-src/rsa.cpp -o test
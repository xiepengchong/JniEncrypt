//
// Created by XiePengchong on 2018/12/3.
//

#ifndef JNIENCRYPT_AES_H
#define JNIENCRYPT_AES_H

#include <stddef.h>
#include <string>

std::string DecodeAES(const unsigned char *master_key,std::string data,const unsigned char *iv);
std::string EncodeAES(const unsigned char *master_key,std::string data,const unsigned char *iv);
#endif //JNIENCRYPT_AES_H

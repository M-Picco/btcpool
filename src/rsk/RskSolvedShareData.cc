/*
 The MIT License (MIT)

 Copyright (C) 2017 RSK Labs Ltd.

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

#include "RskSolvedShareData.h"

#include <string>

size_t RskSolvedShareData::serializeTo(uint8_t* buf) const {
  size_t serialized = 0;

  memcpy(buf + serialized, (uint8_t*)&jobId_, sizeof(jobId_));                      serialized += sizeof(jobId_);
  memcpy(buf + serialized, (uint8_t*)&workerId_, sizeof(workerId_));                serialized += sizeof(workerId_);
  memcpy(buf + serialized, (uint8_t*)&userId_, sizeof(userId_));                    serialized += sizeof(userId_);
  memcpy(buf + serialized, (uint8_t*)&height_, sizeof(height_));                    serialized += sizeof(height_);
  memcpy(buf + serialized, (uint8_t*)&header80_, sizeof(header80_));                serialized += BTC_BLOCK_HEADER_SIZE;
  memcpy(buf + serialized, (uint8_t*)&workerFullName_, sizeof(workerFullName_));    serialized += WORKER_NAME_SIZE;
  memcpy(buf + serialized, (uint8_t*)&rskFeesForMiner_, sizeof(rskFeesForMiner_));  serialized += RSK_DATA_STRING_FIELD_SIZE;
  memcpy(buf + serialized, (uint8_t*)&rpcAddress_, sizeof(rpcAddress_));            serialized += RSK_DATA_STRING_FIELD_SIZE;
  memcpy(buf + serialized, (uint8_t*)&rpcUserPwd_, sizeof(rpcUserPwd_));            serialized += RSK_DATA_STRING_FIELD_SIZE;

  return serialized;
}

size_t RskSolvedShareData::deserializeFrom(const uint8_t* buf) {
  size_t deserialized = 0;

  memcpy((uint8_t*)&jobId_          , buf + deserialized,  sizeof(jobId_));           deserialized += sizeof(jobId_);
  memcpy((uint8_t*)&workerId_       , buf + deserialized,  sizeof(workerId_));        deserialized += sizeof(workerId_);
  memcpy((uint8_t*)&userId_         , buf + deserialized,  sizeof(userId_));          deserialized += sizeof(userId_);
  memcpy((uint8_t*)&height_         , buf + deserialized,  sizeof(height_));          deserialized += sizeof(height_);
  memcpy((uint8_t*)&header80_       , buf + deserialized,  sizeof(header80_));        deserialized += BTC_BLOCK_HEADER_SIZE;
  memcpy((uint8_t*)&workerFullName_ , buf + deserialized,  sizeof(workerFullName_));  deserialized += WORKER_NAME_SIZE;
  memcpy((uint8_t*)&rskFeesForMiner_, buf + deserialized,  sizeof(rskFeesForMiner_)); deserialized += RSK_DATA_STRING_FIELD_SIZE;
  memcpy((uint8_t*)&rpcAddress_     , buf + deserialized,  sizeof(rpcAddress_));      deserialized += RSK_DATA_STRING_FIELD_SIZE;
  memcpy((uint8_t*)&rpcUserPwd_     , buf + deserialized,  sizeof(rpcUserPwd_));      deserialized += RSK_DATA_STRING_FIELD_SIZE;

  return deserialized;
}


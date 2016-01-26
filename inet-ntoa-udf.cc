// Copyright 2016 Cloudera Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "inet-ntoa-udf.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

StringVal
INetNToA(FunctionContext* context, const IntVal& address)
{
  if (address.is_null)
    return StringVal::null();

  struct in_addr in;
  in.s_addr = ntohl(address.val);
  const char *host = inet_ntoa(in);

  if (host == NULL)
    return StringVal::null();

  StringVal result(context, strlen(host) + 1);
  memcpy(result.ptr, host, strlen(host) + 1);

  return result;
}

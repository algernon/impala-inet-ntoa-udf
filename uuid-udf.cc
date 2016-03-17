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

#include "uuid-udf.h"
#include <uuid.h>

StringVal
UUIDGen(FunctionContext* context)
{
  uuid_t uuid;
  char out[37];

  uuid_generate (uuid);
  uuid_unparse (uuid, out);

  StringVal result(context, 38);
  memcpy(result.ptr, out, 38);

  return result;
}

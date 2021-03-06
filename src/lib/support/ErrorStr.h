/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    Copyright (c) 2013-2017 Nest Labs, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *      This file defines functions to translate error codes and status reports
 *      used throughout the CHIP package into human-readable strings.
 *
 */

#ifndef ERRORSTR_H_
#define ERRORSTR_H_

#include <stdint.h>

#include <support/DLLUtil.h>

namespace chip {

struct ErrorFormatter
{
    typedef bool (*FormatFunct)(char * buf, uint16_t bufSize, int32_t err);

    FormatFunct FormatError;
    ErrorFormatter * Next;
};

extern const char * ErrorStr(int32_t err);
extern void RegisterErrorFormatter(ErrorFormatter * errFormatter);
extern void DeregisterErrorFormatter(ErrorFormatter * errFormatter);
extern void FormatError(char * buf, uint16_t bufSize, const char * subsys, int32_t err, const char * desc);

extern const char * StatusReportStr(uint32_t profileId, uint16_t statusCode);

} // namespace chip

#endif /* ERRORSTR_H_ */

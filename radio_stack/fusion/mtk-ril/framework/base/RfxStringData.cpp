/*
 * Copyright (C) 2021 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "RfxStringData.h"

RFX_IMPLEMENT_DATA_CLASS(RfxStringData);

RfxStringData::RfxStringData() : RfxBaseData(NULL, 0) {}

RfxStringData::RfxStringData(void* data, int length) : RfxBaseData(data, length) {
    copyString((char*)data, length);
}

RfxStringData::RfxStringData(char data[]) : RfxBaseData(data, strlen(data)) {
    copyString(data, strlen(data));
}

void RfxStringData::copyString(char* data, int length) {
    m_length = length;
    if (data != NULL) {
        m_data = strdup(data);
    } else {
        m_data = NULL;
    }
}

RfxStringData::~RfxStringData() {
    // free memory
    if (m_data) {
        free(m_data);
    }
}

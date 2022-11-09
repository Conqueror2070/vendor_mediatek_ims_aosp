/*
 * Copyright (C) 2016 The Android Open Source Project
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

#ifndef IVT_CLIENT_H
#define IVT_CLIENT_H

#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include "IVTInterface.h"
#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace VTService {

class IVTClient : public IInterface, public IVTNotifyCallback {
  public:
    DECLARE_META_INTERFACE(VTClient);
};

class BnVTClient : public BnInterface<IVTClient> {
  public:
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply,
                                uint32_t flags = 0);
};

extern sp<IVTClient> gVTClient;

}  // namespace VTService

#endif

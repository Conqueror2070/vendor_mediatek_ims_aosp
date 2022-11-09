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

#ifndef __RMC_COMM_SMS_URC_HANDLER_H__
#define __RMC_COMM_SMS_URC_HANDLER_H__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "RfxBaseHandler.h"

/*****************************************************************************
 * Class RpSimController
 *****************************************************************************/

class RmcCommSmsUrcHandler : public RfxBaseHandler {
    RFX_DECLARE_HANDLER_CLASS(RmcCommSmsUrcHandler);

  public:
    RmcCommSmsUrcHandler(int slot_id, int channel_id);

  protected:
    // Process URC here
    virtual void onHandleUrc(const sp<RfxMclMessage>& msg);

  private:
    void setTag(String8 tag) { mTag = tag; }

    // URC handler
    void handleSmsReady(const sp<RfxMclMessage>& msg);

  private:
    String8 mTag;
};
#endif /* __RMC_COMM_SMS_URC_HANDLER_H__ */

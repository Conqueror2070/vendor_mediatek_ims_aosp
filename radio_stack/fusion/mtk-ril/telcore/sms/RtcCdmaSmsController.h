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

#ifndef __RTC_CDMA_SMS_CONTROLLER_H__
#define __RTC_CDMA_SMS_CONTROLLER_H__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "RfxController.h"
#include "RtcSmsMessage.h"

/*****************************************************************************
 * Class RtcCdmaSmsController
 *****************************************************************************/

class RtcCdmaSmsController : public RfxController {
    RFX_DECLARE_CLASS(RtcCdmaSmsController);

  public:
    RtcCdmaSmsController();
    virtual ~RtcCdmaSmsController();

  public:
    void handleRequest(const sp<RfxMessage>& message);
    bool previewMessage(const sp<RfxMessage>& message);
    bool checkIfResumeMessage(const sp<RfxMessage>& message);
    void onTimer();
    void sendCdmaSms(RtcCdmaSmsMessage* msg);
    void sendCdmaSmsAck(const sp<RfxMessage>& message);

  protected:
    virtual void onInit();
    virtual bool onHandleRequest(const sp<RfxMessage>& message);
    virtual bool onHandleResponse(const sp<RfxMessage>& msg);
    virtual bool onHandleUrc(const sp<RfxMessage>& message);
    virtual bool onPreviewMessage(const sp<RfxMessage>& message);
    virtual bool onCheckIfResumeMessage(const sp<RfxMessage>& message);
    virtual bool onCheckIfRejectMessage(const sp<RfxMessage>& message, bool isModemPowerOff,
                                        int radioState);

  private:
    void handleMoSmsRequests(const sp<RfxMessage>& message);
    void handleSmscAdressResponses(const sp<RfxMessage>& message);
    void handleCdmaSmsAck(const sp<RfxMessage>& message);
    void handleMoSmsResponses(const sp<RfxMessage>& msg);
    bool onCheckCdmaSupported(const sp<RfxMessage>& message);
    bool onCheckSimStatus(const sp<RfxMessage>& message);
    bool onHandleNewSms(const sp<RfxMessage>& message);
    bool isSupportSmsFormatConvert();
    bool isCdmaPhoneMode();

  private:
    TimerHandle m_timer;
    bool m_needStatusReport;
    const int MT_SMS_ACK_TIME = 2;
    const char* TAG = "RtcCdmaSmsController";
};
#endif /* __RTC_CDMA_SMS_CONTROLLER_H__ */

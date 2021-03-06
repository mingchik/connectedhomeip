/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
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

#ifndef __TRANSPORT_RENDEZVOUSSESSIONCALLBACK_H__
#define __TRANSPORT_RENDEZVOUSSESSIONCALLBACK_H__

#include <core/CHIPCore.h>

namespace chip {

class RendezvousSessionDelegate
{
public:
    virtual ~RendezvousSessionDelegate() {}

    enum Status : uint8_t
    {
        SecurePairingSuccess = 0,
        SecurePairingFailed,
        NetworkProvisioningSuccess,
        NetworkProvisioningFailed,
    };

    virtual void OnRendezvousConnectionOpened()                             = 0;
    virtual void OnRendezvousConnectionClosed()                             = 0;
    virtual void OnRendezvousError(CHIP_ERROR err)                          = 0;
    virtual void OnRendezvousMessageReceived(System::PacketBuffer * buffer) = 0;
    virtual void OnRendezvousStatusUpdate(Status status) {}
};

} // namespace chip

#endif // __TRANSPORT_RENDEZVOUSSESSIONCALLBACK_H__

/*
 *   Copyright (c) 2022 Project CHIP Authors
 *   All rights reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */

#pragma once

#include "../common/CHIPCommand.h"

/**
 * This command prints out the version.
 *
 */

class VersionCommand : public CHIPCommand
{
public:
    VersionCommand(CredentialIssuerCommands * credIssuerCommands) : CHIPCommand("show", credIssuerCommands) {}

    /////////// CHIPCommand Interface /////////
    CHIP_ERROR RunCommand() override;
    chip::System::Clock::Timeout GetWaitDuration() const override
    {
        // The allowed duration of this method is at least as long as the time specified for blocking the
        // event loop. In order to not fail on some small delays in processing some extra time before
        // failing is added.
        constexpr uint16_t mExtraTimeForFailure = 1000;

        return chip::System::Clock::Milliseconds32(mExtraTimeForFailure);
    }
};

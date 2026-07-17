/*
 * Copyright (c) 2026 Realtek Semiconductor Corporation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <app/util/generic-callbacks.h>

#define AMEBA_CODE_DRIVEN_CALLBACK_BRIDGE(cluster)                                                                    \
    void emberAf##cluster##ClusterInitCallback(chip::EndpointId endpointId);                                           \
    void emberAf##cluster##ClusterShutdownCallback(chip::EndpointId endpointId);                                       \
    void Matter##cluster##ClusterInitCallback(chip::EndpointId endpointId)                                             \
    {                                                                                                                  \
        emberAf##cluster##ClusterInitCallback(endpointId);                                                             \
    }                                                                                                                  \
    void Matter##cluster##ClusterShutdownCallback(chip::EndpointId endpointId, MatterClusterShutdownType)             \
    {                                                                                                                  \
        emberAf##cluster##ClusterShutdownCallback(endpointId);                                                         \
    }

AMEBA_CODE_DRIVEN_CALLBACK_BRIDGE(OvenCavityOperationalState)
AMEBA_CODE_DRIVEN_CALLBACK_BRIDGE(OvenMode)
AMEBA_CODE_DRIVEN_CALLBACK_BRIDGE(LaundryWasherMode)
AMEBA_CODE_DRIVEN_CALLBACK_BRIDGE(RefrigeratorAndTemperatureControlledCabinetMode)
AMEBA_CODE_DRIVEN_CALLBACK_BRIDGE(RvcRunMode)
AMEBA_CODE_DRIVEN_CALLBACK_BRIDGE(RvcCleanMode)
AMEBA_CODE_DRIVEN_CALLBACK_BRIDGE(DishwasherMode)
AMEBA_CODE_DRIVEN_CALLBACK_BRIDGE(MicrowaveOvenMode)
AMEBA_CODE_DRIVEN_CALLBACK_BRIDGE(OperationalState)
AMEBA_CODE_DRIVEN_CALLBACK_BRIDGE(RvcOperationalState)
AMEBA_CODE_DRIVEN_CALLBACK_BRIDGE(EnergyEvseMode)
AMEBA_CODE_DRIVEN_CALLBACK_BRIDGE(WaterHeaterMode)
AMEBA_CODE_DRIVEN_CALLBACK_BRIDGE(DeviceEnergyManagementMode)
AMEBA_CODE_DRIVEN_CALLBACK_BRIDGE(SoilMeasurement)

#undef AMEBA_CODE_DRIVEN_CALLBACK_BRIDGE

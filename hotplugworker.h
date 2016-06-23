/*
 * Copyright (C) 2015 The Android Open Source Project
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

#ifndef ANDROID_HOTPLUG_WORKER_H_
#define ANDROID_HOTPLUG_WORKER_H_

#include "drmresources.h"
#include "worker.h"

#include <map>
#include <stdint.h>
#include <poll.h>

#include <hardware/hardware.h>
#include <hardware/hwcomposer.h>
#include <hardware_legacy/uevent.h>

namespace android {

class HotplugWorker : public Worker {
 public:
  HotplugWorker();
  ~HotplugWorker() override;

  int Init(DrmResources *drm, int display);
  int SetProcs(hwc_procs_t const *procs);

 protected:
  void Routine() override;

 private:
  DrmResources *drm_;
  hwc_procs_t const *procs_;

  int display_;
  bool connected;

  struct pollfd fds[1];
};
}

#endif

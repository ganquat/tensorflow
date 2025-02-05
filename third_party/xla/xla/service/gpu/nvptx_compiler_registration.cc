/* Copyright 2019 The OpenXLA Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include <memory>

#include "xla/service/gpu/nvptx_compiler.h"
#include "xla/stream_executor/cuda/cuda_platform_id.h"

static bool InitModule() {
  xla::Compiler::RegisterCompilerFactory(
      stream_executor::cuda::kCudaPlatformId,
      []() { return std::make_unique<xla::gpu::NVPTXCompiler>(); });
  return true;
}
static bool module_initialized = InitModule();

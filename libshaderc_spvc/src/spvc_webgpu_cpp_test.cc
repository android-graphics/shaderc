// Copyright 2019 The Shaderc Authors. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <gtest/gtest.h>

#include "common_shaders_for_test.h"
#include "spvc/spvc.hpp"

using shaderc_spvc::CompilationResult;
using shaderc_spvc::CompileOptions;
using shaderc_spvc::Context;

namespace {

class CompileTest : public testing::Test {
 public:
  Context context_;
  CompileOptions options_;
  CompilationResult result_;
};

TEST_F(CompileTest, Glsl) {
  options_.SetSourceEnvironment(shaderc_target_env_webgpu,
                                shaderc_env_version_webgpu);
  options_.SetTargetEnvironment(shaderc_target_env_vulkan,
                                shaderc_env_version_vulkan_1_1);

  shaderc_compilation_status status = context_.CompileSpvToGlsl(
      kWebGPUShaderBinary, sizeof(kWebGPUShaderBinary) / sizeof(uint32_t),
      options_, &result_);
  EXPECT_EQ(shaderc_compilation_status_success, status);
  EXPECT_NE(0, result_.GetStringOutput().size());
  EXPECT_EQ(0, result_.GetBinaryOutput().size());
}

TEST_F(CompileTest, Hlsl) {
  options_.SetSourceEnvironment(shaderc_target_env_webgpu,
                                shaderc_env_version_webgpu);
  options_.SetTargetEnvironment(shaderc_target_env_vulkan,
                                shaderc_env_version_vulkan_1_1);

  shaderc_compilation_status status = context_.CompileSpvToHlsl(
      kWebGPUShaderBinary, sizeof(kWebGPUShaderBinary) / sizeof(uint32_t),
      options_, &result_);
  EXPECT_EQ(shaderc_compilation_status_success, status);
  EXPECT_NE(0, result_.GetStringOutput().size());
  EXPECT_EQ(0, result_.GetBinaryOutput().size());
}

TEST_F(CompileTest, Msl) {
  options_.SetSourceEnvironment(shaderc_target_env_webgpu,
                                shaderc_env_version_webgpu);
  options_.SetTargetEnvironment(shaderc_target_env_vulkan,
                                shaderc_env_version_vulkan_1_1);

  shaderc_compilation_status status = context_.CompileSpvToMsl(
      kWebGPUShaderBinary, sizeof(kWebGPUShaderBinary) / sizeof(uint32_t),
      options_, &result_);
  EXPECT_EQ(shaderc_compilation_status_success, status);
  EXPECT_NE(0, result_.GetStringOutput().size());
  EXPECT_EQ(0, result_.GetBinaryOutput().size());
}

TEST_F(CompileTest, Vulkan) {
  options_.SetSourceEnvironment(shaderc_target_env_webgpu,
                                shaderc_env_version_webgpu);
  options_.SetTargetEnvironment(shaderc_target_env_vulkan,
                                shaderc_env_version_vulkan_1_1);

  shaderc_compilation_status status = context_.CompileSpvToVulkan(
      kWebGPUShaderBinary, sizeof(kWebGPUShaderBinary) / sizeof(uint32_t),
      options_, &result_);
  EXPECT_EQ(shaderc_compilation_status_success, status);
  EXPECT_EQ(0, result_.GetStringOutput().size());
  EXPECT_NE(0, result_.GetBinaryOutput().size());
}

}  // anonymous namespace
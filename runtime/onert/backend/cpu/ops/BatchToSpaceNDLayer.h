/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
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

#ifndef __ONERT_BACKEND_CPU_OPS_BATCHTOSPACEND_LAYER_H__
#define __ONERT_BACKEND_CPU_OPS_BATCHTOSPACEND_LAYER_H__

#include <backend/IPortableTensor.h>
#include "OperationUtils.h"

#include <exec/IFunction.h>

namespace onert
{
namespace backend
{
namespace cpu
{
namespace ops
{

class BatchToSpaceNDLayer : public ::onert::exec::IFunction
{
public:
  BatchToSpaceNDLayer();

public:
  void batchToSpaceNDFloat32();

  void batchToSpaceNDQuant8();

  void configure(const IPortableTensor *input, IPortableTensor *output,
                 IPortableTensor *block_shape, IPortableTensor *crops);

  void run() override;

private:
  const IPortableTensor *_input;
  IPortableTensor *_output;
  IPortableTensor *_block_shape;
  IPortableTensor *_crops;
  //  const int32_t *_crops_buffer;
};

} // namespace ops
} // namespace cpu
} // namespace backend
} // namespace onert

#endif // __ONERT_BACKEND_CPU_OPS_BATCHTOSPACEND_LAYER_H__

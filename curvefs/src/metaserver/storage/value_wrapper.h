/*
 *  Copyright (c) 2022 NetEase Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*
 * Project: Curve
 * Created Date: 2022-04-05
 * Author: Jingli Chen (Wine93)
 */

#ifndef CURVEFS_SRC_METASERVER_STORAGE_VALUE_WRAPPER_H_
#define CURVEFS_SRC_METASERVER_STORAGE_VALUE_WRAPPER_H_

#include <cstddef>
#include <memory>

#include "curvefs/src/metaserver/storage/common.h"

namespace curvefs {
namespace metaserver {
namespace storage {

class ValueWrapper {
 public:
    explicit ValueWrapper(const ValueType& value) {
        value_.reset(value.New());
        value_->CopyFrom(value);
    }

    std::shared_ptr<ValueType> Message() const { return value_; }

 private:
    std::shared_ptr<ValueType> value_;
};

}  // namespace storage
}  // namespace metaserver
}  // namespace curvefs

#endif  // CURVEFS_SRC_METASERVER_STORAGE_VALUE_WRAPPER_H_

// Copyright 2011 Google Inc.
// Author: moesenle@google.com (Lorenz Moesenlechner)
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

#include <ros/ros.h>

#include "laser_signal_filter/laser_signal_filter.h"

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "laser_signal_filter");
  ros::NodeHandle node_handle("~");
  laser_signal_filter::LaserSignalFilter laser_signal_filter(node_handle);
  bool increasing_enabled;
  node_handle.param("increasing_enabled", increasing_enabled, true);
  bool decreasing_enabled;
  node_handle.param("decreasing_enabled", decreasing_enabled, true);
  laser_signal_filter.EnableSignals(increasing_enabled, decreasing_enabled);
  ros::spin();
  return 0;
}

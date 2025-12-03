/*
 * Copyright (C) 2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include "effect.h"

#include <json/json.h>
#include <unordered_map>

class VibrationEffectLoader {
  public:
    static VibrationEffectLoader &getInstance();

    effect_stream* getEffectStream(uint32_t effect_id);
  private:
    VibrationEffectLoader();
    ~VibrationEffectLoader();

    // Disallow copy constructor and copy assignment operator for a singleton.
    VibrationEffectLoader(const VibrationEffectLoader &) = delete;
    VibrationEffectLoader &operator=(const VibrationEffectLoader &) = delete;

    Json::Value parseEffectJson(std::ifstream& config_stream);
    void loadEffects(Json::Value&& effect_nodes);

    uint32_t translatePrimitiveToEffect(uint32_t primitive_id);

    std::unordered_map<uint32_t, effect_stream> effect_map_;
};

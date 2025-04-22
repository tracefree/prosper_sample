#pragma once

#include <core/component.h>

struct RotateScript : public Component {

    void update(double delta) override;

    std::string get_name() {
        return "RotateScript";
    }

    COMPONENT_FACTORY_H(RotateScript)
};
#include "rotate.h"
#include <core/node.h>
#include <yaml.h>

void RotateScript::update(double delta) {
    node->rotate(Vec3(0.0f, 1.0f, 0.0f), 0.6f * delta);
}

COMPONENT_FACTORY_IMPL(RotateScript, rotate) {}
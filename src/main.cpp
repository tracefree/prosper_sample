#include <prosper.h>
#include <core/node.h>
#include <core/scene_graph.h>
#include <components/collectible.h>
#include <resources/scene.h>
#include <core/resource.h>
#include <core/resource_manager.h>

#include "components/rotate.h"
#include <components/state_machine.h>

#include <states/air.h>
#include <states/dodge.h>
#include <states/move.h>
#include <states/idle.h>

extern SceneGraph scene;
extern Ref<Node> player;

int main(int argc, char * argv[]) {
    if (!prosper::initialize()) {
        return 1;
    }

    const char* initial_level_path;
    if (argc == 3 && strcmp(argv[1], "--scene") == 0) {
        initial_level_path = argv[2];
    } else {
        initial_level_path = "data/level.yaml";
    }

    Ref<Node> level = (*ResourceManager::load<Scene>(initial_level_path))->instantiate();
    scene.root->add_child(level);

    player = (*ResourceManager::load<Scene>("data/player.yaml"))->instantiate();
    scene.root->add_child(player);
    
    bool running = true;
    while (running) {
        running = prosper::iterate();

        if (Collectible::total_count > 0) {
            player->get_component<StateMachine>()->jump_speed = 1.0f + 3.0f * Collectible::collected_count;
        }
    }
    
    prosper::quit();
    return 0;
}
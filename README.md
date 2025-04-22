# Prosper Sample

This is an example project that can be inspected to see how my custom game engine [Prosper](https://github.com/tracefree/prosper) can be used and showcases some of its features. It is an extremely simple 3D game where you must collect seven krapfens scattered around the famous Sponza scene. Each krapfen you eat increases your jump height, making it possible to reach higher areas.

![prosper_sample_screenshot](https://github.com/user-attachments/assets/7374ebc1-24d6-4824-a8a6-4846fa594fb6)

## Install
Binaries are coming soon™.

## Build
### Unix

Requirements: You need to have installed SDL3, Vulkan SDK, and the Vulkan utility libraries on your system.

Clone the repository and execute the following commands with a terminal inside the directory:

```
cmake -B build . -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

The binary is then generated in the root folder of the project and can be executed with `./prosper_sample`.

### Windows
Coming soon™.

## License
See [LICENSE.md](LICENSE.md).

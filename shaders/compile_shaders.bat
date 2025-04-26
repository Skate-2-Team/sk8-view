@echo off

REM This script compiles the shaders for the game.
REM Using VULKAN_SDK environment variable to find the glslc compiler.

REM Compile the shaders
for %%f in (*.vert) do (
    "%VULKAN_SDK%\Bin\glslc.exe" "%%f" -o "%%~nf_vert.spv"
)

for %%f in (*.frag) do (
    "%VULKAN_SDK%\Bin\glslc.exe" "%%f" -o "%%~nf_frag.spv"
)
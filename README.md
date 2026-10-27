# VEERA: The Forgotten Soldiers

A historically grounded World War II game project centred on the British Indian Armed Forces, personal stories, family, and service.

## Unreal Engine 5.6 project

This repository contains a native Unreal Engine C++ project:

- `Veera.uproject` targets Unreal Engine 5.6 and enables Enhanced Input as a project plugin.
- `AVeeraCharacter` provides first-person mouse look, WASD movement, jump and target interaction.
- `AVeeraGameMode` builds a small training yard at runtime from Unreal's built-in basic shapes.
- Three range targets can be inspected with **E** to complete the first drill.

The training yard is deliberately a code-built prototype. It has no imported character art, animations, weapons, audio or saved `.umap` yet. The old `index.html` is a legacy browser prototype and is not the Unreal game. This project has not been compiled or opened in Unreal Editor in this environment.

## Open and play on macOS

1. Install Unreal Engine 5.6 through the Epic Games Launcher.
2. Clone or download this repository.
3. Double-click `Veera.uproject`. Let Unreal generate project files and compile the C++ module. If prompted, install Apple's Xcode Command Line Tools.
4. Create a new **Basic** level (or open the default level) and press **Play**. The game mode builds the training yard when play begins.
5. Use **WASD** to move, the **mouse** to look, **Space** to jump, and **E** while facing a range target to inspect it.

If the editor does not use `AVeeraGameMode` in a newly created level, set it in **World Settings → GameMode Override**. Project defaults are in `Config/DefaultEngine.ini`.

## Current prototype scope

The code-built yard uses generic primitive geometry so it needs no third-party assets. It is a foundation for iteration, not final environment art. Next production steps:

1. Save and refine the yard as `/Game/Maps/TrainingGround`, replacing blockout geometry with licensed, period-appropriate assets.
2. Add authored training objectives, an instructor, UI feedback and audio.
3. Add researched uniforms, equipment, units and campaign details; avoid presenting invented dialogue or characters as historical fact.
4. Build the family farewell scene, further missions, progression and save data.

Use assets only under licences that permit the intended use. Represent Sikh cultural and religious details respectfully and verify historical specifics before they appear in the game.

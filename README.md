# VEERA: The Forgotten Soldiers

A historically grounded World War II game project centred on the British Indian Armed Forces, personal stories, family, and service.

## Main project: Unreal Engine 5

The repository now contains the beginning of a native Unreal Engine C++ project:

- `Veera.uproject` project descriptor (configured for Unreal Engine 5.6)
- A first-person character class with mouse look, WASD movement and jump
- A default game mode that spawns the VEERA character
- Basic keyboard and mouse input mappings

**This is a project scaffold, not a finished game.** It has not been compiled or opened in Unreal Editor in this environment. The training camp, character models, animations, weapons, cinematics, audio, materials and final levels still need to be created or imported in Unreal Engine. The old `index.html` is only a legacy browser prototype and is not the Unreal game.

## Open the project on macOS

1. Install Unreal Engine 5.6 (or update the project configuration to match the installed engine version) through the Epic Games Launcher.
2. Download or clone this repository to your Mac.
3. Double-click `Veera.uproject` and allow Unreal to generate project files and compile the C++ module. If prompted, install Apple's Xcode Command Line Tools.
4. Once the editor opens, create a level and save it as `/Game/Maps/TrainingGround`.
5. Add a Player Start and a GameMode override if needed, then press **Play** to test the basic character.

The source code is under `Source/Veera`; default input and game-mode settings are under `Config`.

## Development priorities

1. **Playable vertical slice:** training-ground level, first-person controls, basic interactable training targets and clear objectives.
2. **Environment:** period-informed barracks, parade square, obstacle course, training lanes, props, terrain, lighting and atmosphere.
3. **Characters:** historically appropriate soldier assets, rigging, locomotion, marching/drill animations, instructor behaviours and crowd placement.
4. **Cinematics:** family farewell sequence, camera blocking, facial/body animation, dialogue, subtitles and transitions.
5. **Audio:** original score, environmental ambience, drill commands, footsteps and weapon sounds.
6. **Campaign:** researched missions, progression, save data and further gameplay systems.

## Assets and historical accuracy

Use licensed assets and keep a record of their source and permitted use. Unreal Engine's built-in starter content and learning assets can help prototype the first level; higher-quality character models, uniforms, props and animations will need appropriate licensed assets or custom work. Avoid presenting invented dialogue or characters as historical fact. Research period uniforms, ranks, equipment, units and campaigns, and represent Sikh cultural and religious details respectfully.

## Legacy browser prototype

`index.html` remains in the repository as an old proof of concept. GitHub Pages can host that page, but **it does not run the Unreal Engine game**. Unreal development and packaging must be done with Unreal Engine on a supported computer.

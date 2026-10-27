# VEERA: The Forgotten Soldiers

A historically grounded World War II game concept centred on the British Indian Armed Forces, personal stories, family, and service.

## Current build: browser prototype

The repository currently contains an early, playable first-person training-range prototype in `index.html`. It includes:
- A story-led opening with a sister's farewell and the name "Veera"
- Army, Navy, and Air Force selection screens
- A 3D training ground, movement, mouse-look, a simple placeholder rifle, and target practice
- A lightweight HUD and basic range objective

### Play it locally
Because the prototype imports Three.js from a CDN, run it from a local web server rather than opening the file directly.

With Python installed:
```bash
python3 -m http.server 8000
```
Then visit `http://localhost:8000`.

### Publish with GitHub Pages
1. Open the repository's **Settings → Pages**.
2. Under **Build and deployment**, select **Deploy from a branch**.
3. Select branch **main** and folder **/(root)**, then save.
4. Wait for the Pages deployment to finish. The site will be available at:
   `https://vihaanchillguy-ui.github.io/veera-the-forgotten-soldiers/`

If Pages is unavailable or the deployment fails, check the Actions tab and repository Pages settings.

## Important scope note

This is a prototype, not a finished Battlefield-scale game. The 3D range uses simple procedural placeholder assets and has no real multiplayer, save accounts, production-grade weapon simulation, naval or aircraft gameplay, or final historical assets yet. The long-term target is a realistic Unreal Engine 5 game with dedicated multiplayer servers; GitHub is source control and can host this companion prototype, but it does not itself run multiplayer game servers.

## Historical approach

Use verified historical references for unit names, uniforms, ranks, equipment, campaigns, and service branches. Clearly distinguish invented characters and dialogue from documented history. Sikh cultural and religious items and expressions should be represented respectfully and accurately.

## Roadmap
- [ ] Replace placeholder geometry with researched period-appropriate assets
- [ ] Add character creator and saved story progress
- [ ] Add academy training tasks and scripted scenes
- [ ] Add historically researched campaign missions
- [ ] Plan Unreal Engine 5 production project
- [ ] Build authoritative dedicated-server multiplayer and matchmaking
- [ ] Expand into naval and aircrew gameplay

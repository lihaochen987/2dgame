# 2dgame

## Directory structure
```markdown
epic-game/                      # Root project directory
├── .gitignore                  # Git ignore file
├── CMakeLists.txt             # Main CMake configuration
├── README.md                  # Project documentation
├── assets/                    # Game assets directory
│   ├── audio/                # Audio files
│   │   ├── music/           # Background music
│   │   └── sfx/            # Sound effects
│   ├── fonts/               # Font files
│   ├── textures/            # Image files
│   │   ├── characters/     # Character sprites
│   │   ├── backgrounds/    # Background images
│   │   ├── ui/            # UI elements
│   │   └── particles/     # Particle effects
│   └── maps/               # Level/map files
├── src/                      # Source code
│   ├── main.cpp             # Entry point
│   ├── core/               # Core game systems
│   │   ├── game.hpp        # Game class
│   │   ├── game.cpp
│   │   ├── resource_manager.hpp
│   │   └── resource_manager.cpp
│   ├── entities/           # Game entities
│   │   ├── entity.hpp      # Base entity class
│   │   ├── player.hpp      # Player class
│   │   └── enemy.hpp       # Enemy class
│   ├── systems/            # Game systems
│   │   ├── input/         # Input handling
│   │   ├── physics/       # Physics/collision
│   │   ├── audio/         # Audio system
│   │   └── rendering/     # Rendering system
│   ├── ui/                # User interface
│   │   ├── menu.hpp
│   │   └── hud.hpp
│   └── utils/             # Utility functions/classes
│       ├── math.hpp
│       └── debug.hpp
├── tests/                    # Test directory
│   ├── CMakeLists.txt       # Test CMake configuration
│   ├── unit/               # Unit tests
│   └── integration/        # Integration tests
├── docs/                     # Documentation
│   ├── api/                # API documentation
│   └── design/             # Design documents
├── extern/                   # External dependencies
│   └── CMakeLists.txt       # External deps CMake
└── scripts/                  # Build/deployment scripts
    ├── build.sh
    └── package.sh
```
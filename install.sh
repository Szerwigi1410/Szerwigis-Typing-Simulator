#!/bin/bash

GREEN="\033[32m"
RED="\033[31m"
BLUE="\033[34m"
CYAN="\033[36m"
WHITE="\033[37m"
YELLOW="\033[33m"
PURPLE="\033[35m"
BOLD="\033[1m"
RESET="\033[0m"
BLACK="\033[30m"
GRAY="\033[90m"

clear

# Check if OpenGL headers are present
if [ -f /usr/include/GL/gl.h ]; then
    echo -e "[${GREEN} OK ${RESET}] GL header present"
else
    echo -e "${BOLD}${YELLOW}WARNING:${RESET} GL header is ${BOLD}not${RESET} present"
    echo -e "Would you like to install it automatically? (y/n): "

    read glYN
    case "$glYN" in
        'y') sudo apt update && sudo apt install -y build-essential libgl1-mesa-dev libglu1-mesa-dev && sudo pacman -Syu --needed mesa mesa-demos && sudo dnf install -y mesa-libGL-devel mesa-libGLU-devel && sudo zypper install -y Mesa-devel Mesa-libGLU-devel && sudo apk add mesa-dev && sudo pkg install -y mesa-libs && sudo emerge --ask media-libs/mesa && sudo slackpkg install mesa && sudo xbps-install -Sy mesa mesa-devel && sudo eopkg install mesa libGLU-devel;;
        *) exit;;
    esac

fi

# Check if GLUT headers are present
if [ -f /usr/include/GL/glut.h ] || [ -f /usr/include/GL/freeglut.h ]; then
    echo -e "[${GREEN} OK ${RESET}] GLUT/FreeGLUT header present"
else
    echo -e "${BOLD}${YELLOW}WARNING:${RESET} GLUT/FreeGLUT headers are ${BOLD}not${RESET} present"
    echo -e "Would you like to install them automatically? (y/n): "

    read glutYN
    case "$glutYN" in
        'y') sudo apt update && sudo apt install -y freeglut3-dev && sudo pacman -Syu --needed freeglut && sudo dnf install -y freeglut-devel && sudo zypper install -y freeglut-devel && sudo apk add freeglut-dev && sudo pkg install -y freeglut && sudo emerge --ask media-libs/freeglut && sudo slackpkg install freeglut && sudo xbps-install -Sy freeglut freeglut-devel && sudo eopkg install freeglut-devel;;
        *) exit;;
    esac
fi

#compile
bash compiling-FreeBSD.sh
echo -e "${BOLD}${GREEN}Ignore the warnings. Everything is fine${RESET}"

# --- Step 1: Identify available source files ---

available_scripts=()
if [ -f "game" ]; then
    available_scripts+=("game")
fi

# Exit if no source files are found
if [ ${#available_scripts[@]} -eq 0 ]; then
    echo -e "${RED}Error code 001:${RESET} game was not found in the current directory."
    exit 1
fi

# --- Step 2: Prompt user for choice if multiple scripts are found ---

source_file=""
if [ ${#available_scripts[@]} -eq 1 ]; then
    source_file="${available_scripts[0]}"
    echo "Found '${source_file}'. This script will be installed."
else
    echo "Multiple brokefetch scripts found. Please choose one to install:"
    select choice in "${available_scripts[@]}"; do
        if [ -n "$choice" ]; then
            source_file="$choice"
            break
        else
            echo "Invalid choice. Please select a number from the list."
        fi
    done
fi

# --- Step 3: Check for existing installation and prompt for overwrite/remove ---

# Check if an old version of brokefetch exists
if [ -f "/usr/bin/szerwigis-typing-sim" ]; then
    echo "An existing 'ascii-enc' script was found at /usr/bin/ascii-enc."
    
    # Prompt the user to remove or replace
    while true; do
        read -p "Do you want to (r)eplace it or (x) to remove it first? (r/x) " action
        case "$action" in
            [Rr]* ) 
                echo "Replacing existing ascii-enc script."
                break
                ;;
            [Xx]* )
                echo "Removing old version before installation."
                sudo rm /usr/bin/szerwigis-typing-sim
                break
                ;;
            * ) 
                echo "Invalid input. Please enter 'r' or 'x'."
                ;;
        esac
    done
fi

# --- Step 4: Perform the installation ---

echo "Installing '$source_file' to /usr/bin/szerwigis-typing-sim..."

# Copy the chosen file to /usr/bin
sudo cp "$source_file" /usr/bin/szerwigis-typing-sim
sudo cp STSLogo.png /usr/share/icons
sudo cp szerwigis-typing-sim.desktop /usr/share/applications/

# --- Step 5: Verify installation and provide success message ---

if [ -f "/usr/bin/szerwigis-typing-sim" ]; then
    echo "Success! '$source_file' is now installed as 'szerwigis-typing-sim'."
    echo "You can run it from any directory by typing 'szerwigis-typing-sim'."
else
    echo -e "${RED}Error code 002:${RESET} an occurred during installation."
    exit 1
fi

exit 0

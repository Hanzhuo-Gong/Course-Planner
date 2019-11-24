#!/bin/bash

function homebrew() {
    echo "L"
    if command -v brew &>/dev/null; then
        return 1
    fi
    echo "Installing Homebrew..."
    /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
}

if command -v python3 &>/dev/null; then
    echo "Python 3 is installed."
else
    homebrew
    echo "Installing Python 3 with Homebrew..."
    brew install python3
fi

if command -v pip3 &>/dev/null; then
    echo "Pip 3 is installed."
else
    homebrew
    echo "Installing Pip 3 with Homebrew..."
    brew install pip3
fi

if command -v flask &>/dev/null; then
    echo "Flask is installed."
else
    echo "Installing Flask with Pip 3..."
    pip3 install flask
fi

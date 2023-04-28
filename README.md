#!/bin/bash

# Mettre à jour la liste des paquets et le système
sudo apt update && sudo apt upgrade -y

# Installer les paquets nécessaires pour ajouter des dépôts tiers
sudo apt install -y curl gnupg software-properties-common

# Installer NVM (Node Version Manager)
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.38.0/install.sh | bash

# Charger NVM et installer Node.js et npm
export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"
nvm install --lts
nvm use --lts

# Installer Git
sudo apt install -y git

# Installer Chromium
sudo apt install -y chromium-browser

# Installer Mullvad VPN
curl -LO https://github.com/mullvad/mullvadvpn-app/releases/download/2021.4/mullvad-vpn_2021.4-1_arm64.deb
sudo dpkg -i mullvad-vpn_2021.4-1_arm64.deb
sudo apt install -f -y
rm mullvad-vpn_2021.4-1_arm64.deb

# Installer Yarn
curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | sudo apt-key add -
echo "deb https://dl.yarnpkg.com/debian/ stable main" | sudo tee /etc/apt/sources.list.d/yarn.list
sudo apt update && sudo apt install -y yarn

# Installer Zsh et Oh My Zsh
sudo apt install -y zsh
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

# Changer le shell par défaut pour l'utilisateur actuel
chsh -s $(which zsh)

echo "Toutes les installations sont terminées. Vous devrez peut-être redémarrer votre machine pour que tous les changements prennent effet."


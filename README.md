# Médocs [![Launchpad.net !](http://media.launchpad.net/lp-badge-kit/launchpad-badge-w120px.png)](https://launchpad.net/medocs)
[![Licence](https://img.shields.io/github/license/drxtun/medocs.svg)](LICENSE) [![Etat du build sur Travis](https://travis-ci.org/drxtun/medocs.svg?branch=master)](https://travis-ci.org/drxtun/medocs) [![Etat du build sur Appveyor](https://ci.appveyor.com/api/projects/status/9auqcy32ae4uvy5c?svg=true)](https://ci.appveyor.com/project/drxtun61291/medocs) [![Dernière version](https://img.shields.io/github/release/drxtun/medocs.svg)](https://github.com/drxtun/medocs/releases/latest) [![Nombre de téléchargements](https://img.shields.io/github/downloads/drxtun/medocs/total.svg)](https://github.com/drxtun/medocs/releases)
## A propos
Cette application permet au grand public et aux professionnels de santé d'accéder à des données sur les médicaments commercialisés ou ayant l'autorisation de mise sur le marché tunisien. C'est une application gratuite et son code source est ouvert (voir [licence GPL-3](LICENSE)).
> En savoir plus sur le projet: https://drxtun.github.io
> Rapporter des bugs ou des erreurs: https://github.com/drxtun/medocs/issues

## Installation
Vous retrouverez des programmes d'installation en téléchargement pour Windows 32 bits (`medocs*_x86.exe`) et 64 bits (`medocs*_x64.exe`) sur la page [releases](https://github.com/drxtun/medocs/releases).

Sous Ubuntu Trusty, Xenial, Artful, Bionic et Cosmic vous pouvez installer l'application en ajoutant le ppa [ppa:drx.tn/ppa](https://launchpad.net/~drx.tn/+archive/ubuntu/ppa) à vos sources de mises-à-jour puis en l'installant avec ces commandes:

    sudo add-apt-repository -y ppa:drx.tn/ppa
    sudo apt-get update
    sudo apt-get install -y medocs

Pour les autres versions de linux vous devez compiler l'application par vous même.

## Compilation à partir de la source
> Pour compiler l'application pour Windows/Linux/Mac vous aurez besoin de [Qt](https://www.qt.io/download-qt-installer) et pour Android [Android Studio ou les outils en ligne de commande](https://developer.android.com/studio/#downloads).

La première étape consiste à cloner ce dépôt et à se diriger à l'intérieur du dossier `medocs`:

    git clone https://github.com/drxtun/medocs
    cd medocs

### Sous Linux

A partir de Qt Creator ou en ligne de commande avec:

    qmake -config release
    make

Sous Linux vous pouvez ensuite installer l'application avec:

    sudo make install

### Sous Windows

A partir de Qt Creator ou en ligne de commande avec:

    qmake -config release
    nmake                 # Commande à utiliser si vous utilisez MSVC
                          # ou autre si vous utilisez un autre environnement.

Vous pouvez ensuite déployer l'application avec:

    windeployqt qt\release

Ou bien encore comme utilisé dans la configuration de notre environnement d'intégration continue:

    windeployqt --release --no-patchqt --no-quick-import --no-translations --no-compiler-runtime --no-webkit2 --no-angle --no-opengl-sw qt\release

> Pour compiler le programme d'installation sous Windows il vous faudra [NSIS](http://nsis.sourceforge.net).

Pour compiler le programme d'installation il faudra tout d'abord nettoyer le dossier `qt/release` avec:

    nmake clean           # Commande à utiliser si vous utilisez MSVC
                          # ou autre si vous utilisez un autre environnement.

puis compiler le script NSIS avec:

    makensis VERSION ARCHITECTURE medocs.nsi       # vous pouvez mettre ou pas ces 2 variables.

### Sous Mac

> Bien que ça n'a pas été testé ces étapes devraient marcher. :wink:

A partir de Qt Creator ou en ligne de commande avec:

    qmake -config release
    make

Pour déployer l'image d'installation il suffit d'utiliser `macdeployqt`:

    macdeployqt qt/medocs.app -dmg

### Compilation de l'application Android

> Cette application est encore en développement.

A partir d'Android Studio ou en ligne de commande avec `gradlew`:

Sous windows:

    gradlew.bat assembleRelease

Sous Linux ou Mac:

    ./gradlew assembleRelease

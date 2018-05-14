# Médocs [![Launchpad.net](http://media.launchpad.net/lp-badge-kit/launchpad-badge-w120px.png)](https://launchpad.net/medocs) [![Build Status](https://travis-ci.org/drxtun/medocs.svg?branch=master)](https://travis-ci.org/drxtun/medocs) [![Build status](https://ci.appveyor.com/api/projects/status/9auqcy32ae4uvy5c?svg=true)](https://ci.appveyor.com/project/drxtun61291/medocs)
## A propos
Cette application permet au grand public et aux professionnels de santé d'accéder à des données sur les médicaments commercialisés ou ayant l'autorisation de mise sur le marché tunisien. C'est une application gratuite et son coude source est ouvert (voir [licence GPL-3](LICENSE.md)).
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
> Pour compiler l'application pour Windows/Linux/Mac vous devez avoir [Qt](https://www.qt.io/download-qt-installer) et pour Android [Android Studio ou les outils en ligne de commande](https://developer.android.com/studio/#downloads).

Clonez ce dépôt:

    git clone https://github.com/drxtun/medocs

Les étapes nécessaires ensuite:

    cd medocs
    qmake -config release
    make

Sous Linux vous pouvez ensuite installer l'application avec:

    sudo make install

Sous Windows vous pouvez déployer l'application avec:

    windeployqt

et sous Mac avec:

    macdeployqt

Sous Windows vous pouvez après créer le programme d'installation à partir du script [NSIS](http://nsis.sourceforge.net):

    make clean            # pour nettoyer les fichiers non nécessaires
    makensis medocs.nsi   # ce qui créera medocs.exe (programme d'installation)

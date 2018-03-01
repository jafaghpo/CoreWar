# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    install_ressources.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 22:30:09 by jafaghpo          #+#    #+#              #
#    Updated: 2018/03/01 16:32:05 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/zsh

CORE_PATH=/Users/jafaghpo/Projects/Corewar
TEST_DIR=tests

#====== Colors ======#

EOC="\033[0m";
RED="\033[31m";
GREEN="\033[32m";
YELLOW="\033[33m"
BLUE="\033[34m";
MAGENTA="\033[35m";
CYAN="\033[36m";
HIGH="\033[1m";
BG_RED="\033[41m";
BG_BLUE="\033[44m";

#====== Script ======#

echo "$HIGH$YELLOW> Downloading ressources:$EOC"
mkdir -p $CORE_PATH/$TEST_DIR
rm $CORE_PATH/$TEST_DIR/*.tar*
cd $CORE_PATH/$TEST_DIR
wget "https://projects.intra.42.fr/uploads/document/document/391/vm_champs.tar"
tar xvf vm_champs.tar
cd -

mkdir -p $CORE_PATH/$TEST_DIR/true_champs
mkdir -p $CORE_PATH/$TEST_DIR/true_champs
cp $CORE_PATH/$TEST_DIR/champs/**/**/**/*.s tests/true_champs/.
cp -R $CORE_PATH/$TEST_DIR/true_champs tests/my_champs

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_dl.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 22:30:09 by jafaghpo          #+#    #+#              #
#    Updated: 2018/03/12 16:47:13 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/zsh

CORE_PATH=$(pwd)
TEST_DIR=tests
MY_ASM=my_champs
REAL_ASM=real_champs
MY_BIN=my_bin
REAL_BIN=real_bin

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
cd $CORE_PATH/$TEST_DIR
wget "https://projects.intra.42.fr/uploads/document/document/391/vm_champs.tar"
tar xvf vm_champs.tar
cd -

mkdir -p $CORE_PATH/$TEST_DIR/$REAL_ASM
cp $CORE_PATH/$TEST_DIR/champs/**/**/**/*.s $CORE_PATH/$TEST_DIR/$REAL_ASM/.
cp $CORE_PATH/$TEST_DIR/champs/*.s $CORE_PATH/$TEST_DIR/$REAL_ASM/.
cp -R $CORE_PATH/$TEST_DIR/$REAL_ASM $CORE_PATH/$TEST_DIR/$MY_ASM
mkdir -p $CORE_PATH/$TEST_DIR/$REAL_BIN
mkdir -p $CORE_PATH/$TEST_DIR/$MY_BIN
cp $CORE_PATH/$TEST_DIR/$REAL_ASM/*.s $CORE_PATH/$TEST_DIR/$MY_BIN/.
cp $CORE_PATH/$TEST_DIR/$REAL_ASM/*.s $CORE_PATH/$TEST_DIR/$REAL_BIN/.

echo "$HIGH$YELLOW\n> Compiling my binary files:$EOC"
for i in $CORE_PATH/$TEST_DIR/$MY_BIN/*.s
do $CORE_PATH/$TEST_DIR/asm $i;
done;

echo "$HIGH$YELLOW\n> Compiling real binary files:$EOC"
for i in $CORE_PATH/$TEST_DIR/$REAL_BIN/*.s
do $CORE_PATH/$TEST_DIR/asm $i;
done;
cp $CORE_PATH/$TEST_DIR/$REAL_BIN/*.cor $CORE_PATH/$TEST_DIR/$MY_BIN/

rm $CORE_PATH/$TEST_DIR/$REAL_BIN/*.s
rm $CORE_PATH/$TEST_DIR/$MY_BIN/*.s
rm -rf $CORE_PATH/$TEST_DIR/champs
rm $CORE_PATH/$TEST_DIR/vm_champs.tar

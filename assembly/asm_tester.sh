# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    asm_tester.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 15:37:51 by jafaghpo          #+#    #+#              #
#    Updated: 2018/03/08 19:19:19 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/zsh

CORE_PATH=/Users/jafaghpo/Projects/Corewar
TEST_DIR=tests
MY_DIR=my_champs
REAL_DIR=real_champs

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

echo "$HIGH$GREEN--- Welcome to asm_tester ---$EOC"

echo "$HIGH$YELLOW\n> Compiling real assembly files:$EOC"
for i in $CORE_PATH/$TEST_DIR/$REAL_DIR/*.s
do $CORE_PATH/$TEST_DIR/asm $i;
done;

echo "$HIGH$YELLOW\n> Compiling my assembly files:$EOC"
$CORE_PATH/asm $CORE_PATH/$TEST_DIR/$MY_DIR/*.s;

rm $CORE_PATH/$TEST_DIR/$MY_DIR/*.cor
rm $CORE_PATH/$TEST_DIR/$REAL_DIR/*.cor

echo "$HIGH$YELLOW\n> Comparing folders:$EOC"
diff $CORE_PATH/$TEST_DIR/$REAL_DIR $CORE_PATH/$TEST_DIR/$MY_DIR;
if [[ $? -eq 0 ]]; then
	echo "There is no differences"
fi;

echo $EOC;
echo "done."

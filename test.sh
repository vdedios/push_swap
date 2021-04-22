#usr/bin/env bash

export NUMSDEF=$(shuf -i 0-$1 -n $1 | xargs)

./push_swap $(echo $NUMSDEF) | ./checker $2 $3 $4 $(echo $NUMSDEF)
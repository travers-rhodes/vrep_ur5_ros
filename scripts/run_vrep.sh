#!/usr/bin/env bash

#pushd ~/vrep_ws > /dev/null
#source devel/setup.bash
#popd > /dev/null

echo $1
# pass in the full path to the desired ttm scene as argument 1
# also start another remote server (so we can attach via Python as well as via C++)
pushd ~/V-REP_PRO_EDU_V3_5_0_Linux > /dev/null
./vrep.sh -s $1 -gREMOTEAPISERVERSERVICE_19992_FALSE_FALSE
popd > /dev/null

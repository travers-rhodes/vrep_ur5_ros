#!/usr/bin/env bash

#pushd ~/vrep_ws > /dev/null
#source devel/setup.bash
#popd > /dev/null

echo $1
# pass in the full path to the desired ttm scene as argument 1
pushd ~/V-REP_PRO_EDU_V3_5_0_Linux > /dev/null
./vrep.sh -s $1
popd > /dev/null
